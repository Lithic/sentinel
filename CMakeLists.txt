cmake_minimum_required (VERSION 3.1.0)

set(PROJECT_NAME sentinel)

project(${PROJECT_NAME})
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-std=c++11)
endif()

# sentinel
include_directories(include)
file(GLOB LIB_HEADERS "include/sentinel/*.h")
file(GLOB LIB_SOURCES "src/sentinel/*.cpp")
add_library(${PROJECT_NAME} ${LIB_HEADERS} ${LIB_SOURCES})
target_link_libraries(${PROJECT_NAME})

# sentinel-test
include_directories(test/include)
file(GLOB TEST_HEADERS "test/include/sentinel/*.h")
file(GLOB TEST_SOURCES "test/src/sentinel/*.cpp")
set(TEST_SOURCES ${TEST_SOURCES} "test/src/main.cpp")
add_library(${PROJECT_NAME}-test ${TEST_HEADERS} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
