add_executable(vm STATIC src/main.cpp)
target_include_directories(vm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(vm PRIVATE common)

# Assume the test executable is named "tests"
add_executable(
    tests 
    test/test.cpp
)

# Link the GoogleTest libraries
target_link_libraries(tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
gtest_discover_tests(tests)

add_test(NAME tests COMMAND tests)
