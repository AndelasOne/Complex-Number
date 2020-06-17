include_directories(../source)
add_executable(google_test tests.cpp)

target_link_libraries(
        google_test
        PUBLIC
        gtest_main
        SourceLib
)

