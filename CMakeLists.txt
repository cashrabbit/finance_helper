# Minimum CMake version required
# Newer versions have more features and better practices
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# Project declaration with version and language support
# LANGUAGES specifies which programming languages are used
project(CerealSerializer 
    VERSION 1.0.0 
    LANGUAGES CXX
)

# Specify C++ standard globally for the entire project
# CMAKE_CXX_STANDARD is a modern way to set language standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforce the specified standard
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions

# Optional: Control build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Modern way to find and include external libraries
# STATIC or INTERFACE libraries are good for header-only libraries like Cereal
add_library(cereal INTERFACE)
target_include_directories(cereal 
    INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include  # Path to Cereal headers
)

# Create executable target
add_executable(serializer 
    driver.cpp# Your main source file
    Transaction.cpp
)

# Link libraries and set include directories for the specific target
target_link_libraries(serializer 
    PRIVATE 
    cereal  # Link the Cereal interface library
)

# Optional: Additional compiler warnings (modern best practice)
if(MSVC)
    target_compile_options(serializer PRIVATE /W4)
else()
    target_compile_options(serializer PRIVATE 
        -Wall 
        -Wextra 
        -Wpedantic 
        -Werror
    )
endif()

# Optional: Install rules for your project
install(TARGETS serializer
    RUNTIME DESTINATION bin  # Where the executable will be installed
)