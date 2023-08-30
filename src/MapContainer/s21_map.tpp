namespace s21 {
template <typename K, typename T>
void Map<K, T>::MapConstIterator::operator++() noexcept {
  if (node_->left_ && node_->left_ != lastvist_) {
    node_ = node_->left_;
  } else if (node_->right_) {
    node_ = node_->right_;
    while (node_->left_) {
      node_ = node_->left_;
    }
  } else {
    K a = node_->key_;
    while (a >= node_->key_) {
      lastvist_ = node_;
      node_ = node_->parent_;
    }
  }
}

template <typename K, typename T>
void Map<K, T>::MapConstIterator::operator--() noexcept {
  if (node_->left_ && node_->left_ != lasvisit_1_) {
    node_ = node_->left_;
    while (node_->right_) {
      node_ = node_->right_;
    }
  } else {
    K a = node_->key_;
    while (a <= node_->key_) {
      lasvisit_1_ = node_;
      if (node_->parent_) {
        node_ = node_->parent_;
      } else {
        return;
      }
    }
  }
}

template <typename K, typename T>
bool Map<K, T>::MapConstIterator::operator!=(
    const MapConstIterator& other) const noexcept {
  return (this->node_ != other.node_);
}

template <typename K, typename T>
bool Map<K, T>::MapConstIterator::operator==(
    const MapConstIterator& other) const noexcept {
  return this->node_ == other.node_;
}

template <typename K, typename T>
Map<K, T>::MapIterator::MapIterator() : MapConstIterator() {}

template <typename K, typename T>
Map<K, T>::MapIterator::MapIterator(Node* value) : MapConstIterator(value) {}

template <typename K, typename T>
Map<K, T>::MapIterator::MapIterator(const MapIterator& other)
    : MapConstIterator(other) {}

template <typename K, typename T>
Map<K, T>::MapIterator::MapIterator(const MapConstIterator& other)
    : MapConstIterator(other) {}

template <typename K, typename T>
std::pair<K, T> Map<K, T>::MapConstIterator::operator*() const noexcept {
  std::pair<K, T> result(node_->key_, node_->value_);
  return result;
}

template <typename K, typename T>
typename Map<K, T>::MapIterator& Map<K, T>::MapIterator::operator=(
    const Iterator& other) noexcept {
  this->node_ = other.node_;
  this->lasvisit_1_ = other.lasvisit_1_;
  this->lastvist_ = other.lastvist_;
  return *this;
}

template <typename K, typename T>
Map<K, T>::Map() {
  tree_.root_ = nullptr;
  tree_.end_ = nullptr;
  tree_.max_value_ = 0;
  map_size_ = 0;
}

template <typename K, typename T>
Map<K, T>::Map(
    std::initializer_list<typename Map<K, T>::value_type> const& items) {
  tree_.root_ = nullptr;
  tree_.end_ = nullptr;
  tree_.max_value_ = 0;
  map_size_ = 0;
  for (auto i = items.begin(); i != items.end(); ++i) {
    Insert(*i);
  }
};

template <typename K, typename T>
void Map<K, T>::CopyMap(const Map& m) {
  if (m.tree_.root_ != nullptr) {
    for (s21::Map<K, T>::Iterator iter = m.Begin(); iter != m.End(); ++iter) {
      Insert((*iter).first, (*iter).second);
    }
  }
}

template <typename K, typename T>
Map<K, T>::Map(const Map& m) {
  CopyMap(m);
};

template <typename K, typename T>
Map<K, T>::Map(Map&& m) noexcept {
  MoveMap(m);
}

template <typename K, typename T>
Map<K, T>::~Map() {
  if ((!Empty())) {
    DeleteMap(this->tree_.root_);
  }
  delete tree_.end_;
}

template <typename K, typename T>
void Map<K, T>::operator=(Map& m) {
  if (this != &m) {
    if (map_size_ > 0) {
      DeleteMap(tree_.root_);
    }
    CopyMap(m);
  }
}
template <typename K, typename T>
void Map<K, T>::MoveMap(Map& m) noexcept {
  if (this == &m) {
    return;
  }
  tree_ = m.tree_;
  tree_.root_ = m.tree_.root_;
  tree_.end_ = m.tree_.end_;
  tree_.max_value_ = m.tree_.max_value_;
  m.tree_.root_ = nullptr;
  m.tree_.end_ = nullptr;
  m.tree_.max_value_ = 0;
}
template <typename K, typename T>
void Map<K, T>::operator=(Map&& m) noexcept {
  if (this != &m) {
    if (map_size_ > 0) {
      DeleteMap(this->tree_.root_);
    }
    MoveMap(m);
  }
}

//----------------------------------------Insert-----------------------------
template <typename K, typename T>
std::pair<typename Map<K, T>::Iterator, bool> Map<K, T>::Insert(
    const K& key, const T& obj) noexcept {
  std::pair<typename Map<K, T>::Iterator, bool> result;
  Iterator tmp = this->SearchKey(std::pair<K, T>(key, obj));
  if (tmp == nullptr) {
    this->tree_.root_ = this->tree_.Insert_one(std::pair<K, T>(key, obj));
    result.first = SearchKey(std::pair<K, T>(key, obj));
    if (result.first != nullptr) {
      result.second = true;
    }
  } else {
    result.first = tmp;
    result.second = false;
  }
  return result;
};

template <typename K, typename T>
typename Map<K, T>::Iterator Map<K, T>::SearchKey(
    const value_type& value) noexcept {
  Iterator result = nullptr;
  for (Iterator iter = this->Begin(); iter != this->End(); ++iter) {
    if (value.first == iter.node_->key_) {
      result = iter;
    }
  }
  return result;
}

template <typename K, typename T>
std::pair<typename Map<K, T>::Iterator, bool> Map<K, T>::Insert_or_assign(
    const K& key, const T& obj) noexcept {
  std::pair<typename Map<K, T>::Iterator, bool> result(nullptr, false);
  Iterator tmp = this->SearchKey(std::pair<K, T>(key, obj));
  if (tmp == nullptr) {
    result = Insert(key, obj);
    result.second = true;
  } else {
    tmp.node_->value_ = obj;
    result.first = tmp;
    result.second = false;
  }
  return result;
};

template <typename K, typename T>
std::pair<typename Map<K, T>::Iterator, bool> Map<K, T>::Insert(
    const value_type& value) noexcept {
  std::pair<typename Map<K, T>::Iterator, bool> result;
  Iterator tmp = this->SearchKey(value);
  if (tmp == nullptr) {
    this->tree_.root_ = this->tree_.Insert_one(value);
    result.first = this->SearchKey(std::pair<K, T>(value));
    if (result.first != nullptr) {
      result.second = true;
    }
  } else {
    result.first = tmp;
    result.second = false;
  }
  return result;
}

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::Insert_one(
    const value_type& value) noexcept {
  if (end_ && max_value_ <= value.first) {
    end_->parent_->right_ = nullptr;
  }
  this->root_ = InsertNodeInTree(this->root_, value, nullptr);
  this->ParentAssigner(this->root_, nullptr);
  this->root_->parent_ = nullptr;
  if (max_value_ <= value.first) {
    max_value_ = value.first + 1;
    FindEnd(root_);
    end_->key_ = max_value_;
  }
  return root_;
};

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::FindEnd(Node* root) noexcept {
  Node* search = root;
  while (search->right_) {
    search = search->right_;
  }
  end_->parent_ = search;
  search->right_ = end_;
  end_->right_ = nullptr;
  end_->left_ = nullptr;
  int height = end_->height_;
  end_->height_ = search->height_;
  search->height_ = height;
  return search;
}

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::InsertNodeInTree(Node* node,
                                                            value_type key,
                                                            Node* parent) {
  if (node == nullptr) {
    node = new Node(key.first, key.second);
    node->left_ = nullptr;
    node->right_ = nullptr;
    node->height_ = 1;
    node->parent_ = parent;
    node->height_ = 1;
    this->inserted_ = true;
    if (!end_) {
      max_value_ = key.first;
      end_ = new Node(key.first, key.second);
      end_->left_ = nullptr;
      end_->right_ = nullptr;
    }
    return node;
  }
  if (key.first < node->key_) {
    node->left_ = InsertNodeInTree(node->left_, key, node);
  } else if (key.first > node->key_) {
    node->right_ = InsertNodeInTree(node->right_, key, node);
  } else {
    return node;
  }

  node->height_ = 1 + Max(Height(node->left_), Height(node->right_));
  int balanceFactor = GetBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key.first < node->left_->key_) {
      return TurnRight(node);
    } else if (key.first > node->left_->key_) {
      node->left_ = TurnLeft(node->left_);
      return TurnRight(node);
    }
  }
  if (balanceFactor < -1) {
    if (key.first > node->right_->key_) {
      return TurnLeft(node);
    } else if (key.first < node->right_->key_) {
      node->right_ = TurnRight(node->right_);
      return TurnLeft(node);
    }
  }
  return node;
}

template <typename K, typename T>
void Map<K, T>::Tree::ParentAssigner(Node* parent, Node* child) noexcept {
  if (parent && !child) {
    Node* main = parent;
    if (parent->left_) {
      if (parent->left_) {
        ParentAssigner(parent, parent->left_);
      }
      if (parent->right_) {
        ParentAssigner(parent, parent->right_);
      }
    }
    if (parent->right_) {
      parent = main;
      if (parent->left_) {
        ParentAssigner(parent, parent->left_);
      }
      if (parent->right_) {
        ParentAssigner(parent, parent->right_);
      }
    }
  } else if (child) {
    child->parent_ = parent;
    parent = child;
    if (parent->left_) {
      ParentAssigner(parent, parent->left_);
    }
    if (parent->right_) {
      ParentAssigner(parent, parent->right_);
    }
  }
}

template <typename K, typename T>
int Map<K, T>::Tree::Max(int a, int b) noexcept {
  return (a > b) ? a : b;
};
template <typename K, typename T>
int Map<K, T>::Tree::Height(Node* node) noexcept {
  if (node == NULL) {
    return 0;
  }
  return node->height_;
};

template <typename K, typename T>
int Map<K, T>::Tree::GetBalanceFactor(Node* node) noexcept {
  if (node == nullptr) {
    return 0;
  } else {
    return Height(node->left_) - Height(node->right_);
  }
};

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::TurnLeft(Node* node) noexcept {
  Node* tmp_1 = node->right_;
  Node* tmp_2 = tmp_1->left_;
  tmp_1->left_ = node;
  node->right_ = tmp_2;
  node->height_ = Max(Height(node->left_), Height(node->right_)) + 1;
  tmp_1->height_ = Max(Height(tmp_1->left_), Height(tmp_1->right_)) + 1;
  return tmp_1;
}

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::TurnRight(Node* node) noexcept {
  Node* tmp_1 = node->left_;
  Node* T2 = tmp_1->right_;
  tmp_1->right_ = node;
  node->left_ = T2;
  node->height_ = Max(Height(node->left_), Height(node->right_)) + 1;
  tmp_1->height_ = Max(Height(tmp_1->left_), Height(tmp_1->right_)) + 1;
  return tmp_1;
};

template <typename K, typename T>
typename Map<K, T>::Iterator Map<K, T>::Begin() const noexcept {
  Node* node_begin = nullptr;

  if (this->tree_.root_ != nullptr) {
    node_begin = this->tree_.root_;
    while (node_begin->left_) {
      node_begin = node_begin->left_;
    }
  }
  return node_begin;
}

template <typename K, typename T>
typename Map<K, T>::Iterator Map<K, T>::End() const noexcept {
  Node* node_begin = nullptr;
  if (this->tree_.root_) {
    node_begin = this->tree_.root_;
    while (node_begin->right_) {
      node_begin = node_begin->right_;
    }
  }
  return node_begin;
}

template <typename K, typename T>
bool Map<K, T>::Empty() const noexcept {
  return tree_.root_ == nullptr;
}
template <typename K, typename T>
size_t Map<K, T>::Size() const noexcept {
  size_t res = 0;
  if (this->Begin() != nullptr && !(this->Empty())) {
    for (Iterator iter = this->Begin(); iter != this->End(); ++iter) {
      res++;
    }
  }

  return res;
}

template <typename K, typename T>
void Map<K, T>::Erase(Iterator pos) noexcept {
  tree_.root_ = tree_.DeleteNode(this->tree_.root_, pos.node_->key_, 0);
  map_size_ -= 1;
}

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::DeleteNode(
    Node* root, K& key, int flag_balans_off) noexcept {
  if (root == nullptr) return root;
  if (key < root->key_)
    root->left_ = DeleteNode(root->left_, key, flag_balans_off);
  else if (key > root->key_)
    root->right_ = DeleteNode(root->right_, key, flag_balans_off);
  else {
    if ((root->left_ == nullptr) || (root->right_ == nullptr)) {
      Node* temp = root->left_ ? root->left_ : root->right_;
      if (temp == nullptr) {
        temp = root;
        root = nullptr;
      } else
        root = temp;
      delete (temp);
    } else {
      Node* temp = MimumValue(root->right_);
      root->key_ = temp->key_;
      root->right_ = DeleteNode(root->right_, temp->key_, flag_balans_off);
    }
  }
  if (root == nullptr) return root;
  root->height_ = 1 + Max(Height(root->left_), Height(root->right_));
  int balanceFactor = GetBalanceFactor(root);
  if (balanceFactor > 1) {
    if (GetBalanceFactor(root->left_) >= 0) {
      return TurnRight(root);
    } else {
      root->left_ = TurnLeft(root->left_);
      return TurnRight(root);
    }
  }
  if (balanceFactor < -1) {
    if (GetBalanceFactor(root->right_) <= 0) {
      return TurnLeft(root);
    } else {
      root->right_ = TurnRight(root->right_);
      return TurnLeft(root);
    }
  }
  root = BalanceAVLTree(root);
  ParentAssigner(root, nullptr);
  return root;
}

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::BalanceAVLTree(Node* root) noexcept {
  root->height_ = 1 + Max(Height(root->left_), Height(root->right_));
  int balanceFactor = GetBalanceFactor(root);
  if (balanceFactor > 1) {
    if (GetBalanceFactor(root->left_) >= 0) {
      return TurnRight(root);
    } else {
      root->left_ = TurnLeft(root->left_);
      return TurnRight(root);
    }
  }
  if (balanceFactor < -1) {
    if (GetBalanceFactor(root->right_) <= 0) {
      return TurnLeft(root);
    } else {
      root->right_ = TurnRight(root->right_);
      return TurnLeft(root);
    }
  }
  return root;
}

template <typename K, typename T>
typename Map<K, T>::Node* Map<K, T>::Tree::MimumValue(
    Node* node) const noexcept {
  Node* current = node;
  while (current->left_ != nullptr) current = current->left_;
  return current;
}

template <typename K, typename T>
void Map<K, T>::Clear() noexcept {
  DeleteMap(tree_.root_);
}

template <typename K, typename T>
void Map<K, T>::DeleteMap(Node* list) noexcept {
  if (list && list != tree_.end_) {
    Node* l = list->left_;
    Node* r = list->right_;
    delete list;
    if (l) {
      DeleteMap(l);
    }
    if (r) {
      DeleteMap(r);
    }
  }
  tree_.root_ = nullptr;
}

template <typename K, typename T>
bool Map<K, T>::Contains(const K& key) const noexcept {
  bool result = false;
  for (Iterator iter = Begin(); iter != End(); ++iter) {
    if (key == iter.node_->key_) {
      result = true;
    }
  }
  return result;
}

template <typename K, typename T>
void Map<K, T>::Merge(Map& other) noexcept {
  Iterator iter_other;
  while (iter_other != other.End()) {
    for (iter_other = other.Begin(); iter_other != other.End(); ++iter_other) {
      if (!this->Contains(iter_other.node_->key_)) {
        this->Insert((*iter_other).first, (*iter_other).second);
        this->tree_.ParentAssigner(this->tree_.root_, nullptr);
        this->tree_.root_->parent_ = nullptr;
        iter_other = other.Begin();
        break;
      }
    }
  }
};

template <typename K, typename T>
void Map<K, T>::Swap(Map& other) noexcept {
  Map tmp(std::move(other));
  other = (std::move(*this));
  *this = (std::move(tmp));
}

template <typename K, typename T>
typename Map<K, T>::mapped_type& Map<K, T>::At(const K& key) const {
  Node* node_serch = nullptr;
  for (Iterator iter = Begin(); iter != End(); ++iter) {
    node_serch = iter.node_;
    if (node_serch->key_ == key) {
      return node_serch->value_;
    }
  }
  throw std::invalid_argument("This key doesn't exist");
}

template <typename K, typename T>
typename Map<K, T>::mapped_type& Map<K, T>::operator[](
    const K& key) const noexcept {
  Node* node_serch = nullptr;
  if (!this->Empty()) {
    for (Iterator iter = Begin(); iter != End(); ++iter) {
      node_serch = iter.node_;
      if (node_serch->key_ == key) {
        return node_serch->value_;
      }
    }
  }
  return node_serch->value_;
}
template <typename K, typename T>
size_t Map<K, T>::MaxSize() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(Map);
}
template <typename K, typename T>
template <class... Args>
std::vector<std::pair<typename s21::Map<K, T>::Iterator, bool>>
s21::Map<K, T>::Emplace(Args&&... args) {
  std::vector<std::pair<Iterator, bool>> result;
  std::vector<typename Map<K, T>::value_type> argsVector = {args...};
  for (auto& i : argsVector) {
    result.push_back(Insert(i));
  }
  return result;
}
}  // namespace s21