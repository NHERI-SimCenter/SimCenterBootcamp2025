cmake_minimum_required (VERSION 2.6)
set (CMAKE_C_STANDARD 99)

project (Shapes)

include_directories(${PROJECT_SOURCE_DIR})
add_library(ShapeLib ColoredShape.cpp Rectangle.cpp Circle.cpp Ellipse.cpp)

add_executable(shapeList mainList.cpp)
target_link_libraries (shapeList  ShapeLib)

add_executable(shapeContainer mainContainer.cpp)
target_link_libraries (shapeContainer ShapeLib)

