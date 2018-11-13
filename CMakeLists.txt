cmake_minimum_required(VERSION 3.0)
project(meuProjeto)

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/include")

#file(GLOB SOURCES "src/*.cpp")
#add_executable(programa ${SOURCES})

add_executable(programa main.cpp src/Matematica.cpp)
