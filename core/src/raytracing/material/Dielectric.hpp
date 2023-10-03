/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Dielectric.hpp
*/

#ifndef RAYTRACER_DIELECTRIC_HPP
    #define RAYTRACER_DIELECTRIC_HPP

    #include "Material.hpp"

namespace RayTracer {

    class Dielectric : public Material {

        private:
            double refract{0};

        public:
            explicit Dielectric(double refraction) : refract(refraction) {}

            bool scatter(const Ray& ray,
                         const HitRecord& rec,
                         Math::Vector<3>& att,
                         Ray& scattered) const override;

        private:
            static double reflectance(double cos, double ref);
    };
}

#endif // !RAYTRACER_DIELECTRIC_HPP
