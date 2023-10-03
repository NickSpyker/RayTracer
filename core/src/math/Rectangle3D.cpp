/*
** EPITECH PROJECT, 2022
** Rectangle3D
** File description:
** Rectangle3D
*/
#include "Rectangle3D.hpp"

#include <utility>

namespace Math {


Point3D Rectangle3D::pointAt(double u, double v) const {
  /*if (u < 0 || u > 1 || v < 0 || v > 1) {
    throw std::runtime_error("Rectangle3D::pointAt: u and v must be in [0, 1]");
  }*/
  return origin + horizontalSide * u + verticalSide * v;
}
Rectangle3D::Rectangle3D(Point3D origin, const Vector<3> &horizontalSide,
                         const Vector<3> &verticalSide) : origin(std::move(origin)),
                                                      horizontalSide(horizontalSide),
                                                      verticalSide(verticalSide) {}

std::ostream &operator<<(std::ostream &os, const Rectangle3D &point) {
  os << "Rectangle3D(" << point.origin << ", " << point.horizontalSide << ", "
     << point.verticalSide << ")";
  return os;
}
} // namespace Math