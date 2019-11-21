cmake_minimum_required(VERSION 3.15)
project(comp_distribuida)
set(CMAKE_CXX_STANDARD 14)
# Si se desea debuggear se debe eliminar esto

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_ALL "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
# Hasta aqui.

add_executable(comp_distribuida main.cpp persistencia.cpp persistencia.h calculoJacobi.cpp calculoJacobi.h)
target_link_libraries(comp_distribuida sqlite3)