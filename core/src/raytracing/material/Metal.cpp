/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Metal.cpp
*/

#include "MathStandard.hpp"
#include "Metal.hpp"

bool RayTracer::Metal::scatter(const RayTracer::Ray &ray,
                               const RayTracer::HitRecord &rec,
                               Math::Vector<3> &att,
                               RayTracer::Ray &scattered) const
{
    Math::Vector<3> reflected = Math::Vector<3>::reflect(ray.direction.unitVector(), rec.normal);
    scattered = Ray(rec.p, reflected + (Math::Vector<3>::randomUnitSphere() * fuzz), ray.time());
    att = al;

    return 0 < scattered.direction.dot(rec.normal);
}
