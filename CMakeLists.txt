cmake_minimum_required(VERSION 3.20)
project(hash_map)

set(CMAKE_CXX_STANDARD 20)

add_executable(hash_map src/main.cpp test/HashMap.cpp test/HashMap.h)
add_executable(hash_map_test
        test/catch.hpp
        test/test.cpp
        test/HashMapTest.cpp test/HashMap.cpp test/HashMap.h)
