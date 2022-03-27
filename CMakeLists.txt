cmake_minimum_required(VERSION 2.8)

project(alglib_study)

set(CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_STANDARD 14)

# Required and optional packages
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

find_package(ALGLIB REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(curve_fitting_alglib
    src/curve_fitting_alglib.cpp
    src/geometry_types.h
)
target_link_libraries(curve_fitting_alglib
    ${ALGLIB_LIBRARIES}
)

add_executable(qp_demo
    src/qp_demo.cpp
)
target_link_libraries(qp_demo
    ${ALGLIB_LIBRARIES}
)

add_executable(curve_fitting_eigen
    src/curve_fitting_eigen.cpp
    src/geometry_types.h
)

add_executable(curve_crossing
    src/curve_crossing.cpp
)

add_executable(simple_path_search
    src/simple_path_search.cpp
)

add_executable(to_left_test
    src/to_left_test.cpp
)

add_executable(rvalue
    src/rvalue.cpp
)

add_executable(quick_sort
    src/quick_sort.cpp
)

add_executable(double_bi_search
    src/double_bi_search.cpp
)

add_executable(second_short_path
    src/second_short_path.cpp
)

#add_executable(matrix
#    src/matrix.cpp
#)


add_executable(hammer_of_god
    src/hammer_of_god.cpp
)

add_executable(bfs_traversing
    src/bfs_traversing.cpp
)

add_executable(dfs_traversing
    src/dfs_traversing.cpp
)

add_executable(dfs_all_path
    src/dfs_all_path.cpp
)

add_executable(is_binary_tree_symmetrical
    src/is_binary_tree_symmetrical.cpp
)

add_executable(max_sum_of_sub_array
    src/max_sum_of_sub_array.cpp
)

add_executable(matrix_all_path
    src/matrix_all_path.cpp
)

add_executable(matrix_min_sum_path
    src/matrix_min_sum_path.cpp
)

add_executable(string_to_possible_ip
    src/string_to_possible_ip.cpp
)

add_executable(reverse_link_list
    src/reverse_link_list.cpp
)

add_executable(reconstruct_binary_tree
    src/reconstruct_binary_tree.cpp
)

add_executable(bitwise_operators
    src/bitwise_operators.cpp
)