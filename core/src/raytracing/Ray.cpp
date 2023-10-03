/*
** EPITECH PROJECT, 2022
** Ray
** File description:
** Ray
*/
#include "Ray.hpp"

#include <utility>

RayTracer::Ray::Ray(const RayTracer::Ray &&other) noexcept
{
  this->origin = other.origin;
  this->direction = other.direction;
}

RayTracer::Ray::Ray(Math::Point3D origin, const Math::Vector<3> &direction, double time)
    : origin(std::move(origin)), direction(direction), _time(time) {}

Math::Point3D RayTracer::Ray::at(double t) const {
  return this->origin + this->direction * t;
}

double RayTracer::Ray::time() const
{
    return this->_time;
}

std::ostream &RayTracer::operator<<(std::ostream &os,
                                    const RayTracer::Ray &point) {
  os << "Ray(" << point.origin << ", " << point.direction << ")";
  return os;
}
