cmake_minimum_required(VERSION 3.24)
project (raytracer)

set(CMAKE_CXX_STANDARD 20)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.hpp)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(header_list)
HEADER_DIRECTORIES(core)

include_directories(${header_list})

FILE(GLOB_RECURSE src_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(raytracer ${src_files}
        core/src/raytracing/primitives/HittableList.cpp
        core/src/raytracing/primitives/HittableList.hpp api/math/MathStandard.hpp
        core/src/raytracing/material/Material.hpp
        core/src/raytracing/material/Diffuse.cpp
        core/src/raytracing/material/Diffuse.hpp
        core/src/raytracing/material/Metal.cpp
        core/src/raytracing/material/Metal.hpp
        core/src/raytracing/material/Dielectric.cpp
        core/src/raytracing/material/Dielectric.hpp
        core/src/scene/randomScene.cpp
        core/src/raytracing/primitives/MovingSphere.cpp
        core/src/raytracing/primitives/MovingSphere.hpp
        core/src/raytracing/primitives/AxisAlignedBoundingBox.cpp
        core/src/raytracing/primitives/AxisAlignedBoundingBox.hpp
        core/src/raytracing/primitives/BoundingVolHierarchy.cpp
        core/src/raytracing/primitives/BoundingVolHierarchy.hpp
        core/src/raytracing/texture/Texture.hpp
        core/src/raytracing/texture/SolidColor.cpp
        core/src/raytracing/texture/SolidColor.hpp
        core/src/raytracing/texture/Checker.cpp
        core/src/raytracing/texture/Checker.hpp
        core/src/raytracing/texture/random/Perlin.cpp
        core/src/raytracing/texture/random/Perlin.hpp
        core/src/raytracing/texture/NoiseTexture.hpp
        core/src/raytracing/material/DiffuseLight.cpp
        core/src/raytracing/material/DiffuseLight.hpp
        core/src/raytracing/primitives/PlaneXY.hpp
        core/src/raytracing/primitives/PlaneXY.cpp
        core/src/raytracing/primitives/PlaneXZ.hpp
        core/src/raytracing/primitives/PlaneXZ.cpp
        core/src/raytracing/primitives/PlaneYZ.hpp
        core/src/raytracing/primitives/PlaneYZ.cpp
        core/src/raytracing/primitives/Box.cpp
        core/src/raytracing/primitives/Box.hpp
        core/src/raytracing/primitives/tools/Translate.cpp
        core/src/raytracing/primitives/tools/Translate.hpp
        core/src/raytracing/primitives/tools/RotateY.cpp
        core/src/raytracing/primitives/tools/RotateY.hpp
        core/src/scene/SceneBuilder.cpp
        core/src/scene/SceneBuilder.hpp
        core/src/raytracing/primitives/Cylinder.cpp
        core/src/raytracing/primitives/Cylinder.hpp
        core/src/raytracing/primitives/Cone.cpp
        core/src/raytracing/primitives/Cone.hpp
        core/src/factories/ObjectFactory.cpp
        core/src/factories/ObjectFactory.hpp)
