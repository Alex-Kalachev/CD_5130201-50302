all: build run

build:
	mkdir -p build
	clang++ -g -I src \
	src/lab4.cpp src/list.cpp \
	-o build/pragma

run:
	./build/pragma

clean:
	rm -rf build