/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Diffuse.cpp
*/

#include "Diffuse.hpp"

bool RayTracer::Diffuse::scatter(const RayTracer::Ray &ray,
                                 const RayTracer::HitRecord &rec,
                                 Math::Vector<3>& att,
                                 RayTracer::Ray &scattered) const
{
    Math::Vector<3> scatter_dir = rec.normal + Math::Vector<3>::randomUnitVector();

    if (scatter_dir.nearZero())
        scatter_dir = rec.normal;

    scattered = Ray(rec.p, scatter_dir, ray.time());
    att = this->al->value(rec.u, rec.v, Math::Vector<3>(rec.p[0], rec.p[1], rec.p[2]));
    return true;
}
