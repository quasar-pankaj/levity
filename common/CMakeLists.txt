add_library(common STATIC src/object.cpp src/loader.cpp src/vm.cpp)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(common PRIVATE libmath)

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
