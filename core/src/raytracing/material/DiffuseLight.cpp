/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** DiffuseLight.cpp
*/

#include "SolidColor.hpp"
#include "DiffuseLight.hpp"

RayTracer::DiffuseLight::DiffuseLight(const std::shared_ptr<Texture>& texture):
_emit(texture)
{}

RayTracer::DiffuseLight::DiffuseLight(const Math::Vector<3>& color):
_emit(std::make_shared<SolidColor>(color))
{}

bool RayTracer::DiffuseLight::scatter(const RayTracer::Ray &ray, const RayTracer::HitRecord &rec, Math::Vector<3> &att, RayTracer::Ray &scattered) const
{
    return false;
}

Math::Vector<3> RayTracer::DiffuseLight::emittedColor(double u, double v, const Math::Vector<3> &point) const
{
    return this->_emit->value(u, v, point);
}
