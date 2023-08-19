cmake_minimum_required(VERSION 3.5)
project(cman)

# Here add additional source files in the SRC variable
file(GLOB SRC "src/lib/**/*.cpp")
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED on)
cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_library(${PROJECT_NAME}-lib STATIC ${SRC})
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

# Testing
enable_testing()
add_executable(${PROJECT_NAME}-ut src/cman.ut.cpp)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
