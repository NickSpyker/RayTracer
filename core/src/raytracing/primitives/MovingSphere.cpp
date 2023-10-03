/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** MovingSphere.cpp
*/

#include <utility>
#include "MovingSphere.hpp"

RayTracer::MovingSphere::MovingSphere(Math::Vector<3> center0, Math::Vector<3> center1,
                                      double time0, double time1,
                                      double radius,
                                      const std::shared_ptr<Material>& material):
_center0(std::move(center0)), _center1(std::move(center1)),
_time0(time0), _time1(time1),
_radius(radius),
_material(material)
{
    this->setName("blur sphere");
}

bool RayTracer::MovingSphere::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &rec) const
{
    Math::Vector<3> oc = ray.origin - this->center(ray.time());
    double a = ray.direction.lengthSquared();
    double half_b = oc.dot(ray.direction);
    double c = oc.lengthSquared() - this->_radius * this->_radius;

    double discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return false;
    double sqrtd = sqrt(discriminant);

    double root = (-half_b - sqrtd) / a;
    if (root < tMin || tMax < root) {
        root = (-half_b + sqrtd) / a;
        if (root < tMin || tMax < root)
            return false;
    }

    rec.t = root;
    rec.p = ray.at(rec.t);
    Math::Vector<3> outwardNormal = (rec.p - this->center(ray.time())) / this->_radius;
    rec.normal = outwardNormal;
    rec.setFaceNormal(ray, outwardNormal);
    rec.material = this->_material;
    return true;
}

bool RayTracer::MovingSphere::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &outputBox) const
{
    Math::Vector<3> r(this->_radius, this->_radius, this->_radius);

    AxisAlignedBBox box0(
        this->center(this->_time0) - r,
        this->center(this->_time0) + r
    );

    AxisAlignedBBox box1(
        this->center(this->_time1) - r,
        this->center(this->_time1) + r
    );

    outputBox = AxisAlignedBBox::surroundingBox(box0, box1);

    return true;
}

Math::Vector<3> RayTracer::MovingSphere::center(double time) const
{
    double t = (time - this->_time0) / (this->_time1 - this->_time0);
    Math::Vector<3> centerDiff = this->_center1 - this->_center0;

    return this->_center0 + (centerDiff * t);
}
