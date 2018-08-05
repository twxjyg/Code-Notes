cmake_minimum_required(VERSION 2.8)

project(alglib_study)

set(CMAKE_BUILD_TYPE Debug)

# Required and optional packages
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

find_package(ALGLIB REQUIRED)

add_executable(curve_fitting
    src/curve_fitting.cpp
    src/geometry_types.h
)
target_link_libraries(curve_fitting
    ${ALGLIB_LIBRARIES}
)

add_executable(qp_demo
    src/qp_demo.cpp
)
target_link_libraries(qp_demo
    ${ALGLIB_LIBRARIES}
)
