/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** SolidColor.cpp
*/

#include "SolidColor.hpp"

RayTracer::SolidColor::SolidColor(const Math::Vector<3>& color):
_color(color)
{}

RayTracer::SolidColor::SolidColor(double r, double g, double b):
SolidColor(Math::Vector<3>(r, g, b))
{}

Math::Vector<3> RayTracer::SolidColor::value(double u, double v, const Math::Vector<3> &point) const
{
    return this->_color;
}
