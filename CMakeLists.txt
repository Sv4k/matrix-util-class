cmake_minimum_required(VERSION 3.10)
project(newPrj)

set(CMAKE_CXX_STANDARD 17)

add_executable(newPrj main.cpp Matrix.cpp Matrix.h gausian.cpp gausian.h gausian_w.cpp gausian_w.h matrix_util_functions.cpp matrix_lines_operations.cpp matrix_columns_operations.cpp matrix_operators.cpp Exception.cpp Exception.h Zeydel.cpp Zeydel.h MMN.cpp MMN.h)
