cmake_minimum_required(VERSION 3.15)

project(pcb_demo
        VERSION 0.1
        LANGUAGES CXX
)

# Use C++17 (change to 20 if you prefer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type if none specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Useful compiler warnings (added only for supported compilers)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

# Sources
set(SRC_LIST
        main.cpp
        ProcessList.cpp
)

# Create executable
add_executable(pcb_demo ${SRC_LIST})

# Include current directory so headers are found
target_include_directories(pcb_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Enable address sanitizer for debug builds (optional, only for clang/gcc)
option(ENABLE_ASAN "Enable AddressSanitizer for Debug builds" ON)
if (ENABLE_ASAN AND CMAKE_BUILD_TYPE STREQUAL "Debug" AND (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang"))
    message(STATUS "Enabling AddressSanitizer for Debug build")
    target_compile_options(pcb_demo PRIVATE -fsanitize=address -fno-omit-frame-pointer)
    target_link_options(pcb_demo PRIVATE -fsanitize=address)
endif()

# Installation (optional)
install(TARGETS pcb_demo
        RUNTIME DESTINATION bin)

# Add a small target to run the binary via 'cmake --build . --target run' (only local convenience)
add_custom_target(run
        COMMAND $<TARGET_FILE:pcb_demo>
        DEPENDS pcb_demo
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running pcb_demo..."
)
