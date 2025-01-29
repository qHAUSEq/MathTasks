cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем поддержку x64
set(CMAKE_GENERATOR_PLATFORM x64)

# Определяем режим сборки по умолчанию как Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(PROJECT_NAME MTask1)
project(${PROJECT_NAME})

set(SOURCE src/Source.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})