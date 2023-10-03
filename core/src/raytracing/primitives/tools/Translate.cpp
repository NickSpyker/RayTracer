/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** Translate.cpp
*/

#include "Translate.hpp"

#include <utility>

namespace RayTracer
{
    Translate::Translate(std::shared_ptr<Hittable> object, const Math::Vector<3> &displacement):
    _object(std::move(object)), _offset(displacement)
    {
        this->setName("translated " + this->_object->getName());
    }

    bool Translate::hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const
    {
        Math::Point3D p(ray.origin.x - this->_offset[0], ray.origin.y - this->_offset[1], ray.origin.z - this->_offset[2]);
        Ray moved(p, ray.direction, ray.time());

        if (!this->_object->hit(moved, tMin, tMax, rec))
        {
            return false;
        }

        rec.p[0] += this->_offset[0];
        rec.p[1] += this->_offset[1];
        rec.p[2] += this->_offset[2];

        rec.setFaceNormal(moved, rec.normal);

        return true;
    }

    bool Translate::boundingBox(double t0, double t1, AxisAlignedBBox &output) const
    {
        if (!this->_object->boundingBox(t0, t1, output))
        {
            return false;
        }

        output = AxisAlignedBBox(
            output.min() + this->_offset,
            output.max() + this->_offset
        );

        return true;
    }
}
