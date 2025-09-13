cmake_minimum_required(VERSION 4.0)
project(ISA_CPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(ISA_CPP main.cpp
        SimModel.h
        Node.h
        MathFunction.h
        Request.h)
