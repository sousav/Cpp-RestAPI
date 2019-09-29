cmake_minimum_required(VERSION 3.9)
set(NAME CPP_restAPI)
project(${NAME})

set(CMAKE_CXX_STANDARD 17)
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


## Dependencies
find_package(Boost REQUIRED COMPONENTS system)


## Setup Logger library
if (NOT TARGET Logger)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/Logger)
    include_directories(${PROJECT_SOURCE_DIR}/Lib/Logger/Includes/)
endif ()

## Setup Argument parsing library
if (NOT TARGET ArgParser)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/ArgParser)
    include_directories(${PROJECT_SOURCE_DIR}/Lib/ArgParser/Includes/)
endif ()

## Setup ClassBase library
if (NOT TARGET ClassBase)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Lib/ClassBase)
    include_directories(${PROJECT_SOURCE_DIR}/Lib/ClassBase/Includes/)
endif ()


## Setup the source files
set(Sources
        ${PROJECT_SOURCE_DIR}/Sources/main.cpp

        ${PROJECT_SOURCE_DIR}/Includes/MainClass.h
        ${PROJECT_SOURCE_DIR}/Sources/MainClass.cpp

        ${PROJECT_SOURCE_DIR}/Includes/Rest/Rest.h
        ${PROJECT_SOURCE_DIR}/Sources/Rest/Rest.cpp

        ${PROJECT_SOURCE_DIR}/Includes/Rest/Router.h
        ${PROJECT_SOURCE_DIR}/Sources/Rest/Router.cpp

        ${PROJECT_SOURCE_DIR}/Routes/ApiRouter.h
        ${PROJECT_SOURCE_DIR}/Routes/Comments/CommentsRouter.h
        )


## Setup default include path
include_directories(
        ${PROJECT_SOURCE_DIR}/Includes
        ${PROJECT_SOURCE_DIR}/Routes

        ${PROJECT_SOURCE_DIR}/Lib/BeastHttp/include
        ${PROJECT_SOURCE_DIR}/Lib/Json/Includes
        ${Boost_INCLUDE_DIRS}
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

        Boost::system
        )
