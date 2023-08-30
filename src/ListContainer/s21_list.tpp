namespace s21 {

template <class value_type>
typename List<value_type>::const_reference
List<value_type>::ConstListIterator::operator*() const noexcept {
  if (this->current_node_) return this->current_node_->val_;
  return this->zero_;
}

template <class value_type>
typename List<value_type>::ConstListIterator&
List<value_type>::ConstListIterator::operator++() noexcept {
  this->current_node_ = this->current_node_->next_;
  return *this;
}

template <class value_type>
typename List<value_type>::ConstListIterator&
List<value_type>::ConstListIterator::operator--() noexcept {
  this->current_node_ = this->current_node_->prev_;
  return *this;
}

template <class value_type>
bool List<value_type>::ConstListIterator::operator!=(
    const ConstListIterator& other) const noexcept {
  return this->current_node_ != other.current_node_;
}

template <class value_type>
bool List<value_type>::ConstListIterator::operator==(
    const ConstListIterator& other) const noexcept {
  return this->current_node_ == other.current_node_;
}

template <class value_type>
List<value_type>::ListIterator::ListIterator() : ConstListIterator() {}

template <class value_type>
List<value_type>::ListIterator::ListIterator(Node* value)
    : ConstListIterator(value) {}

template <class value_type>
List<value_type>::ListIterator::ListIterator(const ListIterator& other)
    : ConstListIterator(other) {}

template <class value_type>
List<value_type>::ListIterator::ListIterator(const ConstListIterator& other)
    : ConstListIterator(other) {}

template <class value_type>
typename List<value_type>::reference List<value_type>::ListIterator::operator*()
    const noexcept {
  if (this->current_node_) return this->current_node_->val_;
  return this->zero_;
}

template <class value_type>
typename List<value_type>::ListIterator&
List<value_type>::ListIterator::operator=(const ListIterator other) noexcept {
  this->current_node_ = other.current_node_;
  return *this;
}

// List
template <class T>
List<T>::List() {}

template <class T>
List<T>::List(size_type n) {
  long int b = n;
  if (b <= 0 || n >= MaxSize()) {
    return;
  }
  value_type quantity = 0;
  for (size_type i = 0; i < n; i++) {
    value_type val_ = 0;
    PushBack(val_);
    quantity++;
  }
  size_of_list_ = n;
  if (end_node_) end_node_->val_ = quantity;
}
template <class T>
List<T>::List(std::initializer_list<T> const& items) {
  typename std::initializer_list<T>::iterator it = items.begin();
  value_type size = 0;
  for (size_type i = 0; items.size() > i; i++) {
    PushBack(*it);
    it++;
    size++;
  }
  if (end_node_) end_node_->val_ = size;
}
template <class T>
List<T>::~List() {
  Clear();
}

template <class T>
typename List<T>::iterator List<T>::Begin() const noexcept {
  if (end_node_) end_node_->next_ = head_;
  if (head_) head_->prev_ = end_node_;
  return head_;
}
template <class T>
typename List<T>::iterator List<T>::End() const noexcept {
  if (end_node_) end_node_->next_ = head_;
  if (head_) head_->prev_ = end_node_;
  return end_node_;
}
template <class T>
typename List<T>::Node* List<T>::GetAt(int index) const noexcept {
  Node* ptr = head_;
  int n = 0;
  while (n != index) {
    if (ptr == nullptr) {
      return nullptr;
    }
    ptr = ptr->next_;
    n++;
  }
  return ptr;
}
template <class T>
void List<T>::PushFront(const_reference value) {
  if (MaxSize() <= size_of_list_) {
    return;
  }
  Node* ptr = new Node(value);
  ptr->next_ = head_;
  if (head_ != nullptr) {
    head_->prev_ = ptr;
  }
  if (tail_ == nullptr) {
    tail_ = ptr;
  }
  size_of_list_ += 1;
  head_ = ptr;

  if (end_node_ == nullptr) {
    end_node_ = new Node(value);
    end_node_->next_ = nullptr;
  }
  tail_->next_ = end_node_;
  end_node_->prev_ = tail_;
}
template <class T>
void List<T>::PushBack(const_reference value) {
  if (MaxSize() <= size_of_list_) {
    return;
  }
  Node* ptr = new Node(value);
  ptr->prev_ = tail_;
  if (tail_ != nullptr) {
    tail_->next_ = ptr;
  }
  if (head_ == nullptr) {
    head_ = ptr;
  }
  tail_ = ptr;
  size_of_list_ += 1;
  if (end_node_ == nullptr) {
    end_node_ = new Node(value);
    end_node_->next_ = nullptr;
  }
  tail_->next_ = end_node_;
  end_node_->prev_ = tail_;
}

template <class T>
void List<T>::PopFront() {
  if (Empty()) {
    return;
  }
  Node* ptr = head_->next_;
  if (ptr != nullptr) {
    ptr->prev_ = nullptr;
  } else {
    tail_ = nullptr;
  }
  delete head_;
  size_of_list_ -= 1;
  head_ = ptr;
}

template <class T>
void List<T>::PopBack() {
  if (Empty()) {
    return;
  }
  Node* ptr = tail_->prev_;
  if (ptr != nullptr) {
    ptr->next_ = nullptr;
  } else {
    head_ = nullptr;
  }
  delete tail_;
  size_of_list_ -= 1;
  tail_ = ptr;

  tail_->next_ = end_node_;
  end_node_->prev_ = tail_;
}

template <class T>
typename List<T>::iterator List<T>::Insert(iterator pos, const_reference val) {
  Node* iter = head_;
  int index = 0;
  while (head_ && iter != pos.current_node_) {
    if (iter->next_ == nullptr) {
      throw std::invalid_argument("s21::List::Insert::Incorrect input\n");
    }
    iter = iter->next_;
    index++;
  }
  if (head_ == nullptr) {
    PushFront(val);
    pos = head_;
    return pos;
  }
  Node* right = GetAt(index);
  if (right == nullptr) {
    PushBack(val);
    return pos;
  }
  Node* left = right->prev_;
  if (left == end_node_ || left == nullptr) {
    PushFront(val);
    --pos;
    return pos;
  }
  Node* ptr = new Node(val);
  ptr->prev_ = left;
  ptr->next_ = right;
  left->next_ = ptr;
  right->prev_ = ptr;
  size_of_list_ += 1;
  if (right == end_node_) {
    tail_ = ptr;
  }
  return ptr;
}

template <class T>
bool List<T>::Empty() const noexcept {
  return head_ == nullptr;
  ;
}
template <class T>
typename List<T>::size_type List<T>::Size() const noexcept {
  return size_of_list_;
}
template <class T>
void List<T>::Erase(iterator pos) {
  if (pos.current_node_ == end_node_ || pos.current_node_ == nullptr) {
    throw std::invalid_argument("s21::List::Erase::Incorrect position\n");
  }
  if (pos.current_node_->prev_ == end_node_) {
    PopFront();
    return;
  }
  if (pos.current_node_->next_ == head_) {
    PopBack();
    return;
  }
  if (tail_ == pos.current_node_) {
    tail_ = pos.current_node_->prev_;
  }
  Node* left = pos.current_node_->prev_;
  Node* right = pos.current_node_->next_;
  left->next_ = right;
  right->prev_ = left;
  size_of_list_ -= 1;

  delete pos.current_node_;
}

template <class T>
void List<T>::CopyList(const List& l) {
  Clear();
  Node* ptr = l.head_;
  for (size_t i = 0; i < l.Size(); i++) {
    PushBack(ptr->val_);
    ptr = ptr->next_;
  }
  if (end_node_) end_node_->val_ = l.end_node_->val_;
}

template <class T>
List<T>::List(const List& l) {
  CopyList(l);
}

template <class T>
typename List<T>::List& List<T>::operator=(List&& l) noexcept {
  if (head_ != l.head_ && tail_ != l.tail_) {
    MoveList(l);
  }
  return *this;
}
template <class T>
List<T>::List(List&& l) noexcept {
  MoveList(l);
}
template <class T>
typename List<T>::List& s21::List<T>::operator=(const List& l) {
  if (head_ != l.head_ && tail_ != l.tail_) {
    CopyList(l);
  }
  return *this;
}
template <class T>
void List<T>::MoveList(List& l) noexcept {
  Clear();
  head_ = l.head_;
  tail_ = l.tail_;
  size_of_list_ = l.size_of_list_;
  end_node_ = l.end_node_;

  l.end_node_ = nullptr;
  l.size_of_list_ = 0;
  l.head_ = nullptr;
  l.tail_ = nullptr;
}

template <class T>
typename List<T>::const_reference List<T>::Front() const noexcept {
  if (head_ == nullptr) {
    const_reference zero = 0;
    return zero;
  }
  return head_->val_;
}
template <class T>
typename List<T>::const_reference List<T>::Back() const noexcept {
  if (tail_ == nullptr) {
    const_reference zero = 0;
    return zero;
  }
  return tail_->val_;
}

template <class T>
void List<T>::Unique() {
  if (Size() != 0) {
    value_type tmp = head_->val_;
    for (List<T>::ListIterator id = Begin(); id != End(); ++id) {
      if (tmp == *id && id != Begin()) {
        Erase(id);
      }
      tmp = *id;
    }
  }
}

template <class T>
void List<T>::Sort() noexcept {
  size_type size = this->size_of_list_;
  for (size_type i = 0; i < size - 1; i++) {
    for (size_type j = 0; j < size - i - 1; j++) {
      Node* first = GetAt(j);
      Node* second = GetAt(j + 1);
      if (first == nullptr || second == nullptr) {
        break;
      }
      if (first->val_ > second->val_) {
        std::swap(first->val_, second->val_);
      }
    }
  }
}

template <class T>
void List<T>::Splice(const_iterator pos, List& other) {
  for (List<T>::ListIterator id = other.Begin(); id != other.End(); ++id) {
    if (pos.current_node_) {
      Insert(pos, *id);
    } else {
      PushBack(*id);
    }
  }
  other.Clear();
}

template <class T>
void List<T>::Clear() noexcept {
  delete end_node_;
  if (head_) head_->prev_ = nullptr;
  if (tail_) tail_->next_ = nullptr;
  while (head_ != nullptr) {
    PopFront();
  }
  end_node_ = nullptr;
  size_of_list_ = 0;
}

template <class T>
void List<T>::Swap(List& other) noexcept {
  std::swap(*this, other);
}

template <class T>
void List<T>::Reverse() {
  Node* orig = tail_;
  List reverse;
  for (size_type i = 0; i < size_of_list_; i++) {
    reverse.PushBack(orig->val_);
    orig = orig->prev_;
  }
  CopyList(reverse);
  reverse.Clear();
}

template <class T>
void List<T>::Merge(List& other) {
  iterator own = Begin();
  iterator iter = other.Begin();
  if (!head_) {
    for (; iter != other.End(); ++iter) {
      PushBack(*iter);
    }
  } else {
    for (; iter != other.End() && own != End();) {
      if (*iter <= *own) {
        Insert(own, *iter);
        ++iter;
      } else if (*iter > *own && own != End()) {
        ++own;
      }
      if (own == End()) {
        PushBack(*iter);
      }
    }
  }
  other.Clear();
}

template <class T>
typename List<T>::size_type List<T>::MaxSize() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(List);
}

template <class T>
template <typename... Args>
typename List<T>::ListIterator List<T>::Emplace(ListIterator pos,
                                                Args&&... args) {
  if (pos != nullptr) {
    ([&] { pos = Insert(pos, args); }(), ...);
  }
  return pos;
}

template <class T>
template <typename... Args>
void List<T>::EmplaceFront(Args&&... args) {
  ([&] { PushFront(args); }(), ...);
}

template <class T>
template <typename... Args>
void List<T>::EmplaceBack(Args&&... args) {
  ([&] { PushBack(args); }(), ...);
}
}  // namespace s21
