cmake_minimum_required(VERSION 3.10)
project(TreePrinter)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定源文件目录
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 添加源文件
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Component.cpp
    ${SOURCE_DIR}/Iterator.cpp
    ${SOURCE_DIR}/PrintStrategy.cpp
    ${SOURCE_DIR}/jsonToTree.cpp
    ${SOURCE_DIR}/Printer.cpp
)

# 添加头文件目录
include_directories(${SOURCE_DIR})

# 定义可执行文件
add_executable(TreePrinter ${SOURCES})
