#ifndef _SRC_VECTORCONTAINER_S21_MULTISET_H_
#define _SRC_VECTORCONTAINER_S21_MULTISET_H_

#include <limits>
#include <utility>

namespace s21 {
template <class T>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 public:
  Vector();
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &other);
  Vector(Vector &&other) noexcept;
  ~Vector() {
    m_size_ = 0;
    m_capacity_ = 0;
    delete[] arr_;
  }
  Vector &operator=(Vector &&v) noexcept;
  Vector &operator=(Vector &v);

  reference At(size_type pos) const;
  reference operator[](size_type pos) const;
  const_reference Front() const;
  const_reference Back() const;
  value_type *Data() const noexcept;

  iterator Begin() const noexcept;
  iterator End() const noexcept;

  bool Empty() const noexcept;
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;

  void Reserve(size_type size);
  size_type Capacity() const noexcept;
  void ShrinkToFit();

  void Clear() noexcept;
  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator pos);
  void PushBack(const_reference v);
  void PopBack();
  void Swap(Vector &other);

  template <typename... Args>
  iterator Emplace(iterator pos, Args &&...args);
  template <typename... Args>
  void Emplace_back(Args &&...args);

  class VectorIterator;
  class VectorConstIterator;
  friend class VectorConstIterator;
  friend class VectorIterator;

  class VectorIterator {
    friend class Vector<T>;

   public:
    VectorIterator();
    VectorIterator(iterator first);
    ~VectorIterator(){};

    void operator++() { iter_++; };
    void operator--() { iter_--; };
    T &operator*() { return *(iter_); };
    bool operator==(const VectorIterator &other) {
      return iter_ == other.iter_;
    }
    bool operator!=(const VectorIterator &other) {
      return iter_ != other.iter_;
    }
    VectorIterator(const VectorIterator &other) : iter_(other.iter_) {}

   private:
    value_type *iter_;
  };

  class VectorConstIterator : public VectorIterator {
   public:
    VectorConstIterator() : VectorIterator(){};

   private:
    value_type *iter_;
  };

 private:
  size_type m_size_;
  size_type m_capacity_;
  value_type *arr_;
  void CopyVector(const Vector &other);
  void MoveVector(Vector &other, int type_of_operation) noexcept;
  void ReserveMoreCapacity(size_type size);
};
}  // namespace s21
#include "s21_vector.tpp"
#endif  //  _SRC_VECTORCONTAINER_S21_MULTISET_H_