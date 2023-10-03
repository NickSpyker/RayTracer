/*
** EPITECH PROJECT, 2022
** Point
** File description:
** Point
*/
#ifndef POINT_HPP
#define POINT_HPP

#include "Vector.hpp"

namespace Math {
class Point3D {
public:
  Point3D();

  Point3D(double x, double y, double z);

  Point3D(const Point3D &other) = default;

  Point3D(Point3D &&other) noexcept = default;

  ~Point3D() = default;

  Point3D &operator=(const Point3D &other);

  Point3D &operator=(Point3D &&other) noexcept = default;

  Point3D operator+(const Vector<3> &other) const;

  Vector<3> operator-(const Vector<3> &other) const;

  Point3D operator+(const Point3D &other) const;

  Vector<3> operator-(const Point3D &other) const;

  double operator[](int index) const;
  double &operator[](int index);

  double x;
  double y;
  double z;
};

std::ostream &operator<<(std::ostream &os, const Point3D &point);

} // namespace Math

#endif // POINT_HPP
