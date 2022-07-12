cmake_minimum_required(VERSION 3.0.0)

set(This maze)
project(${This} VERSION 0.1.0)

include(CTest)
enable_testing()



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(googletest)

set(Headers
    room.hpp
    graph.hpp
    stringhandle.cpp
)

set(Sources 
    room.cpp 
    main.cpp
    graph.cpp
    stringhandle.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)

add_executable(run ${Sources} ${Headers})