cmake_minimum_required(VERSION 3.24)

project(
    ConstraintSchedulingPlatform
    VERSION 0.2.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(platform/core)
add_subdirectory(domains/academic)
add_subdirectory(solvers/genetic)
add_subdirectory(tests)
