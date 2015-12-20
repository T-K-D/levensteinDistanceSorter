cmake_minimum_required(VERSION 3.3)
project(levensteinDistanceSorter)
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)


## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    ##set(CMAKE_CXX_FLAGS_RELEASE "-O3")        ## Optimization for release build
    ##set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os")     ## Optimization for MinRelSize build
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
set(TEST_SOURCES test/distance.cpp)

add_library(levenshteinCalculator src/LevenshteinCalculator.cpp src/LevenshteinCalculator.h src/LevenshteinSorter.cpp src/LevenshteinSorter.h)

add_executable(mainExec ${SOURCE_FILES})
add_executable(testExec ${TEST_SOURCES})

target_link_libraries(mainExec
    levenshteinCalculator
)


target_link_libraries(testExec
        levenshteinCalculator
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
