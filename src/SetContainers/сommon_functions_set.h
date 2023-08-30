#ifndef _SRC_CONTAINERS_COMMONFUNCTIONS_SET_H_
#define _SRC_CONTAINERS_COMMONFUNCTIONS_SET_H_

namespace s21 {
template <class key>
class Node {
 public:
  Node(key data) {
    height_ = 1;
    this->key_ = data;
    this->left_ = this->right_ = nullptr;
  }
  int height_ = 0;
  key key_ = 0;
  Node* left_ = nullptr;
  Node* right_ = nullptr;
  Node* next_ = nullptr;
  Node* prev_ = nullptr;
  Node* parent_ = nullptr;
};
}  // namespace s21

template <class key>
typename s21::Node<key>* NodeWithMimumValue(s21::Node<key>* node) noexcept {
  s21::Node<key>* current = node;
  while (current->left_ != nullptr) current = current->left_;
  return current;
}

int Max(int a, int b) noexcept { return (a > b) ? a : b; }

template <class key>
int Height(s21::Node<key>* N) noexcept {
  if (N == nullptr) return 0;
  return N->height_;
}

template <class key>
int GetBalanceFactor(s21::Node<key>* N) noexcept {
  if (N == nullptr) return 0;
  return Height(N->left_) - Height(N->right_);
}

template <class key>
typename s21::Node<key>* RightRotate(s21::Node<key>* y) noexcept {
  s21::Node<key>* x = y->left_;
  s21::Node<key>* T2 = x->right_;
  x->right_ = y;
  y->left_ = T2;
  y->height_ = Max(Height(y->left_), Height(y->right_)) + 1;
  x->height_ = Max(Height(x->left_), Height(x->right_)) + 1;
  return x;
}

template <class key>
typename s21::Node<key>* LeftRotate(s21::Node<key>* x) noexcept {
  s21::Node<key>* y = x->right_;
  s21::Node<key>* T2 = y->left_;
  y->left_ = x;
  x->right_ = T2;
  x->height_ = Max(Height(x->left_), Height(x->right_)) + 1;
  y->height_ = Max(Height(y->left_), Height(y->right_)) + 1;
  return y;
}

template <class key>
typename s21::Node<key>* Balance(key key_, s21::Node<key>* node) noexcept {
  node->height_ = 1 + Max(Height(node->left_), Height(node->right_));
  int balanceFactor = GetBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key_ <= node->left_->key_) {
      return RightRotate(node);
    } else if (key_ > node->left_->key_) {
      node->left_ = LeftRotate(node->left_);
      return RightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key_ > node->right_->key_) {
      return LeftRotate(node);
    } else if (key_ <= node->right_->key_) {
      node->right_ = RightRotate(node->right_);
      return LeftRotate(node);
    }
  }
  return node;
}

template <class key>
typename s21::Node<key>* DelBalance(s21::Node<key>* root) noexcept {
  root->height_ = 1 + Max(Height(root->left_), Height(root->right_));
  int balanceFactor = GetBalanceFactor(root);
  if (balanceFactor > 1) {
    if (GetBalanceFactor(root->left_) >= 0) {
      return RightRotate(root);
    } else {
      root->left_ = LeftRotate(root->left_);
      return RightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (GetBalanceFactor(root->right_) <= 0) {
      return LeftRotate(root);
    } else {
      root->right_ = RightRotate(root->right_);
      return LeftRotate(root);
    }
  }
  return root;
}
#endif  //  _SRC_CONTAINERS_COMMONFUNCTIONS_SET_H_