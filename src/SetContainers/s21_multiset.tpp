namespace s21 {

template <class value_type>
typename Multiset<value_type>::const_reference
Multiset<value_type>::MultisetConstIterator::operator*() const noexcept {
  if (this->iter_) return this->iter_->key_;
  return this->zero_;
}

template <class value_type>
typename Multiset<value_type>::MultisetConstIterator&
Multiset<value_type>::MultisetConstIterator::operator++() noexcept {
  this->iter_ = this->iter_->next_;
  return *this;
}

template <class value_type>
typename Multiset<value_type>::MultisetConstIterator&
Multiset<value_type>::MultisetConstIterator::operator--() noexcept {
  this->iter_ = this->iter_->prev_;
  return *this;
}

template <class value_type>
bool Multiset<value_type>::MultisetConstIterator::operator!=(
    const MultisetConstIterator& other) const noexcept {
  return this->iter_ != other.iter_;
}

template <class value_type>
bool Multiset<value_type>::MultisetConstIterator::operator==(
    const MultisetConstIterator& other) const noexcept {
  return this->iter_ == other.iter_;
}

template <class value_type>
Multiset<value_type>::MultisetIterator::MultisetIterator()
    : MultisetConstIterator() {}

template <class value_type>
Multiset<value_type>::MultisetIterator::MultisetIterator(Node* value)
    : MultisetConstIterator(value) {}

template <class value_type>
Multiset<value_type>::MultisetIterator::MultisetIterator(
    const MultisetIterator& other)
    : MultisetConstIterator(other) {}

template <class value_type>
Multiset<value_type>::MultisetIterator::MultisetIterator(
    const MultisetConstIterator& other)
    : MultisetConstIterator(other) {}

template <class value_type>
typename Multiset<value_type>::reference
Multiset<value_type>::MultisetIterator::operator*() const noexcept {
  if (this->iter_) return this->iter_->key_;
  return this->zero_;
}

template <class value_type>
typename Multiset<value_type>::MultisetIterator&
Multiset<value_type>::MultisetIterator::operator=(
    const MultisetIterator other) {
  this->iter_ = other.iter_;
  return *this;
}

template <class key>
typename Multiset<key>::Multiset& Multiset<key>::operator=(const Multiset& o) {
  if (this != &o) {
    CopyMultiSet(o);
  }
  return *this;
}

template <class key>
typename Multiset<key>::Multiset& Multiset<key>::operator=(
    Multiset<key>&& o) noexcept {
  if (this != &o) {
    MoveMultiset(o);
  }
  return *this;
}
template <class key>
Multiset<key>::Multiset(Multiset&& ms) noexcept {
  MoveMultiset(ms);
}
template <class key>
void Multiset<key>::MoveMultiset(Multiset& o) noexcept {
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
Multiset<key>::Multiset(const Multiset& ms) {
  this->CopyMultiSet(ms);
}
template <class key>
void Multiset<key>::CopyMultiSet(const Multiset& o) {
  Clear();
  Multiset<key>::MultisetIterator it = o.Begin();
  size_t i = 0;
  while (o.mset_size_ > i) {
    this->root_ = InsertNode(this->root_, *it);
    ++it;
    i++;
  }
  mset_size_ = o.mset_size_;
}

template <class key>
void Multiset<key>::Clear() noexcept {
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
Multiset<key>::~Multiset() {
  Clear();
}

template <class key>
void Multiset<key>::Erase(iterator pos) noexcept {
  root_ = DeleteNode(root_, *pos);
  mset_size_ -= 1;
}

template <class key>
void Multiset<key>::Swap(Multiset& other) {
  Multiset<key> tmp(other);
  other.MoveMultiset(*this);
  MoveMultiset(tmp);
}

template <class key>
void Multiset<key>::Merge(Multiset& other) noexcept {
  Multiset<key>::MultisetIterator it = other.Begin();
  for (; it != other.End(); ++it) {
    Insert(*it);
  }
  other.Clear();
}

template <class key>
typename Multiset<key>::size_type Multiset<key>::Count(
    const key_type& key_val) const noexcept {
  size_type Count = 0;
  Node* node = root_;
  while (key_val != node->key_ && node != last_end_) {
    if (key_val < node->key_) {
      node = node->left_;
    } else {
      node = node->right_;
    }
  }
  if (key_val == node->key_) {
    Count++;
    Node* pr_node = node->prev_;
    while (pr_node && pr_node->key_ == key_val) {
      Count++;
      if (pr_node == pr_node->prev_) {
        break;
      }
      pr_node = pr_node->prev_;
    }

    while (node->next_->key_ == key_val) {
      Count++;
      node = node->next_;
    }
  }

  return Count;
}

template <class key>
typename Multiset<key>::iterator Multiset<key>::Find(
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
  if (node && key_val == node->key_) {
    a = node;
    return a;
  } else {
    return last_end_;
  }
}

template <class key>
bool Multiset<key>::Contains(const key_type& key_val) {
  return Find(key_val) != last_end_;
}
template <class key>
bool Multiset<key>::Empty() const noexcept {
  return mset_size_ == 0;
}

template <class key>
typename Multiset<key>::size_type Multiset<key>::Size() const noexcept {
  return mset_size_;
}

template <class key>
Multiset<key>::Multiset(std::initializer_list<value_type> const& items) {
  typename std::initializer_list<key>::iterator it = items.begin();
  size_t i = 0;
  while (items.size() > i) {
    this->root_ = InsertNode(this->root_, *it);
    it++;
    i++;
  }
  mset_size_ = i;
  last_end_->prev_ = tail_;
  tail_->next_ = last_end_;
}

template <class key>
std::pair<typename s21::Multiset<key>::iterator, bool>
Multiset<key>::InsertBonus(const value_type& value) noexcept {
  std::pair<s21::Multiset<key>::iterator, bool> result;
  result.first = Insert(value);
  result.second = true;
  return result;
}

template <class key>
typename Multiset<key>::iterator Multiset<key>::Insert(
    const value_type& value) noexcept {
  root_ = InsertNode(root_, value);
  last_end_->prev_ = tail_;
  tail_->next_ = last_end_;
  mset_size_++;
  last_end_->key_ = mset_size_;
  return inserted_;
}
template <class key>
std::pair<typename Multiset<key>::iterator, typename Multiset<key>::iterator>
Multiset<key>::EqualRange(const key_type& key_val) noexcept {
  std::pair<typename Multiset<key>::iterator, typename Multiset<key>::iterator>
      result;
  result.first = LowerBound(key_val);
  result.second = UpperBound(key_val);
  return result;
}

template <class key>
typename Multiset<key>::iterator Multiset<key>::LowerBound(
    const key_type& key_val) noexcept {
  iterator ptr = Begin();
  while (*ptr < key_val && ptr != End()) {
    ++ptr;
  }
  return ptr;
}

template <class key>
typename Multiset<key>::iterator Multiset<key>::UpperBound(
    const key_type& key_val) noexcept {
  iterator ptr = Begin();
  while (*ptr <= key_val && ptr != End()) {
    ++ptr;
  }
  return ptr;
}

template <class key>
typename Multiset<key>::Node* Multiset<key>::Begin() const noexcept {
  return head_;
}

template <class key>
typename Multiset<key>::Node* Multiset<key>::End() noexcept {
  if (last_end_ && tail_) {
    last_end_->prev_ = tail_;
    tail_->next_ = last_end_;
  } else {
    return nullptr;
  }
  return last_end_;
}

template <class key>
size_t Multiset<key>::MaxSize() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(Multiset);
}

template <class key>
typename Multiset<key>::Node* Multiset<key>::InsertNode(
    Node* node, value_type key_) noexcept {
  if (last_end_ == nullptr) {
    last_end_ = new Node(key_);
  }
  if (node == nullptr) {
    node = new Node(key_);
    inserted_.iter_ = node;
    if (!head_) {
      head_ = node;
    }
    if (!tail_) {
      tail_ = node;
    }
    if (tail_ && tail_->key_ <= node->key_) {
      node->prev_ = tail_;
      tail_->next_ = node;
      tail_ = node;
    } else if (head_->key_ >= node->key_) {
      node->next_ = head_;
      head_->prev_ = node;
      head_ = node;
    } else {
      Node* ptr = tail_;
      while (node->key_ <= ptr->key_) {
        ptr = ptr->prev_;
      }
      node->next_ = ptr->next_;
      ptr->next_->prev_ = node;
      node->prev_ = ptr;
      ptr->next_ = node;
    }
    return node;
  }
  if (node && key_ <= node->key_) {
    node->left_ = InsertNode(node->left_, key_);
  } else if (node && key_ > node->key_) {
    node->right_ = InsertNode(node->right_, key_);
  }

  node = Balance(key_, node);
  return node;
}

template <class key>
typename Multiset<key>::Node* Multiset<key>::DeleteNode(
    Node* root, value_type key_) noexcept {
  if (root == NULL) return root;
  if (key_ < root->key_)
    root->left_ = DeleteNode(root->left_, key_);
  else if (key_ > root->key_)
    root->right_ = DeleteNode(root->right_, key_);
  else {
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
  if (root == NULL) return root;
  root = DelBalance(root);
  return root;
}

template <class key>
template <class... Args>
std::vector<std::pair<typename s21::Multiset<key>::iterator, bool>>
s21::Multiset<key>::Emplace(Args&&... args) {
  std::vector<std::pair<iterator, bool>> result;
  std::vector<typename Multiset<key>::value_type> argsVector = {args...};
  for (auto& i : argsVector) {
    result.push_back(InsertBonus(i));
  }
  return result;
}
}  // namespace s21
