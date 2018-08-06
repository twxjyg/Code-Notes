cmake_minimum_required(VERSION 2.8)

project(alglib_study)

set(CMAKE_BUILD_TYPE Debug)

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