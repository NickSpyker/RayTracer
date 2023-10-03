/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Cylinder.cpp
*/

#include "Cylinder.hpp"
#include "Ray.hpp"

namespace RayTracer {

    Cylinder::Cylinder() : center(0, 0, 0), radius(0), height(0)
    {
        this->setName("cylinder");
    }

    Cylinder::Cylinder(Math::Point3D center, double radius, double height)
    : center(std::move(center)), radius(radius), height(height)
    {
        this->setName("cylinder");
    }

    Cylinder::Cylinder(Math::Point3D center, double radius, double height, std::shared_ptr<Material> m)
    : center(std::move(center)), radius(radius), height(height), mat(std::move(m))
    {
        this->setName("cylinder");
    }

    std::string Cylinder::getInfo()
    {
        std::stringstream ss;
        ss << "{" << center.x << ", " << center.y << ", " << center.z << "} with radius of " << radius << " and height of " << height;
        return ss.str();
    }

    bool Cylinder::hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const
    {
        Math::Vector<3> oc = ray.origin - center;
        double a = ray.direction[0] * ray.direction[0] + ray.direction[2] * ray.direction[2];
        double b = 2.0 * (oc[0] * ray.direction[0] + oc[2] * ray.direction[2]);
        double c = oc[0] * oc[0] + oc[2] * oc[2] - radius * radius;
        double d = b * b - 4 * a * c;

        if (d < 0)
        {
            return false;
        }

        double root = (-b - sqrt(d)) / (2.0 * a);

        if (root < tMin || tMax < root)
        {
            root = (-b + sqrt(d)) / (2.0 * a);
            if (root < tMin || tMax < root)
            {
                return false;
            }
        }

        double y = ray.origin.y + root * ray.direction[1];

        if ((y < center.y) || (y > center.y + height))
        {
            return false;
        }

        rec.t = root;
        rec.p = ray.at(rec.t);
        rec.normal = Math::Vector<3>((rec.p.x - center.x) / radius, 0, (rec.p.z - center.z) / radius);
        Math::Vector<3> outward_normal = (rec.p - center) / radius;
        rec.setFaceNormal(ray, outward_normal);
        getCylinderUV(outward_normal, rec.u, rec.v, radius);
        rec.material = this->mat;
        return true;
    }

    bool Cylinder::boundingBox(double t0, double t1, AxisAlignedBBox &outputBox) const
    {
        outputBox = AxisAlignedBBox(
            Math::Vector<3>(center.x - radius, center.y, center.z - radius),
            Math::Vector<3>(center.x + radius, center.y + height, center.z + radius)
        );
        return true;
    }

    void Cylinder::getCylinderUV(const Math::Vector<3> &p, double &u, double &v, double radiu) const
    {
        auto theta = std::atan2(p[0], p[2]);
        auto phi = std::atan2(p[1], radiu);
        u = 1 - (theta + M_PI) / (2 * M_PI);
        v = (phi + M_PI / 2) / M_PI;
    }

} // namespace RayTracer
