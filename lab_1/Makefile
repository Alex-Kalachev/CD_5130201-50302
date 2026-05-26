objects = \
	build/rect.o \
	build/my_string.o \
	build/barrel.o \
	build/cat.o \
	build/matrix.o

tests = \

build/pragma: $(objects) src/lab1.cpp
	clang++ -g -o build/pragma src/lab1.cpp $(objects)


debug: build/pragma
	lldb build/pragma

build/rect.o: src/rect.cpp src/rect.hpp
	clang++ -g -c src/rect.cpp -o build/rect.o

build/matrix.o: src/matrix.cpp src/matrix.hpp
	clang++ -g -c src/matrix.cpp -o build/matrix.o

build/my_string.o: src/my_string.cpp src/my_string.hpp
	clang++ -g -c src/my_string.cpp -o build/my_string.o

build/barrel.o: src/barrel.cpp src/barrel.hpp
	clang++ -g -c src/barrel.cpp -o build/barrel.o

build/cat.o: src/cat.cpp src/cat.hpp
	clang++ -g -c src/cat.cpp -o build/cat.o

#проверка на утечки
leaks: build/pragma
	leaks --atExit -- build/pragma < input.txt


# Запуск всех тестов

build/test_rect_properties: $(objects) tests/test_rect_properties.cpp
	clang++ -g -o build/test_rect_properties tests/test_rect_properties.cpp $(objects)

build/test_rect_operations: $(objects) tests/test_rect_operations.cpp
	clang++ -g -o build/test_rect_operations tests/test_rect_operations.cpp $(objects)

build/test_rect_basic_methods: $(objects) tests/test_rect_basic_methods.cpp
	clang++ -g -o build/test_rect_basic_methods tests/test_rect_basic_methods.cpp $(objects)

build/test_bounding_rect: $(objects) tests/test_bounding_rect.cpp
	clang++ -g -o build/test_bounding_rect tests/test_bounding_rect.cpp $(objects)

test: build/test_bounding_rect build/test_rect_basic_methods \
		build/test_rect_operations build/test_rect_properties

	./build/test_bounding_rect
	./build/test_rect_basic_methods
	./build/test_rect_operations
	./build/test_rect_properties

clean:
	-rm build/*.o build/pragma

# TODO: добавить цели для сборки и запуска всех тестов разом