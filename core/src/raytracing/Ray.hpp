/*
** EPITECH PROJECT, 2022
** Ray
** File description:
** Ray
*/
#ifndef RAY_HPP
#define RAY_HPP

#include "Vector.hpp"
#include "math/Point3D.hpp"

namespace RayTracer {
class Ray {
public:
  ~Ray() = default;

  Ray() = default;

  Ray(Math::Point3D origin, const Math::Vector<3> &direction, double time = 0.0);

  Ray(const Ray &other) = default;

  Ray(const Ray &&other) noexcept;

  Ray &operator=(const Ray &other) = default;

  Ray &operator=(Ray &&other) noexcept = default;

  double time() const;

  Math::Point3D at(double t) const;

  Math::Point3D origin;
  Math::Vector<3> direction;
  double _time{0.0};
};

std::ostream &operator<<(std::ostream &os, const Ray &point);
} // namespace RayTracer

#endif // RAY_HPP
