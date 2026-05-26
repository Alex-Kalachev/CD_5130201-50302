
all: build run

build:
	mkdir -p build
	clang++ -g -I src \
	src/lab3.cpp src/matrix.cpp src/my_string.cpp \
	src/worker_dd.cpp src/notification.cpp \
	src/notification_class.cpp src/notification_queue.cpp \
	src/basefile.cpp \
	src/boolarray.cpp \
	-o build/pragma

run:
	./build/pragma

test:
	mkdir -p build
	clang++ -g -I src \
	src/notification.cpp src/notification_class.cpp src/notification_queue.cpp \
	tests/test_nubber_4.4.cpp \
	-o build/test_basefile
	./build/test_basefile

clean:
	rm -rf build