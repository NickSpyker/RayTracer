/*
** EPITECH PROJECT, 2022
** Sphere
** File description:
** Sphere
*/
#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Hittable.hpp"
#include "Ray.hpp"
#include "Point3D.hpp"
#include <memory>

namespace RayTracer {
class Sphere : public Hittable{

    private:
        static void getSphereUV(const Math::Vector<3>& point, double& u, double& v);

public:
  Sphere();
  Sphere(Math::Point3D center, double radius);

        std::string getInfo() override
        {
            std::stringstream ss;
            ss << "{" << center.x << ", " << center.y << ", " << center.z << "} with radius of " << radius;
            return ss.str();
        }

  Sphere(Math::Point3D center, double radius, std::shared_ptr<Material> m);

  ~Sphere() override = default;

  Sphere(const Sphere &other) = default;

  Sphere(Sphere &&other) noexcept = default;

  Sphere &operator=(const Sphere &other) = default;

  Sphere &operator=(Sphere &&other) noexcept = default;

  bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;

  bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const override;

  double radius{0.0};
  Math::Point3D center;
  std::shared_ptr<Material> mat;
};

std::ostream &operator<<(std::ostream &os, const Sphere &point);
}

#endif // SPHERE_HPP
