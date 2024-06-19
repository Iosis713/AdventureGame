cmake_minimum_required(VERSION 3.14)
project(AdventureGame)

set(CXX_STANDARD_REQUIRED 20)
set(FLAGS -Wall -Wextra -Werror -Wpedantic)

find_package(GTest REQUIRED)

set(SFML_LIB    sfml-graphics
                sfml-window
                sfml-system)

set(SRC     Source/Sprite.cpp
            Source/Item.cpp
            Source/Inventory.cpp
            Source/Moveable.cpp
            Source/Controllable.cpp)

add_library(${PROJECT_NAME}-lib STATIC  ${SRC})
add_executable(${PROJECT_NAME} main.cpp)
add_executable(TestRunner   testRunner.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIB}
                                              ${PROJECT_NAME}-lib)

target_link_libraries(TestRunner PRIVATE    ${PROJECT_NAME}-lib
                                            ${GTEST_LIBRARIES}
                                            ${SFML_LIB})


target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(TestRunner PRIVATE ${FLAGS})



set_target_properties(${PROJECT_NAME}-lib   PROPERTIES
                                            CXX_STANDARD 20
                                            CXX_STANDARD_REQUIRED ON)


set_target_properties(${PROJECT_NAME}  PROPERTIES
                                       CXX_STANDARD 20
                                       CXX_STANDARD_REQUIRED ON)

set_target_properties(TestRunner    PROPERTIES
                                    CXX_STANDARD 20
                                    CXX_STANDARD_REQUIRED ON)

