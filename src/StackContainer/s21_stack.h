#ifndef _SRC_STACKCONTAINER_S21_STACK_H_
#define _SRC_STACKCONTAINER_S21_STACK_H_

namespace s21 {

template <class T>
class Stack {
  class Node;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Stack();
  Stack(std::initializer_list<value_type> const &items);
  Stack(const Stack &other);
  Stack(Stack &&other) noexcept;
  ~Stack();
  Stack &operator=(Stack &&other) noexcept;
  Stack &operator=(Stack &other);

  const_reference Top() const;
  bool Empty() const noexcept;
  size_type Size() const noexcept;

  void Push(const_reference value);
  void Pop() noexcept;
  void Swap(Stack &other) noexcept;

  template <typename... Args>
  void EmplaceFront(Args &&...args);

 private:
  Node *head_ = nullptr;
  size_type size_ = 0;

  void CopyStack(const Stack &other);
  void MoveStack(Stack &other) noexcept;

  class Node {
    friend class Stack<T>;
    value_type val_ = 0;
    Node *next_ = nullptr;
    Node(value_type val) { this->val_ = val; }
  };
};
}  // namespace s21
#endif  //  _SRC_STACKCONTAINER_S21_STACK_H_
#include "s21_stack.tpp"