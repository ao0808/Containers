#ifndef _SRC_LISTCONTAINER_S21_LIST_H_
#define _SRC_LISTCONTAINER_S21_LIST_H_

namespace s21 {
template <class T>
class List {
  class Node;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  class ConstListIterator {
   public:
    Node* current_node_;
    value_type nil_ = 0;  //для краевых случаев
    reference zero_ = nil_;

    ConstListIterator() { current_node_ = nullptr; }
    ConstListIterator(Node* value) { current_node_ = value; }
    ConstListIterator(const ConstListIterator& other)
        : current_node_(other.current_node_) {}
    ~ConstListIterator() {}
    ConstListIterator& operator++() noexcept;
    ConstListIterator& operator--() noexcept;
    const_reference operator*() const noexcept;
    bool operator!=(const ConstListIterator& other) const noexcept;
    bool operator==(const ConstListIterator& other) const noexcept;
  };

  class ListIterator : public ConstListIterator {
   public:
    ListIterator();
    ListIterator(Node* value);
    ListIterator(const ListIterator& other);
    ListIterator(const ConstListIterator& other);
    ~ListIterator() {}
    reference operator*() const noexcept;
    ListIterator& operator=(const ListIterator other) noexcept;
  };
  using iterator = ListIterator;
  using const_iterator = ConstListIterator;

 public:
  List();
  List(size_type n);
  List(std::initializer_list<T> const& items);
  List(const List& l);
  List(List&& l) noexcept;
  ~List();
  List& operator=(List&& l) noexcept;
  List& operator=(const List& o);

  const_reference Front() const noexcept;
  const_reference Back() const noexcept;

  iterator Begin() const noexcept;
  iterator End() const noexcept;

  bool Empty() const noexcept;
  size_type MaxSize() const noexcept;
  size_type Size() const noexcept;

  void Clear() noexcept;
  iterator Insert(iterator pos, const_reference val);
  void Erase(iterator pos);

  void PopFront();
  void PopBack();
  void PushFront(const_reference value);
  void PushBack(const_reference value);

  void Swap(List& other) noexcept;
  void Merge(List& other);
  void Splice(const_iterator pos, List& other);
  void Reverse();
  void Unique();
  void Sort() noexcept;

  template <typename... Args>
  ListIterator Emplace(ListIterator pos, Args&&... args);
  template <typename... Args>
  void EmplaceFront(Args&&... args);
  template <typename... Args>
  void EmplaceBack(Args&&... args);

 private:
  size_type size_of_list_ = 0;
  Node *head_ = nullptr, *tail_ = nullptr;
  Node* end_node_ = nullptr;

  Node* GetAt(int index) const noexcept;
  void MoveList(List& l) noexcept;
  void CopyList(const List& l);

  class Node {
    friend class List<T>;

   private:
    value_type val_ = 0;
    Node *prev_, *next_;
    Node(value_type val_) {
      this->val_ = val_;
      this->prev_ = this->next_ = nullptr;
    }
  };
};
}  // namespace s21
#include "s21_list.tpp"
#endif  //  _SRC_LISTCONTAINER_S21_LIST_H_