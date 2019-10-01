cmake_minimum_required(VERSION 3.9)
add_subdirectory(./RestServer)

set(NAME CommentsAPI)

project(${NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


## Dependencies
find_package(Boost REQUIRED COMPONENTS system)
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)


## Setup Logger library
if (NOT TARGET Logger)
    add_subdirectory(${PROJECT_SOURCE_DIR}/RestServer/Lib/Logger)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/RestServer/Lib/Logger/Includes)


## Setup ClassBase library
if (NOT TARGET ClassBase)
    add_subdirectory(${PROJECT_SOURCE_DIR}/RestServer/Lib/ClassBase)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/RestServer/Lib/ClassBase/Includes)


## Setup MongoLink library
if (NOT TARGET MongoLink)
    add_subdirectory(${PROJECT_SOURCE_DIR}/RestServer/Lib/MongoLink)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/RestServer/Lib/MongoLink/Includes)


## Setup RestRouter library
if (NOT TARGET RestRouter)
    add_subdirectory(${PROJECT_SOURCE_DIR}/RestServer/Lib/RestRouter)
endif()
include_directories(${PROJECT_SOURCE_DIR}/RestServer/Lib/RestRouter/Includes)


## Setup the source files
add_library(${NAME} SHARED "")

## Setup the source files
target_sources(${NAME}
        PRIVATE

        ${PROJECT_SOURCE_DIR}/BaseRouter.h
        ${PROJECT_SOURCE_DIR}/BaseRouter.cpp
        ${PROJECT_SOURCE_DIR}/Routes/ApiRouter.h
        ${PROJECT_SOURCE_DIR}/Routes/Comments/CommentsRouter.h
        )


## Setup default include path
include_directories(
        ${PROJECT_SOURCE_DIR}/Routes
        ${PROJECT_SOURCE_DIR}/Models

        ${PROJECT_SOURCE_DIR}/RestServer/Lib/Json/Includes
        ${PROJECT_SOURCE_DIR}/RestServer/Lib/BeastHttp/include

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
        RestRouter
        MongoLink

        Boost::system
        ${LIBMONGOCXX_LIBRARIES}
        ${LIBBSONCXX_LIBRARIES}
        )
