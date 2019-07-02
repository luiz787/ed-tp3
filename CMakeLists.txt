cmake_minimum_required(VERSION 3.14)
project(ed_tp3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(src)

add_executable(ed_tp3
        src/BinaryTrie.cpp
        src/BinaryTrie.hpp
        src/main.cpp
        src/MorseCodeChar.cpp
        src/MorseCodeChar.hpp
        src/Node.cpp
        src/Node.hpp)
