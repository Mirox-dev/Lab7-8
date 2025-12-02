cmake_minimum_required(VERSION 3.15)

# Название проекта
project(pcb_demo VERSION 0.1 LANGUAGES CXX)

# Используем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Источники проекта
set(SRC_LIST
        main.cpp
        ProcessList.cpp
)

# Создаём исполняемый файл
add_executable(pcb_demo ${SRC_LIST})

# Указываем CLion, где искать заголовки
target_include_directories(pcb_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Включаем предупреждения компилятора
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(pcb_demo PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(pcb_demo PRIVATE /W4)
endif()
