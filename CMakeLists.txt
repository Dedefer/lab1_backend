cmake_minimum_required(VERSION 3.8)
project(lab1_backend)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Sequence.h ArraySequence.h ListSequence.h SequenceSorts.h Lab1Menu.cpp Lab1Menu.h)
add_executable(lab1_backend ${SOURCE_FILES})