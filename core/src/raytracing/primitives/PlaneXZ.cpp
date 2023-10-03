/*
** EPITECH PROJECT, 2022
** PlaneXZ
** File description:
** PlaneXZ
*/

#include "AxisAlignedBoundingBox.hpp"
#include "PlaneXZ.hpp"

RayTracer::PlaneXZ::PlaneXZ(double x0, double x1, double z0, double z1, double y, const std::shared_ptr<Material>& material):
_x0(x0), _x1(x1), _z0(z0), _z1(z1), _y(y), _material(material)
{
    this->setName("plane xz");
}

bool RayTracer::PlaneXZ::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &rec) const
{
    double t = (this->_y - ray.origin.y) / ray.direction[1];

    if (t < tMin || tMax < t)
    {
        return false;
    }

    double x = ray.origin.x + t * ray.direction[0];
    double z = ray.origin.z + t * ray.direction[2];

    if (x < this->_x0 || this->_x1 < x || z < this->_z0 || this->_z1 < z)
    {
        return false;
    }

    rec.u = (x - this->_x0) / (this->_x1 - this->_x0);
    rec.v = (z - this->_z0) / (this->_z1 - this->_z0);
    rec.t = t;

    Math::Vector<3> outwardNormal = Math::Vector<3>(0.0, 1.0, 0.0);
    rec.setFaceNormal(ray, outwardNormal);
    rec.material = this->_material;
    rec.p = ray.at(t);

    return true;
}

bool RayTracer::PlaneXZ::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &outputBox) const
{
    outputBox = AxisAlignedBBox(
        Math::Vector<3>(this->_x0, this->_y - 0.0001, this->_z0),
        Math::Vector<3>(this->_x1, this->_y + 0.0001, this->_z1)
    );

    return true;
}
