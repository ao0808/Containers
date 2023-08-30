#ifndef _SRC_SETCONTAINERS_S21_MULTISET_H_
#define _SRC_SETCONTAINERS_S21_MULTISET_H_

#include "сommon_functions_set.h"
namespace s21 {
template <class key>
class Multiset {
 public:
  using key_type = key;
  using value_type = key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using Node = s21::Node<key>;

 public:
  class MultisetConstIterator {
   public:
    Node* iter_ = nullptr;
    value_type nil_ = 0;  //для краевых случаев
    reference zero_ = nil_;

   public:
    MultisetConstIterator() { this->iter_ = nullptr; }
    MultisetConstIterator(Node* value) { this->iter_ = value; }
    MultisetConstIterator(const MultisetConstIterator& other)
        : iter_(other.iter_) {}
    ~MultisetConstIterator() {}
    MultisetConstIterator& operator++() noexcept;
    MultisetConstIterator& operator--() noexcept;
    const_reference operator*() const noexcept;
    bool operator!=(const MultisetConstIterator& other) const noexcept;
    bool operator==(const MultisetConstIterator& other) const noexcept;
  };

  class MultisetIterator : public MultisetConstIterator {
   public:
    MultisetIterator();
    MultisetIterator(Node* value);
    MultisetIterator(const MultisetIterator& other);
    MultisetIterator(const MultisetConstIterator& other);
    ~MultisetIterator() {}
    reference operator*() const noexcept;
    MultisetIterator& operator=(const MultisetIterator other);
  };

 public:
  using iterator = MultisetIterator;
  using const_iterator = MultisetConstIterator;

  ~Multiset();
  Multiset(){};
  Multiset(std::initializer_list<value_type> const& items);
  Multiset(Multiset&& ms) noexcept;
  Multiset(const Multiset& ms);
  Multiset& operator=(Multiset&& o) noexcept;
  Multiset& operator=(const Multiset& o);

  size_type Size() const noexcept;
  size_t MaxSize() const noexcept;
  bool Empty() const noexcept;

  void Swap(Multiset& other);
  void Merge(Multiset& other) noexcept;
  size_type Count(const key_type& key_val) const noexcept;
  iterator Find(const key_type& key_val) const noexcept;
  bool Contains(const key_type& key_val);

  std::pair<iterator, iterator> EqualRange(const key_type& key_val) noexcept;
  iterator LowerBound(const key_type& key_val) noexcept;
  iterator UpperBound(const key_type& key_val) noexcept;

  void Erase(iterator pos) noexcept;
  iterator Insert(const value_type& value) noexcept;
  void Clear() noexcept;
  Node* Begin() const noexcept;
  Node* End() noexcept;

  template <class... Args>
  std::vector<std::pair<typename s21::Multiset<key>::iterator, bool>> Emplace(
      Args&&... args);

 private:
  Node* last_end_ = nullptr;
  size_type mset_size_ = 0;
  Node* root_ = nullptr;
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  iterator inserted_;

  void CopyMultiSet(const Multiset& o);
  void MoveMultiset(Multiset& ms) noexcept;

  Node* InsertNode(Node* node, value_type key_) noexcept;
  Node* DeleteNode(Node* root, value_type key_) noexcept;
  std::pair<iterator, bool> InsertBonus(const value_type& value) noexcept;
};
}  // namespace s21
#include "s21_multiset.tpp"
#endif  //  _SRC_SETCONTAINERS_S21_MULTISET_H_