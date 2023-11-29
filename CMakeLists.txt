cmake_minimum_required(VERSION 3.10)
project(PageRankProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(code/src)
include_directories(/opt/homebrew/include)

# Add the executable for the tests
add_executable(tests code/tests/tests.cpp code/src/PageRank.cpp)

# Locate the Catch2 testing framework
find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)
