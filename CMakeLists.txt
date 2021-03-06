cmake_minimum_required(VERSION 3.0)
project(rma)
# project(rma CXX)

find_package(MPI REQUIRED)

set(PEBBL_ROOT ${CMAKE_SOURCE_DIR}/external/pebbl)

#include(ExternalProject)
#set( EXTERNAL_INSTALL_DIR ${CMAKE_BINARY_DIR}/external_install )
#add_subdirectory(external)

set(PEBBL_LIBRARIES ${PEBBL_ROOT}/build/src/pebbl/libpebbl.a)
set(PEBBL_INCLUDES  ${PEBBL_ROOT}/src ${PEBBL_ROOT}/build/src)

set(CMAKE_CXX_COMPILER mpicxx)
# set(CMAKE_CXX_COMPILER /usr/bin/mpicxx)

set(CMAKE_CXX_COMPILE_FLAGS     ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS        ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
set(CMAKE_CXX_STANDARD          11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g -Wall -Werror=reorder")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

MESSAGE( STATUS "C++ compiler:             ${CMAKE_CXX_COMPILER}" )
MESSAGE( STATUS "C++ compiler ID:          ${CMAKE_CXX_COMPILER_ID}" )
MESSAGE( STATUS "C++ compiler version:     ${CMAKE_CXX_COMPILER_VERSION}" )
MESSAGE( STATUS "C++ compiler string:      ${CXX_COMPILER_STRING}" )
MESSAGE( STATUS "MPI C++ compiler:         ${MPI_CXX_COMPILER}" )
MESSAGE( STATUS "MPI C++ compiler options: ${MPI_CXX_COMPILE_OPTIONS}" )
MESSAGE( STATUS "MPI libraries:            ${MPI_LIBRARIES}" )
MESSAGE( STATUS "PEBBL include dir:        ${PEBBL_INCLUDES}" )
MESSAGE( STATUS "PEBBL libraries:          ${PEBBL_LIBRARIES}" )

include_directories(
  ${MPI_INCLUDE_PATH}
  ${CMAKE_SOURCE_DIR}
  ${PEBBL_INCLUDES}
)

add_library(lrma STATIC
            src/argRMA.cpp
            src/baseRMA.cpp
            src/dataRMA.cpp
            src/greedyRMA.cpp
            src/parRMA.cpp
            src/serRMA.cpp
            src/solveRMA.cpp
            src/utility.cpp
)

target_link_libraries(lrma ${PEBBL_LIBRARIES})

add_executable(rma src/driver.cpp)

target_link_libraries(rma
                      ${PEBBL_LIBRARIES}
                      lrma)

#################################################

# pybind11
# Message("Link pybind11")
# add_subdirectory(external/pybind11)

# find_package(PythonInterp REQUIRED)
# FIND_PACKAGE( PythonLibs )
# INCLUDE_DIRECTORIES( ${PYTHON_INCLUDE_PATH} )
# INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR} )
# INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/src )

# pybind11_add_module(pyRMA src/python/pythonInterface.cpp)
# pybind11_add_module(pyRMA ./src/solveRMA.cpp)
