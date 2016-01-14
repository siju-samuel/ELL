#
# cmake file
#

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)

set (PROJ_NAME common)

PROJECT(${PROJ_NAME})

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-std=c++1y)
endif()

set (SRC src/Loaders.cpp)

set (INCLUDE include/Loaders.h)

source_group("src" FILES ${SRC})
source_group("include" FILES ${INCLUDE})
source_group("tcc" FILES ${TCC})

include_directories(include)
include_directories(tcc)
include_directories(../dataset/include)
include_directories(../layers/include)
include_directories(../linear/include)
include_directories(../types/include)
include_directories(../utilities/include)

add_library(${PROJ_NAME} ${SRC} ${INCLUDE} ${TCC})

set_property(TARGET ${PROJ_NAME} PROPERTY FOLDER "libraries")