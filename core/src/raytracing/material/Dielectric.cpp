/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Dielectric.cpp
*/

#include "Dielectric.hpp"

bool RayTracer::Dielectric::scatter(const RayTracer::Ray &ray,
                                    const RayTracer::HitRecord &rec,
                                    Math::Vector<3> &att,
                                    RayTracer::Ray &scattered) const
{
    att = Math::Vector<3>(1.0, 1.0, 1.0);
    double ratio = rec.frontFace ? (1.0 / this->refract) : this->refract;

    Math::Vector<3> ud = ray.direction.unitVector();
    double cosT = std::fmin(-ud.dot(rec.normal), 1.0);
    double sinT = std::sqrt(1.0 - cosT * cosT);

    bool cannot_refract = ratio * sinT > 1.0;
    Math::Vector<3> direction;

    if (cannot_refract || reflectance(cosT, sinT) > Math::randomDouble())
        direction = Math::Vector<3>::reflect(ud, rec.normal);
    else
        direction = Math::Vector<3>::refract(ud, rec.normal, ratio);

    scattered = Ray(rec.p, direction);

    Math::Vector<3> re = Math::Vector<3>::refract(ud, rec.normal, ratio);

    scattered = Ray(rec.p, re, ray.time());
    return true;
}

double RayTracer::Dielectric::reflectance(double cos, double ref)
{
    double r0 = (1 - ref) / (1 + ref);

    r0 *= r0;
    return r0 + (1 - r0) * std::pow((1 - cos), 5);
}
