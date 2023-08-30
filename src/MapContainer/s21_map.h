#ifndef _SRC_MAPCONTAINER_S21_MULTISET_H_
#define _SRC_MAPCONTAINER_S21_MULTISET_H_

#include <initializer_list>

namespace s21 {
template <typename K, typename T>
class Map {
  struct Node;
  struct Tree;

 public:
  class MapIterator;
  class MapConstIterator;

  using key_type = K;
  using mapped_type = T;
  using size_type = size_t;
  using value_type = std::pair<const key_type, mapped_type>;
  using Iterator = Map<K, T>::MapIterator;
  using ConstIterator = Map<K, T>::MapConstIterator;
  using reference = value_type&;

  Map();
  Map(std::initializer_list<value_type> const& items);
  Map(const Map& m);
  Map(Map&& m) noexcept;
  ~Map();
  void operator=(Map& m);
  void operator=(Map&& m) noexcept;

  T& At(const K& key) const;
  T& operator[](const K& key) const noexcept;
  Iterator Begin() const noexcept;
  Iterator End() const noexcept;
  bool Empty() const noexcept;
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;
  void Clear() noexcept;

  std::pair<Iterator, bool> Insert(const value_type& value) noexcept;
  std::pair<Iterator, bool> Insert(const K& key, const T& obj) noexcept;
  std::pair<Iterator, bool> Insert_or_assign(const K& key,
                                             const T& obj) noexcept;

  void Erase(Iterator pos) noexcept;
  void Swap(Map& other) noexcept;
  void Merge(Map& other) noexcept;
  bool Contains(const K& key) const noexcept;

  template <class... Args>
  std::vector<std::pair<typename s21::Map<K, T>::Iterator, bool>> Emplace(
      Args&&... args);

 public:
  class MapConstIterator {
   public:
    Node* lastvist_ = nullptr;
    Node* lasvisit_1_ = nullptr;
    Node* node_ = nullptr;
    MapConstIterator() { this->node_ = nullptr; }
    MapConstIterator(Node* value) { this->node_ = value; }
    MapConstIterator(const MapConstIterator& other) : node_(other.node_) {}
    ~MapConstIterator() {}
    void operator++() noexcept;
    void operator--() noexcept;
    std::pair<K, T> operator*() const noexcept;
    bool operator!=(const MapConstIterator& other) const noexcept;
    bool operator==(const MapConstIterator& other) const noexcept;
  };

  class MapIterator : public MapConstIterator {
   public:
    MapIterator();
    MapIterator(Node* value);
    MapIterator(const MapIterator& other);
    MapIterator(const MapConstIterator& other);
    ~MapIterator() {}
    MapIterator& operator=(const Iterator& other) noexcept;
  };

 private:
  Tree tree_;
  size_type map_size_ = 0;
  void DeleteMap(Node* list) noexcept;
  void MoveMap(Map& m) noexcept;
  void CopyMap(const Map& m);
  Iterator SearchKey(const value_type& value) noexcept;

  struct Node {
   public:
    friend class Map;
    Node()
        : height_(0),
          value_(0),
          size_(0),
          left_(nullptr),
          right_(nullptr),
          parent_(nullptr) {}
    Node(Node& other)
        : key_(other.key),
          value_(other.value),
          height_(other.height),
          size_(other.size_),
          left_(other.left),
          right_(other.right),
          parent_(other.parent) {}

    Node(const K& k, T& t)
        : key_(k),
          value_(t),
          height_(1),
          size_(1),
          left_(nullptr),
          right_(nullptr),
          parent_(nullptr) {}

    Node(K& k, T& t)
        : key_(k),
          value_(t),
          height_(1),
          size_(1),
          left_(nullptr),
          right_(nullptr),
          parent_(nullptr) {}

   private:
    K key_ = 0;
    T value_ = 0;
    int height_ = 0;
    size_t size_ = 0;
    Node* left_ = nullptr;
    Node* right_ = nullptr;
    Node* parent_ = nullptr;
  };

  struct Tree {
    friend class Map;
    friend struct Node;
    Node* end_ = nullptr;
    Node* root_ = nullptr;
    int max_value_ = 0;
    bool inserted_;
    int Height(Node* node) noexcept;
    void ParentAssigner(Node* parent, Node* child) noexcept;
    int GetBalanceFactor(Node* node) noexcept;
    Node* FindEnd(Node* root) noexcept;
    int Max(int a, int b) noexcept;
    Node* TurnLeft(Node* node) noexcept;
    Node* TurnRight(Node* node) noexcept;
    Node* DeleteNode(Node* root, K& key, int flag_balans_off) noexcept;
    Node* MimumValue(Node* node) const noexcept;
    Node* InsertNodeInTree(Node* node, value_type key, Node* parent);
    Node* Insert_one(const value_type& value) noexcept;
    Node* BalanceAVLTree(Node* root) noexcept;
  };
};

}  // namespace s21
#include "s21_map.tpp"
#endif  //   _SRC_MAPCONTAINER_S21_MULTISET_H_