cmake_minimum_required(VERSION 3.10)
project(HuffmanCompressor)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(HuffmanCompressor
    src/main.cpp
    src/HuffmanCoding.cpp
)
