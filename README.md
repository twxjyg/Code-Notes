# Why
As a software engineer who has lack of math knowledge, I want to solve some numeric computting problem like how to fit curve from a list of 2D points, how to find the intersection points of two curve, how to solve some function like a + a_1x + a_2 x*x + a_3 x*x*x = 0 ?

Seems like these are very simple math problem right ? but I found that there no explicity c++ library is help to easily solve these problem, but there a lot of library like ALGLIB, lapck, eigen as so on some how have ability to solve these problem, but you need have a lot of math knowledge to find them out.

So, this project is aim to solve problem like I said at first segment by ALGLIB and try to give out very easily understand API to help who have no idea about UBLAS, Linear blablabla, Eigenvalues???, deep numeric computting blablabla to solve your problem.

# Why2
I was a start-up company CTO, at least some days ago, because some tough reason I need start find a job, so a lot of baisc knowledage need to self-check, I will push some very simple coding test and continue add some basic mathematical library usage for you.


# Coding Test Guidline

## Common Data Structure

this file use to declare needed data structure like: Binary-Tree, Linked-List, Graph ....

[src/data_struct_types.h](https://github.com/twxjyg/Code-Notes/blob/master/src/data_struct_types.h)

this file use to declare robotics related data structure like: Point, Pose, Area ...

[src/geometry_types.h](https://github.com/twxjyg/Code-Notes/blob/master/src/geometry_types.h)


## Common Utils

this file use to implement small utils like print utils, debug utils, visualization utils ...

[src/print_utils](https://github.com/twxjyg/Code-Notes/blob/master/src/print_utils.h)



## Algorthims (Computer Seiance)

### Binary-Tree Part

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| ** | BFS traversing |[src/bfs_traversing.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/bfs_traversing.cpp)|
|1| *** | DFS traversing and recall |[src/dfs_all_path.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/dfs_all_path.cpp)|
|2| ** | DFS traversing | [src/dfs_traversing.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/dfs_traversing.cpp)|
|3| *** | BFS and Stack | [src/is_binary_tree_symmetrical.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/is_binary_tree_symmetrical.cpp)|
|4| *** | Reconstruct Binary-Tree | [src/reconstruct_binary_tree.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/reconstruct_binary_tree.cpp)|

### Linked-List Part

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| * | Linked-List Reversing|[src/reverse_link_list.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/reverse_link_list.cpp)|


### Sorting

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| *** | Quick Sort | [src/quick_sort.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/quick_sort.cpp) |

### Search

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| *** | Binary-Search | [src/double_bi_search.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/double_bi_search.cpp) |
|1| *** | Dynamic-Programming in Array | [src/max_sum_of_sub_array.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/max_sum_of_sub_array.cpp)|
|2| *** | string permutation in IP adress | [src/string_to_possible_ip.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/string_to_possible_ip.cpp) |

### Matrix

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| *** | Find All Path | [src/matrix_all_path.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/matrix_all_path.cpp) </br> Unfinished|
|1| ** | Dynamic-Programming| [src/matrix_min_sum_path.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/matrix_min_sum_path.cpp)|
|2| ** | DFS in Matrix |[src/simple_path_search.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/simple_path_search.cpp)|
|3| *** | Matrix computation | [src/matrix.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/matrix.cpp)|

### Graph

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0|***|DFS and Recall in Graph|[src/second_short_path.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/second_short_path.cpp) |


## Algorthims (Robotics)

### Curve
|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| ** | Fitting by alglib | [src/curve_fitting_alglib.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/curve_fitting_alglib.cpp)|
|1| ** | Fitting by Eigen | [src/curve_fitting_eigen.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/curve_fitting_eigen.cpp) |
|2| *** | Determine crossing | [src/curve_crossing.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/curve_crossing.cpp) |
|3| *** | Determine crossing 2 | [src/fast_curve_crossing.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/fast_curve_crossing.cpp) |

### Solver

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| ** |Basic Qudratic-Programming | [src/qp_demo.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/qp_demo.cpp) |

### Geometry

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| * | ToLeft Test |[src/to_left_test.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/to_left_test.cpp) |


## C++ Advanced

|ID| Hard-Level | Key Point | File|
-:|:-:|:-:|:-
|0| ** | rvalue and lvalue | [src/rvalue.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/rvalue.cpp)|
|1| *** | template specializing and macro |[src/hammer_of_god.cpp](https://github.com/twxjyg/Code-Notes/blob/master/src/hammer_of_god.cpp)|