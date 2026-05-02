cmake_minimum_required(VERSION 3.10)

project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_library(my_lib
    src/list.cpp
)
# Создаем библиотеку, в которой вся функциональность выраженная классами и функциями, и отделена от основоного файла

target_include_directories(my_lib PUBLIC src)
# говорим что при использовании нашей библиотеки my_lib, нужно искать зависимые .hpp файлы в папке src

add_executable(lab4_exec
    src/lab4.cpp
)
# создаем бинарный файл с точкой входа main()

target_link_libraries(lab4_exec my_lib)
# при сборке бинарника подключаем библиотеку my_lib

enable_testing()
# подключаем систему тестирования CTest
add_subdirectory(tests)
# подключаем папку tests -> через нее CMake заходит в файл tests/CMakeLists.txt и добавляет тесты в проект

add_custom_target(run
    COMMAND lab4_exec
    DEPENDS lab4_exec
)