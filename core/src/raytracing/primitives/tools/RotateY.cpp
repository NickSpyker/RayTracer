/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** RotateY.cpp
*/

#include "MathStandard.hpp"
#include "RotateY.hpp"

#include <utility>

namespace RayTracer
{
    RotateY::RotateY(std::shared_ptr<Hittable> object, double angle):
    _object(std::move(object)), angle(angle)
    {
        double rad = Math::deg_to_rad(angle);

        this->sinTheta = std::sin(rad);
        this->cosTheta = std::cos(rad);

        this->hashBox = this->_object->boundingBox(0.0, 1.0, this->box);

        Math::Vector<3> min(Math::infinity, Math::infinity, Math::infinity);
        Math::Vector<3> max(-Math::infinity, -Math::infinity, -Math::infinity);

        for (int i{0}; i < 2; i++)
        {
            for (int j{0}; j < 2; j++)
            {
                for (int k{0}; k < 2; k++)
                {
                    double x = i * this->box.max()[0] + (1 - i) * this->box.min()[0];
                    double y = j * this->box.max()[1] + (1 - j) * this->box.min()[1];
                    double z = k * this->box.max()[2] + (1 - k) * this->box.min()[2];

                    double newX = this->cosTheta * x + this->sinTheta * z;
                    double newZ = -this->sinTheta * x + this->cosTheta * z;

                    Math::Vector<3> t(newX, y, newZ);

                    for (int l{0}; l < 3; l++)
                    {
                        min[l] = std::fmin(min[l], t[l]);
                        max[l] = std::fmax(max[l], t[l]);
                    }
                }
            }
        }

        this->box = AxisAlignedBBox(min, max);

        this->setName("rotated " + this->_object->getName());
    }

    bool RotateY::hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const
    {
        Math::Point3D origin = ray.origin;
        Math::Vector<3> direction = ray.direction;

        origin[0] = this->cosTheta * ray.origin[0] - this->sinTheta * ray.origin[2];
        origin[2] = this->sinTheta * ray.origin[0] + this->cosTheta * ray.origin[2];

        direction[0] = this->cosTheta * ray.direction[0] - this->sinTheta * ray.direction[2];
        direction[2] = this->sinTheta * ray.direction[0] + this->cosTheta * ray.direction[2];

        Ray rotated(origin, direction, ray.time());

        if (!this->_object->hit(rotated, tMin, tMax, rec))
        {
            return false;
        }

        Math::Point3D p = rec.p;
        Math::Vector<3> normal = rec.normal;

        p[0] =  this->cosTheta*rec.p[0] + this->sinTheta*rec.p[2];
        p[2] = -this->sinTheta*rec.p[0] + this->cosTheta*rec.p[2];

        normal[0] =  this->cosTheta*rec.normal[0] + this->sinTheta*rec.normal[2];
        normal[2] = -this->sinTheta*rec.normal[0] + this->cosTheta*rec.normal[2];

        rec.p = p;
        rec.setFaceNormal(rotated, normal);

        return true;
    }

    bool RotateY::boundingBox(double t0, double t1, AxisAlignedBBox &output) const
    {
        output = this->box;
        return this->hashBox;
    }
}
