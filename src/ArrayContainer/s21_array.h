#ifndef _SRC_ARRAYCONTAINER_S21_ARRAY_H_
#define _SRC_ARRAYCONTAINER_S21_ARRAY_H_

#include <initializer_list>

namespace s21 {
template <class T, size_t V>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 public:
  Array();
  Array(std::initializer_list<value_type> const &items);
  Array(const Array &a);
  Array(Array &&a) noexcept;
  ~Array();
  Array &operator=(Array &&a) noexcept;
  Array &operator=(Array &a);

  reference At(size_type pos);
  reference operator[](size_type pos);
  const_reference Front() const noexcept;
  const_reference Back() const noexcept;
  iterator Data() noexcept;

  iterator Begin() noexcept;
  iterator End() noexcept;

  bool Empty() const noexcept;
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;

  void Swap(Array &other) noexcept;
  void Fill(const_reference value) noexcept;

 private:
  value_type array_[V + 1];
  long int size_ = -1;
  void MoveArray(Array &a) noexcept;
  void CopyArray(const Array &a);
};
}  // namespace s21
#include "s21_array.tpp"
#endif  //  _SRC_ARRAYCONTAINER_S21_ARRAY_H_