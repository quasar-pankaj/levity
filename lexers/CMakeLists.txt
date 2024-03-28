add_library(lexers STATIC common src/rpn_parser.cpp)
target_include_directories(lexers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(lexers PUBLIC common)

# Assume the test executable is named "tests"
add_executable(
    lexer_tests 
    test/test.cpp
)

# Link the GoogleTest libraries
target_link_libraries(lexer_tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
gtest_discover_tests(lexer_tests)

add_test(NAME lexer_tests COMMAND lexer_tests)
