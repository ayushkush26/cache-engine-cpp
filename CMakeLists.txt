cmake_minimum_required(VERSION 3.10)

project(cache_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES
    src/*.cpp
)

add_executable(cache_system ${SOURCES})
add_executable(lru_test tests/testLRUCache.cpp src/LRUCache.cpp)
add_executable(lfu_test tests/testLFUCache.cpp src/LFUCache.cpp)