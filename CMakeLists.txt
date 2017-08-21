cmake_minimum_required (VERSION 3.1.0)

set(PROJECT_NAME sentinel)
set(CMAKE_CXX_STANDARD 11)

project(${PROJECT_NAME})

# sentinel
set(SENTINEL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${SENTINEL_INCLUDE_DIR})
file(GLOB LIB_HEADERS "include/sentinel/*.h")
file(GLOB LIB_SOURCES "src/sentinel/*.cpp")
add_library(${PROJECT_NAME} ${LIB_HEADERS} ${LIB_SOURCES})
target_link_libraries(${PROJECT_NAME})

# sentinel-test
include_directories(test/include)
file(GLOB TEST_HEADERS "test/include/sentinel/*.h")
file(GLOB TEST_SOURCES "test/src/sentinel/*.cpp")
set(TEST_SOURCES ${TEST_SOURCES} "test/src/main.cpp")
add_executable(${PROJECT_NAME}-test ${TEST_HEADERS} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
