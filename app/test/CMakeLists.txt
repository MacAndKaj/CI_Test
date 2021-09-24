include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(Test math/ComplexNumberTests.cpp)

target_link_libraries(Test Math)

find_package(GTest REQUIRED)
target_include_directories(Test PUBLIC ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
target_link_libraries(Test gtest gmock gtest_main pthread)
