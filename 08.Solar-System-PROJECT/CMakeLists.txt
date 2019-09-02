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
        sources/2D/LineSegment.cpp
        includes/2D/LineSegment.h
        sources/2D/MyPoint2D.cpp
        includes/2D/MyPoint2D.h
        sources/3D/MyPoint3D.cpp
        includes/3D/MyPoint3D.h
        sources/MyWidget.cpp
        includes/MyWidget.h
        sources/Matrices/TransformationMatrix4x4.cpp
        includes/Matrices/TransformationMatrix4x4.h
        sources/2D/Triangle.cpp
        includes/2D/Triangle.h
        sources/3D/Triangle3D.cpp
        includes/3D/Triangle3D.h
        sources/TriangleTexturing.cpp
        includes/TriangleTexturing.h
        sources/3D/Vector3D.cpp
        includes/3D/Vector3D.h
        sources/3D/Sphere.cpp
        includes/3D/Sphere.h
        sources/MilkyWay.cpp
        includes/MilkyWay.h
        sources/Matrices/SunTransformationMatrix.cpp
        includes/Matrices/SunTransformationMatrix.h
        sources/Matrices/PlanetTransformationMatrix.cpp
        includes/Matrices/PlanetTransformationMatrix.h)

target_link_libraries(08_Solar_System_PROJECT Qt5::Core)
target_link_libraries(08_Solar_System_PROJECT Qt5::Widgets)
#target_link_libraries(08_Solar_System_PROJECT Qt5::Quick))