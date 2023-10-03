/*
** EPITECH PROJECT, 2022
** Color
** File description:
** Color
*/
#ifndef COLOR_HPP
#define COLOR_HPP

#include "Vector.hpp"
#include "iostream"
namespace RayTracer {
class ColorUtils {
public:
  static int toInt(double x) { return static_cast<int>(255.999 * x); }

  static std::string toString(const Math::Vector<3>& color) {
    return std::to_string(toInt(color.e[0])) + " " + std::to_string(toInt(color.e[1])) + " " + std::to_string(toInt(color.e[2]));
  }
};

} // namespace RayTracer

#endif // COLOR_HPP
