add_executable(levity src/main.cpp)
target_include_directories(levity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(levity PRIVATE common)

# Assume the test executable is named "tests"
add_executable(
    main_tests 
    test/test.cpp
)

# Link the GoogleTest libraries
target_link_libraries(main_tests gtest gtest_main)

# Include the GoogleTest module and discover tests
include(GoogleTest)
gtest_discover_tests(main_tests)

add_test(NAME main_tests COMMAND main_tests)
