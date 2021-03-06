cmake_minimum_required(VERSION 3.9.0)

set(INCLUDE_ROOT "/usr/local/include")
set(BOOST_ROOT   "${INCLUDE_ROOT}/boost_1_67_0")
set(LEXERTL_ROOT "${INCLUDE_ROOT}/lexertl")
set(GTEST_ROOT   "${INCLUDE_ROOT}/googletest")

#set(CMAKE_CXX_FLAGS "-g -std=gnu++2a             \
#                     -Werror                     \
#                     -Werror=unused              \
#                     -Wall                       \
#                     -Wextra                     \
#                     -Wno-parentheses            \
#                     -Wno-variadic-macros        \
#                     -Wno-unused-function        \
#                     -Werror=implicit-fallthrough")
#add_compile_definitions(_DEFAULT_SOURCE=1)         #some strange glibc macro warning supression

set(CMAKE_CXX_FLAGS "-g -std=gnu++2a             \
                     -Werror                     \
                     -Wno-parentheses            \
                     -Wno-variadic-macros        \
                     -Wno-unused-function        \
                     -Werror=implicit-fallthrough"
                    CACHE STRING "compiler flags")


file(GLOB SOURCES "src/*.cpp")
# global include for all projects (use target_link_libraries otherwise)
include_directories(include ${BOOST_ROOT} ${LEXERTL_ROOT} ${GTEST_ROOT})



add_library(calamity_core ${SOURCES})

#==========================================================#
    project (lexer.out)
    add_executable(${PROJECT_NAME} main_lexer.cpp)
    target_link_libraries(${PROJECT_NAME} m calamity_core)
#==========================================================#

#==========================================================#
    project (parser.out)

    add_executable(${PROJECT_NAME} main_parser.cpp)
    target_link_libraries(${PROJECT_NAME} m calamity_core)
#==========================================================#

#===========================#
    project(tests.out)
    add_subdirectory(tests)
#===========================#

#=================================#
    project(lexertl_gen.out)
    add_subdirectory(lexertl_gen)
#=================================#

# Pure C test framwork linkings:
#target_link_libraries(${PROJECT_NAME} m check subunit m rt pthread)
