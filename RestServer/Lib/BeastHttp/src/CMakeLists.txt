cmake_minimum_required(VERSION 3.11)

project(BeastHttp VERSION 3.0 LANGUAGES CXX)

find_package(Boost 1.70 COMPONENTS system thread)

set(BEASTHTTP_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/../include)
set(BEASTHTTP_EXAMPLES_DIR ${PROJECT_SOURCE_DIR}/examples)
set(BEASTHTTP_TESTS_DIR ${PROJECT_SOURCE_DIR}/tests)

option(USE_MAKE_SHARED "Allocate memory object with std::make_shared" ON)

configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/version.hxx.in"
  "${BEASTHTTP_INCLUDE_PATH}/http/base/version.hxx"
)

configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/config.hxx.in"
  "${BEASTHTTP_INCLUDE_PATH}/http/base/config.hxx"
)

if(NOT CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
endif()

if( NOT CMAKE_BUILD_TYPE )
   SET(CMAKE_BUILD_TYPE Debug)
endif()

message("CXX=" ${CMAKE_CXX_COMPILER})
message("CXXFLAGS=" ${CMAKE_CXX_FLAGS})
message("CMAKE_BUILD_TYPE=" ${CMAKE_BUILD_TYPE})

include_directories(${BEASTHTTP_INCLUDE_PATH})
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory("${BEASTHTTP_EXAMPLES_DIR}/reactor")
add_subdirectory("${BEASTHTTP_EXAMPLES_DIR}/reactor_ssl")
add_subdirectory("${BEASTHTTP_EXAMPLES_DIR}/reactor_cxx11")
add_subdirectory("${BEASTHTTP_EXAMPLES_DIR}/reactor_timers")
add_subdirectory("${BEASTHTTP_EXAMPLES_DIR}/reactor_flex")
add_subdirectory("${BEASTHTTP_EXAMPLES_DIR}/reactor_sse")
enable_testing ()
add_subdirectory("${BEASTHTTP_TESTS_DIR}/display")
add_subdirectory("${BEASTHTTP_TESTS_DIR}/basic_router")
add_subdirectory("${BEASTHTTP_TESTS_DIR}/chain_router")
add_subdirectory("${BEASTHTTP_TESTS_DIR}/param")
