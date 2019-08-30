cmake_minimum_required(VERSION 3.14)
project(08_Solar_System_PROJECT)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/usr/lib/qt5")

#include_directories(.)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Quick REQUIRED)

add_executable(08_Solar_System_PROJECT
        main.cpp
        sources/LineSegment.cpp
        includes/LineSegment.h
        sources/MyPoint2D.cpp
        includes/MyPoint2D.h
        sources/MyPoint3D.cpp
        includes/MyPoint3D.h
        sources/MyWidget.cpp
        includes/MyWidget.h
        sources/TransformationMatrix4x4.cpp
        includes/TransformationMatrix4x4.h
        sources/Triangle.cpp
        includes/Triangle.h
        sources/Triangle3D.cpp
        includes/Triangle3D.h
        sources/TriangleTexturing.cpp
        includes/TriangleTexturing.h
        sources/Vector3D.cpp
        includes/Vector3D.h sources/Sphere.cpp includes/Sphere.h)

target_link_libraries(08_Solar_System_PROJECT Qt5::Core)
target_link_libraries(08_Solar_System_PROJECT Qt5::Widgets)
#target_link_libraries(08_Solar_System_PROJECT Qt5::Quick))