add_library(parsers STATIC 
    src/rpn_parser.cpp
)
target_include_directories(parsers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(parsers PUBLIC common)

# Assume the test executable is named "tests"
add_executable(
    parser_tests 
    test/test.cpp
)

# Link the GoogleTest libraries
target_link_libraries(parser_tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
gtest_discover_tests(parser_tests)

add_test(NAME parser_tests COMMAND parser_tests)
