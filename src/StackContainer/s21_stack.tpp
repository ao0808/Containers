namespace s21 {
template <class value_type>
Stack<value_type>::Stack() {}
template <class value_type>
Stack<value_type>::Stack(std::initializer_list<value_type> const &items) {
  typename std::initializer_list<value_type>::iterator it = items.begin();
  size_t i = 0;
  while (items.size() > i) {
    Push(*it);
    ++it;
    i++;
  }
}

template <class value_type>
template <typename... Args>
void Stack<value_type>::EmplaceFront(Args &&...args) {
  ([&] { Push(args); }(), ...);
}

template <class value_type>
Stack<value_type>::Stack(const Stack &other) {
  CopyStack(other);
}

template <class value_type>
void Stack<value_type>::CopyStack(const Stack &other) {
  while (head_ != nullptr) {
    Pop();
  }
  Stack<value_type> tmpRevers;
  Node *tmp = other.head_;
  while (tmp != nullptr) {
    tmpRevers.Push(tmp->val_);
    tmp = tmp->next_;
  }
  tmp = tmpRevers.head_;
  while (tmp != nullptr) {
    Push(tmp->val_);
    tmp = tmp->next_;
  }
}
template <class value_type>
Stack<value_type>::Stack(Stack &&other) noexcept {
  MoveStack(other);
}
template <class value_type>
void Stack<value_type>::MoveStack(Stack &other) noexcept {
  while (head_ != nullptr) {
    Pop();
  }
  head_ = other.head_;
  other.head_ = nullptr;
  size_ = other.size_;
  other.size_ = 0;
}
template <class value_type>
Stack<value_type>::~Stack() {
  while (head_ != nullptr) {
    Pop();
  }
}
template <class value_type>
void Stack<value_type>::Push(const_reference value) {
  Node *ptr = new Node(value);
  if (head_ != nullptr) {
    ptr->next_ = head_;
  }
  head_ = ptr;
  size_ += 1;
}
template <class value_type>
void Stack<value_type>::Pop() noexcept {
  if (head_ != nullptr) {
    Node *tmp = head_->next_;
    delete head_;
    head_ = tmp;
    size_ -= 1;
  }
}

template <class value_type>
void Stack<value_type>::Swap(Stack &other) noexcept {
  Stack<value_type> tmp = std::move(*this);
  *this = std::move(other);
  other = std::move(tmp);
  ;
}
template <class value_type>
bool Stack<value_type>::Empty() const noexcept {
  return head_ == nullptr;
}
template <class value_type>
typename Stack<value_type>::size_type Stack<value_type>::Size() const noexcept {
  return size_;
}
template <class value_type>
typename Stack<value_type>::const_reference Stack<value_type>::Top() const {
  if (!head_) {
    throw std::out_of_range("s21::Stack::top - out of range");
  }
  return head_->val_;
}
template <class value_type>
typename Stack<value_type>::Stack &Stack<value_type>::operator=(Stack &other) {
  if (&other != this) CopyStack(other);
  return *this;
}
template <class value_type>
typename Stack<value_type>::Stack &Stack<value_type>::operator=(
    Stack &&other) noexcept {
  if (&other != this) MoveStack(other);
  return *this;
}
}  // namespace s21
