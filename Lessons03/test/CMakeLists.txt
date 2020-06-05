add_executable(
    unit_tests
    test_heuristic.cpp
    test_addtoopen.cpp
    test_compare.cpp 
    test_search.cpp  
    ../astar_maze.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    )


target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_test(NAME unit_tests COMMAND unit_tests)