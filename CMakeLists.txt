# CMakeLists.txt for organizing the HFT project

cmake_minimum_required(VERSION 3.10)
project(HFTProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Include directories
include_directories( src)  # Add src directory here
include_directories(${Boost_INCLUDE_DIRS})

# Source files
set(SMA_SRC src/sma.cpp)
set(TEST_SRC tests/test_sma.cpp)

# Create a library from the SMA source files
add_library(chtf STATIC ${SMA_SRC})

# Test target
add_executable(test_sma ${TEST_SRC})
target_link_libraries(test_sma ${Boost_LIBRARIES} chtf)

# Enable testing
enable_testing()
add_test(NAME TestSMA COMMAND test_sma)