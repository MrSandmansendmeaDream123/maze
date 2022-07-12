cmake_minimum_required(VERSION 3.0.0)

set(This MazeTests)

set(Source 
    MazeTest.cpp
)

add_executable(${This} ${Source})

target_link_libraries(${This} PUBLIC
    gtest_main
    maze
)

add_test(
    NAME ${This}
    COMMAND ${This}
)