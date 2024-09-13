cmake_minimum_required(VERSION 3.14)
project(SimpleChess)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS  "-Ofast -Wall -pedantic")


add_library(bitboard  app/src/main/cpp/bitboard.cpp)

#TO-DO: Update this to use the new way of doing things.
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  basic_bitboard_test
  app/src/test/cpp/basic_bitboard_test.cpp
  app/src/main/cpp/bitboard.cpp
)

target_link_libraries(
  basic_bitboard_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(basic_bitboard_test)

# examples : https://google.github.io/googletest/quickstart-cmake.html
