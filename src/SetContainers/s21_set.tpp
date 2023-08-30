namespace s21 {
template <class value_type>
typename Set<value_type>::const_reference
Set<value_type>::SetConstIterator::operator*() const noexcept {
  if (this->iter_) return this->iter_->key_;
  this->zero_ = 0;
  return this->zero_;
}

template <class value_type>
typename Set<value_type>::SetConstIterator&
Set<value_type>::SetConstIterator::operator++() noexcept {
  this->iter_ = this->iter_->next_;
  return *this;
}

template <class value_type>
typename Set<value_type>::SetConstIterator&
Set<value_type>::SetConstIterator::operator--() noexcept {
  this->iter_ = this->iter_->prev_;
  return *this;
}

template <class value_type>
bool Set<value_type>::SetConstIterator::operator!=(
    const SetConstIterator& other) const noexcept {
  return this->iter_ != other.iter_;
}

template <class value_type>
bool Set<value_type>::SetConstIterator::operator==(
    const SetConstIterator& other) const noexcept {
  return this->iter_ == other.iter_;
}

template <class value_type>
Set<value_type>::SetIterator::SetIterator() : SetConstIterator() {}

template <class value_type>
Set<value_type>::SetIterator::SetIterator(Node* value)
    : SetConstIterator(value) {}

template <class value_type>
Set<value_type>::SetIterator::SetIterator(const SetIterator& other)
    : SetConstIterator(other) {}

template <class value_type>
Set<value_type>::SetIterator::SetIterator(const SetConstIterator& other)
    : SetConstIterator(other) {}

template <class value_type>
typename Set<value_type>::reference Set<value_type>::SetIterator::operator*()
    const noexcept {
  if (this->iter_) return this->iter_->key_;
  return this->zero_;
}
template <class value_type>
typename Set<value_type>::SetIterator& Set<value_type>::SetIterator::operator=(
    const SetIterator other) noexcept {
  this->iter_ = other.iter_;
  return *this;
}

template <class key>
typename Set<key>::Set& Set<key>::operator=(Set<key>&& o) noexcept {
  if (root_ != o.root_) {
    MoveSet(o);
  }
  return *this;
}
template <class key>
Set<key>::Set(Set&& ms) noexcept {
  MoveSet(ms);
}
template <class key>
void Set<key>::MoveSet(Set& o) noexcept {
  Clear();
  head_ = o.head_;
  tail_ = o.tail_;
  root_ = o.root_;
  last_end_ = o.last_end_;
  mset_size_ = o.mset_size_;

  o.head_ = nullptr;
  o.tail_ = nullptr;
  o.root_ = nullptr;
  o.last_end_ = nullptr;
  o.mset_size_ = 0;
}

template <class key>
Set<key>::Set(const Set& ms) {
  CopySet(ms);
}

template <class key>
typename Set<key>::Set& Set<key>::operator=(Set& o) {
  if (root_ != o.root_) {
    CopySet(o);
  }
  return *this;
}
template <class key>
void Set<key>::CopySet(const Set& o) {
  Clear();
  size_t i = 0;
  Set<key>::iterator it = o.Begin();
  it = o.Begin();
  key_type ans = 0;
  key_type& res = ans;
  while (it != o.End()) {
    this->root_ = InsertNode(root_, *it, res);
    ++it;
    i++;
  }
  mset_size_ = o.mset_size_;
  last_end_->prev_ = tail_;
  tail_->next_ = last_end_;
}
template <class key>
void Set<key>::Clear() noexcept {
  while (head_ != nullptr) {
    Node* ptr = head_->next_;
    if (ptr != nullptr) {
      ptr->prev_ = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete head_;
    head_ = ptr;
  }
  mset_size_ = 0;
}

template <class key>
Set<key>::~Set() {
  Clear();
}

template <class key>
void Set<key>::Erase(iterator pos) noexcept {
  root_ = DeleteNode(root_, *pos);
  mset_size_ -= 1;
}

template <class key>
void Set<key>::Swap(Set& other) {
  Set<key> tmp(other);
  other.MoveSet(*this);
  MoveSet(tmp);
}

template <class key>
void Set<key>::Merge(Set& other) noexcept {
  s21::Set<key>::iterator it = other.Begin();
  for (it = other.Begin(); it != other.End(); ++it) {
    if (this->Find(*it) == last_end_) {
      this->Insert(*it);
      other.Erase(it);
      it = other.Begin();
    }
  }
}
template <class key>
typename Set<key>::iterator Set<key>::Find(
    const key_type& key_val) const noexcept {
  Node* node = root_;
  iterator a;
  while (node && key_val != node->key_ && node != last_end_) {
    if (key_val < node->key_) {
      node = node->left_;
    } else {
      node = node->right_;
    }
  }

  if (node && key_val == node->key_ && node != last_end_) {
    a = node;
    return a;
  } else {
    return last_end_;
  }
}
template <class key>
bool Set<key>::Contains(const key_type& key_val) const noexcept {
  if (!root_ || Find(key_val) == last_end_) {
    return false;
  } else {
    return true;
  }
}

template <class key>
typename Set<key>::Node* Set<key>::DeleteNode(Node* root,
                                              value_type key_) noexcept {
  if (root == nullptr) return root;
  if (key_ < root->key_) {
    root->left_ = DeleteNode(root->left_, key_);
  } else if (key_ > root->key_) {
    root->right_ = DeleteNode(root->right_, key_);
  } else {
    if ((root->left_ == nullptr) || (root->right_ == nullptr)) {
      Node* temp = root->left_ ? root->left_ : root->right_;
      if (temp == nullptr) {
        temp = root;
        root = nullptr;
      } else
        *root = *temp;
      if (head_ == temp) {
        head_ = temp->next_;
        head_->prev_ = nullptr;
      }
      if (tail_ == temp) {
        tail_ = temp->prev_;
        tail_->next_ = last_end_;
      }
      if (temp->prev_) {
        temp->prev_->next_ = temp->next_;
        temp->next_->prev_ = temp->prev_;
      } else {
        temp->next_->prev_ = nullptr;
      }

      delete (temp);
    } else {
      Node* temp = NodeWithMimumValue(root->right_);
      root->key_ = temp->key_;
      root->right_ = DeleteNode(root->right_, temp->key_);
    }
  }
  if (root == nullptr) return root;

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

template <class key>
bool Set<key>::Empty() const noexcept {
  return root_ == nullptr ? true : false;
}

template <class key>
typename Set<key>::size_type Set<key>::Size() const noexcept {
  return mset_size_;
}

template <class key>
Set<key>::Set(std::initializer_list<value_type> const& items) {
  typename std::initializer_list<key>::iterator it = items.begin();
  size_t i = 0;
  key_type ans = 0;
  key_type& res = ans;
  while (items.size() > i) {
    this->root_ = InsertNode(this->root_, *it, res);
    it++;
    i++;
  }
  mset_size_ = i;
  last_end_->prev_ = tail_;
  tail_->next_ = last_end_;
  last_end_->key_ = mset_size_;
}

template <class key>
typename Set<key>::Node* Set<key>::InsertNode(Node* node, value_type key_,
                                              key_type& res) noexcept {
  if (last_end_ == nullptr) {
    last_end_ = new Node(key_);
  }
  if (node == nullptr) {
    node = new Node(key_);
    res = node->key_;
    if (!head_) {
      head_ = node;
    }
    if (!tail_) {
      tail_ = node;
    }
    if (tail_ && tail_->key_ < node->key_) {
      node->prev_ = tail_;
      tail_->next_ = node;
      tail_ = node;
    } else if (head_->key_ > node->key_) {
      node->next_ = head_;
      head_->prev_ = node;
      head_ = node;
    } else {
      Node* ptr = tail_;
      while (node->key_ < ptr->key_) {
        ptr = ptr->prev_;
      }
      if (ptr->key_ != node->key_) {
        node->next_ = ptr->next_;
        ptr->next_->prev_ = node;
        node->prev_ = ptr;
        ptr->next_ = node;
      }
    }
    return node;
  }

  if (node && key_ < node->key_) {
    node->left_ = InsertNode(node->left_, key_, res);
  } else if (node && key_ > node->key_) {
    node->right_ = InsertNode(node->right_, key_, res);
  }

  node = Balance(key_, node);
  return node;
}

template <class key>
std::pair<typename s21::Set<key>::iterator, bool> Set<key>::Insert(
    const value_type& value) noexcept {
  key_type ans = value - 1;
  key_type& res = ans;
  std::pair<typename Set<key>::iterator, bool> result;

  root_ = InsertNode(root_, value, res);
  if (res == value) {
    mset_size_ += 1;
    last_end_->prev_ = tail_;
    tail_->next_ = last_end_;
    last_end_->key_ = mset_size_;

    result.first = Find(res);
    result.second = true;
  } else {
    result.second = false;
    result.first = nullptr;
  }

  return result;
}

template <class key>
typename Set<key>::iterator Set<key>::Begin() const noexcept {
  return head_;
}

template <class key>
typename Set<key>::iterator Set<key>::End() const noexcept {
  if (last_end_ && tail_) {
    last_end_->prev_ = tail_;
    tail_->next_ = last_end_;
  } else {
    return nullptr;
  }

  return last_end_;
}
template <class key>
size_t Set<key>::MaxSize() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(Set);
}

template <class key>
template <class... Args>
std::vector<std::pair<typename s21::Set<key>::iterator, bool>>
s21::Set<key>::Emplace(Args&&... args) {
  std::vector<std::pair<iterator, bool>> result;
  std::vector<typename Set<key>::value_type> argsVector = {args...};
  for (auto& i : argsVector) {
    result.push_back(Insert(i));
  }
  return result;
}

}  // namespace s21