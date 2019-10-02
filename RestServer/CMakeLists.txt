cmake_minimum_required(VERSION 3.9)
set(NAME RestServer)
project(${NAME})

set(CMAKE_CXX_STANDARD 17)
list(INSERT CMAKE_MODULE_PATH 0 cmake)

## Dependencies
find_package(Boost REQUIRED COMPONENTS system)
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)

## Setup Logger library
if (NOT TARGET Logger)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/Logger)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/Lib/Logger/Includes)

## Setup Argument parsing library
if (NOT TARGET ArgParser)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/ArgParser)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/Lib/ArgParser/Includes)

## Setup SharedLib library
if (NOT TARGET SharedLib)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/SharedLib)
endif()
include_directories(${PROJECT_SOURCE_DIR}/Lib/SharedLib/Includes)

## Setup ClassBase library
if (NOT TARGET ClassBase)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/ClassBase)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/Lib/ClassBase/Includes)

## Setup MongoLink library
if (NOT TARGET MongoLink)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/MongoLink)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/Lib/MongoLink/Includes)

## Setup MongoLink library
if (NOT TARGET RestRouter)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/RestRouter)
endif ()
include_directories(${PROJECT_SOURCE_DIR}/Lib/RestRouter/Includes)


## Setup the source files
set(Sources
        ${PROJECT_SOURCE_DIR}/Sources/main.cpp

        ${PROJECT_SOURCE_DIR}/Includes/MainClass.h
        ${PROJECT_SOURCE_DIR}/Sources/MainClass.cpp

        ${PROJECT_SOURCE_DIR}/Includes/Rest/Rest.h
        ${PROJECT_SOURCE_DIR}/Sources/Rest/Rest.cpp
        Lib/RestValidator/Includes/Validator.h Lib/RestValidator/Sources/Validator.cpp)


## Setup default include path
include_directories(
        ${PROJECT_SOURCE_DIR}/Includes

        ${PROJECT_SOURCE_DIR}/Lib/BeastHttp/include
        ${PROJECT_SOURCE_DIR}/Lib/Json/Includes

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

## Create executables
add_executable(${NAME} ${Sources})


## Setup used library
target_link_libraries(${NAME}
        Logger
        ArgParser
        ClassBase
        MongoLink
        SharedLib
        RestRouter

        Boost::system
        ${LIBMONGOCXX_LIBRARIES}
        ${LIBBSONCXX_LIBRARIES}
        )
