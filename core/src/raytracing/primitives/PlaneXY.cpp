/*
** EPITECH PROJECT, 2022
** PlaneXY
** File description:
** PlaneXY
*/

#include "AxisAlignedBoundingBox.hpp"
#include "PlaneXY.hpp"

RayTracer::PlaneXY::PlaneXY(double x0, double x1, double y0, double y1, double z, const std::shared_ptr<Material>& material):
_x0(x0), _x1(x1), _y0(y0), _y1(y1), _z(z), _material(material)
{
    this->setName("plane xy");
}

bool RayTracer::PlaneXY::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &rec) const
{
    double t = (this->_z - ray.origin.z) / ray.direction[2];

    if (t < tMin || tMax < t)
    {
        return false;
    }

    double x = ray.origin.x + t * ray.direction[0];
    double y = ray.origin.y + t * ray.direction[1];

    if (x < this->_x0 || this->_x1 < x || y < this->_y0 || this->_y1 < y)
    {
        return false;
    }

    rec.u = (x - this->_x0) / (this->_x1 - this->_x0);
    rec.v = (y - this->_y0) / (this->_y1 - this->_y0);
    rec.t = t;

    Math::Vector<3> outwardNormal = Math::Vector<3>(0.0, 0.0, 1.0);
    rec.setFaceNormal(ray, outwardNormal);
    rec.material = this->_material;
    rec.p = ray.at(t);

    return true;
}

bool RayTracer::PlaneXY::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &outputBox) const
{
    outputBox = AxisAlignedBBox(
        Math::Vector<3>(this->_x0, this->_y0, this->_z - 0.0001),
        Math::Vector<3>(this->_x1, this->_y1, this->_z + 0.0001)
    );

    return true;
}
