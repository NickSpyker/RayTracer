/*
** EPITECH PROJECT, 2022
** Point3D
** File description:
** Point3D
*/
#include "Point3D.hpp"

namespace Math {
Point3D::Point3D() : x(0), y(0), z(0) {}

Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

Point3D &Point3D::operator=(const Point3D &other) {
  if (this == &other) {
    return *this;
  }
  this->x = other.x;
  this->y = other.y;
  this->z = other.z;
  return *this;
}

Point3D Point3D::operator+(const Vector<3> &other) const {
  return {this->x + other.e[0], this->y + other.e[1], this->z + other.e[2]};
}

Point3D Point3D::operator+(const Point3D &other) const {
  return {this->x + other.x, this->y + other.y, this->z + other.z};
}

Vector<3> Point3D::operator-(const Point3D &other) const {
  return Vector<3>(x - other.x, y - other.y, z - other.z);
}
Vector<3> Point3D::operator-(const Vector<3> &other) const {
  return Vector<3>(x - other.e[0], y - other.e[1], z - other.e[2]);
}

double Point3D::operator[](int index) const
{
    switch (index) {
        case 0:  return this->x;
        case 1:  return this->y;
        default: return this->z;
    }
}

double &Point3D::operator[](int index)
{
    switch (index) {
        case 0:  return this->x;
        case 1:  return this->y;
        default: return this->z;
    }
}

std::ostream &operator<<(std::ostream &os, const Point3D &point) {
  os << "Point3D(" << point.x << ", " << point.y << ", " << point.z << ")";
  return os;
}

} // namespace Math
