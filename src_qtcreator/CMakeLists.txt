cmake_minimum_required(VERSION 3.16)

project(Snake LANGUAGES C)

find_package(SDL2 REQUIRED)
include_directories({SDL2_INCLUDE_DIR})

add_executable(Snake main.c


    map.h
    snake.h
    snake.c)


target_link_libraries(Snake ${SDL2_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS Snake
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
