cmake_minimum_required(VERSION 3.9)
set(NAME SharedLib)
project(${NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_library(${NAME} STATIC "")

## Setup the source files
target_sources(${NAME}
    PRIVATE

    ${PROJECT_SOURCE_DIR}/Includes/SharedLib.h
    ${PROJECT_SOURCE_DIR}/Sources/SharedLib.cpp
)


## Setup default include path
include_directories(
        ${PROJECT_SOURCE_DIR}/Includes/
)

## Setup link path
link_directories(

)


## Setup used library
target_link_libraries(${NAME}

)
