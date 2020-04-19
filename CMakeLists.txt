cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

project(shell-grid)

include_directories(
    include
)

add_executable(
    ${PROJECT_NAME} src/main.cpp
)

#############
### TESTS ###
#############

project(shell-grid-test)

set(CMAKE_BUILD_TYPE Debug)

set(SCHEDULER_SOURCES_TEST
    tests/main.cpp
)

include_directories(
    include
)

find_library(CPP_UNIT_TEST libcpp-unit-test.a)
message(STATUS "Found cpp-unit-test: ${CPP_UNIT_TEST}")

add_executable(
    ${PROJECT_NAME} tests/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${CPP_UNIT_TEST}
)
