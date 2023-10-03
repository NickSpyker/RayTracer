/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** ObjectFactory.cpp
*/

#include "Box.hpp"
#include "Cone.hpp"
#include "Sphere.hpp"
#include "PlaneYZ.hpp"
#include "PlaneXZ.hpp"
#include "PlaneXY.hpp"
#include "Cylinder.hpp"
#include "ObjectFactory.hpp"

std::shared_ptr<RayTracer::Hittable> RayTracer::ObjectFactory::createBox(
        const Math::Point3D &p0,
        const Math::Point3D &p1,
        const std::shared_ptr<Material> &material)
{
    return std::make_shared<
            RayTracer::Box
    >(p0, p1, material);
}

std::shared_ptr<RayTracer::Hittable> RayTracer::ObjectFactory::createCylinder(
        const Math::Point3D &center,
        double radius,
        double height,
        const std::shared_ptr<Material> &material)
{
    return std::make_shared<
            RayTracer::Cylinder
    >(center, radius, height, material);
}

std::shared_ptr<RayTracer::Hittable> RayTracer::ObjectFactory::createSphere(
        const Math::Point3D &center,
        double radius,
        const std::shared_ptr<Material> &material)
{
    return std::make_shared<
            RayTracer::Sphere
    >(center, radius, material);
}

std::shared_ptr<RayTracer::Hittable> RayTracer::ObjectFactory::createCone(
        const Math::Point3D &center,
        double height,
        double radius,
        const std::shared_ptr<Material> &material)
{
    return std::make_shared<
            RayTracer::Cone
    >(Math::Vector<3>(center.x, center.y, center.z), height, radius, material);
}

std::shared_ptr<RayTracer::Hittable> RayTracer::ObjectFactory::createPlane(
        const Math::Point3D &p0,
        Math::Point3D p1,
        const std::shared_ptr<Material> &material)
{
    if (p0.x == p1.x)
    {
        double x = p0.x;
        double y0 = p0.y < p1.y ? p0.y : p1.y;
        double y1 = p0.y < p1.y ? p1.y : p0.y;
        double z0 = p0.z < p1.z ? p0.z : p1.z;
        double z1 = p0.z < p1.z ? p1.z : p0.z;

        return std::make_shared<
                RayTracer::PlaneYZ
        >(y0, y1, z0, z1, x, material);
    }

    if (p0.y == p1.y)
    {
        double y = p0.y;
        double x0 = p0.x < p1.x ? p0.x : p1.x;
        double x1 = p0.x < p1.x ? p1.x : p0.x;
        double z0 = p0.z < p1.z ? p0.z : p1.z;
        double z1 = p0.z < p1.z ? p1.z : p0.z;

        return std::make_shared<
                RayTracer::PlaneXZ
        >(x0, x1, z0, z1, y, material);
    }

    if (p0.z == p1.z)
    {
        double z = p0.z;
        double x0 = p0.x < p1.x ? p0.x : p1.x;
        double x1 = p0.x < p1.x ? p1.x : p0.x;
        double y0 = p0.y < p1.y ? p0.y : p1.y;
        double y1 = p0.y < p1.y ? p1.y : p0.y;

        return std::make_shared<
                RayTracer::PlaneXY
        >(x0, x1, y0, y1, z, material);
    }

    throw std::runtime_error("a plane should always be created aligned to one of the x, y, or z axes");
}
