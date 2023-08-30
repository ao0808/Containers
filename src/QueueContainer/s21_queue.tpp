namespace s21 {
template <class T>
Queue<T>::Queue() {}
template <class T>
Queue<T>::~Queue() {
  while (head_) {
    Pop();
  }
}

template <class T>
Queue<T>::Queue(std::initializer_list<value_type> const& items) {
  typename std::initializer_list<T>::iterator it = items.begin();
  size_t i = 0;
  while (items.size() > i) {
    Push(*it);
    it++;
    i++;
  }
  queue_size_ = i;
}

template <class T>
void Queue<T>::Push(const_reference value) noexcept {
  Node* ptr = new Node(value);
  if (head_ == nullptr) {
    head_ = ptr;
    head_->next_ = nullptr;
  } else {
    Node* ptrB = head_;
    for (; ptrB->next_ != nullptr; ptrB = ptrB->next_) {
    }
    ptr->next_ = nullptr;
    ptrB->next_ = ptr;
  }
  queue_size_ += 1;
}

template <class T>
Queue<T>::Queue(Queue&& other) noexcept {
  MoveQueue(other);
}

template <class T>
void Queue<T>::MoveQueue(Queue& other) noexcept {
  if (queue_size_) {
    while (head_) {
      Pop();
    }
  }
  if (other.head_) {
    std::swap(head_, other.head_);
    queue_size_ = other.queue_size_;
  }
}

template <class T>
typename Queue<T>::Queue& Queue<T>::operator=(Queue&& other) noexcept {
  if (this != &other) {
    MoveQueue(other);
  }
  return *this;
}

template <class T>
typename Queue<T>::Queue& Queue<T>::operator=(Queue& other) {
  if (this != &other) {
    CopyQueue(other);
  }
  return *this;
}

template <class T>
Queue<T>::Queue(const Queue& q) {
  CopyQueue(q);
}

template <class T>
void Queue<T>::Pop() noexcept {
  if (head_) {
    Node* ptr2 = head_->next_;
    delete head_;
    head_ = ptr2;
    queue_size_ -= 1;
  }
}

template <class T>
typename Queue<T>::size_type Queue<T>::Size() const noexcept {
  return queue_size_;
}

template <class T>
typename Queue<T>::const_reference Queue<T>::Front() const noexcept {
  if (!head_) {
    return zero_;
  }
  return head_->val_;
}

template <class T>
typename Queue<T>::const_reference Queue<T>::Back() const noexcept {
  if (!head_) {
    return zero_;
  }
  Node* ptr = head_;
  for (; ptr->next_ != nullptr; ptr = ptr->next_) {
  }
  return ptr->val_;
}
template <class T>
bool Queue<T>::Empty() const noexcept {
  return head_ == nullptr;
}

template <class T>
void Queue<T>::Swap(Queue& other) noexcept {
  Queue<T> tmp;
  tmp.CopyQueue(other);
  other.CopyQueue(*this);
  this->CopyQueue(tmp);
}

template <class T>
void Queue<T>::CopyQueue(const Queue& other) {
  while (head_) Pop();
  queue_size_ = 0;
  Node* ptr = other.head_;
  for (size_t i = 0; i < other.queue_size_; i++) {
    Push(ptr->val_);
    ptr = ptr->next_;
  }
}

template <class T>
template <typename... Args>
void Queue<T>::EmplaceBack(Args&&... args) noexcept {
  ([&] { Push(args); }(), ...);
}
}  // namespace s21