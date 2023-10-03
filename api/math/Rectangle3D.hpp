/*
** EPITECH PROJECT, 2022
** Rectangle3D
** File description:
** Rectangle3D
*/
#ifndef RECTANGLE3D_HPP
#define RECTANGLE3D_HPP

#include "math/Point3D.hpp"

namespace Math {
class Rectangle3D {
public:

  Rectangle3D() = default;

    Rectangle3D(Point3D origin, const Vector<3> &horizontalSide, const Vector<3> &verticalSide);

  Point3D pointAt(double u, double v) const;

  Point3D origin;
  Vector<3> horizontalSide;
  Vector<3> verticalSide;
};

std::ostream &operator<<(std::ostream &os, const Rectangle3D &point);
}

#endif // RECTANGLE3D_HPP
