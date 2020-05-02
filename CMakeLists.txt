cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

project(shell-grid)

include_directories(
    include
)

set(SHELL_GRID_SHARED_SOURCES
    src/cell/numeric.cpp
    src/cell/null.cpp
    src/cell/string.cpp
    src/grid.cpp
)

set(SHELL_GRID_SOURCES
    src/main.cpp
    ${SHELL_GRID_SHARED_SOURCES}
)

if(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
    set(CMAKE_INSTALL_INCLUDEDIR include)
endif(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)

# installation of shell-grid CXX library headers
install(DIRECTORY include/shell-grid DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#----------------#
# Static library #
#----------------#

project(shell-grid VERSION 0.0.3 DESCRIPTION "shell-grid")

add_library(${PROJECT_NAME} STATIC ${SHELL_GRID_SHARED_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/shell-grid.h)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "shell-grid")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS -fPIC)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

install (TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    COMPONENT library
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
