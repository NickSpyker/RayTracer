/*
** EPITECH PROJECT, 2022
** PlaneYZ
** File description:
** PlaneYZ
*/

#include "AxisAlignedBoundingBox.hpp"
#include "PlaneYZ.hpp"

RayTracer::PlaneYZ::PlaneYZ(double y0, double y1, double z0, double z1, double x, const std::shared_ptr<Material>& material):
_y0(y0), _y1(y1), _z0(z0), _z1(z1), _x(x), _material(material)
{
    this->setName("plane yz");
}

bool RayTracer::PlaneYZ::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &rec) const
{
    double t = (this->_x - ray.origin.x) / ray.direction[0];

    if (t < tMin || tMax < t)
    {
        return false;
    }

    double y = ray.origin.y + t * ray.direction[1];
    double z = ray.origin.z + t * ray.direction[2];

    if (z < this->_z0 || this->_z1 < z || y < this->_y0 || this->_y1 < y)
    {
        return false;
    }

    rec.u = (y - this->_y0) / (this->_y1 - this->_y0);
    rec.v = (z - this->_z0) / (this->_z1 - this->_z0);
    rec.t = t;

    Math::Vector<3> outwardNormal = Math::Vector<3>(1.0, 0.0, 0.0);
    rec.setFaceNormal(ray, outwardNormal);
    rec.material = this->_material;
    rec.p = ray.at(t);

    return true;
}

bool RayTracer::PlaneYZ::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &outputBox) const
{
    outputBox = AxisAlignedBBox(
        Math::Vector<3>(this->_x - 0.0001, this->_y0, this->_z0),
        Math::Vector<3>(this->_x + 0.0001, this->_y1, this->_z1)
    );

    return true;
}
