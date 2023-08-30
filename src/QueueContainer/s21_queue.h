#ifndef _SRC_QUEUECONTAINER_S21_QUEUE_H_
#define _SRC_QUEUECONTAINER_S21_QUEUE_H_

namespace s21 {
template <class T>

class Queue {
  class Node;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Queue();
  Queue(std::initializer_list<value_type> const &items);
  Queue(const Queue &q);
  Queue(Queue &&q) noexcept;
  ~Queue();
  Queue &operator=(Queue &&q) noexcept;
  Queue &operator=(Queue &q);

  const_reference Front() const noexcept;
  const_reference Back() const noexcept;

  size_type Size() const noexcept;
  bool Empty() const noexcept;

  void Push(const_reference value) noexcept;
  void Pop() noexcept;
  void Swap(Queue &other) noexcept;

  template <typename... Args>
  void EmplaceBack(Args &&...args) noexcept;

 private:
  void MoveQueue(Queue &other) noexcept;
  void CopyQueue(const Queue &other);

  Node *head_ = nullptr;
  size_type queue_size_ = 0;
  value_type nil_ = 0;
  const_reference zero_ = nil_;
  class Node {
    friend class Queue<T>;
    Node(value_type val_) { this->val_ = val_; }
    value_type val_ = 0;
    Node *next_ = nullptr;
  };
};
}  // namespace s21
#include "s21_queue.tpp"
#endif  //  _SRC_QUEUECONTAINER_S21_QUEUE_H_