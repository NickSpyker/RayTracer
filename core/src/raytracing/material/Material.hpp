/*
** EPITECH PROJECT, 2022
** Ray Tracer
** File description:
** Material.hpp
*/

#ifndef RAYTRACER_MATERIAL_HPP
    #define RAYTRACER_MATERIAL_HPP

    #include "Ray.hpp"
    #include "Hittable.hpp"

namespace RayTracer {

    class Material {

        public:
            virtual bool scatter(const Ray& ray,
                                 const HitRecord& rec,
                                 Math::Vector<3>& att,
                                 Ray& scattered) const = 0;

            [[nodiscard]] virtual Math::Vector<3> emittedColor(double u, double v, const Math::Vector<3>& point) const
            {
                return Math::Vector<3>(0.0, 0.0, 0.0);
            };
    };
}

#endif // !RAYTRACER_MATERIAL_HPP
