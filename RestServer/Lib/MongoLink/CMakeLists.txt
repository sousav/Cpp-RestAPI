cmake_minimum_required(VERSION 3.9)
set(NAME MongoLink)
project(${NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

## Dependencies
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)


## Setup Logger library
if (NOT TARGET Logger)
    add_subdirectory(${PROJECT_SOURCE_DIR}/../Lib/Logger)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/../Lib/Logger/Includes/)


add_library(${NAME} STATIC "")

## Setup the source files
target_sources(${NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/Includes/Database.h
        ${PROJECT_SOURCE_DIR}/Sources/Database.cpp
        ${PROJECT_SOURCE_DIR}/Includes/ICollection.h
        ${PROJECT_SOURCE_DIR}/Includes/ACollection.h
        ${PROJECT_SOURCE_DIR}/Sources/ACollection.cpp
        ${PROJECT_SOURCE_DIR}/Includes/IModel.h
        ${PROJECT_SOURCE_DIR}/Includes/AModel.h
        ${PROJECT_SOURCE_DIR}/Sources/AModel.cpp
        )


## Setup default include path
include_directories(
        ${PROJECT_SOURCE_DIR}/Includes/

        ${PROJECT_SOURCE_DIR}/../Json/Includes
        ${LIBMONGOCXX_INCLUDE_DIR}
        ${LIBBSONCXX_INCLUDE_DIR}
        /usr/local/include/mongocxx/v_noabi
        /usr/local/include/bsoncxx/v_noabi
)

## Setup link path
link_directories(
        ${PROJECT_BINARY_DIR}/Lib/Logger/
)


## Setup used library
target_link_libraries(${NAME}
        Logger

        ${LIBMONGOCXX_LIBRARIES}
        ${LIBBSONCXX_LIBRARIES}
        )
