##
## EPITECH PROJECT, 2020
## OOP_indie_studio_2019
## File description:
## CMakefile
##
cmake_minimum_required(VERSION 3.11)

project(bomberman)

if (WIN32)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif (WIN32)

if (UNIX)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lsfml-audio")
endif (UNIX)

include_directories(
      include
      include/irr
)

FILE(GLOB SRCS
src/*.cpp
)

FILE(GLOB HDRS include/*.hpp
include/irr/*.hpp
include/irr/*.h
)

ADD_EXECUTABLE(bomberman
   ${SRCS}
   ${HDRS}
)

if (UNIX)
	target_link_libraries(bomberman ${IRRLICHT_LIBRARY} Irrlicht)
endif(UNIX)

if (WIN32)
	link_directories(${Irrlicht_LIBRARIES})
	target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
endif(WIN32)