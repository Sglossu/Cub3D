cmake_minimum_required(VERSION 3.20)
project(Cub3D C)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/gnl/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/mlx/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/includes)


set(CMAKE_C_COMPILER gcc)
#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

FILE(GLOB SRC
        "main.c"
        "srcs/*.c"
        "srcs/engine/*.c"
        "srcs/parsing/*.c"
        "srcs/utils/*.c"
        "gnl/*.c"
        "srcs/errors/*.c")

add_executable(Cub3D ${SRC} srcs/parsing/color_parser.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -L ${CMAKE_CURRENT_SOURCE_DIR}/minilibx_opengl/ -framework OpenGL -framework AppKit")

include_directories(Cub3D ${CMAKE_CURRENT_SOURCE_DIR}/includes/)			# Расположение заголовочных файлов
target_link_libraries (Cub3D ${CMAKE_CURRENT_SOURCE_DIR}/mlx/libmlx.a)