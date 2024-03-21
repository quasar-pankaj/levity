add_library(common STATIC 
    src/loader.cpp 
    src/vm.cpp
    src/typed_object.cpp
    src/unary_operator.cpp
    src/binary_operator.cpp
    src/ternary_operator.cpp
    src/lexer.cpp
)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(common PRIVATE libmath)

# Assume the test executable is named "tests"
add_executable(
    common_tests 
    test/test.cpp
)

# Link the GoogleTest libraries
target_link_libraries(common_tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
gtest_discover_tests(common_tests)

add_test(NAME common_tests COMMAND common_tests)
