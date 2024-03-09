cmake_minimum_required(VERSION 3.25.1)

PROJECT(levity VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE "Debug")

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
  OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(common)
#add_subdirectory(compilers)
#add_subdirectory(loaders)
#add_subdirectory(vm)
#add_executable(${PROJECT_NAME} ${SRC_FILES})

#use this if you want to make it accessible to all projects
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#this will make it accessible to the project name
#target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIRS})

# Add the Google Test directory
#add_subdirectory(googletest googletest)

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Assume the test executable is named "chapter1_test"
#add_executable(
#    chapter1_test 
#    test/test.cpp 
#    src/virtual_machine.cpp 
#    src/tokenizer.cpp 
#    src/parser.cpp
#)

# Link the GoogleTest libraries
#target_link_libraries(tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
#gtest_discover_tests(tests)

# Add an executable for each class and its unit test
#add_test(NAME tests COMMAND tests)
# set_tests_properties(chapter1_test PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# If you have any libraries to link
#target_link_libraries(main my_library)
#target_link_libraries(class1_test my_library)
#target_link_libraries(class2_test my_library)
# add more as needed...

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
