/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** Box.cpp
*/

#include <memory>
#include "PlaneYZ.hpp"
#include "PlaneXZ.hpp"
#include "PlaneXY.hpp"
#include "Box.hpp"

namespace RayTracer
{
    Box::Box(const Math::Point3D &p0, const Math::Point3D &p1, const std::shared_ptr<Material> &material)
    {
        this->setName("box");

        this->_boxMin = Math::Vector<3>(p0.x, p0.y, p0.z);
        this->_boxMax = Math::Vector<3>(p1.x, p1.y, p1.z);

        this->_sides.add(std::make_shared<PlaneXY>(p0.x, p1.x, p0.y, p1.y, p1.z, material));
        this->_sides.add(std::make_shared<PlaneXY>(p0.x, p1.x, p0.y, p1.y, p0.z, material));

        this->_sides.add(std::make_shared<PlaneXZ>(p0.x, p1.x, p0.z, p1.z, p1.y, material));
        this->_sides.add(std::make_shared<PlaneXZ>(p0.x, p1.x, p0.z, p1.z, p0.y, material));

        this->_sides.add(std::make_shared<PlaneYZ>(p0.y, p1.y, p0.z, p1.z, p1.x, material));
        this->_sides.add(std::make_shared<PlaneYZ>(p0.y, p1.y, p0.z, p1.z, p0.x, material));
    }

    bool Box::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &rec) const
    {
        return this->_sides.hit(ray, tMin, tMax, rec);
    }

    bool Box::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &output) const
    {
        output = AxisAlignedBBox(this->_boxMin, this->_boxMax);
        return true;
    }
}
