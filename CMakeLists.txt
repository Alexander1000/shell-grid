cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

project(shell-grid)

include_directories(
    include
)

set(SHELL_GRID_SHARED_SOURCES
    src/cell.cpp
    src/grid.cpp
)

set(SHELL_GRID_SOURCES
    src/main.cpp
    ${SHELL_GRID_SHARED_SOURCES}
)

add_executable(
    ${PROJECT_NAME} src/main.cpp
    ${SHELL_GRID_SOURCES}
)

#############
### TESTS ###
#############

project(shell-grid-test)

set(CMAKE_BUILD_TYPE Debug)

set(SHELL_GRID_SOURCES_TEST
    tests/main.cpp
    ${SHELL_GRID_SHARED_SOURCES}
)

include_directories(
    include
)

find_library(CPP_UNIT_TEST libcpp-unit-test.a)
message(STATUS "Found cpp-unit-test: ${CPP_UNIT_TEST}")

add_executable(
    ${PROJECT_NAME} tests/main.cpp
    ${SHELL_GRID_SOURCES_TEST}
)

target_link_libraries(${PROJECT_NAME}
    ${CPP_UNIT_TEST}
)
