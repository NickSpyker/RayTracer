/*
** EPITECH PROJECT, 2022
** Vector
** File description:
** Vector
*/
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "MathStandard.hpp"
#include <cmath>
#include <cstdarg>
#include <ostream>

namespace Math {
template <int N> class Vector {
public:
  Vector() {
    for (int i = 0; i < N; i++) {
      this->e[i] = 0;
    }
  }

  Vector(const Vector &other) {
    for (int i = 0; i < N; i++) {
      this->e[i] = other.e[i];
    }
  }

  Vector(Vector &&other) noexcept = default;

  [[nodiscard]] double length() const { return sqrt(lengthSquared()); }

  double lengthSquared() const {
    double sum = 0;
    for (int i = 0; i < N; i++) {
      sum += this->e[i] * this->e[i];
    }
    return sum;
  }

  explicit Vector(double data, ...) {
    va_list args;
    va_start(args, data);
    this->e[0] = data;
    for (int i = 1; i < N; i++) {
      this->e[i] = va_arg(args, double);
    }
    va_end(args);
  }

  inline Vector &operator=(const Vector &other) {
    if (this == &other) {
      return *this;
    }
    for (int i = 0; i < N; i++) {
      this->e[i] = other.e[i];
    }
    return *this;
  }

  inline Vector &operator=(Vector &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    for (int i = 0; i < N; i++) {
      this->e[i] = other.e[i];
    }
    return *this;
  }

  inline Vector operator+(const Vector &other) const {
    Vector result;
    for (int i = 0; i < N; i++) {
      result.e[i] = this->e[i] + other.e[i];
    }
    return result;
  }

  inline Vector operator+=(const Vector &other) {
    for (int i = 0; i < N; i++) {
      this->e[i] += other.e[i];
    }
    return *this;
  }

  inline Vector operator-(const Vector &other) const {
    Vector result;
    for (int i = 0; i < N; i++) {
      result.e[i] = this->e[i] - other.e[i];
    }
    return result;
  }

  inline Vector operator-=(const Vector &other) {
    for (int i = 0; i < N; i++) {
      this->e[i] -= other.e[i];
    }
    return *this;
  }

  inline Vector operator*(const Vector &other) const {
    Vector result;
    for (int i = 0; i < N; i++) {
      result.e[i] = this->e[i] * other.e[i];
    }
    return result;
  }

  inline Vector operator*=(const Vector &other) {
    for (int i = 0; i < N; i++) {
      this->e[i] *= other.e[i];
    }
    return *this;
  }

  inline Vector operator/(const Vector &other) const {
    Vector result;
    for (int i = 0; i < N; i++) {
      result.e[i] = this->e[i] / other.e[i];
    }
    return result;
  }

  inline Vector operator/=(const Vector &other) {
    for (int i = 0; i < N; i++) {
      this->e[i] /= other.e[i];
    }
    return *this;
  }

  inline Vector operator*(double scalar) const {
    Vector result;
    for (int i = 0; i < N; i++) {
      result.e[i] = this->e[i] * scalar;
    }
    return result;
  }

  inline Vector operator*=(double scalar) {
    for (int i = 0; i < N; i++) {
      this->e[i] *= scalar;
    }
    return *this;
  }

  inline Vector operator/(double scalar) const {
    Vector result;
    for (int i = 0; i < N; i++) {
      result.e[i] = this->e[i] / scalar;
    }
    return result;
  }

  inline Vector operator/=(double scalar) {
    for (int i = 0; i < N; i++) {
      this->e[i] /= scalar;
    }
    return *this;
  }

  inline Vector operator-() const {
    Vector result;
    for (int i = 0; i < N; i++) {
      result.e[i] = -this->e[i];
    }
    return result;
  }

  inline double dot(const Vector &other) const {
    double result = 0;
    for (int i = 0; i < N; i++) {
      result += this->e[i] * other.e[i];
    }
    return result;
  }

  inline Vector unitVector() const { return *this / length(); }

  static inline Vector randomUnitVector()
  {
      return Vector<3>::randomUnitSphere().unitVector();
  }

  static inline Vector<N> randomHemisphere(const Vector<N> normal)
  {
      Vector<N> unit(Vector<N>::randomUnitSphere());

      if (0.0 < unit.dot(normal))
      {
          return unit;
      }
      else
      {
          return -unit;
      }
  }

  static inline Vector<3> cross(const Vector<3> &u, const Vector<3> &v)
  {
      return Math::Vector<3>(
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]
      );
  }

  double e[N]{};

  inline double operator[](int index) const
  {
      return this->e[index];
  }
  inline double& operator[](int index)
  {
      return this->e[index];
  }

  inline static Vector random()
  {
      return Vector<3>(randomDouble(), randomDouble(), randomDouble());
  }
  inline static Vector random(double min, double max)
  {
      return Vector<3>(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
  }

  inline static Vector randomUnitSphere()
  {
      while (true)
      {
          Vector<3> p = Vector::random(-1, 1);
          if (p.lengthSquared() >= 1)
          {
              continue;
          }
          return p;
      }
  }

  bool nearZero() const
  {
      const double s = 1e-8;
      return fabs(this->e[0]) < s && fabs(this->e[1]) < s && fabs(this->e[2]) < s;
  }

  static inline Vector<3> reflect(const Vector<3>& u, const Vector<3>& v)
  {
      return u - v * 2 * u.dot(v);
  }

  static Vector<N> refract(const Vector<N>& uv, const Vector<N>& n, double over)
  {
      double cosT = fmin(-uv.dot(n), 1.0);

      Vector<N> perp = (uv + (n * cosT)) * over;
      Vector<N> para = n * -std::sqrt(std::fabs(1.0 - perp.lengthSquared()));
      return perp + para;
  }

  static Vector<3> randomUnitDisk()
  {
      while (true)
      {
          Vector<3> p = Vector<3>(Math::randomDouble(-1, 1), Math::randomDouble(-1, 1), 0.0);

          if (1 <= p.lengthSquared())
          {
              continue;
          }
          else
          {
              return p;
          }
      }
  }
};

template <int N>
std::ostream &operator<<(std::ostream &os, const Vector<N> &v) {
  os << "Vector<" << N << ">(";
  for (int i = 0; i < N; i++) {
    os << v.e[i];
    if (i != N - 1) {
      os << ", ";
    }
  }
  os << ")";
  return os;
}
} // namespace Math

#endif // VECTOR_HPP