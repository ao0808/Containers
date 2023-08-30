#include <gtest/gtest.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include "s21_containersplus.h"
#include "s21_containers.h"
// //_______________________________LIST_TESTS________________________________

class TestList {
 public:
  s21::List<int> s21_list_empty;
  s21::List<int> s21_list_three{1, 2, 3};
  s21::List<int> s21_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  s21::List<char> s21_char_list{'L', 'I', 'S', 'T'};
  s21::List<int> s21_list_ten{1, 2, 3, 5, 9, 10};
  s21::List<int> s21_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};

  std::list<int> std_list_empty;
  std::list<int> std_list_three{1, 2, 3};
  std::list<int> std_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  std::list<char> std_char_list{'L', 'I', 'S', 'T'};
  std::list<int> std_list_ten{1, 2, 3, 5, 9, 10};
  std::list<int> std_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};
};

TEST(List, default_constructor) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.Size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.Empty(), tester.std_list_empty.empty());
}

TEST(List, init_constructor) {
  TestList tester;
  s21::List<int> a(3);
  std::list<int> b(3);
  s21::List<int>::iterator s21_it = a.Begin();
  std::list<int>::iterator std_it = b.begin();
  while (s21_it != a.End()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(List, initializer_constructor) {
  TestList tester;
  s21::List<int>::iterator s21_iter = tester.s21_list_three.Begin();
  std::list<int>::iterator std_iter = tester.std_list_three.begin();
  while (s21_iter != tester.s21_list_three.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
}

TEST(List, copy_constructor) {
  TestList tester;
  s21::List<int> s21_list_copy(tester.s21_list_three);
  std::list<int> std_list_copy(tester.std_list_three);
  s21::List<int>::iterator s21_iter = s21_list_copy.Begin();
  std::list<int>::iterator std_iter = std_list_copy.begin();
  while (s21_iter != s21_list_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_copy.Size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.Empty(), std_list_copy.empty());
}

TEST(List, move_constructor) {
  TestList tester;
  s21::List<int> s21_list_move(std::move(tester.s21_list_three));
  std::list<int> std_list_move(std::move(tester.std_list_three));
  s21::List<int>::iterator s21_iter = s21_list_move.Begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.Size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.Empty(), std_list_move.empty());
  s21::List<int> s21_list_three{1,2,3};
  std::list<int> s21_list_three_{1,2,3};
  s21_iter = s21_list_three.Begin();
  std_iter = s21_list_three_.begin();
  while (s21_iter != s21_list_three.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
}

TEST(List, copy_assigment_lesser) {
  TestList tester;
  s21::List<int> s21_list_copy{1, 2};
  std::list<int> std_list_copy{1, 2};
  s21_list_copy = tester.s21_lesser;
  std_list_copy = tester.std_lesser;
  s21::List<int>::iterator s21_iter = s21_list_copy.Begin();
  std::list<int>::iterator std_iter = std_list_copy.begin();
  while (s21_iter != s21_list_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_copy.Size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.Empty(), std_list_copy.empty());
}

TEST(List, move_assigment) {
  TestList tester;
  s21::List<int> s21_list_move{1, 2};
  std::list<int> std_list_move{1, 2};
  s21_list_move = std::move(tester.s21_lesser);
  std_list_move = std::move(tester.std_lesser);
  s21::List<int>::iterator s21_iter = s21_list_move.Begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.Size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.Empty(), std_list_move.empty());
}

TEST(List, function_front) {
  TestList tester;
  EXPECT_EQ(tester.s21_char_list.Front(), tester.std_char_list.front());
}
TEST(List, function_front_empty) {
  TestList tester;

         s21::List<int> one {1,5,9,3};
  EXPECT_DOUBLE_EQ(tester.s21_list_empty.Front(), tester.std_list_empty.front());
}

TEST(List, function_back) {
  TestList tester;
  EXPECT_EQ(tester.s21_char_list.Back(), tester.std_char_list.back());
    s21::List<char> emptylist;
    s21::List<char>::const_iterator con_it = emptylist.Begin();
    EXPECT_TRUE(*con_it == 0);
}
TEST(List, function_back_empty) {
  TestList tester;
  EXPECT_DOUBLE_EQ(tester.s21_list_empty.Back(), tester.std_list_empty.back());
}

TEST(List, iterator_access) {
  TestList tester;
  s21::List<char>::const_iterator con_it = tester.s21_char_list.Begin();
  s21::List<char>::iterator s21_iter(con_it);
  std::list<char>::iterator std_iter = tester.std_char_list.begin();
  while (s21_iter != tester.s21_char_list.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
}

TEST(List, const_iterator_access) {
  TestList tester;
  s21::List<char>::const_iterator s21_const_iter = tester.s21_char_list.Begin();
  std::list<char>::const_iterator std_const_iter = tester.std_char_list.begin();
  while (s21_const_iter != tester.s21_char_list.End()) {
    EXPECT_EQ(*s21_const_iter, *std_const_iter);
    ++s21_const_iter;
    ++std_const_iter;
  }
}

TEST(List, function_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.Empty(), tester.std_list_empty.empty());
  EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
}

TEST(List, function_size) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_empty.Size(), tester.std_list_empty.size());
}

TEST(List, function_clear) {
  TestList tester;
  tester.s21_list_three.Clear();
  tester.std_list_three.clear();
  EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
}

TEST(List, function_insert_begin) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_empty.Begin();
  std::list<int>::iterator std_it = tester.std_list_empty.begin();
  s21_it = tester.s21_list_empty.Insert(s21_it, 666);
  std_it = tester.std_list_empty.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_empty.Begin();
  std_it = tester.std_list_empty.begin();
  while (s21_it != tester.s21_list_empty.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_empty.Size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.Empty(), tester.std_list_empty.empty());
}

TEST(List, function_insert_mid) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.Insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_insert_end) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.End();
  std::list<int>::iterator std_it = tester.std_list_ten.end();
  s21_it = tester.s21_list_ten.Insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_insert_multi) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  s21_it = tester.s21_list_ten.Insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.Insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    ASSERT_DOUBLE_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function__begin) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  tester.s21_list_ten.Erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_mid) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  tester.s21_list_ten.Erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_end) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.End();
   std::list<int>::iterator std_it = tester.std_list_ten.end();
  --s21_it;
  --std_it;
  tester.s21_list_ten.Erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_multi) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  tester.s21_list_ten.Erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  tester.s21_list_ten.Erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}
TEST(List, function_push_back) {
  TestList tester;
  tester.s21_list_three.PushBack(666);
  tester.std_list_three.push_back(666);
  tester.s21_list_three.PushBack(123);
  tester.std_list_three.push_back(123);
  s21::List<int>::iterator s21_it = tester.s21_list_three.Begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
}

TEST(List, function_pop_back) {
  TestList tester;
  tester.s21_list_ten.PopBack();
  tester.std_list_ten.pop_back();
  tester.s21_list_ten.PopBack();
  tester.std_list_ten.pop_back();
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_push_front) {
  TestList tester;
  tester.s21_list_ten.PushFront(666);
  tester.std_list_ten.push_front(666);
  tester.s21_list_ten.PushFront(123);
  tester.std_list_ten.push_front(123);
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_pop_front) {
  TestList tester;
  tester.s21_list_ten.PopFront();
  tester.std_list_ten.pop_front();
  tester.s21_list_ten.PopFront();
  tester.std_list_ten.pop_front();
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_swap) {
  TestList tester;
  s21::List<int> s21_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  tester.s21_lesser.Swap(s21_list_swap);
  tester.std_lesser.swap(std_list_swap);
  s21::List<int>::iterator s21_it = s21_list_swap.Begin();
  std::list<int>::iterator std_it = std_list_swap.begin();
  while (s21_it != s21_list_swap.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_swap.Size(), std_list_swap.size());
  EXPECT_EQ(s21_list_swap.Empty(), std_list_swap.empty());
  s21_it = tester.s21_lesser.Begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.End()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
}
TEST(List, function_merge_nonsorted) {
  TestList tester;
  s21::List<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
  std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
  tester.s21_lesser.Merge(s21_list_merge);
  tester.std_lesser.merge(std_list_merge);
  s21::List<int>::iterator s21_it = s21_list_merge.Begin();
  std::list<int>::iterator std_it = std_list_merge.begin();
  while (s21_it != s21_list_merge.End()) {

    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_merge.Size(), std_list_merge.size());
  EXPECT_EQ(s21_list_merge.Empty(), std_list_merge.empty());
  s21_it = tester.s21_lesser.Begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.End()) {
  EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
}

TEST(List, function_merge_sorted) {
  TestList tester;
  s21::List<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
  std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
  tester.s21_lesser.Sort();
  tester.std_lesser.sort();
  tester.s21_lesser.Merge(s21_list_merge);
  tester.std_lesser.merge(std_list_merge);
  s21::List<int>::iterator s21_it = s21_list_merge.Begin();
  std::list<int>::iterator std_it = std_list_merge.begin();
  while (s21_it != s21_list_merge.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_merge.Size(), std_list_merge.size());
  EXPECT_EQ(s21_list_merge.Empty(), std_list_merge.empty());
  s21_it = tester.s21_lesser.Begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
}

TEST(List, function_splice) {
  TestList tester;
  s21::List<int> s21_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::List<int>::iterator s21_it = tester.s21_lesser.Begin();
  std::list<int>::iterator std_it = tester.std_lesser.begin();
  ++s21_it;
  ++std_it;
  tester.s21_lesser.Splice(s21_it, s21_list_splice);
  tester.std_lesser.splice(std_it, std_list_splice);
  s21_it = s21_list_splice.Begin();
  std_it = std_list_splice.begin();
  while (s21_it != s21_list_splice.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_splice.Size(), std_list_splice.size());
  EXPECT_EQ(s21_list_splice.Empty(), std_list_splice.empty());
  s21_it = tester.s21_lesser.Begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
}

TEST(List, function_reverse) {
  TestList tester;
  tester.s21_list_ten.Reverse();
  tester.std_list_ten.reverse();
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_unique) {
  TestList tester;
  tester.s21_list_unique.Unique();
  tester.std_list_unique.unique();
  s21::List<int>::iterator s21_it = tester.s21_list_unique.Begin();
  std::list<int>::iterator std_it = tester.std_list_unique.begin();
  while (s21_it != tester.s21_list_unique.End()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_unique.Size(), tester.std_list_unique.size());
  EXPECT_EQ(tester.s21_list_unique.Empty(), tester.std_list_unique.empty());
}

TEST(List, function_sort) {
  TestList tester;
  tester.s21_lesser.Sort();
  tester.std_lesser.sort();
  s21::List<int>::iterator s21_it = tester.s21_lesser.Begin();
  std::list<int>::iterator std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.Size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.Empty(), tester.std_lesser.empty());
}

TEST(List, function_emplace_begin) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_mid) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_end) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.End();
  std::list<int>::iterator std_it = tester.std_list_ten.end();
  s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_multi) {
  TestList tester;
  s21::List<int>::iterator s21_it = tester.s21_list_ten.Begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.Emplace(s21_it, 666);
  std_it = tester.std_list_ten.emplace(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.Begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.Size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.Empty(), tester.std_list_ten.empty());
}

TEST(List, function_emplace_back) {
  TestList tester;
  tester.s21_list_three.EmplaceBack(666);
  tester.std_list_three.emplace_back(666);
  tester.s21_list_three.EmplaceBack(123);
  tester.std_list_three.emplace_back(123);
  s21::List<int>::iterator s21_it = tester.s21_list_three.Begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
}

TEST(List, function_emplace_front) {
  TestList tester;
  tester.s21_list_three.EmplaceFront(666);
  tester.std_list_three.emplace_front(666);
  tester.s21_list_three.EmplaceFront(123);
  tester.std_list_three.emplace_front(123);
  s21::List<int>::iterator s21_it = tester.s21_list_three.Begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.Size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.Empty(), tester.std_list_three.empty());
}




TEST(initializer_lists, TEST_1){
 s21::List<int>A = {};
 std::list<int>B = {};

  size_t a = A.Size();
  size_t b = B.size();
  ASSERT_EQ(a, b);

}

TEST(initializer_lists, TEST_2){
 s21::List<int>A = {1,2,3,4,5,6,7,8,9,10,456545,987,5423,3454,3673};
 std::list<int>B = {1,2,3,4,5,6,7,8,9,10,456545,987,5423,3454,3673};

  size_t a = A.Size();
  size_t b = B.size();
  ASSERT_EQ(a, b);

  s21::List<int>::ListIterator iterA = A.Begin();
  std::list<int>::iterator iterB =  B.begin();
    ASSERT_EQ(*iterA, *iterB);

  iterA = A.End();
  iterB = B.end();
  --iterA;
  --iterB;
 
  ASSERT_EQ(*iterA, *iterB);
}

TEST(initializer_lists, TEST_3){
 s21::List<double>A{77.987654};
 std::list<double>B{77.987654};

  size_t a = A.Size();
  size_t b = B.size();
  ASSERT_EQ(a, b);
  s21::List<double>::ListIterator iterA = A.Begin();
  std::list<double>::iterator iterB =  B.begin();
  ASSERT_EQ(*iterA, *iterB);
}


TEST(parameterized_constructor, TEST_4){
 s21::List<double>A(50);
 std::list<double>B(50);

  size_t a = A.Size();
  size_t b = B.size();
  ASSERT_EQ(a, b);
  s21::List<double>::ListIterator iterA = A.Begin();
  std::list<double>::iterator iterB =  B.begin();

  ASSERT_EQ(*iterA, *iterB);
  iterA = A.End();
  iterB = B.end();
  --iterA;
  --iterB;
  ASSERT_EQ(*iterA, *iterB);
}

TEST(parameterized_constructor, TEST_5){
 s21::List<double>A(50);
 s21::List<double>::ListIterator iterA;
  double y = 0.5;
  for (iterA = A.Begin(); iterA != A.End(); ++iterA) {
    *iterA = 1648.090 + y;
  }
  std::list<double> B(50);
  std::list<double>::iterator iterB;
  for (iterB = B.begin(); iterB != B.end(); ++iterB) {
    *iterB = 1648.090 + y;
  }
  size_t a = A.Size();
  size_t b = B.size();
  EXPECT_EQ(a, b);

  iterA = A.Begin();
  iterB = B.begin();
  EXPECT_DOUBLE_EQ(*iterA, *iterB);

  iterA = A.End();
  iterB = B.end();
  --iterA;
  --iterB;
  EXPECT_DOUBLE_EQ(*iterA, *iterB);
}

TEST(parameterized_constructor_throw, TEST_1){
s21::List<double>A(-777);
EXPECT_EQ(A.Size(), 0);

}

TEST(parameterized_constructor_throw, TEST_2){
s21::List<double>A(0);
 EXPECT_EQ(A.Size(), 0);
}



TEST(copy_constructor, TEST_1){
s21::List<double>A = {1.0006,21,3,4,51,6,7,8,9,10,765765467.646,6,7,7,53,2,2,45,6,32,1};
 s21:: List<double>B(A);
  s21:: List<double>::ListIterator iterA = A.Begin();
  s21::  List<double>::ListIterator iterB = B.Begin();
   EXPECT_DOUBLE_EQ(*iterA, *iterB);

  iterA = A.End();
  iterB = B.End();

  EXPECT_DOUBLE_EQ(*iterA, *iterB);

  size_t a = A.Size();
  size_t b = B.Size();
  EXPECT_EQ(a, b);
}

TEST(move_constructor, TEST_1){
  s21:: List<int>A = {1,4,6,4,8};
  s21:: List<int>B(std::move(A));

  EXPECT_EQ(A.Size(), 0);

  EXPECT_EQ(B.Size(), 5);

  s21:: List<int>::ListIterator iterA = B.Begin();
   EXPECT_EQ(*iterA, 1);
   iterA = B.End();
   --iterA;
   EXPECT_EQ(*iterA, 8);

  iterA = A.Begin();
  EXPECT_EQ(iterA, nullptr);
  iterA = A.End();
  EXPECT_EQ(iterA, nullptr);
}

TEST(move_operator, TEST_1){
   s21::List<int>A = {1,4,6,4,8};
   s21::List<int>B(std::move(A));

   EXPECT_EQ(A.Size(), 0);

   EXPECT_EQ(B.Size(), 5);

   s21::List<int>::ListIterator iterB = B.Begin();
   EXPECT_EQ(*iterB, 1);
    iterB = B.End();
    --iterB;
    EXPECT_EQ(*iterB, 8);
}

TEST(insert_throwTest, TEST_1){
 s21::  List<int>A{7,7,7};
 s21::  List<int>B{0,0,0,0};
 s21::  List<int>::ListIterator it = B.Begin();
   ++it;
   EXPECT_ANY_THROW(A.Insert(it,0));
}




TEST(insert_test, TEST_1){
   s21::List<int>A{0,0,0,0,0,0,0};
  s21:: List<int>::ListIterator it = A.Begin();
   A.Insert(it,-999);
   it = A.Begin();

   std::list<int>orig{0,0,0,0,0,0,0};
   std::list<int>::iterator it_orig = orig.begin();
    orig.insert(it_orig,-999);
    orig.begin();
    for(it_orig = orig.begin(); it_orig != orig.end(); ++it_orig){
    EXPECT_EQ(*it,*it_orig);
    ++it;
    }
}


TEST(insert_test, TEST_2){
  s21:: List<int>B{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   s21::List<int>::ListIterator iter = B.End();

   iter = B.Insert(iter,0);
 
    for(s21::List<int>::ListIterator iterat  = B.Begin(); iterat != B.End(); ++iterat){
      if(iter == iterat){
     EXPECT_EQ(*iter,0);
      } else {
        EXPECT_EQ(*iterat,1);
      }

   }
}

TEST(insert_test, TEST_3){
 s21::  List<int>A{0,0,0,0,0,0,0};
  s21:: List<int>::ListIterator it = A.Begin();
   A.Insert(it,-999);
   A.Insert(it,-999);
   A.Insert(it,-999);
   A.Insert(it,-999);

   ++it;
   ++it;
   A.Insert(it,-999);
   it = A.Begin();

   std::list<int>orig{0,0,0,0,0,0,0};
   std::list<int>::iterator it_orig = orig.begin();
    orig.insert(it_orig,-999);
    orig.insert(it_orig,-999);
    orig.insert(it_orig,-999);
    orig.insert(it_orig,-999);
    ++it_orig;
    ++it_orig;
    orig.insert(it_orig,-999);
      
    for(it_orig = orig.begin(); it_orig != orig.end(); ++it_orig){
    EXPECT_EQ(*it,*it_orig);
    ++it;
    }
}

TEST(empty, TEST_1){
 s21::  List<int>A;
   std::list<int>orig;
    bool A_ = A.Empty();
    bool B = orig.empty();
    EXPECT_EQ(B,A_);
}

TEST(empty, TEST_2){
  s21:: List<int>A(30);
   std::list<int>orig(30);
    bool A_ = A.Empty();
    bool B = orig.empty();
    EXPECT_EQ(B,A_);
}

TEST(empty, TEST_3){
  s21:: List<int>A{1,1,1,1};
   std::list<int>orig{1,1,1,1};
    bool A_ = A.Empty();
    bool B = orig.empty();
    EXPECT_EQ(B,A_);
}

TEST(empty, TEST_4){
  s21:: List<int>A{1,1,1,1};
   A.Clear();
   std::list<int>orig{1,1,1,1};
   orig.clear();
    bool A_ = A.Empty();
    bool B = orig.empty();
    EXPECT_EQ(B,A_);
}



TEST(const_reference_front_back, TEST_1){
  
  std::list<int> A;
  int ans =  A.front();
 s21:: List<int>B;
  int ans_mine =  B.Front();
  EXPECT_EQ(ans,ans_mine);

  ans =  A.back();
  ans_mine =  B.Back();
  EXPECT_EQ(ans,ans_mine);
}


TEST(const_reference_front_back, TEST_2){
  
  std::list<int> A{1,2,3,4,5,6,7,8,9,0,10};
  int ans =  A.front();
  s21::List<int>B{1,2,3,4,5,6,7,8,9,0,10};
  int ans_mine =  B.Front();
  EXPECT_EQ(ans,ans_mine);

  ans =  A.back();
  ans_mine =  B.Back();
  EXPECT_EQ(ans,ans_mine);
}

TEST(const_reference_front_back, TEST_3){
  std::list<int> A(20);
  int ans =  A.front();
  s21::List<int>B(20);
  int ans_mine =  B.Front();
  EXPECT_EQ(ans,ans_mine);

  ans =  A.back();
  ans_mine =  B.Back();
  EXPECT_EQ(ans,ans_mine);
}

TEST(const_reference_front_back, TEST_4){
  std::list<int> A(20);
  A.clear();
  int ans =  A.front();
  s21::List<int>B(20);
  B.Clear();  
  int ans_mine =  B.Front();
  EXPECT_EQ(ans,ans_mine);

  ans =  A.back();
  ans_mine =  B.Back();
  EXPECT_EQ(ans,ans_mine);
}

TEST(size_test, TEST_1){
  std::list<int> A(20);
  s21::List<int>B(20);
  size_t mine = B.Size();
  size_t orig = A.size();
 EXPECT_EQ(mine,orig);
}

TEST(size_test, TEST_2){
  std::list<int> A(20);
  s21::List<int>B(20);
  B.Clear();
  A.clear();
  size_t mine = B.Size();
  size_t orig = A.size();
 EXPECT_EQ(mine,orig);
}

TEST(size_test, TEST_3){
  std::list<int> A{1,2,3,4,5,5,32,2,4,1,1,1,3};
  s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
  size_t mine = B.Size();
  size_t orig = A.size();
 EXPECT_EQ(mine,orig);
}

TEST(MaxSize_test, TEST_1){
  s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
  size_t mine = B.MaxSize();
 EXPECT_EQ(mine,576460752303423487);
}

TEST(MaxSize_test, TEST_2){
  s21::List<double>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
  size_t mine = B.MaxSize();
 EXPECT_EQ(mine,576460752303423487);
}

TEST(MaxSize_test, TEST_3){

  s21::List<char>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
  size_t mine = B.MaxSize();
 EXPECT_EQ(mine,576460752303423487);
}

TEST(MaxSize_test, TEST_4){
  s21::List<char>B;
  size_t mine = B.MaxSize();

 EXPECT_EQ(mine,576460752303423487);
}


TEST(PushBack_front_test, TEST_4){
  std::list<char> A;
  A.push_back('I');
  A.push_front('G');
  A.push_back('\'');
   A.push_front('G');
   A.push_back('m');
     A.push_back(' ');
      A.push_front('s');
     A.push_back('D');
      A.push_front('!');
       A.push_front('!');
  s21::List<char>B;
    B.PushBack('I');
      B.PushFront('G');
    B.PushBack('\'');
      B.PushFront('G');
    B.PushBack('m');
    B.PushBack(' ');
      B.PushFront('s');
    B.PushBack('D');
     B.PushFront('!');
      B.PushFront('!');

  size_t mine = B.Size();
  size_t orig = A.size();
  EXPECT_EQ(mine,orig);
 std::list<char>::iterator it = A.begin();
 s21::List<char>::ListIterator it_mine = B.Begin();
  for(; it != A.end();++it){
     EXPECT_EQ(*it,*it_mine);
     ++it_mine;
  }
}


TEST(erase, TEST_1){
  std::list<int> A{1,2,3,4,5,5,32,2,4,1,1,1,3};
  s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
  std::list<int>::iterator it = A.begin();
  s21::List<int>::ListIterator it_mine = B.Begin();
    A.erase(it);
    B.Erase(it_mine);
    it = A.begin();
    it_mine = B.Begin();
     for(; it != A.end();++it){
     EXPECT_EQ(*it,*it_mine);
     ++it_mine;
  }
    size_t mine = B.Size();
  size_t orig = A.size();
  EXPECT_EQ(mine,orig);
}

TEST(erase, TEST_2){

  s21::List<int>B{1,2,3,4,5,5,32,2,4,1,1,1,3};
  s21::List<int>::ListIterator it_mine = B.End();
  EXPECT_ANY_THROW(B.Erase(it_mine));

}









TEST(VectorTest, Constructor_default) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Data(), std_v.data());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());
}

TEST(VectorTest, Constructor_n) {
  s21::Vector<int> s21_v(5);
  std::vector<int> std_v(5);
  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());
}

TEST(VectorTest, Constructor_n_throw) {
  EXPECT_ANY_THROW(s21::Vector<int> s21_v(-1));
}

TEST(VectorTest, Constructor_initializer_list_1) {
  s21::Vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());
  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
  EXPECT_EQ(s21_v.At(3), std_v.at(3));
  EXPECT_EQ(s21_v.At(4), std_v.at(4));
  EXPECT_ANY_THROW(s21_v.At(-1));
}

TEST(VectorTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::Vector<int> s21_v{b};
  std::vector<int> std_v{b};
  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());
}

TEST(VectorTest, Constructor_copy_1) {
  s21::Vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  s21::Vector<int> s21_copy(s21_v);
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());
  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
  EXPECT_EQ(s21_v.At(3), std_v.at(3));
  EXPECT_EQ(s21_v.At(4), std_v.at(4));

  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
  EXPECT_EQ(s21_copy.At(0), std_copy.at(0));
  EXPECT_EQ(s21_copy.At(1), std_copy.at(1));
  EXPECT_EQ(s21_copy.At(2), std_copy.at(2));
  EXPECT_EQ(s21_copy.At(3), std_copy.at(3));
  EXPECT_EQ(s21_copy.At(4), std_copy.at(4));
}

TEST(VectorTest, Constructor_copy_2) {
  s21::Vector<int> s21_v;
  s21::Vector<int> s21_copy(s21_v);
  std::vector<int> std_v;
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());

  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(VectorTest, Constructor_move_1) {
  s21::Vector<int> s21_v;
  s21::Vector<int> s21_move(s21_v);
  std::vector<int> std_v;
  std::vector<int> std_move(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());

  EXPECT_EQ(s21_move.Size(), std_move.size());
  EXPECT_EQ(s21_move.Capacity(), std_move.capacity());
  EXPECT_EQ(s21_move.Empty(), std_move.empty());
}

TEST(VectorTest, Constructor_move_2) {
  s21::Vector<int> s21_v{1, 2, 3, 4, 5};
  s21::Vector<int> s21_move(s21_v);
  std::vector<int> std_v{1, 2, 3, 4, 5};
  std::vector<int> std_move(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.Empty(), std_v.empty());

  EXPECT_EQ(s21_move.Size(), std_move.size());
  EXPECT_EQ(s21_move.Capacity(), std_move.capacity());
  EXPECT_EQ(s21_move.Empty(), std_move.empty());
}

TEST(VectorTest, Destructor) {
  s21::Vector<int> s21_v{1, 2, 3, 4, 5};
  s21_v.Clear();
  EXPECT_EQ(0, s21_v.Size());
  EXPECT_EQ(0, s21_v.Capacity());
  EXPECT_EQ(0, s21_v.Data());
  s21::Vector<int> s2;
  s2.Emplace_back(1,2,3,45,6,7);
   s21::Vector<int>::VectorIterator iter = s2.Begin();
    s21::Vector<int>::VectorIterator iter2 = iter;
     s21::Vector<int>::VectorIterator iter3;
    EXPECT_TRUE(iter == iter2);
   EXPECT_EQ(1,*iter2);
}

TEST(VectorTest, Operator_move_1) {
  s21::Vector<int> s21_v1{1, 2, 3};
  s21::Vector<int> s21_v2;
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.Size(), 3);
  EXPECT_EQ(s21_v2.At(0), 1);
  EXPECT_EQ(s21_v2.At(1), 2);
  EXPECT_EQ(s21_v2.At(2), 3);
}

TEST(VectorTest, Operator_move_2) {
  s21::Vector<int> s21_v1{1, 2, 3};
  s21::Vector<int> s21_v2{4, 5, 6};
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.Size(), 3);
  EXPECT_EQ(s21_v2.At(0), 1);
  EXPECT_EQ(s21_v2.At(1), 2);
  EXPECT_EQ(s21_v2.At(2), 3);
}

TEST(VectorTest, Element_at) {
  s21::Vector<int> s21_v{1, 2, 3, 4, 5};
  std::vector<int> std_v{1, 2, 3, 4, 5};

  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
  EXPECT_EQ(s21_v.At(3), std_v.at(3));
  EXPECT_EQ(s21_v.At(4), std_v.at(4));
}

TEST(VectorTest, Element_at_throw) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.At(1));
  EXPECT_ANY_THROW(std_v.at(1));
}

TEST(VectorTest, Element_front) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.Front(), std_v.front());
}

TEST(VectorTest, Element_front_throw) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.Front());
}

TEST(VectorTest, Element_back) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.Back(), std_v.back());
}

TEST(VectorTest, Element_back_throw) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.Back());
}

TEST(VectorTest, Element_operator_square_brackets) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v[0], std_v[0]);
  EXPECT_EQ(s21_v[1], std_v[1]);
  EXPECT_EQ(s21_v[2], std_v[2]);
}

TEST(VectorTest, Element_operator_square_brackets_throw_1) {
  s21::Vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[5]);
}

TEST(VectorTest, Element_operator_square_brackets_throw_2) {
  s21::Vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[-1]);
}

TEST(VectorTest, Element_data) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(*s21_v.Data(), *std_v.data());
}

TEST(VectorTest, Capacity_empty_1) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.Empty(), std_v.empty());
}

TEST(VectorTest, Capacity_empty_2) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.Empty(), std_v.empty());
}

TEST(VectorTest, Capacity_size_1) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.Size(), std_v.size());
}

TEST(VectorTest, Capacity_size_2) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.Size(), std_v.size());
}

TEST(VectorTest, Capacity_capacity_1) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_capacity_2) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_1) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.Reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_2) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.Reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_3) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.Reserve(10);
  std_v.reserve(10);
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_4_throw) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v.Reserve(-2));
  EXPECT_ANY_THROW(std_v.reserve(-2));
}

TEST(VectorTest, Capacity_shrink_to_fit_1) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.Reserve(10);
  std_v.reserve(10);
  s21_v.ShrinkToFit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_shrink_to_fit_2) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.Reserve(10);
  std_v.reserve(10);
  s21_v.ShrinkToFit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());
}

TEST(VectorTest, Modifiers_clear_1) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.Clear();
  std_v.clear();

  EXPECT_EQ(s21_v.Size(), std_v.size());
}

TEST(VectorTest, Modifiers_clear_2) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.Clear();
  std_v.clear();

  EXPECT_EQ(s21_v.Size(), std_v.size());
}

TEST(VectorTest, Modifiers_insert_1) {
  s21::Vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.Insert(s21_v.Begin() + 1, 5);
  std_v.insert(std_v.begin() + 1, 5);

  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
}

TEST(VectorTest, Modifiers_insert_2) {
  s21::Vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.Insert(s21_v.Begin() + s21_v.Size(), 100);
  std_v.insert(std_v.begin() + std_v.size(), 100);

  EXPECT_EQ(s21_v.At(5), std_v.at(5));
}

TEST(VectorTest, Modifiers_insert_3) {
  try {
    s21::Vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.Insert(s21_v.Begin() + 10, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_insert_4) {
  try {
    s21::Vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.Insert(s21_v.Begin() - 4, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_erase_1) {
  s21::Vector<int> s21_v{1, 2, 3, 4};
  std::vector<int> std_v{1, 2, 3, 4};

  s21_v.Erase(s21_v.Begin() + 1);
  std_v.erase(std_v.begin() + 1);

  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
}

TEST(VectorTest, Modifiers_erase_2) {
  s21::Vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.Erase(s21_v.Begin());
  std_v.erase(std_v.begin());

  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
  EXPECT_EQ(s21_v.At(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_erase_3) {
  s21::Vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.Erase(s21_v.End() - 1);
  std_v.erase(std_v.end() - 1);

  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
  EXPECT_EQ(s21_v.At(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_erase_4) {
  try {
    s21::Vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.Erase(s21_v.Begin() - 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_erase_5) {
  try {
    s21::Vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.Erase(s21_v.End() + 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_push_back_1) {
  s21::Vector<int> s21_v;
  std::vector<int> std_v;

  s21_v.PushBack(2);
  s21_v.PushBack(3);
  s21_v.PushBack(4);
  s21_v.PushBack(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
  EXPECT_EQ(s21_v.At(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_push_back_2) {
  s21::Vector<int> s21_v{1, 2};
  std::vector<int> std_v{1, 2};

  s21_v.PushBack(2);
  s21_v.PushBack(3);
  s21_v.PushBack(4);
  s21_v.PushBack(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.At(0), std_v.at(0));
  EXPECT_EQ(s21_v.At(1), std_v.at(1));
  EXPECT_EQ(s21_v.At(2), std_v.at(2));
  EXPECT_EQ(s21_v.At(3), std_v.at(3));
  EXPECT_EQ(s21_v.At(4), std_v.at(4));
  EXPECT_EQ(s21_v.At(5), std_v.at(5));
}

TEST(VectorTest, Modifiers_pop_back_1) {
  s21::Vector<int> s21_v{1, 2};

  s21_v.PopBack();
  s21_v.PopBack();
  s21_v.PopBack();
  s21_v.PopBack();

  EXPECT_EQ(s21_v.Size(), 0);
  EXPECT_EQ(s21_v.Capacity(), 2);
}

TEST(VectorTest, Modifiers_pop_back_2) {
  s21::Vector<int> s21_v;

  s21_v.PopBack();
  s21_v.PopBack();
  s21_v.PopBack();
  s21_v.PopBack();

  EXPECT_EQ(s21_v.Size(), 0);
  EXPECT_EQ(s21_v.Capacity(), 0);
}

TEST(VectorTest, Modifiers_swap_1) {
  s21::Vector<int> s21_v;
  s21::Vector<int> s21_v_copy;

  std::vector<int> std_v;
  std::vector<int> std_v_copy;

  s21_v_copy.Swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.Size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.Capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_2) {
  s21::Vector<int> s21_v{1, 2, 3, 4};
  s21::Vector<int> s21_v_copy;

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy;

  s21_v_copy.Swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.Size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.Capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_3) {
  s21::Vector<int> s21_v{1, 2, 3, 4};
  s21::Vector<int> s21_v_copy{1, 2};

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy{1, 2};

  s21_v_copy.Swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.Size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.Capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_4) {
  s21::Vector<int> s21_v{1, 2, 3, 4};
  s21::Vector<int> s21_v_copy{1, 2, 3, 4, 5, 6};

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy{1, 2, 3, 4, 5, 6};

  s21_v_copy.Swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.Size(), std_v.size());
  EXPECT_EQ(s21_v.Capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.Size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.Capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Helpers_add_memotysize_1) {
  int n = 1000;
  s21::Vector<int> s21_v(n);
  s21_v.PushBack(1);
  EXPECT_EQ(s21_v.Size(), n + 1);
}

TEST(VectorTest, Helpers_add_memotysize_2) {
  int n = 10000;
  s21::Vector<int> s21_v(n);
  s21_v.PushBack(1);

  EXPECT_EQ(s21_v.Size(), n + 1);
}

TEST(VectorTest, Helpers_add_memotysize_3) {
  int n = 100000;
  s21::Vector<int> s21_v(n);
  s21_v.PushBack(1);
  s21_v.PushBack(1);
  s21_v.PushBack(1);

  EXPECT_EQ(s21_v.Size(), n + 3);
}
class Test_vector {
 public:
  s21::Vector<int> empty_Vector;
  s21::Vector<int> five_Vector{1, 2, 3, 4, 5};
  s21::Vector<int> four_Vector{1, 2, 3, 4};
  s21::Vector<char> char_Vector;
  s21::Vector<float> float_Vector;
  s21::Vector<double> double_Vector;
  std::vector<int> origin_five_vector{1, 2, 3, 4, 5};
  std::vector<int> origin_four_vector{1, 2, 3, 4};
  std::vector<int> origin_int;
  std::vector<char> origin_char;
  std::vector<float> origin_float;
  std::vector<double> origin_double;
  std::vector<int>::iterator it_origin = origin_five_vector.begin();
  s21::Vector<int> s21_vector_lesser{534789,   2479056, 987654, 110101024,
                                     62348710, 1,       35674};
  std::vector<int> std_vector_lesser{534789,   2479056, 987654, 110101024,
                                     62348710, 1,       35674};
  s21::Vector<int> s21_vector_copy_lesser{1, 2};
  std::vector<int> std_vector_copy_lesser{1, 2};
  s21::Vector<int> s21_vector_copy_larger{9, 8, 7, 6, 5, 4, 3};
  std::vector<int> std_vector_copy_larger{9, 8, 7, 6, 5, 4, 3};
  s21::Vector<int> s21_vector_larger{1, 2};
  std::vector<int> std_vector_larger{1, 2};
  s21::Vector<int> s21_vector_ass{-333, -999, 123, 11765, 3};
  std::vector<int> std_vector_ass{-333, -999, 123, 11765, 3};
  s21::Vector<int> s21_vector_move{1, 2};
  std::vector<int> std_vector_move{1, 2};
  s21::Vector<int> s21_vector_s{111, 222, 333, 444, 555};
  std::vector<int> std_vector_s{111, 222, 333, 444, 555};
  s21::Vector<int> s21_vector_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
};

TEST(Vector, constructor_default) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.Size(), logger.origin_int.size());
  EXPECT_EQ(logger.empty_Vector.Capacity(), logger.origin_int.capacity());
  EXPECT_EQ(logger.empty_Vector.Empty(), logger.origin_int.empty());
}

TEST(Vector, constructor_init) {
  s21::Vector<int> s21_vector(3);
  std::vector<int> std_vector(3);
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, constructor_initializer_lit) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector[0], logger.origin_five_vector[0]);
  EXPECT_EQ(logger.five_Vector[4], logger.origin_five_vector[4]);
  EXPECT_EQ(logger.five_Vector.Size(), logger.origin_five_vector.size());
  EXPECT_EQ(logger.five_Vector.Capacity(),logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.Empty(), logger.origin_five_vector.empty());
}

TEST(Vector, constructor_copy_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(logger.empty_Vector);
  std::vector<int> std_copy(logger.origin_int);
  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, constructor_copy_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(logger.five_Vector);
  std::vector<int> std_copy(logger.origin_five_vector);
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.Size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, constructor_move_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(std::move(logger.five_Vector));
  std::vector<int> std_copy(std::move(logger.origin_five_vector));
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.Size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, constructor_move_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy(std::move(logger.empty_Vector));
  std::vector<int> std_copy(std::move(logger.origin_int));
  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, operator_copy_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = logger.empty_Vector;
  std_copy = logger.origin_int;
  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, operator_copy_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = logger.five_Vector;
  std_copy = logger.origin_five_vector;
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.Size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, operator_move_not_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = std::move(logger.five_Vector);
  std_copy = std::move(logger.origin_five_vector);
  EXPECT_EQ(s21_copy[0], std_copy[0]);
  EXPECT_EQ(s21_copy[s21_copy.Size() - 1], std_copy[std_copy.size() - 1]);
  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, operator_move_empty) {
  Test_vector logger;
  s21::Vector<int> s21_copy;
  std::vector<int> std_copy;
  s21_copy = std::move(logger.empty_Vector);
  std_copy = std::move(logger.origin_int);

  EXPECT_EQ(s21_copy.Size(), std_copy.size());
  EXPECT_EQ(s21_copy.Capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.Empty(), std_copy.empty());
}

TEST(Vector, copy_assignment_lesser_buffer) {
  Test_vector logger;
  logger.s21_vector_copy_lesser = logger.s21_vector_lesser;
  logger.std_vector_copy_lesser = logger.std_vector_lesser;
  EXPECT_EQ(logger.s21_vector_copy_lesser[0], logger.std_vector_copy_lesser[0]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[1], logger.std_vector_copy_lesser[1]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[2], logger.std_vector_copy_lesser[2]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[3], logger.std_vector_copy_lesser[3]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[4], logger.std_vector_copy_lesser[4]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[5], logger.std_vector_copy_lesser[5]);
  EXPECT_EQ(logger.s21_vector_copy_lesser[6], logger.std_vector_copy_lesser[6]);
  EXPECT_EQ(logger.s21_vector_copy_lesser.Size(),
            logger.std_vector_copy_lesser.size());
  EXPECT_EQ(logger.s21_vector_copy_lesser.Capacity(),
            logger.std_vector_copy_lesser.capacity());
  EXPECT_EQ(logger.s21_vector_copy_lesser.Empty(),
            logger.std_vector_copy_lesser.empty());
}

TEST(Vector, copy_assignment_larger_buffer) {
  Test_vector logger;
  logger.s21_vector_copy_larger = logger.s21_vector_copy_larger;
  logger.std_vector_copy_larger = logger.std_vector_copy_larger;
  EXPECT_EQ(logger.s21_vector_copy_larger[0], logger.std_vector_copy_larger[0]);
  EXPECT_EQ(logger.s21_vector_copy_larger[1], logger.std_vector_copy_larger[1]);
  EXPECT_EQ(logger.s21_vector_copy_larger.Size(),
            logger.std_vector_copy_larger.size());
  EXPECT_EQ(logger.s21_vector_copy_larger.Capacity(),
            logger.std_vector_copy_larger.capacity());
  EXPECT_EQ(logger.s21_vector_copy_larger.Empty(),
            logger.std_vector_copy_larger.empty());
}

TEST(Vector, move_assigment) {
  Test_vector logger;
  logger.s21_vector_move = std::move(logger.s21_vector_ass);
  logger.std_vector_move = std::move(logger.std_vector_ass);
  EXPECT_EQ(logger.s21_vector_move[0], logger.std_vector_move[0]);
  EXPECT_EQ(logger.s21_vector_move[1], logger.std_vector_move[1]);
  EXPECT_EQ(logger.s21_vector_move[2], logger.std_vector_move[2]);
  EXPECT_EQ(logger.s21_vector_move[3], logger.std_vector_move[3]);
  EXPECT_EQ(logger.s21_vector_move[4], logger.std_vector_move[4]);
  EXPECT_EQ(logger.s21_vector_move.Size(), logger.std_vector_move.size());
  EXPECT_EQ(logger.s21_vector_move.Capacity(),
            logger.std_vector_move.capacity());
  EXPECT_EQ(logger.s21_vector_move.Empty(), logger.std_vector_move.empty());
  EXPECT_EQ(logger.s21_vector_ass.Size(), logger.std_vector_ass.size());
  EXPECT_EQ(logger.s21_vector_ass.Capacity(), logger.std_vector_ass.capacity());
  EXPECT_EQ(logger.s21_vector_ass.Empty(), logger.std_vector_ass.empty());
}

TEST(Vector, function_at) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.At(0), logger.origin_five_vector.at(0));
  EXPECT_EQ(logger.five_Vector.At(1), logger.origin_five_vector.at(1));
  EXPECT_EQ(logger.five_Vector.At(2), logger.origin_five_vector.at(2));
  EXPECT_EQ(logger.five_Vector.At(3), logger.origin_five_vector.at(3));
}

TEST(Vector, operator_square) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector[0], logger.origin_five_vector[0]);
  EXPECT_EQ(logger.five_Vector[1], logger.origin_five_vector[1]);
  EXPECT_EQ(logger.five_Vector[2], logger.origin_five_vector[2]);
  EXPECT_EQ(logger.five_Vector[3], logger.origin_five_vector[3]);
}

TEST(Vector, function_front) {
  Test_vector logger;
  EXPECT_EQ(logger.origin_five_vector.front(), logger.five_Vector.Front());
}

TEST(Vector, function_back) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.Back(), logger.origin_five_vector.back());
}

TEST(Vector, iterator_element_access) {
  s21::Vector<char> s21_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  std::vector<char> std_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  s21::Vector<char>::iterator s21_it = s21_vector.Begin();
  std::vector<char>::iterator std_it = std_vector.begin();
  while (s21_it != s21_vector.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(vector_iterator_suit, const_iterator_element_access) {
  s21::Vector<char> s21_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  std::vector<char> std_vector{'p', 'e', 'r', 'f', 'o',
                               'r', 'a', 't', 'o', 'r'};
  s21::Vector<char>::const_iterator s21_it = s21_vector.Begin();
  std::vector<char>::const_iterator std_it = std_vector.begin();
  while (s21_it != s21_vector.End()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(Vector, function_data) {
  Test_vector logger;
  EXPECT_EQ(*logger.five_Vector.Data(), *logger.origin_five_vector.data());
}

TEST(Vector, function_data_e) {
  s21::Vector<char> s21_vector_empty;
  std::vector<char> std_vector_empty;
  EXPECT_EQ(s21_vector_empty.Data(), nullptr);
  EXPECT_EQ(std_vector_empty.data(), nullptr);
  s21::Vector<char> s21_vector{'L', 'I', 'Z', 'A'};
  std::vector<char> std_vector{'L', 'I', 'Z', 'A'};
  EXPECT_NE(s21_vector.Data(), nullptr);
  EXPECT_NE(std_vector.data(), nullptr);
}

TEST(Vector, function_insert_begin) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.Insert(s21_it, 665);
  std_it = std_vector.insert(std_it, 665);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.At(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.At(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_insert_mid) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = s21_vector.Insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.At(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.At(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_insert_end) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.End();
  std::vector<int>::iterator std_it = std_vector.end();
  s21_it = s21_vector.Insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.At(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.At(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_insert_multi) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.Insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = s21_vector.Insert(s21_it, 666);
  std_it = std_vector.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.At(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.At(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.At(7), std_vector.at(7));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_erase_begin) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_vector.Erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_erase_mid) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_vector.Erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_erase_end) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.End() - 1;
  std::vector<int>::iterator std_it = std_vector.end() - 1;
  s21_vector.Erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_erase_multi) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_vector.Erase(s21_it);
  std_vector.erase(std_it);
  s21_it = s21_vector.Begin();
  std_it = std_vector.begin();
  s21_vector.Erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, empty_testing) {
  Test_vector logger;
  EXPECT_FALSE(logger.five_Vector.Empty());
  EXPECT_TRUE(logger.empty_Vector.Empty());
}

TEST(Vector, size_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.empty_Vector.Size(), 0);
  EXPECT_EQ(logger.five_Vector.Size(), 5);
}

TEST(Vector, reserve_testing) {
  Test_vector logger;
  logger.five_Vector.Reserve(2);
  logger.origin_five_vector.reserve(2);
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.Reserve(1000);
  logger.origin_five_vector.reserve(1000);
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.Reserve(0);
  logger.origin_five_vector.reserve(0);
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
         EXPECT_ANY_THROW(logger.five_Vector.Reserve(-1));
}

TEST(Vector, capacity_testing) {
  Test_vector logger;
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.PushBack(3);
  logger.origin_five_vector.push_back(4);
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
  logger.five_Vector.PopBack();
  logger.origin_five_vector.pop_back();
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
}

TEST(Vector, shrink_to_fit_testing) {
  Test_vector logger;
  logger.five_Vector.Reserve(3);
  logger.origin_five_vector.reserve(3);
  logger.five_Vector.ShrinkToFit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.Size(), logger.origin_five_vector.size());
  logger.five_Vector.Reserve(100);
  logger.origin_five_vector.reserve(100);
  logger.five_Vector.ShrinkToFit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.Size(), logger.origin_five_vector.size());
  logger.five_Vector.Reserve(0);
  logger.origin_five_vector.reserve(0);
  logger.five_Vector.ShrinkToFit();
  logger.origin_five_vector.shrink_to_fit();
  EXPECT_EQ(logger.five_Vector.Capacity(),
            logger.origin_five_vector.capacity());
  EXPECT_EQ(logger.five_Vector.Size(), logger.origin_five_vector.size());
}


TEST(Vector, function_swap) {
  Test_vector logger;
  logger.s21_vector_s.Swap(logger.s21_vector_swap);
  logger.std_vector_s.swap(logger.std_vector_swap);
  EXPECT_EQ(logger.s21_vector_swap.At(0), logger.std_vector_swap.at(0));
  EXPECT_EQ(logger.s21_vector_swap.At(1), logger.std_vector_swap.at(1));
  EXPECT_EQ(logger.s21_vector_swap.At(2), logger.std_vector_swap.at(2));
  EXPECT_EQ(logger.s21_vector_swap.At(3), logger.std_vector_swap.at(3));
  EXPECT_EQ(logger.s21_vector_swap.At(4), logger.std_vector_swap.at(4));
  EXPECT_EQ(logger.s21_vector_swap.Size(), logger.std_vector_swap.size());
  EXPECT_EQ(logger.s21_vector_swap.Capacity(),
            logger.std_vector_swap.capacity());
  EXPECT_EQ(logger.s21_vector_s.At(0), logger.std_vector_s.at(0));
  EXPECT_EQ(logger.s21_vector_s.At(1), logger.std_vector_s.at(1));
  EXPECT_EQ(logger.s21_vector_s.At(2), logger.std_vector_s.at(2));
  EXPECT_EQ(logger.s21_vector_s.At(3), logger.std_vector_s.at(3));
  EXPECT_EQ(logger.s21_vector_s.At(4), logger.std_vector_s.at(4));
  EXPECT_EQ(logger.s21_vector_s.At(5), logger.std_vector_s.at(5));
  EXPECT_EQ(logger.s21_vector_s.At(6), logger.std_vector_s.at(6));
  EXPECT_EQ(logger.s21_vector_s.At(7), logger.std_vector_s.at(7));
  EXPECT_EQ(logger.s21_vector_s.At(8), logger.std_vector_s.at(8));
  EXPECT_EQ(logger.s21_vector_s.At(9), logger.std_vector_s.at(9));
  EXPECT_EQ(logger.s21_vector_s.Size(), logger.std_vector_s.size());
  EXPECT_EQ(logger.s21_vector_s.Capacity(), logger.std_vector_s.capacity());
  EXPECT_EQ(logger.s21_vector_s.Empty(), logger.std_vector_s.empty());
}

TEST(Vector, function_push_back) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.PushBack(666);
  std_vector.push_back(666);
  s21_vector.PushBack(123);
  std_vector.push_back(123);
  ASSERT_EQ(s21_vector.At(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.At(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.At(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.At(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.At(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.Size(), std_vector.size());
  ASSERT_EQ(s21_vector.Capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_pop_back) {
  s21::Vector<int> s21_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.PopBack();
  std_vector.pop_back();
  s21_vector.PopBack();
  std_vector.pop_back();
  ASSERT_EQ(s21_vector.At(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.At(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.At(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.At(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.At(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.At(5), std_vector.at(5));
  ASSERT_EQ(s21_vector.At(6), std_vector.at(6));
  ASSERT_EQ(s21_vector.At(7), std_vector.at(7));
  ASSERT_EQ(s21_vector.Size(), std_vector.size());
  ASSERT_EQ(s21_vector.Capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_reserve) {
  s21::Vector<double> s21_vector_empty;
  std::vector<double> std_vector_empty;
  s21_vector_empty.Reserve(100);
  std_vector_empty.reserve(100);
  ASSERT_EQ(s21_vector_empty.Size(), std_vector_empty.size());
  ASSERT_EQ(s21_vector_empty.Capacity(), std_vector_empty.capacity());
  ASSERT_EQ(s21_vector_empty.Empty(), std_vector_empty.empty());
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.Reserve(50);
  std_vector.reserve(50);
  ASSERT_EQ(s21_vector.At(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.At(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.At(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.Size(), std_vector.size());
  ASSERT_EQ(s21_vector.Capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_shrink_to_fit) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.Reserve(50);
  std_vector.reserve(50);
  s21_vector.ShrinkToFit();
  std_vector.shrink_to_fit();
  ASSERT_EQ(s21_vector.At(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.At(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.At(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.Size(), std_vector.size());
  ASSERT_EQ(s21_vector.Capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector.Empty(), std_vector.empty());
}

TEST(Vector, function_emplace_begin) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.Emplace(s21_it, 665);
  std_it = std_vector.emplace(std_it, 665);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.At(5), std_vector.at(5));
  EXPECT_EQ(s21_vector.At(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}


TEST(Vector, function_emplace_no) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 9, 10};
  std::vector<int> std_vector{1, 2, 3, 5, 9, 10};
  s21::Vector<int>::iterator s21_it = s21_vector.Begin();
  // std::vector<int>::iterator std_it = std_vector.begin();
  s21_it = s21_vector.Emplace(s21_it);
  // EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_vector.At(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.At(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.At(2), std_vector.at(2));
  EXPECT_EQ(s21_vector.At(3), std_vector.at(3));
  EXPECT_EQ(s21_vector.At(4), std_vector.at(4));
  EXPECT_EQ(s21_vector.At(5), std_vector.at(5));
  // EXPECT_EQ(s21_vector.At(6), std_vector.at(6));
  EXPECT_EQ(s21_vector.Size(), std_vector.size());
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.Empty(), std_vector.empty());
}






















// // STACK
TEST(StackTest, Constructor_default) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.Size(), std_stack.size());
}

TEST(StackTest, Constructor_initializer_list_1) {
  s21::Stack<int> s21_stack{1, 2, 4};
   EXPECT_EQ(s21_stack.Size(), 3);
  EXPECT_EQ(s21_stack.Top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::Stack<int> s21_stack{b};
  std::stack<int> std_stack{b};

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
}

TEST(StackTest, Constructor_copy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_copy{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.Size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.Top(), std_stack_copy.top());
}

TEST(StackTest, Constructor_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.Size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.Top(), std_stack_move.top());
}

TEST(StackTest, Opertator_move_1) {
  std::initializer_list<int> il1 = {1, 2,3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());
}

TEST(StackTest, Opertator_move_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());
}

TEST(StackTest, Opertator_move_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());
}

TEST(StackTest, Top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};

  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.Top(), std_stack.top());
}

TEST(StackTest, Top_2_throw) {
  std::initializer_list<int> il1;

  s21::Stack<int> s21_stack{il1};

  EXPECT_THROW(s21_stack.Top(), std::out_of_range);
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.Empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.Empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.Push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.Push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.Pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());
}

TEST(StackTest, Pop_2) {
  std::initializer_list<int> il1;

  s21::Stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.Pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.Size(), 0);
}

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.Swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.Size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.Top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.Swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.Size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.Top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.Swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.Size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.Swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.Size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.Swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.Size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::Stack<int> s21_stack{il1};
  s21::Stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.Swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.Size(), std_stack.size());
  EXPECT_EQ(s21_stack.Top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.Size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.Top(), std_stack_swap.top());
}
TEST(StackTest, Emplace) {
         s21::Stack<int> s1;
        s1.EmplaceFront(2, 3, 5);
   

  EXPECT_EQ(s1.Top(),5);
  s1.Pop();
    EXPECT_EQ(s1.Top(),3);
  s1.Pop();
    EXPECT_EQ(s1.Top(),2);
  s1.Pop();
}

TEST(StackTest, Move) {
         s21::Stack<int> s1{1,2,3,4,5,6};
         s21::Stack<int> s2{6,5,4,3,2,1};
     s2 = (std::move(s1));
          
  EXPECT_EQ(s2.Top(),6);
  s2.Pop();
    EXPECT_EQ(s2.Top(),5);
  s2.Pop();
    EXPECT_EQ(s2.Top(),4);
  s2.Pop();
 EXPECT_EQ(s1.Size(), 0);

  s21::Stack<int> s3{1,2,3,4,5,6};
  s21::Stack<int> s4(std::move(s3));
  EXPECT_EQ(s4.Top(),6);
  s4.Pop();
    EXPECT_EQ(s4.Top(),5);
  s4.Pop();
    EXPECT_EQ(s4.Top(),4);
  s4.Pop();

 EXPECT_EQ(s3.Size(), 0);
}


// LIST



 template <class T>
bool compare(s21::List<T> my_list,std::list<T> std_list){
bool result = true;
  if (my_list.Size() == std_list.size()) {
     s21::List<int>::ListIterator iterA = my_list.Begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.Size(); ++i) {
      if (*iterA != *std_it) {
        result = false;
        break;
      }
      ++iterA;
      std_it++;
    }
  } else {
    result = false;
  }
  return result;
}



TEST(ListTest, CompareLists) {
  s21::List<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  EXPECT_TRUE(compare(my_list, std_list));
  std_list.push_back(6);
  EXPECT_FALSE(compare(my_list, std_list));
  std_list.pop_back();
  my_list.PushFront(0);
  std_list.push_front(0);
  EXPECT_TRUE(compare(my_list, std_list));
}


TEST(ListTest, DefaultConstructor) {
  s21::List<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.Size(), 0);
  EXPECT_TRUE(my_list.Empty());

  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, SizeConstructor) {
  s21::List<int> my_list(1000000);
  std::list<int> std_list(1000000);
  EXPECT_EQ(my_list.Size(), 1000000);
  bool result = true;
  if (my_list.Size() == std_list.size()) {
  s21::List<int>::ListIterator iterA = my_list.Begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.Size(); ++i) {
      if (*iterA != *std_it) {
        result = false;
        break;
      }
      ++iterA;
      std_it++;
    }
  } else {
    result = false;
  }
  EXPECT_TRUE(result);
}

TEST(ListTest, SizeConstructorThrow) {

    s21::List<int> my_list(-1);
   EXPECT_EQ(my_list.Size(), 0);
}

TEST(ListTest, InitializerListConstructor) {
  s21::List<int> my_list{1, 2, 3, 7, 9};
  std::list<int> std_list{1, 2, 3, 7, 9};

 bool result = true;
  if (my_list.Size() == std_list.size()) {
  s21::List<int>::ListIterator iterA = my_list.Begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.Size(); ++i) {
      if (*iterA != *std_it) {
        result = false;
        break;
      }
      ++iterA;
      std_it++;
    }
  } else {
    result = false;
  }

  EXPECT_TRUE(result);
}

TEST(ListTest, InitializerListConstructor_2) {
  std::initializer_list<int> b{1,2,3,5,7,45,3,2};
  s21::List<int> my_list{b};
  std::list<int> std_list{b};

   bool result = true;
  if (my_list.Size() == std_list.size()) {
  s21::List<int>::ListIterator iterA = my_list.Begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.Size(); ++i) {
      if (*iterA != *std_it) {
        result = false;
        break;
      }
      ++iterA;
      std_it++;
    }
  } else {
    result = false;
  }
  EXPECT_TRUE(result);
}

TEST(ListTest, CopyConstructor) {
  s21::List<int> my_list{1, 2, 3};
  s21::List<int> my_list_copy(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);

   bool result = true;
  if (my_list.Size() == std_list.size()) {
  s21::List<int>::ListIterator iterA = my_list.Begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.Size(); ++i) {
      if (*iterA != *std_it) {
        result = false;
        break;
      }
      ++iterA;
      std_it++;
    }
  } else {
    result = false;
  }

  EXPECT_TRUE(result);
}


TEST(ListTest, CopyConstructorEmpty) {
  s21::List<int> my_list;
  s21::List<int> my_list_copy(my_list);
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
     bool result = true;
  if (my_list.Size() == std_list.size()) {
  s21::List<int>::ListIterator iterA = my_list.Begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.Size(); ++i) {
      if (*iterA != *std_it) {
        result = false;
        break;
      }
      ++iterA;
      std_it++;
    }
  } else {
    result = false;
  }
  EXPECT_TRUE(result);
}

TEST(ListTest, MoveConstructor) {
  s21::List<int> my_list{1, 2, 3};
  s21::List<int> my_list_copy(my_list);
  s21::List<int> my_list_move(std::move(my_list));
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveConstructorEmpty) {
  s21::List<int> my_list;
  s21::List<int> my_list_copy(my_list);
  s21::List<int> my_list_move(std::move(my_list));
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveAssignmentOperator) {
  s21::List<int> my_list{1, 2, 3};
  s21::List<int> my_list_copy(my_list);
  s21::List<int> my_list_move = std::move(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare(my_list_move, std_list_move));
}

TEST(ListTest, MoveAssignmentOperatorEmpty) {
  s21::List<int> my_list;
  s21::List<int> my_list_copy(my_list);
  s21::List<int> my_list_move = std::move(my_list);
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare(my_list_move, std_list_move));
}

TEST(ListTest, Front) {
  s21::List<int> my_list{99, 2, 3, 4, 5};
  std::list<int> std_list{99, 2, 3, 4, 5};
  EXPECT_EQ(my_list.Front(), std_list.front());
}

TEST(ListTest, Back) {
  s21::List<int> my_list{1, 2, 3, 4, 99};
  std::list<int> std_list{1, 2, 3, 4, 99};
  EXPECT_EQ(my_list.Back(), std_list.back());
}

TEST(ListTest, Empty) {
  s21::List<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.Empty(), std_list.empty());
  my_list.PushBack(10);
  std_list.push_back(10);
  EXPECT_EQ(my_list.Empty(), std_list.empty());
}

TEST(ListTest, Size) {
  s21::List<int> my_list{1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(my_list.Size(), std_list.size());
}

TEST(ListTest, SizeEmpty) {
  s21::List<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.Size(), std_list.size());
}


TEST(ListTest, Clear) {
  s21::List<int> my_list{1, 2, 3, 4};
  my_list.Clear();
  std::list<int> std_list{1, 2, 5, 4, 3};
  std_list.clear();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, ClearEmpty) {
  s21::List<int> my_list;
  my_list.Clear();
  std::list<int> std_list;
  std_list.clear();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, PushBack) {
  s21::List<int> my_list{1, 2, 3, 4, 5};
  my_list.PushBack(6);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_back(6);
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, PopBack) {
  s21::List<int> my_list{1, 2, 3, 4, 5};
  my_list.PopBack();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_back();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, PushFront) {
  s21::List<int> my_list{1, 2, 3, 4, 5};
  my_list.PushFront(0);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_front(0);
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, PopFront) {
  s21::List<int> my_list{1, 2, 3, 4, 5};
  my_list.PopFront();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_front();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, Swap) {
  s21::List<int> my_list1{1, 2, 3, 4, 5};
  s21::List<int> my_list2{6, 7, 8, 9, 10, 11};
  my_list1.Swap(my_list2);

  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{6, 7, 8, 9, 10, 11};
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare(my_list1, std_list1));
  EXPECT_TRUE(compare(my_list2, std_list2));
}

TEST(ListTest, Swap_2) {
  s21::List<int> my_list1{1, 5, 8, 100};
  s21::List<int> my_list2;
  my_list1.Swap(my_list2);

  std::list<int> std_list1{1, 5, 8, 100};
  std::list<int> std_list2;
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare(my_list1, std_list1));
  EXPECT_TRUE(compare(my_list2, std_list2));
}

TEST(ListTest, begin_1) {
  s21::List<int> my_list1{500, 15000, 30000};
  s21::List<int>::ListIterator first = my_list1.Begin();
  std::list<int> std_list2{500, 15000, 30000};
   EXPECT_EQ(*first, *std_list2.begin());
}

TEST(ListTest, begin_2) {
  s21::List<int> my_list1(4);

  std::list<int> std_list2(4);
    s21::List<int>::ListIterator first = my_list1.Begin();
  EXPECT_EQ(*first, *std_list2.begin());
}

TEST(ListTest, begin_3_throw) {
  s21::List<int> my_list1;
  std::list<int> std_list2;
  s21::List<int>::ListIterator first = my_list1.Begin();
  EXPECT_EQ(*first, 0);
}

TEST(ListTest, end_1) {
  s21::List<int> my_list1{500, 15000, 30000};
  s21::List<int>::ListIterator first = my_list1.End();
  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*first, *std_list2.end());
}

TEST(ListTest, end_2) {
  s21::List<int> my_list1(4);
  s21::List<int>::ListIterator first = my_list1.End();
  std::list<int> std_list2(4);
  EXPECT_EQ(*first, *std_list2.end());
}

TEST(ListTest, end_3) {
  s21::List<int> my_list1;
  s21::List<int>::ListIterator first = my_list1.End();
  std::list<int> std_list2;
  EXPECT_EQ(*first, *std_list2.end());
}

TEST(ListTest, Merge_1) {
  s21::List<int> my_list1{1, 9999, 20000};
  s21::List<int> my_list2{500, 15000, 30000};
  my_list1.Merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.merge(std_list2);
      
        EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Merge_2) {
  s21::List<int> my_list1{1, 9999, 20000};
  s21::List<int> my_list2{15000, 30000};
  my_list1.Merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Merge_3) {
  s21::List<int> my_list1{1, 20000, 666};
  s21::List<int> my_list2{15000, 154, 124,3000};
  my_list1.Merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2{15000, 154, 124,3000};
  std_list1.merge(std_list2);

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Merge_4) {
  s21::List<int> my_list1;
  s21::List<int> my_list2{15000, 154, 124, 30000};
  my_list1.Merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{15000, 154, 124, 30000};
  std_list1.merge(std_list2);
           
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Merge_5) {
  s21::List<int> my_list1{1, 20000, 666};
  s21::List<int> my_list2;
  my_list1.Merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Merge_6) {
  s21::List<int> my_list1;
  s21::List<int> my_list2;
  my_list1.Merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Reverse_1) {
  s21::List<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_list.Reverse();
  std_list.reverse();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, Reverse_2) {
  s21::List<int> my_list(4);
  std::list<int> std_list(4);
  my_list.Reverse();
  std_list.reverse();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, Reverse_3) {
  s21::List<int> my_list;
  std::list<int> std_list;
  my_list.Reverse();
  std_list.reverse();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, Unique_1) {
  s21::List<int> my_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  my_list.Unique();
  std_list.unique();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, Unique_2) {
  s21::List<int> my_list(3);
  std::list<int> std_list(3);
  my_list.Unique();
  std_list.unique();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, Unique_3) {
  s21::List<int> my_list;
  std::list<int> std_list;
  my_list.Unique();
  std_list.unique();
  EXPECT_TRUE(compare(my_list, std_list));
}

TEST(ListTest, Splice_1) {
  s21::List<int> my_list1{1, 9999, 20000};
  s21::List<int> my_list2{500, 15000, 30000};

  my_list1.Splice(my_list1.Begin(), my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Splice_2) {
  s21::List<int> my_list1;
  s21::List<int> my_list2{500, 15000, 30000};
  my_list1.Splice(my_list1.Begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Splice_3) {
  s21::List<int> my_list1{1, 9999, 20000};
  s21::List<int> my_list2;
  
  my_list1.Splice(my_list1.Begin(), my_list2); 

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Splice_4) {
  s21::List<int> my_list1;
  s21::List<int> my_list2;
  my_list1.Splice(my_list1.Begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Insert_1) {
  s21::List<int> my_list1{1, 9999, 20000};
  my_list1.Insert(my_list1.Begin(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Insert_2) {
  s21::List<int> my_list1{1, 9999, 20000};
  my_list1.Insert(my_list1.End(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Insert_3) {
  s21::List<int> my_list1;
  my_list1.Insert(my_list1.Begin(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Insert_4) {
  s21::List<int> my_list1;
  my_list1.Insert(my_list1.End(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Insert_5) {
  s21::List<int> my_list1(4);
  my_list1.Insert(my_list1.Begin(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Insert_6) {
  s21::List<int> my_list1(4);
  my_list1.Insert(my_list1.End(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Erase_1) {
  s21::List<int> my_list1{1, 9999, 20000};
  my_list1.Erase(my_list1.Begin());

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.begin());

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Erase_2_throw) {
  s21::List<int> my_list1{1, 9999, 20000};

  EXPECT_THROW(my_list1.Erase(my_list1.End()), std::invalid_argument);
}

TEST(ListTest, Erase_3) {
  s21::List<int> my_list1{1, 9999, 20000};
  s21::List<int>::ListIterator id = my_list1.End();
  my_list1.Erase(--id);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare(my_list1, std_list1));
}

TEST(ListTest, Erase_4_throw) {
  s21::List<int> my_list1;

  EXPECT_THROW(my_list1.Erase(my_list1.End()), std::invalid_argument);
}

TEST(ListTest, Erase_5) {
  s21::List<int> my_list1(5);
  s21::List<int>::ListIterator id = my_list1.End();
  my_list1.Erase(--id);

  std::list<int> std_list1(5);
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare(my_list1, std_list1));
}

// // // QUEUE

template <typename T>
bool compare_queues(s21::Queue<T> my_queue,
                    std::queue<T> std_queue) {
  bool result = true;
  if (my_queue.Size() == std_queue.size()) {
    while (!my_queue.Empty() && !std_queue.empty()) {
      if (my_queue.Front() != std_queue.front()) {
        result = false;
        break;
      }
      my_queue.Pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(QueueTest, CompareQueues) {
  s21::Queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, DefaultConstructor) {
  s21::Queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.Size(), 0);
  EXPECT_TRUE(my_queue.Empty());
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  s21::Queue<int> my_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  s21::Queue<int> my_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  s21::Queue<int> my_queue{1, 2, 3, 7, 9};
  s21::Queue<int> my_queue_copy(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorEmpty) {
  s21::Queue<int> my_queue;
  s21::Queue<int> my_queue_copy(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  s21::Queue<int> my_queue{1, 2, 3, 7, 20};
  s21::Queue<int> my_queue_copy(my_queue);
  s21::Queue<int> my_queue_move(std::move(my_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructorEmpty) {
  s21::Queue<int> my_queue;
  s21::Queue<int> my_queue_copy(my_queue);
  s21::Queue<int> my_queue_move(std::move(my_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::Queue<int> my_queue{1, 2, 3, 7, 20};
  s21::Queue<int> my_queue_copy(my_queue);
  s21::Queue<int> my_queue_move = std::move(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentOperatorEmpty) {
  s21::Queue<int> my_queue;
  s21::Queue<int> my_queue_copy(my_queue);
  s21::Queue<int> my_queue_move = std::move(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, Front) {
  s21::Queue<int> my_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.Front(), std_queue.front());
}

TEST(QueueTest, Back) {
  s21::Queue<int> my_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.Back(), std_queue.back());
}

TEST(QueueTest, Empty) {
  s21::Queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.Empty(), std_queue.empty());
  my_queue.Push(2354);
  std_queue.push(2354);
  EXPECT_EQ(my_queue.Empty(), std_queue.empty());
}

TEST(QueueTest, Size) {
  s21::Queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.Size(), std_queue.size());
}

TEST(QueueTest, Push) {
  s21::Queue<int> my_queue;
  std::queue<int> std_queue;
  my_queue.Push(627);
  std_queue.push(627);
  my_queue.Push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, Pop) {
  s21::Queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.Pop();
  my_queue.Pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  EXPECT_EQ(my_queue.Front(), 3);
}

TEST(QueueTest, Swap) {
  s21::Queue<int> my_queue1{1, 2, 3, 4, 5};
  s21::Queue<int> my_queue2{6, 7, 8, 9, 10, 11};
  my_queue1.Swap(my_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}


TEST(QueueTest, emplace_back) {
  s21::Queue<int> my_queue1{17,40,32};
  s21::Queue<int> my_queue2;
  my_queue2 = (std::move(my_queue1));
     my_queue2.EmplaceBack(1,2,3,4,5,67,8);
    EXPECT_EQ(my_queue2.Front() , 17);
       EXPECT_EQ(my_queue2.Back() , 8);
}


TEST(QueueTest, Swap_2) {
  s21::Queue<int> my_queue1{1, 2, 99, 4, 242};
  s21::Queue<int> my_queue2;
  my_queue1.Swap(my_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}


// ////set


TEST(setTest, DefaultConstructor) {
  s21::Set<int> s;
  EXPECT_TRUE(s.Empty());
  EXPECT_EQ(s.Size(), 0);
}

TEST(setTest, InitializerListConstructor) {
  s21::Set<int> s = {1, 2, 3};
  EXPECT_EQ(s.Size(), 3);
   EXPECT_TRUE(s.Contains(1));
  EXPECT_TRUE(s.Contains(2));
  EXPECT_TRUE(s.Contains(3));
}

TEST(setTest, CopyConstructor) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s2(s1);
  s1.Clear();
  s2.Clear();

  EXPECT_EQ(s1.Size(), s2.Size());
}

 TEST(set, function_emplace) {
        s21::Set<int> s1;
        auto it1 = s1.Emplace(2, 3, 5);
        EXPECT_EQ(*it1[0].first, 2);
        EXPECT_EQ(*it1[1].first, 3);
        EXPECT_EQ(*it1[2].first, 5);
}

TEST(setTest, MoveConstructor) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s2(std::move(s1));
  EXPECT_EQ(s2.Size(), 3);
  EXPECT_TRUE(s2.Contains(1));
  EXPECT_TRUE(s2.Contains(2));
  EXPECT_TRUE(s2.Contains(3));

   EXPECT_EQ(s1.Size(), 0);
   EXPECT_FALSE(s1.Contains(1));
}

TEST(setTest, MoveOperator) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s6 = {45,32,23,1,-78,23,67,45,23,12,65,9087,53,0,89,-223,445,23,12,4,787,13,777,6};
  std::set<int> s6original = {45,32,23,1,-78,23,67,45,23,12,65,9087,53,0,89,-223,445,23,12,4,787,13,777,6};
   std::set<int>::const_iterator orig = s6original.begin();
   s21::Set<int>::const_iterator mine = s6.Begin();
  for(; orig != s6original.end();++orig){
    EXPECT_EQ(*orig, *mine);
  ++mine;
  }
  
  
  s21::Set<int> s2;
  s21::Set<int>::const_iterator it =  s2.Begin();
  EXPECT_EQ(*it, 0);
  s2 = (std::move(s1));
  EXPECT_EQ(s2.Size(), 3);
  EXPECT_TRUE(s2.Contains(1));
  EXPECT_TRUE(s2.Contains(2));
  EXPECT_TRUE(s2.Contains(3));

  EXPECT_EQ(s1.Size(), 0);
  EXPECT_FALSE(s1.Contains(1));
}


TEST(setTest, BeginEnd) {
  s21::Set<int> s{3, 5, 1, 4, 2};
  s21::Set<int>::iterator it = s.Begin();

 std::set<int> s1{3, 5, 1, 4, 2};

 std::set<int>::iterator it1 = s1.begin();
 ASSERT_EQ(*it, *it1);
 it1 = s1.end();
 it = s.End();
 ASSERT_EQ(*it, *it1);

  s.Clear();
  s1.clear();
  it = s.Begin();
  it1 = s1.begin();
  ASSERT_EQ(*it, *it1);

  it = s.End();
  it1 = s1.end();
  ASSERT_EQ(*it, *it1);
}
TEST(setTestee, CopyConstructor) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s2(s1);
  s1.Clear();
  s2.Clear();

  EXPECT_EQ(s1.Size(), s2.Size());
}

TEST(setTest, SizeMaxSize) {
  s21::Set<int> s{3, 5, 1, 4, 2};
  std::set<int> s1{3, 5, 1, 4, 2};
  ASSERT_EQ(s.Size(), 5);
  ASSERT_GE(s.MaxSize(), s1.max_size());
  
  s.Clear();
  ASSERT_EQ(s.Size(), 0);
}

TEST(setTest, Erase) {
  s21::Set<int> s{1, 2, 3, 4, 5};
  s21::Set<int>::SetIterator it= s.Find(3);
  
  s.Erase(it);
  EXPECT_EQ(s.Size(), 4);
  EXPECT_FALSE(s.Contains(3));
}

TEST(setTest, Swap) {
  s21::Set<int> s1{1, 2, 3};
  s21::Set<int> s2{4, 5, 6};
  s1.Swap(s2);
  EXPECT_EQ(s1.Size(), 3);
  EXPECT_EQ(s2.Size(), 3);
  EXPECT_TRUE(s2.Contains(1));
  EXPECT_TRUE(s1.Contains(4));
}

TEST(setTest, Merge) {
  s21::Set<int> s1{1, 2, 3};
  s21::Set<int> s2{3,4, 5};
  s1.Merge(s2);

  std::set<int> o1{1, 2, 3};
  std::set<int> o2{3, 4, 5};
  o1.merge(o2);

  EXPECT_EQ(s1.Size(), o1.size());
  EXPECT_EQ(s2.Size(), o2.size());
  EXPECT_EQ(s1.Contains(4), o1.count(4));
  EXPECT_EQ(s2.Contains(3),o2.count(3));
} 

TEST(setTest, const_iter) {
  s21::Set<int> s1{1, 2, 3};
  s21::Set<int> s2{3,4, 5};
 s21::Set<int>::iterator first_it = s2.Begin();
 s21::Set<int>::const_iterator second_it = s1.Begin();
 s21::Set<int>::const_iterator third_it = s1.Begin();

 s21::Set<int>::iterator x(second_it);
EXPECT_TRUE(x == second_it);

 EXPECT_TRUE(second_it == third_it);
  *first_it = *second_it;
   EXPECT_EQ( *first_it, *second_it);
  ++second_it;
   *first_it = *second_it;
   EXPECT_EQ( *first_it, *second_it);

    --second_it;
    *first_it = *second_it;
    EXPECT_EQ( *first_it, *second_it);

     s1.Clear();
     s21::Set<int>::iterator iter = s1.Begin();
     EXPECT_EQ( *iter, 0);
}

TEST(setTest, Find) {
  s21::Set<int> s{1, 2, 3, 5};
  s21::Set<int>::SetIterator  it1 = s.Find(2);
  EXPECT_EQ(*it1, 2);
  
  std::set<int> o{1, 2, 3, 5};
  std::set<int>::iterator  o_it = o.find(4);
  std::set<int>::iterator  o_it2 = o.end();

  s21::Set<int>::SetIterator it2 = s.Find(4);
  s21::Set<int>::SetIterator it3 = s.End();

   EXPECT_EQ(*o_it,  *it2);
   EXPECT_EQ(*o_it2,  *it3);
}

TEST(mapConstructorTest, DefaultConstructor) {
  s21::Map<int, int> m;
  size_t zero = 0;
  EXPECT_EQ(m.Size(), zero);
  EXPECT_TRUE(m.Empty());
}

TEST(mapConstructorTest, InitializerListConstructor) {
  s21::Map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  size_t a = 3;
  EXPECT_EQ(m.Size(), a);
  EXPECT_FALSE(m.Empty());
  EXPECT_EQ(m.At(1), "one");
  EXPECT_EQ(m.At(2), "two");
  EXPECT_EQ(m.At(3), "three");
}

class TestMap {
 public:
  s21::Map<int, int> s21_map_empty;
  s21::Map<int, int> s21_map_four{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::Map<int, int> s21_map_swap{{1, 95}, {2, 94}, {3, 93}};

  std::map<int, int> std_map_empty;
  std::map<int, int> std_map_four{{1,1},{2, 2},{3, 3},{4, 4}};
  std::map<int, int> std_map_swap{{1, 95}, {2, 95}, {3, 95}};
};

TEST(Map, construcor_default) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
}

TEST(Map, construcot_initializer) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
}

TEST(Map, constructor_copy_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_copy(tester.s21_map_empty);
  std::map<int, int> std_map_copy(tester.std_map_empty);
  EXPECT_EQ(s21_map_copy.Size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.Empty(), std_map_copy.empty());
}

TEST(Map, constructor_copy_not_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_copy(tester.s21_map_four);
  std::map<int, int> std_map_copy(tester.std_map_four);
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.Size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.Empty(), std_map_copy.empty());
}

TEST(Map, constructor_move_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_move = std::move(tester.s21_map_empty);
  std::map<int, int> std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move.Size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.Empty(), std_map_move.empty());
}

TEST(Map, constructor_move_not_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_move = std::move(tester.s21_map_four);
  std::map<int, int> std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(s21_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.Size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.Empty(), std_map_move.empty());
}

TEST(Map, operator_copy_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_copy;
  std::map<int, int> std_map_copy;
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.Size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.Empty(), std_map_copy.empty());
}

TEST(Map, operator_copy_not_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_copy{{1, 1}, {2, 2}};
  std::map<int, int> std_map_copy{{1, 1}, {2, 2}};
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.Size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.Empty(), std_map_copy.empty());
}

TEST(Map, operator_move_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_move;
  std::map<int, int> std_map_move;
  s21_map_move = std::move(tester.s21_map_four);
  std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(std_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.Size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.Empty(), std_map_move.empty());
}


TEST(Map, function_empty_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
}

TEST(Map, function_empty_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
}

TEST(Map, function_size_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
}

TEST(Map, function_size_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
}

TEST(Map, function_max_size_empty) {
    TestMap tester;
   EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
   EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
}



TEST(Map, function_swap_empty) {
  s21::Map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::Map<int, int> m2;
 m1.Swap(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4;
  m3.swap(m4);

  ASSERT_EQ(m2[1], m4[1]);
  ASSERT_EQ(m2[2], m4[2]);
  ASSERT_EQ(m2[4], m4[4]);

  ASSERT_EQ(m1.Size(), m3.size());
  ASSERT_EQ(m2.Size(), m4.size());
}

TEST(Map, function_swap_not_empty) {
  TestMap tester;
  s21::Map<int, int> s21_map_swap{{1, 1}, {2, 2}};
  std::map<int, int> std_map_swap{{1, 1}, {2, 2}};
  s21_map_swap.Swap(tester.s21_map_four);
  std_map_swap.swap(tester.std_map_four);
  EXPECT_EQ(s21_map_swap[1], std_map_swap[1]);
  EXPECT_EQ(s21_map_swap[4], std_map_swap[4]);
  EXPECT_EQ(s21_map_swap.Size(), std_map_swap.size());
  EXPECT_EQ(s21_map_swap.Empty(), std_map_swap.empty());
}

TEST(Map, WithDuplicatesCase) {
  s21::Map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::Map<int, int> m2({{1, 3}, {2, 2}});
  m1.Merge(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4({{1, 3}, {2, 2}});
  m3.merge(m4);

  ASSERT_EQ(m1[1], m3[1]);
  ASSERT_EQ(m1[2], m3[2]);
  ASSERT_EQ(m1[4], m3[4]);

  ASSERT_EQ(m2[1], m4[1]);

  ASSERT_EQ(m1.Size(), m3.size());
  ASSERT_EQ(m2.Size(), m4.size());
}

TEST(Map, function_clear_empty) {
  TestMap tester;
  tester.s21_map_empty.Clear();
  tester.std_map_empty.clear();
  EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
}

TEST(Map, function_clear_not_empty) {
  TestMap tester;
  tester.s21_map_four.Clear();
  tester.std_map_four.clear();
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
}

TEST(Map, function_begin_empty) {
  TestMap tester;
  s21::Map<int, int>::MapIterator iter_1 = tester.s21_map_empty.Begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(iter_1 == tester.s21_map_empty.End(),
            iter_2 == tester.std_map_empty.end());
}

TEST(Map, function_begin_not_empty) {
  TestMap tester;
  s21::Map<int, int>::MapIterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.End(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).first, (*iter_2).first);
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, const_begin_empty) { //const_iterator
  TestMap tester;
  s21::Map<int, int>::ConstIterator iter_1 = tester.s21_map_empty.Begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == tester.s21_map_empty.End(), iter_2 == tester.std_map_empty.end());
}

TEST(Map, const_begin_not_empty) {
  TestMap tester;
  s21::Map<int, int>::ConstIterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_EQ(iter_1 != tester.s21_map_four.End(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, operator_plus) {
  TestMap tester;
  s21::Map<int, int>::Iterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).first, (*iter_2).first);
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
   EXPECT_EQ((*iter_1).first, (*iter_2).first);
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
   EXPECT_EQ((*iter_1).first, (*iter_2).first);
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_minus) {
  TestMap tester;
  s21::Map<int, int>::Iterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, insert_) {
  TestMap tester;
   s21::Map<int, int> mine;
  mine.Insert(25, 1000);
  mine.Insert(35, 2000);
  mine.Insert(45, 3000);
  mine.Insert(-25, 4000);
  mine.Insert(-35, 5000);
  mine.Insert(-45, 6000);
  mine.Insert(125, 7000);
  mine.Insert(-125, 8000);

  std::map<int, int> orig;
  orig.emplace(2,5);
  orig.emplace(3,5);
  orig.emplace(4,5);
  orig.emplace(5,5);
  orig.emplace(6,5);
  orig.emplace(7,5);
  orig.emplace(8,5);
  orig.emplace(9,5);
 EXPECT_EQ(mine.Size(), orig.size());
}

TEST(Map, operator_assignment) {
  TestMap tester;
  s21::Map<int, int>::Iterator iter_1 = tester.s21_map_four.Begin();
  
  s21::Map<int, int>::Iterator iter_3 = iter_1;
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, operator_equal) {
  TestMap tester;
  s21::Map<int, int>::Iterator iter_1 = tester.s21_map_four.Begin();
  s21::Map<int, int>::Iterator iter_3 = tester.s21_map_four.Begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}

TEST(Map, operatort_not_equal) {
  TestMap tester;
  s21::Map<int, int>::Iterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.End(),
            iter_2 != tester.std_map_empty.end());
}

TEST(Map, const_operator_plus) {
  TestMap tester;
  s21::Map<int, int>::ConstIterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, const_operator_minus) {
  TestMap tester;
  s21::Map<int, int>::ConstIterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, const_operator_assignment) {
  TestMap tester;
  s21::Map<int, int>::ConstIterator iter_1 = tester.s21_map_four.Begin();
  s21::Map<int, int>::ConstIterator iter_3 = iter_1;
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::const_iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, const_operator_equal) {
  TestMap tester;
  s21::Map<int, int>::ConstIterator iter_1 = tester.s21_map_four.Begin();
  s21::Map<int, int>::ConstIterator iter_3 = tester.s21_map_four.Begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::const_iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.Size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.Empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, const_operatort_not_equal) {
  TestMap tester;
  s21::Map<int, int>::ConstIterator iter_1 = tester.s21_map_four.Begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.End(),
            iter_2 != tester.std_map_empty.end());
}

TEST(Map, function_insert_without_duplicate) {
  TestMap tester;
  std::pair<s21::Map<int, int>::Iterator, bool> iter_1 =
      tester.s21_map_four.Insert({5, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({5, 2});
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_with_duplicate) {
  TestMap tester;
  std::pair<s21::Map<int, int>::Iterator, bool> iter_1 =
      tester.s21_map_four.Insert({1, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 2});
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_without_duplicate) {
  TestMap tester;
  std::pair<s21::Map<int, int>::Iterator, bool> iter_1 =
      tester.s21_map_four.Insert(7, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({7, 7});
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_with_duplicate) {
  TestMap tester;
  std::pair<s21::Map<int, int>::Iterator, bool> iter_1 =
      tester.s21_map_four.Insert(1, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 7});
  EXPECT_EQ(tester.s21_map_four.Size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.Empty(), tester.std_map_four.empty());
  EXPECT_TRUE(iter_1.second == iter_2.second);
}
TEST(Map, function_insert_or_assign_value) { 
    s21::Map<int, int> m1({{1, 3}, {4, 2}});
    std::map<int, int> m2({{1, 3}, {4, 2}});
    std::pair<s21::Map<int, int>::Iterator, bool> it1 = m1.Insert_or_assign(5,2);
    std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(5,2);
   ASSERT_TRUE(it1.second == it2.second);
}

TEST(Map, function_insert_or_assign) {
  s21::Map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::Map<int, int>::Iterator, bool> it1 = m1.Insert_or_assign(1, 2);
  std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(1, 2);
  ASSERT_EQ((*(it1.first)).second, (*(it2.first)).second);
  ASSERT_TRUE(it1.second == it2.second);
}
TEST(Map, function_insert_s) {
  s21::Map<int, int> m1({{1, 3}, {4, 2}});
  std::pair<s21::Map<int, int>::Iterator, bool> it1 = m1.Insert(5, 2);
  ASSERT_EQ((*(it1.first)).second, 2);
  ASSERT_TRUE(it1.second);
}

TEST(Map, function_at) {
    s21::Map<int, int> m1({{1, 3}, {4, 2}});
    std::map<int, int> m2({{1, 3}, {4, 2}});
    ASSERT_EQ(m1.At(1), m2.at(1));
}
TEST(Map, function_erase) {
    s21::Map<int, int> m1({{1, 3}, {4, 2}, {41, 2}});
    std::map<int, int> m2({{2, 6}, {8, 4}, {18, 4}});
    m1.Erase(m1.Begin());
    m2.erase(m2.begin());
  
  ASSERT_EQ(m1.Size(), m2.size());
}

TEST(Map, function_Emplace) {
    s21::Map<int, int> s1({{1, 3}, {4, 2}});
    auto it1 = s1.Emplace(std::pair<int, int>(5, 5), std::pair<int, int>(51, 53));
    ASSERT_EQ((*it1[0].first).second, 5);
    ASSERT_EQ((*it1[1].first).second, 53);
}

TEST(Map, function_ontains) {
    s21::Map<int, int> s1({{1, 3}, {4, 2}});
    ASSERT_TRUE(s1.Contains(1));
    ASSERT_TRUE(s1.Contains(4));
    ASSERT_FALSE(s1.Contains(3));
}

TEST(Map, MaxSize) {
    s21::Map<int, int> s1({{1, 3}, {4, 2}});
    EXPECT_EQ(s1.MaxSize(),576460752303423487);
}


TEST(mapConstructorTest, CopyConstructor) {
  s21::Map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  s21::Map<int, std::string> copy_m(m);
  size_t a = 3; 
  EXPECT_EQ(copy_m.Size(), a);
  EXPECT_FALSE(copy_m.Empty());
  EXPECT_EQ(copy_m.At(1), "one");
}

// Test the insert(key, value) function
TEST(mapTest, InsertKeyValue) {
  s21::Map<int, std::string> map;
  // Insert a single key-value pair
  map.Insert(1, "one");
  // Check that the size is correct
  size_t a = 1; 
  EXPECT_EQ(map.Size(), a);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.Contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair
  map.Insert(2, "two");
  // Check that the size is correct
  a = 2;
  EXPECT_EQ(map.Size(), a);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.Contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.Contains(2), true);
  EXPECT_EQ(map[2], "two");
}
// Test the insert(pair) function
TEST(mapTest, InsertPair) {
  size_t a = 1; 
  s21::Map<int, std::string> map;
  // Insert a single key-value pair using a pair object
  map.Insert(std::make_pair(1, "one"));
  // Check that the size is correct
  EXPECT_EQ(map.Size(), a);
  a = 2;
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.Contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair using a pair object
  map.Insert(std::make_pair(2, "two"));
  // Check that the size is correct
  EXPECT_EQ(map.Size(), a);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.Contains(1), true);                      
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.Contains(2), true);
  EXPECT_EQ(map[2], "two");
}



TEST(mapTest, AtAndOperatorBrackets) {
  s21::Map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_EQ(map.At(1), "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
}

TEST(mapTest, EmptyAndSize) {
  s21::Map<int, std::string> empty_map;
  s21::Map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};
size_t a = 0;
  EXPECT_TRUE(empty_map.Empty());
  EXPECT_EQ(empty_map.Size(), a);
a = 3;
  EXPECT_FALSE(map.Empty());
  EXPECT_EQ(map.Size(), a);
}


TEST(mapTest, Swap) {
  s21::Map<int, std::string> map1;
  map1.Insert({1, "one"});
  map1.Insert({2, "two"});

  s21::Map<int, std::string> map2;
  map2.Insert({3, "three"});
  map2.Insert({4, "four"});

  map1.Swap(map2);
  size_t a = 2;
  EXPECT_EQ(map1.Size(), a);
  EXPECT_TRUE(map1.Contains(3));
  EXPECT_TRUE(map1.Contains(4));

  EXPECT_EQ(map2.Size(), a);
  EXPECT_TRUE(map2.Contains(1));
  EXPECT_TRUE(map2.Contains(2));
}

TEST(mapTest, Merge) {
  s21::Map<int, std::string> map1;
  map1.Insert({5, "one"});
  map1.Insert({7, "two"});
  map1.Insert({17, "four"});
  map1.Insert({27, "four"});

  s21::Map<int, std::string> map2;
  map2.Insert({5, "three"});
  map2.Insert({7, "four"});
  map2.Insert({5, "three"});
  map2.Insert({47, "four"});



  map1.Merge(map2);
  size_t a = 5;
  EXPECT_EQ(map1.Size(), a);
  EXPECT_TRUE(map1.Contains(5));
  EXPECT_TRUE(map1.Contains(7));
  EXPECT_TRUE(map1.Contains(17));
  EXPECT_TRUE(map1.Contains(47));
}

TEST(mapTest, Contains) {
  s21::Map<int, std::string> map;
  map.Insert({1, "one"});
  map.Insert({2, "two"});
  EXPECT_TRUE(map.Contains(2));
  EXPECT_FALSE(map.Contains(3));
}

// // // MULTISET
    class TestMultiset {
    public:
        s21::Multiset<int> s21_multiset_empty;
        s21::Multiset<int> s21_multiset_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
        s21::Multiset<int> s21_multiset_copy;
        std::multiset<int> std_multiset_copy;
        s21::Multiset<int> s21_move;
        std::multiset<int> std_move;
        s21::Multiset<int> s21_multiset_swap{95, 94, 93, 92};
        std::multiset<int> std_multiset_swap{95, 94, 93, 92};
        s21::Multiset<int> s21_multiset_merge{1, 2, 3, 4, 5};
        std::multiset<int> std_multiset_merge{1, 2, 3, 4, 5};

        std::multiset<int> std_multiset_empty;
        std::multiset<int> std_multiset_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
    };

    TEST(Multiset, constructor_default) {
        TestMultiset tester;
        EXPECT_EQ(tester.s21_multiset_empty.Size(), tester.std_multiset_empty.size());
        EXPECT_EQ(tester.s21_multiset_empty.Empty(), tester.std_multiset_empty.empty());
    }

    TEST(Multiset, constructor_initialazer) {
        TestMultiset tester;
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.s21_multiset_ten.Find(1) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(1) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(2) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(2) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(3) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(3) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(4) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(4) != tester.std_multiset_ten.end());
    }

    TEST(Multiset, constructor_copy) {
        TestMultiset tester;
        s21::Multiset<int> s21_empty(tester.s21_multiset_ten);
        std::multiset<int> std_empty(tester.std_multiset_ten);
        EXPECT_EQ(s21_empty.Find(1) != s21_empty.End(),
                  std_empty.find(1) != std_empty.end());
        EXPECT_EQ(s21_empty.Find(2) != s21_empty.End(),
                  std_empty.find(2) != std_empty.end());
        EXPECT_EQ(s21_empty.Find(3) != s21_empty.End(),
                  std_empty.find(3) != std_empty.end());
        EXPECT_EQ(s21_empty.Find(4) != s21_empty.End(),
                  std_empty.find(4) != std_empty.end());
        EXPECT_EQ(s21_empty.Size(), std_empty.size());
        EXPECT_EQ(s21_empty.Empty(), std_empty.empty());
    }

    TEST(Multiset, construct_move) {
        TestMultiset tester;
        s21::Multiset<int> s21_move = std::move(tester.s21_multiset_ten);
        std::multiset<int> std_move = std::move(tester.std_multiset_ten);
        EXPECT_EQ(s21_move.Find(1) != s21_move.End(),
                  std_move.find(1) != std_move.end());
        EXPECT_EQ(s21_move.Find(2) != s21_move.End(),
                  std_move.find(2) != std_move.end());
        EXPECT_EQ(s21_move.Find(3) != s21_move.End(),
                  std_move.find(3) != std_move.end());
        EXPECT_EQ(s21_move.Find(4) != s21_move.End(),
                  std_move.find(4) != std_move.end());
        EXPECT_EQ(s21_move.Size(), std_move.size());
        EXPECT_EQ(s21_move.Empty(), std_move.empty());
    }

    TEST(Multiset, operator_move) {
        TestMultiset tester;
        tester.s21_move = std::move(tester.s21_multiset_ten);
        tester.std_move = std::move(tester.std_multiset_ten);
        EXPECT_EQ(tester.s21_move.Find(1) != tester.s21_move.End(),
                  tester.std_move.find(1) != tester.std_move.end());
        EXPECT_EQ(tester.s21_move.Find(2) != tester.s21_move.End(),
                  tester.std_move.find(2) != tester.std_move.end());
        EXPECT_EQ(tester.s21_move.Find(3) != tester.s21_move.End(),
                  tester.std_move.find(3) != tester.std_move.end());
        EXPECT_EQ(tester.s21_move.Find(4) != tester.s21_move.End(),
                  tester.std_move.find(4) != tester.std_move.end());
        EXPECT_EQ(tester.s21_move.Size(), tester.std_move.size());
        EXPECT_EQ(tester.s21_move.Empty(), tester.std_move.empty());
    }

    TEST(Multiset, operator_copy) {
        TestMultiset tester;
        tester.s21_multiset_copy = tester.s21_multiset_ten;
        tester.std_multiset_copy = tester.std_multiset_ten;
        EXPECT_EQ(tester.s21_multiset_copy.Find(1) != tester.s21_multiset_copy.End(),
                  tester.std_multiset_copy.find(1) != tester.std_multiset_copy.end());
        EXPECT_EQ(tester.s21_multiset_copy.Find(2) != tester.s21_multiset_copy.End(),
                  tester.std_multiset_copy.find(2) != tester.std_multiset_copy.end());
        EXPECT_EQ(tester.s21_multiset_copy.Find(3) != tester.s21_multiset_copy.End(),
                  tester.std_multiset_copy.find(3) != tester.std_multiset_copy.end());
        EXPECT_EQ(tester.s21_multiset_copy.Find(4) != tester.s21_multiset_copy.End(),
                  tester.std_multiset_copy.find(4) != tester.std_multiset_copy.end());
        EXPECT_EQ(tester.s21_multiset_copy.Size(), tester.std_multiset_copy.size());
        EXPECT_EQ(tester.s21_multiset_copy.Empty(), tester.std_multiset_copy.empty());
    }

    TEST(Multiset, function_not_empty) {
        TestMultiset tester;
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.s21_multiset_ten.Empty(), tester.std_multiset_ten.empty());
    }

    TEST(Multiset, function_empty) {
        TestMultiset tester;

        EXPECT_EQ(tester.s21_multiset_empty.Size(), tester.std_multiset_empty.size());
        EXPECT_EQ(tester.s21_multiset_empty.Empty(), tester.std_multiset_empty.empty());
    }

    TEST(Multiset, function_size_empty) {
        TestMultiset tester;
        EXPECT_EQ(tester.s21_multiset_empty.Size(), tester.std_multiset_empty.size());
    }

    TEST(Multiset, function_size_not_empty) {
        TestMultiset tester;
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
    }

 TEST(Multiset, function_max_sez_empty) {
     TestMultiset tester;
     EXPECT_EQ(tester.s21_multiset_empty.MaxSize(),
288230376151711743);
 }

 TEST(Multiset, function_max_siez_not_empty) {
     TestMultiset tester;
     EXPECT_EQ(tester.s21_multiset_ten.MaxSize(), 288230376151711743);

 }
 TEST(Multiset, merge_swap) {
 s21::Multiset<int> a{1,2,3,4,5,6,7};
    s21::Multiset<int> b{6,7,8,9,10};
    a.Merge(b);
    a.Swap(b);
  
    ASSERT_TRUE(a.Size() == 0);
    ASSERT_TRUE(b.Size() == 12);

 }

    TEST(Multiset, function_swap_not_empty) {
        TestMultiset tester;
        tester.s21_multiset_swap.Swap(tester.s21_multiset_ten);
        tester.std_multiset_swap.swap(tester.std_multiset_ten);
        EXPECT_EQ(tester.s21_multiset_swap.Find(1) != tester.s21_multiset_swap.End(),
                  tester.std_multiset_swap.find(1) != tester.std_multiset_swap.end());
        EXPECT_EQ(tester.s21_multiset_swap.Find(56) != tester.s21_multiset_swap.End(),
                  tester.std_multiset_swap.find(56) != tester.std_multiset_swap.end());
        EXPECT_EQ(tester.s21_multiset_swap.Find(76) != tester.s21_multiset_swap.End(),
                  tester.std_multiset_swap.find(76) != tester.std_multiset_swap.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(95) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(95) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(94) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(94) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(93) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(93) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_swap.Size(), tester.std_multiset_swap.size());
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
    }

    TEST(Multiset, function_swap_empty) {
        TestMultiset tester;
        tester.s21_multiset_empty.Swap(tester.s21_multiset_swap);
        tester.std_multiset_empty.swap(tester.std_multiset_swap);

        EXPECT_EQ(tester.s21_multiset_empty.Find(95) != tester.s21_multiset_empty.End(),
                  tester.std_multiset_empty.find(95) != tester.std_multiset_empty.end());
        EXPECT_EQ(tester.s21_multiset_empty.Find(94) != tester.s21_multiset_empty.End(),
                  tester.std_multiset_empty.find(94) != tester.std_multiset_empty.end());
        EXPECT_EQ(tester.s21_multiset_empty.Find(93) != tester.s21_multiset_empty.End(),
                  tester.std_multiset_empty.find(93) != tester.std_multiset_empty.end());

        EXPECT_EQ(tester.s21_multiset_empty.Size(), tester.std_multiset_empty.size());
        EXPECT_EQ(tester.s21_multiset_empty.Empty(), tester.std_multiset_empty.empty());
        EXPECT_EQ(tester.s21_multiset_swap.Size(), tester.std_multiset_swap.size());
        EXPECT_EQ(tester.s21_multiset_swap.Empty(), tester.std_multiset_swap.empty());
    }
    TEST(Multiset, function_merge_with_duplicates) {
        TestMultiset tester;
        tester.s21_multiset_merge.Merge(tester.s21_multiset_ten);
        tester.std_multiset_merge.merge(tester.std_multiset_ten);

        EXPECT_EQ(tester.s21_multiset_merge.Find(1) != tester.s21_multiset_merge.End(),
                  tester.std_multiset_merge.find(1) != tester.std_multiset_merge.end());
        EXPECT_EQ(tester.s21_multiset_merge.Find(2) != tester.s21_multiset_merge.End(),
                  tester.std_multiset_merge.find(2) != tester.std_multiset_merge.end());
        EXPECT_EQ(tester.s21_multiset_merge.Find(76) != tester.s21_multiset_merge.End(),
                  tester.std_multiset_merge.find(76) != tester.std_multiset_merge.end());

        EXPECT_EQ(tester.s21_multiset_merge.Size(), tester.std_multiset_merge.size());
        EXPECT_EQ(tester.s21_multiset_merge.Empty(), tester.std_multiset_merge.empty());
    }

    TEST(Multiset, function_merge_wihout_duplicates) {
        TestMultiset tester;
        printf("--------------");
        tester.s21_multiset_ten.Merge(tester.s21_multiset_swap);
        tester.std_multiset_ten.merge(tester.std_multiset_swap);

        EXPECT_EQ(tester.s21_multiset_ten.Find(95) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(95) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(1) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(1) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(94) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(94) != tester.std_multiset_ten.end());
        EXPECT_EQ(tester.s21_multiset_ten.Find(76) != tester.s21_multiset_ten.End(),
                  tester.std_multiset_ten.find(76) != tester.std_multiset_ten.end());

        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.std_multiset_ten.empty(), tester.std_multiset_ten.empty());
        EXPECT_EQ(tester.s21_multiset_swap.Size(), tester.std_multiset_swap.size());
        EXPECT_EQ(tester.s21_multiset_swap.Empty(), tester.std_multiset_swap.empty());
    }

    TEST(Multiset, function_clear_not_empty) {
        TestMultiset tester;
        tester.s21_multiset_ten.Clear();
        tester.std_multiset_ten.clear();
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.s21_multiset_ten.Empty(), tester.std_multiset_ten.empty());
    }

    TEST(Multiset, function_clear_empty) {
        TestMultiset tester;
        tester.s21_multiset_empty.Clear();
        tester.std_multiset_empty.clear();
        EXPECT_EQ(tester.s21_multiset_empty.Size(), tester.std_multiset_empty.size());
        EXPECT_EQ(tester.s21_multiset_empty.Empty(), tester.std_multiset_empty.empty());
    }

    TEST(Multiset, function_begin_not_empty) {
        TestMultiset tester;
        s21::Multiset<int>::iterator i = tester.s21_multiset_ten.Begin();
        std::multiset<int>::iterator j = tester.std_multiset_ten.begin();
        EXPECT_EQ(*i, *j);
    }

    TEST(Multiset, function_begin_empty) {
        TestMultiset tester;
        s21::Multiset<int>::const_iterator con_it = tester.s21_multiset_empty.Begin();
        s21::Multiset<int>::iterator i(con_it);

        std::multiset<int>::iterator j = tester.std_multiset_empty.begin();
        EXPECT_EQ(*i, *j);
    }


    TEST(Multiset, function_const_begin_not_empty) {
        TestMultiset tester;
        s21::Multiset<int>::const_iterator i = tester.s21_multiset_ten.Begin();
        std::multiset<int>::const_iterator j = tester.std_multiset_ten.begin();
        EXPECT_EQ(*i, *j);
    }

    TEST(Multiset, function_const_begin_empty) {
        TestMultiset tester;
        s21::Multiset<int>::const_iterator i = tester.s21_multiset_empty.Begin();
        std::multiset<int>::const_iterator j = tester.std_multiset_empty.begin();
        EXPECT_EQ(*i, *j);
    }



    TEST(Multiset, function_end_not_empty) {
        TestMultiset tester;
        s21::Multiset<int>::iterator i = tester.s21_multiset_ten.End();
        std::multiset<int>::iterator j = tester.std_multiset_ten.end();
        --i;
        --j;
        EXPECT_EQ(*i, *j);
    }

    TEST(Multiset, function_end_empty) {
        TestMultiset tester;
        s21::Multiset<int>::iterator i = tester.s21_multiset_empty.End();
        std::multiset<int>::iterator j = tester.std_multiset_empty.end();
        EXPECT_EQ(*i, *j);
    }
    TEST(Multiset, function_const_end_not_empty) {
        TestMultiset tester;
        s21::Multiset<int>::const_iterator i = tester.s21_multiset_ten.End();
        std::multiset<int>::const_iterator j = tester.std_multiset_ten.end();
        --i;
        --j;
        EXPECT_EQ(*i, *j);
    }

    TEST(Multiset, function_const_end_empty) {
        TestMultiset tester;
        s21::Multiset<int>::const_iterator i = tester.s21_multiset_empty.End();
        std::multiset<int>::const_iterator j = tester.std_multiset_empty.end();
        EXPECT_EQ(*i, *j);
    }
    TEST(Multiset, operator_plus) {
        TestMultiset tester;
        s21::Multiset<int>::iterator i = tester.s21_multiset_ten.Begin();
        std::multiset<int>::iterator j = tester.std_multiset_ten.begin();
        while (i != tester.s21_multiset_ten.End() && j != tester.std_multiset_ten.end()) {
            EXPECT_EQ(*i, *j);
            ++i;
            ++j;
        }
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.s21_multiset_ten.Empty(), tester.std_multiset_ten.empty());
    }

    TEST(Multiset, operator_minus) {
        TestMultiset tester;
        s21::Multiset<int>::iterator i = tester.s21_multiset_ten.End();
        std::multiset<int>::iterator j = tester.std_multiset_ten.end();
        while (i != tester.s21_multiset_ten.Begin() && j != tester.std_multiset_ten.begin()) {
            --i;
            --j;
            EXPECT_EQ(*i, *j);
        }
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.s21_multiset_ten.Empty(), tester.std_multiset_ten.empty());
    }

    TEST(Multiset, operation_assignment) {
        TestMultiset tester;
        s21::Multiset<int>::iterator iter_1 = tester.s21_multiset_ten.Begin();
        s21::Multiset<int>::iterator iter_3 = iter_1;
        std::multiset<int>::iterator iter_2 = tester.std_multiset_ten.begin();
        std::multiset<int>::iterator iter_4 = iter_2;
        ASSERT_EQ(*iter_1, *iter_3);
        ASSERT_EQ(*iter_2, *iter_4);
    }
    TEST(Multiset, operation_equal) {
        TestMultiset tester;
        s21::Multiset<int>::iterator it1 = tester.s21_multiset_ten.Begin();
        s21::Multiset<int>::iterator it3 = tester.s21_multiset_ten.Begin();
        std::multiset<int>::iterator it2 = tester.std_multiset_ten.begin();
        std::multiset<int>::iterator it4 = tester.std_multiset_ten.begin();
        ASSERT_EQ(it1 == it3, it2 == it4);
    }
    TEST(Multiset, operation_not_equal) {
        TestMultiset tester;
        s21::Multiset<int>::iterator iter_1 = tester.s21_multiset_ten.Begin();
        std::multiset<int>::iterator iter_2 = tester.std_multiset_ten.begin();
        ASSERT_EQ(iter_1 != tester.s21_multiset_ten.End(),
                  iter_2 != tester.std_multiset_ten.end());
    }



    TEST(Multiset, function_insert) {
        TestMultiset tester;
        tester.s21_multiset_ten.Insert(45);
        tester.std_multiset_ten.insert(45);
        EXPECT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
        EXPECT_EQ(tester.s21_multiset_ten.Empty(), tester.std_multiset_ten.empty());
    }

    TEST(Multiset, function_find_have) {
        TestMultiset tester;
        s21::Multiset<int>::iterator i = tester.s21_multiset_ten.Find(1);
        std::multiset<int>::iterator j = tester.std_multiset_ten.find(1);
        EXPECT_EQ(i != tester.s21_multiset_ten.End(), j != tester.std_multiset_ten.end());
    }

    TEST(Multiset, function_find_dont_have) {
        TestMultiset tester;
        s21::Multiset<int>::iterator i = tester.s21_multiset_ten.Find(100);
        std::multiset<int>::iterator j = tester.std_multiset_ten.find(100);
        EXPECT_EQ(i == tester.s21_multiset_ten.End(), j == tester.std_multiset_ten.end());
    }

    TEST(Multiset, function_erase) {
        TestMultiset tester;
        tester.s21_multiset_ten.Erase(tester.s21_multiset_ten.Begin());
        tester.std_multiset_ten.erase(tester.std_multiset_ten.begin());
        s21::Multiset<int>::iterator iter_1 = tester.s21_multiset_ten.Find(1);
        std::multiset<int>::iterator iter_2 = tester.std_multiset_ten.find(1);
        ASSERT_EQ(iter_1 == tester.s21_multiset_ten.End(),
                  iter_2 == tester.std_multiset_ten.end());
    }
    TEST(Multiset, functions_erase_alot) {
        TestMultiset tester;
        s21::Multiset<int>::iterator it1 = tester.s21_multiset_ten.Find(76);
        std::multiset<int>::iterator it2 = tester.std_multiset_ten.find(76);
        tester.s21_multiset_ten.Erase(it1);
        tester.std_multiset_ten.erase(it2);
        it1 = tester.s21_multiset_ten.Find(123);
        it2 = tester.std_multiset_ten.find(123);
        tester.s21_multiset_ten.Erase(it1);
        tester.std_multiset_ten.erase(it2);
        it1 = tester.s21_multiset_ten.Find(43);
        it2 = tester.std_multiset_ten.find(43);
        tester.s21_multiset_ten.Erase(it1);
        tester.std_multiset_ten.erase(it2);
        ASSERT_EQ(tester.s21_multiset_ten.Size(), tester.std_multiset_ten.size());
    }
    TEST(Multiset, function_emplace) {
        TestMultiset tester;
        auto it1 = tester.s21_multiset_merge.Emplace(2, 3, 5);
        EXPECT_EQ(*it1[0].first, 2);
        EXPECT_EQ(*it1[1].first, 3);
        EXPECT_EQ(*it1[2].first, 5);
    }

TEST(Multiset, function_count) {
    s21::Multiset<int> s1({1, 3, 4, 2, 2});
    std::multiset<int> s2({1, 3, 4, 2, 2});
    ASSERT_EQ(s1.Count(2), s2.count(2));
    ASSERT_EQ(s1.Count(3), s2.count(3));
}

TEST(Multiset, function_contains) {
    TestMultiset tester;
    ASSERT_TRUE(tester.s21_multiset_ten.Contains(1));
    ASSERT_TRUE(tester.s21_multiset_ten.Contains(2));
    ASSERT_TRUE(tester.s21_multiset_ten.Contains(56));
    ASSERT_TRUE(tester.s21_multiset_ten.Contains(76));
}
TEST(Multiset, function_lower_bound) {
    s21::Multiset<int> s1({1, 3, 4, 2, 2});
    std::multiset<int> s2({1, 3, 4, 2, 2});
    s21::Multiset<int>::iterator it1 = s1.LowerBound(2);
    std::multiset<int>::iterator it2 = s2.lower_bound(2);
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
    ASSERT_EQ(*it1, *it2);
    --it1;
    --it2;
    --it1;
    --it2;
    --it1;
    --it2;
    ASSERT_EQ(*it1, *it2);
}
TEST(Multiset, function_upper_bound) {
    s21::Multiset<int> s1({1, 3, 4, 2, 2});
    std::multiset<int> s2({1, 3, 4, 2, 2});
    s21::Multiset<int>::iterator it1 = s1.UpperBound(2);
    std::multiset<int>::iterator it2 = s2.upper_bound(2);
    ASSERT_EQ(*it1, *it2);
    ++it1;
    ++it2;
    ASSERT_EQ(*it1, *it2);
    --it1;
    --it2;
    --it1;
    --it2;
    ASSERT_EQ(*it1, *it2);
}
TEST(Multiset, function_equal_range) {
    s21::Multiset<int> s1({1, 3, 4, 2, 2});
    std::multiset<int> s2({1, 3, 4, 2, 2});
    auto it1 = s1.EqualRange(2);
    auto it2 = s2.equal_range(2);
    ASSERT_EQ(*it1.first, *it2.first);
    ASSERT_EQ(*it1.second, *it2.second);
}





class TestArray {
 public:
  
  s21::Array<int, 0> s21_array_empty;
  s21::Array<int, 3> copy_array{234, 21, 11};
  s21::Array<char, 0> copy_ar1;
  s21::Array<double, 5> copy_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  s21::Array<double, 5> copy_array2{-5.3, 1.18, -4.3, 255.34, 1.23};

  std::array<int, 0> std_array_empty;
  std::array<int, 3> orig_array{234, 21, 11};
  std::array<char, 0> orig_ar1;
  std::array<double, 5> orig_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  std::array<double, 5> orig_array2{-5.3, 1.18, -4.3, 255.34, 1.23};
};

TEST(Array, constructor_default) {
    TestArray tester;
    EXPECT_EQ(tester.s21_array_empty.Size(), tester.std_array_empty.size());
    EXPECT_EQ(tester.s21_array_empty.Empty(), tester.std_array_empty.empty());
}

TEST(Array, constructor_initializer) {
    TestArray tester;
    EXPECT_EQ(tester.copy_array1[1], tester.orig_array1[1]);
    EXPECT_EQ(tester.copy_array1.Front(), tester.orig_array1.front());
    EXPECT_EQ(tester.copy_array1.Back(), tester.orig_array1.back());
    EXPECT_EQ(tester.copy_array1.Size(), tester.orig_array1.size());
    EXPECT_EQ(tester.copy_array1.Empty(), tester.orig_array1.empty());
}

TEST(Array, constructor_copy_empty) {
    TestArray tester;
    s21::Array<int, 0> s21_array_copy(tester.s21_array_empty);
    std::array<int, 0> std_array_copy(tester.std_array_empty);
    EXPECT_EQ(s21_array_copy.Size(), std_array_copy.size());
    EXPECT_EQ(s21_array_copy.Empty(), std_array_copy.empty());
}

TEST(Array, simple_test) {
  TestArray logger;
  for (int i{}; i < 3; i++)
  ASSERT_EQ(logger.orig_array.at(i), logger.copy_array.At(i));
  ASSERT_EQ(logger.orig_array.size(), logger.copy_array.Size());
  ASSERT_EQ(logger.orig_array.max_size(), logger.copy_array.MaxSize());
  ASSERT_EQ(logger.orig_ar1.empty(), logger.copy_ar1.Empty());
}
TEST(Array, swap_test) {
  TestArray logger;
  logger.orig_array1.swap(logger.orig_array2);
  logger.copy_array1.Swap(logger.copy_array2);
  for (int i{}; i < 5; i++) {
      ASSERT_DOUBLE_EQ(logger.orig_array1[i], logger.copy_array1[i]);
    ASSERT_DOUBLE_EQ(logger.orig_array2[i], logger.copy_array2[i]);
  }
  ASSERT_EQ(logger.orig_array1.size(), logger.copy_array1.Size());
  ASSERT_EQ(logger.orig_array2.max_size(), logger.copy_array2.MaxSize());
  ASSERT_EQ(logger.orig_array1.front(), logger.copy_array1.Front());
  ASSERT_EQ(logger.orig_array2.front(), logger.copy_array2.Front());
  ASSERT_EQ(logger.orig_array1.back(), logger.copy_array1.Back());
  ASSERT_EQ(logger.orig_array2.back(), logger.copy_array2.Back());
}

TEST(Array, copy_constructor_test) {
  std::array<int, 3> orig_array3{234, 21, 11};
  s21::Array<int, 3> copy_array3{234, 21, 11};
  std::array<int, 3> orig_array4(orig_array3);
  s21::Array<int, 3> copy_array4(copy_array3);
  for (int i{}; i < 3; i++) {
    ASSERT_EQ(orig_array3.at(i), copy_array3.At(i));
    ASSERT_EQ(orig_array4.at(i), copy_array4.At(i));
  }
  ASSERT_EQ(orig_array3.size(), copy_array3.Size());
  ASSERT_EQ(orig_array3.max_size(), copy_array3.MaxSize());
  ASSERT_EQ(orig_array4.size(), copy_array4.Size());
  ASSERT_EQ(orig_array4.max_size(), copy_array4.MaxSize());
  std::array<char, 0> orig_ar5;
  s21::Array<char, 0> copy_ar5;
  std::array<char, 0> orig_ar6(orig_ar5);
  s21::Array<char, 0> copy_ar6(copy_ar5);
  ASSERT_EQ(orig_ar5.empty(), copy_ar5.Empty());
  ASSERT_EQ(orig_ar6.empty(), copy_ar6.Empty());
}

TEST(Array, move_constructor_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::Array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2(std::move(orig_array1));
  s21::Array<int, 5> copy_array2(std::move(copy_array1));
  for (size_t i{}; i < copy_array2.Size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.At(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.Size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.MaxSize());
  ASSERT_EQ(orig_array2.size(), copy_array2.Size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.MaxSize());
  std::array<char, 0> orig_ar1;
  s21::Array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.Empty());
}

TEST(Array, move_operator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::Array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2{25};
  s21::Array<int, 5> copy_array2{25};
  orig_array2 = std::move(orig_array1);
  copy_array2 = std::move(copy_array1);
  for (size_t i{}; i < copy_array2.Size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.At(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.Size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.MaxSize());
  ASSERT_EQ(orig_array2.size(), copy_array2.Size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.MaxSize());
  std::array<char, 0> orig_ar1;
  s21::Array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.Empty());
}

TEST(Array, iterator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::Array<int, 5> copy_array1{234, 21, 11, 34, 999};
  int *orig_beg = orig_array1.begin();
  int *copy_beg = copy_array1.Begin();
  int *orig_end = orig_array1.end();
  int *copy_end = copy_array1.End();
  while (orig_beg < orig_end && copy_beg < copy_end) {
    ASSERT_EQ(*orig_beg++, *copy_beg++);
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.Size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.MaxSize());
  s21::Array<char,0> copy_ar1;
  ASSERT_TRUE(copy_ar1.Begin() == copy_ar1.End());
  s21::Array<double, 3> my_arr{2.3, 4.5555, 6.1234};
  double *d = my_arr.Data();
  ASSERT_DOUBLE_EQ(my_arr[0], *d);
}

TEST(Array, fill_test) {
  std::array<size_t, 10> orig_array;
  s21::Array<size_t, 10> my_arr;
  s21::Array<size_t, 10> my_arr2;
  orig_array.fill(555);
  my_arr.Fill(555);
  my_arr2.Fill(555);
  s21::Array<size_t, 10>::iterator iter = my_arr.Begin();
  s21::Array<size_t, 10>::iterator iter2 = my_arr2.Begin();
  EXPECT_TRUE(iter != iter2);
   iter2 = my_arr.Begin(); 
  EXPECT_TRUE(iter == iter2);

  for (size_t i = 0; i < 10; i++)
    ASSERT_EQ(orig_array[i], my_arr[i]);
  ASSERT_EQ(orig_array.size(), my_arr.Size());
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
