cmake_minimum_required(VERSION 3.9)
set(NAME RestRouter)
project(${NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

## Dependencies
find_package(Boost REQUIRED COMPONENTS system)
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)

## Setup ClassBase library
if (NOT TARGET ClassBase)
    add_subdirectory(${PROJECT_SOURCE_DIR}/../ClassBase)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/../ClassBase/Includes)

add_library(${NAME} STATIC "")

## Setup the source files
target_sources(${NAME}
        PRIVATE

        ${PROJECT_SOURCE_DIR}/Includes/IRouter.h
        ${PROJECT_SOURCE_DIR}/Includes/ARouter.h
        ${PROJECT_SOURCE_DIR}/Sources/ARouter.cpp
        )


## Setup default include path
include_directories(
        ${PROJECT_SOURCE_DIR}/Includes/

        ${PROJECT_SOURCE_DIR}/../BeastHttp/include
        ${PROJECT_SOURCE_DIR}/../Json/Includes

        ${Boost_INCLUDE_DIRS}
        ${LIBMONGOCXX_INCLUDE_DIR}
        ${LIBBSONCXX_INCLUDE_DIR}
        /usr/local/include/mongocxx/v_noabi
        /usr/local/include/bsoncxx/v_noabi
)

## Setup link path
link_directories(
        ${Boost_LIBRARY_DIRS}
)


## Setup used library
target_link_libraries(${NAME}
        Logger
        ClassBase

        Boost::system
        ${LIBMONGOCXX_LIBRARIES}
        ${LIBBSONCXX_LIBRARIES}
        )
