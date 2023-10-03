/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Cone.cpp
*/

#include "Cone.hpp"
#include <utility>

RayTracer::Cone::Cone(Math::Vector<3> center, double height, double radius, std::shared_ptr<Material> m):
_center(std::move(center)), _height(height), _radius(radius), _mat(std::move(m))
{
    this->setName("cone");
}

bool RayTracer::Cone::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &rec) const
{
    Math::Vector<3> oc = ray.origin - _center;
    double tan2 = (_radius / _height) * (_radius / _height);

    double a = ray.direction[0]*ray.direction[0] - tan2*ray.direction[1]*ray.direction[1] + ray.direction[2]*ray.direction[2];
    double b = 2*(ray.direction[0]*oc[0] - tan2*ray.direction[1]*oc[1] + ray.direction[2]*oc[2]);
    double c = oc[0]*oc[0] - tan2*oc[1]*oc[1] + oc[2]*oc[2];
    double d = b * b - 4 * a * c;

    if (d < 0)
        return false;

    double root1 = (-b - sqrt(d)) / (2.0 * a);
    double root2 = (-b + sqrt(d)) / (2.0 * a);

    double root;
    Math::Vector<3> normal;

    double y1 = ray.origin[1] + root1 * ray.direction[1];
    double y2 = ray.origin[1] + root2 * ray.direction[1];

    if ((y1 <= _center[1]) && (y1 >= _center[1] - _height)) {
        root = root1;
        normal = Math::Vector<3>(2*(oc[0] + root*ray.direction[0]) / (_radius * _radius), -2*(_center[1] - _height - (oc[1] + root*ray.direction[1])) / (_height * _height), 2*(oc[2] + root*ray.direction[2]) / (_radius * _radius));
    }
    else if ((y2 <= _center[1]) && (y2 >= _center[1] - _height)) {
        root = root2;
        normal = Math::Vector<3>(2*(oc[0] + root*ray.direction[0]) / (_radius * _radius), -2*(_center[1] - _height - (oc[1] + root*ray.direction[1])) / (_height * _height), 2*(oc[2] + root*ray.direction[2]) / (_radius * _radius));
    }
    else
        return false;

    if (root < tMin || root > tMax)
        return false;

    rec.t = root;
    rec.p = ray.at(rec.t);
    rec.normal = normal;
    Math::Vector<3> outward_normal = normal;
    rec.setFaceNormal(ray, outward_normal);
    getConeUV(outward_normal, rec.u, rec.v);
    rec.material = _mat;
    return true;
}

void RayTracer::Cone::getConeUV(const Math::Vector<3> &p, double &u, double &v)
{
    double phi = atan2(p[2], p[0]);
    u = 1 - (phi + M_PI) / (2 * M_PI);
    v = (p[2] + 1) / 2;
}

std::string RayTracer::Cone::getInfo()
{
    std::stringstream ss;
    ss << "{" << _center[0] << ", " << _center[1] << ", " << _center[2] << "} with radius of " << _radius << " and height of " << _height;
    return ss.str();
}

bool RayTracer::Cone::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &outputBox) const
{
    outputBox = AxisAlignedBBox(
            Math::Vector<3>(_center[0] - _radius, _center[1], _center[2] - _radius),
            Math::Vector<3>(_center[0] + _radius, _center[1] + _height, _center[2] + _radius)
    );
    return true;
}
