#ifndef _SRC_SETCONTAINERS_S21_SET_H_
#define _SRC_SETCONTAINERS_S21_SET_H_

#include "сommon_functions_set.h"
namespace s21 {
using namespace s21;
template <class key>
class Set {
 public:
  using key_type = key;
  using value_type = key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using Node = s21::Node<value_type>;
  class SetConstIterator {
   public:
    s21::Node<value_type>* iter_;
    value_type nil_ = 0;  //для краевых случаев
    reference zero_ = nil_;
    SetConstIterator() { this->iter_ = nullptr; }
    SetConstIterator(Node* value) { this->iter_ = value; }
    SetConstIterator(const SetConstIterator& other) : iter_(other.iter_) {}
    ~SetConstIterator() {}
    SetConstIterator& operator++() noexcept;
    SetConstIterator& operator--() noexcept;
    const_reference operator*() const noexcept;
    bool operator!=(const SetConstIterator& other) const noexcept;
    bool operator==(const SetConstIterator& other) const noexcept;
  };

  class SetIterator : public SetConstIterator {
   public:
    SetIterator();
    SetIterator(Node* value);
    SetIterator(const SetIterator& other);
    SetIterator(const SetConstIterator& other);
    ~SetIterator() {}
    reference operator*() const noexcept;
    SetIterator& operator=(const SetIterator other) noexcept;
  };

 public:
  using iterator = SetIterator;
  using const_iterator = SetConstIterator;

 public:
  Set(){};
  Set(std::initializer_list<value_type> const& items);
  Set(const Set& ms);
  Set(Set&& ms) noexcept;
  ~Set();
  Set& operator=(Set&& o) noexcept;
  Set& operator=(Set& o);

  iterator Begin() const noexcept;
  iterator End() const noexcept;

  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;
  bool Empty() const noexcept;

  void Clear() noexcept;

  template <class... Args>
  std::vector<std::pair<typename s21::Set<key>::iterator, bool>> Emplace(
      Args&&... args);

  std::pair<iterator, bool> Insert(const value_type& value) noexcept;

  void Erase(iterator pos) noexcept;
  void Swap(Set& other);
  void Merge(Set& other) noexcept;

  iterator Find(const key_type& key_val) const noexcept;
  bool Contains(const key_type& key_val) const noexcept;

 private:
  void MoveSet(Set& ms) noexcept;
  void CopySet(const Set& o);

  Node* root_ = nullptr;
  Node* last_end_ = nullptr;
  size_t mset_size_ = 0;
  Node* head_ = nullptr;
  Node* tail_ = nullptr;

  Node* DeleteNode(Node* root, value_type key_) noexcept;
  Node* InsertNode(Node* node, value_type key_, key_type& res) noexcept;
};
//
}  // namespace s21
#include "s21_set.tpp"
#endif  //  _SRC_SETCONTAINERS_S21_SET_H_