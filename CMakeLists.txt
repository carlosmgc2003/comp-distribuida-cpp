cmake_minimum_required(VERSION 3.15)
project(comp_distribuida)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp_distribuida main.cpp lecturaDatos.cpp lecturaDatos.h calculoJacobi.cpp calculoJacobi.h)
target_link_libraries(comp_distribuida sqlite3)