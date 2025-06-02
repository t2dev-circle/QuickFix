# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(fix_server)

# 设置 C++ 标准（可选，如 C++11）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("/usr/local/include")
link_directories("/usr/local/lib")

# 添加可执行文件
add_executable(fix_server
    main.cpp
    acceptor_application.cpp
)

target_link_libraries(fix_server quickfix)