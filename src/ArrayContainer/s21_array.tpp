namespace s21 {
template <class T, size_t V>
Array<T, V>::Array() {
  if (V >= 0) size_ = V - 1;
}
template <class T, size_t V>
Array<T, V>::Array(std::initializer_list<value_type> const &items) {
  typename std::initializer_list<T>::iterator it = items.begin();
  size_type i = 0;
  for (; items.size() > i; i++) {
    array_[i] = *it;
    ++it;
  }
  size_ = i - 1;
}
template <class T, size_t V>
Array<T, V>::~Array() {}
template <class T, size_t V>
Array<T, V>::Array(const Array &a) {
  CopyArray(a);
}
template <class T, size_t V>
void Array<T, V>::CopyArray(const Array &a) {
  size_ = a.size_;
  Fill(value_type(0));
  for (int i = 0; i < size_ + 1; i++) {
    array_[i] = a.array_[i];
  }
}
template <class T, size_t V>
Array<T, V>::Array(Array &&a) noexcept {
  MoveArray(a);
}
template <class T, size_t V>
typename Array<T, V>::Array &Array<T, V>::operator=(Array &&a) noexcept {
  if (this != &a) MoveArray(a);
  return *this;
}
template <class T, size_t V>
typename Array<T, V>::Array &Array<T, V>::operator=(Array &a) {
  if (this != &a) {
    CopyArray(a);
  }
  return *this;
}
template <class T, size_t V>
void Array<T, V>::MoveArray(Array &a) noexcept {
  Fill(value_type(0));
  std::move(a.array_, a.array_ + V, this->array_);
  size_ = a.size_;
}
template <class T, size_t V>
typename Array<T, V>::const_reference Array<T, V>::Front() const noexcept {
  return array_[0];
}
template <class T, size_t V>
typename Array<T, V>::const_reference Array<T, V>::Back() const noexcept {
  return array_[size_];
}
template <class T, size_t V>
typename Array<T, V>::reference Array<T, V>::operator[](size_type pos) {
  return array_[pos];
}
template <class T, size_t V>
typename Array<T, V>::reference Array<T, V>::At(size_type pos) {
  long int i = pos;
  if (i < 0 || i > size_) {
    throw std::out_of_range("Incorret input, out of range!");
  }
  return array_[pos];
}
template <class T, size_t V>
typename Array<T, V>::iterator Array<T, V>::Begin() noexcept {
  return &array_[0];
  ;
}
template <class T, size_t V>
typename Array<T, V>::iterator Array<T, V>::End() noexcept {
  if (size_ != -1) {
    return &array_[size_];
  } else {
    return &array_[0];
  }
}
template <class T, size_t V>
bool Array<T, V>::Empty() const noexcept {
  return size_ == -1;
}
template <class T, size_t V>
typename Array<T, V>::size_type Array<T, V>::Size() const noexcept {
  return size_ + 1;
}
template <class T, size_t V>
void Array<T, V>::Swap(Array &other) noexcept {
  Array<T, V> tmp(std::move(other));
  other = (std::move(*this));
  *this = (std::move(tmp));
}
template <class T, size_t V>
void Array<T, V>::Fill(const_reference value) noexcept {
  for (int i = 0; i < size_ + 1; i++) {
    array_[i] = value;
  }
}
template <class T, size_t V>
typename Array<T, V>::iterator Array<T, V>::Data() noexcept {
  return array_;
}
template <class T, size_t V>
typename Array<T, V>::size_type Array<T, V>::MaxSize() const noexcept {
  return size_ + 1;
}
}  // namespace s21