add_executable(test_list test_list.cpp)
target_link_libraries(test_list PRIVATE my_lib)
add_test(NAME ListTest COMMAND test_list)



add_executable(test_sort test_sort.cpp)
target_link_libraries(test_sort PRIVATE my_lib)
add_test(NAME SortTest COMMAND test_sort)