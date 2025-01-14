if(NOT TARGET GTest::gtest_main)
    find_package(GTest QUIET)
endif()

add_executable(calculator_test
    calculator_test.cpp
)

target_link_libraries(calculator_test
    PRIVATE
        ${PROJECT_NAME}::mylib
        GTest::gtest_main
)

add_test(NAME calculator_test COMMAND calculator_test) 