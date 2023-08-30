FLAGS = -Wall -Werror -Wextra -O0 -g 
SRC = QueueContainer/s21_queue.tpp ArrayContainer/s21_array.tpp ListContainer/s21_list.tpp StackContainer/s21_stack.tpp SetContainers/s21_set.tpp SetContainers/s21_multiset.tpp VectorContainer/s21_vector.tpp  MapContainer/s21_map.tpp
OBJ = $(SRC:.cc =.o)

all: test

test :
	g++ -std=c++17 $(FLAGS) $(SRC) ContainerTest.cc -L.   -lgtest  --coverage -o test
	./test

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html
clean:
	rm -rf *.o *.a *.gcno *.gcda test test.info *.out
	rm -rf report
	rm -rf .txt *.dSYM
style: style2
	cd ArrayContainer && clang-format -style=google -i *.tpp *.h && clang-format -style=google -n *.tpp *.h
	cd ListContainer && clang-format -style=google -i *.tpp *.h && clang-format -style=google -n *.tpp *.h
	cd SetContainers && clang-format -style=google -i *.tpp *.h && clang-format -style=google -n *.tpp *.h
	cd VectorContainer && clang-format -style=google -i *.tpp *.h && clang-format -style=google -n *.tpp *.h
style2:
	cd QueueContainer && clang-format -style=google -i *.tpp *.h && clang-format -style=google -n *.tpp *.h
	cd StackContainer && clang-format -style=google -i *.tpp *.h && clang-format -style=google -n *.tpp *.h
	cd MapContainer && clang-format -style=google -i *.tpp *.h && clang-format -style=google -n *.tpp *.h
    

leaks: test
	leaks -atExit -- ./test


