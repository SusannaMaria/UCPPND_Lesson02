cmake_minimum_required(VERSION 3.0.0)
add_subdirectory(Lessons02)
add_subdirectory(Lessons03)

include(cmake/googletest.cmake)

fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
)
