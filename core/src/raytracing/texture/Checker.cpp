/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Checker.cpp
*/

#include "Checker.hpp"

RayTracer::Checker::Checker(const std::shared_ptr<Texture>& even, const std::shared_ptr<Texture>& odd):
_even(even), _odd(odd)
{}

Math::Vector<3> RayTracer::Checker::value(double u, double v, const Math::Vector<3> &point) const
{
    double sines = sin(10 * point[0]) * sin(10 * point[1]) * sin(10 * point[2]);

    if (sines < 0)
    {
        return this->_odd->value(u, v, point);
    }
    else
    {
        return this->_even->value(u, v, point);
    }
}
