namespace s21 {
template <typename value_type>
void Vector<value_type>::ReserveMoreCapacity(size_type size) {
  if (size > m_capacity_) {
    value_type *buff = new value_type[size];
    for (size_t i = 0; i < m_size_; ++i) buff[i] = std::move(arr_[i]);
    delete[] arr_;
    arr_ = std::move(buff);
    m_capacity_ = size;
  }
}

template <typename value_type>
Vector<value_type>::Vector() {
  m_size_ = 0;
  m_capacity_ = 0;
  arr_ = nullptr;
}

template <typename value_type>
Vector<value_type>::Vector(const Vector &other) {
  m_size_ = 0;
  m_capacity_ = 0;
  arr_ = nullptr;
  CopyVector(other);
}

template <typename value_type>
void Vector<value_type>::CopyVector(const Vector &other) {
  if (this->arr_ != other.arr_) {
    if (arr_ != nullptr) {
      delete[] arr_;
    }
    this->m_size_ = other.m_size_;
    this->m_capacity_ = other.m_capacity_;
    if (this->m_capacity_ > 0) {
      this->arr_ = new value_type[this->m_capacity_];
      for (size_type i = 0; i < this->m_size_; i++) {
        this->arr_[i] = other.arr_[i];
      }
    }
  }
}
template <typename value_type>
void Vector<value_type>::MoveVector(Vector &other,
                                    int type_of_operation) noexcept {
  if (this != &other) {
    if (type_of_operation) this->Clear();
    std::swap(arr_, other.arr_);
    this->m_size_ = other.m_size_;
    this->m_capacity_ = other.m_capacity_;
    other.arr_ = nullptr;
    other.m_size_ = 0;
    other.m_capacity_ = 0;
  }
}

template <typename value_type>
typename Vector<value_type>::Vector &Vector<value_type>::operator=(Vector &v) {
  if (&v != this) CopyVector(v);
  return *this;
}

template <typename value_type>
typename Vector<value_type>::Vector &Vector<value_type>::operator=(
    Vector &&other) noexcept {
  if (&other != this) MoveVector(other, 1);
  return *this;
}

template <typename value_type>
Vector<value_type>::Vector(Vector &&other) noexcept {
  MoveVector(other, 0);
}

template <typename value_type>
Vector<value_type>::Vector::VectorIterator::VectorIterator() {
  iter_ = nullptr;
};

template <typename value_type>
Vector<value_type>::Vector::VectorIterator::VectorIterator(iterator other) {
  iter_ = other;
};

template <typename value_type>
Vector<value_type>::Vector(size_type n) {
  if (MaxSize() < n) throw std::out_of_range("s21::Vector::ConstructError");
  m_size_ = n;
  m_capacity_ = n;
  arr_ = new value_type[m_capacity_];
};

template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const &items) {
  arr_ = new value_type[items.size()];
  size_type i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    arr_[i] = *it;
    i++;
  }
  m_size_ = items.size();
  m_capacity_ = items.size();
};

template <typename value_type>
size_t Vector<value_type>::Size() const noexcept {
  return m_size_;
}

template <typename value_type>
size_t Vector<value_type>::Capacity() const noexcept {
  return m_capacity_;
}

template <typename value_type>
void Vector<value_type>::Reserve(size_type size) {
  if (size >= MaxSize()) {
    throw std::length_error(
        "Error: in reserve(size_type size): size > s21::vector::MaxSize()");
  }
  if (size > m_capacity_) {
    value_type *tmp = arr_;
    // arr_ = nullptr;
    arr_ = new value_type[size];
    m_capacity_ = size;
    for (size_t i = 0; i < m_size_; i++) {
      arr_[i] = tmp[i];
    }
    delete[] tmp;
  }
};

template <typename value_type>
void Vector<value_type>::ShrinkToFit() {
  if (m_size_ < m_capacity_) {
    m_capacity_ = m_size_;
    value_type *tmp = arr_;
    // arr_ = nullptr;
    arr_ = new value_type[m_size_];
    m_capacity_ = m_size_;
    for (size_t i = 0; i < m_size_; i++) {
      arr_[i] = tmp[i];
    }
    delete[] tmp;
  }
}

template <typename value_type>
size_t Vector<value_type>::MaxSize() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(Vector);
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::Begin()
    const noexcept {
  return iterator(&arr_[0]);
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::End() const noexcept {
  return iterator(arr_ + m_size_);
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::At(
    size_type i) const {
  if (i >= this->m_size_) {
    throw std::out_of_range("Index out of range");
  }
  return arr_[i];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::Front() const {
  if (Empty()) {
    throw std::out_of_range("Out of range");
  }
  return arr_[0];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::Back() const {
  if (Empty()) {
    throw std::out_of_range("Out of range");
  }
  return arr_[m_size_ - 1];
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) const {
  return this->At(pos);
}
template <typename value_type>
void Vector<value_type>::PushBack(const_reference v) {
  if (m_size_ == m_capacity_) {
    if (m_size_ == 0) {
      ReserveMoreCapacity(2);
    } else {
      ReserveMoreCapacity(m_size_ * 2);
    }
  }
  arr_[m_size_++] = v;
}

template <typename value_type>
bool Vector<value_type>::Empty() const noexcept {
  return (this->Begin() == this->End());
}

template <typename value_type>
value_type *Vector<value_type>::Data() const noexcept {
  return arr_;
}

template <typename value_type>
void Vector<value_type>::Clear() noexcept {
  if (m_size_) {
    delete[] arr_;
  }
  arr_ = nullptr;
  this->m_capacity_ = 0;
  this->m_size_ = 0;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::Insert(
    iterator pos, const_reference value) {
  size_type position = &(*pos) - this->arr_;
  size_type zero = 0;
  if (zero > position || position > this->m_size_) {
    throw std::out_of_range("Index out ot range");
  }
  if (this->m_size_ + 1 >= this->m_capacity_) {
    if (m_size_ == 0) {
      ReserveMoreCapacity(2);
    } else {
      ReserveMoreCapacity(m_size_ * 2);
    }
  }
  value_type replace = this->arr_[position];
  this->m_size_++;
  this->arr_[position] = value;
  for (size_type i = position + 1; i < this->m_size_; ++i) {
    value_type next = this->arr_[i];
    this->arr_[i] = replace;
    replace = next;
  }
  return this->arr_ + position;
}

template <typename value_type>
void Vector<value_type>::Erase(iterator pos) {
  size_type position = &(*pos) - this->arr_;
  size_type zero = 0;
  if (zero > position || position > this->m_size_) {
    throw std::out_of_range("Index out ot range");
  }
  for (size_type i = position + 1; i < this->m_size_; i++) {
    this->arr_[i - 1] = this->arr_[i];
  }
  this->m_size_--;
}

template <typename value_type>
void Vector<value_type>::PopBack() {
  if (m_size_ > 0) {
    Vector<value_type>::Erase(this->End());
  }
}

template <typename value_type>
void Vector<value_type>::Swap(Vector &other) {
  if (this->arr_ != other.arr_) {
    // Vector<value_type> tmp(std::move(other));
    // other = (std::move(*this));
    // *this = std::move(tmp);
    std::swap(*this, other);
  }
}

template <typename value_type>
template <typename... Args>
void Vector<value_type>::Emplace_back(Args &&...args) {
  ([&] { PushBack(args); }(), ...);
}

template <typename value_type>
template <typename... Args>
typename Vector<value_type>::iterator Vector<value_type>::Emplace(
    iterator pos, Args &&...args) {
  if (pos != nullptr) {
    ([&] { pos = Insert(pos, args); }(), ...);
  }
  return pos;
}
}  // namespace s21
