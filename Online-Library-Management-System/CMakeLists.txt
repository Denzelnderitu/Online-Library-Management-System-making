cmake_minimum_required(VERSION 3.5)
project(OnlineLibraryManagementSystem)


include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(demo src/main.cpp src/Book.cpp src/User.cpp src/Library.cpp)
add_executable(tests tests/tests.cpp src/Book.cpp src/User.cpp src/Library.cpp)
