cmake_minimum_required(VERSION 3.17)
project(Skorowidz C)

set(CMAKE_C_STANDARD 90)

add_executable(Skorowidz main.c Skorowidz.c Skorowidz.h ListaStron.c ListaStron.h Ogolne.h Ogolne.c)