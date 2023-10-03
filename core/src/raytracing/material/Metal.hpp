/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Metal.hpp
*/

#ifndef RAYTRACER_METAL_HPP
    #define RAYTRACER_METAL_HPP

    #include "Material.hpp"

namespace RayTracer {

    class Metal : public Material {

        public:
            Math::Vector<3> al;
            double fuzz{1};

        public:
            explicit Metal(const Math::Vector<3>& color, double f) : al(color), fuzz(f < 1 ? f : 1) {}

            bool scatter(const Ray& ray,
                         const HitRecord& rec,
                         Math::Vector<3>& att,
                         Ray& scattered) const override;
    };
}

#endif // !RAYTRACER_METAL_HPP
