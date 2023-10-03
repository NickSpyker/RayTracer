/*
** EPITECH PROJECT, 2022
** Sphere
** File description:
** Sphere
*/
#include "Sphere.hpp"
#include "Ray.hpp"
#include <iostream>
#include <utility>

namespace RayTracer {

Sphere::Sphere() : radius(0), center(Math::Point3D(0, 0, 0)) {
    this->setName("sphere");
}
Sphere::Sphere(Math::Point3D center, double radius)
    : center(std::move(center)), radius(radius) {
    this->setName("sphere");
}

Sphere::Sphere(Math::Point3D center, double radius, std::shared_ptr<Material> m)
: center(std::move(center)), radius(radius), mat(std::move(m)) {
    this->setName("sphere");
}

bool Sphere::hit(const Ray &ray, double tMin, double tMax,
                 HitRecord &rec) const {
  Math::Vector<3> oc = ray.origin - center;
  double a = ray.direction.lengthSquared();
  double half_b = oc.dot(ray.direction);
  double c = oc.lengthSquared() - radius * radius;
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
  Math::Vector<3> outwardNormal = (rec.p - center) / radius;
  rec.normal = outwardNormal;
  rec.setFaceNormal(ray, outwardNormal);
  Sphere::getSphereUV(outwardNormal, rec.u, rec.v);
  rec.material = this->mat;
  return true;
}

bool Sphere::boundingBox(double t0, double t1, AxisAlignedBBox &outputBox) const
{
    Math::Vector<3> c(this->center.x, this->center.y, this->center.z);

    outputBox = AxisAlignedBBox(
        c - Math::Vector<3>(this->radius, this->radius, this->radius),
        c + Math::Vector<3>(this->radius, this->radius, this->radius)
    );
    return false;
}

    void Sphere::getSphereUV(const Math::Vector<3> &point, double &u, double &v)
    {
        double theta = std::acos(-point[1]);
        double phi = std::atan2(-point[2], -point[0]) + Math::pi;

        u = phi / 2 * Math::pi;
        v = theta / Math::pi;
    }

    std::ostream &operator<<(std::ostream &os, const Sphere &point) {
  os << "Sphere(" << point.radius << ", " << point.center << ")";
  return os;
}

} // namespace RayTracer