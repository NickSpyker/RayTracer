/*
** EPITECH PROJECT, 2022
** Ray Tracer
** File description:
** Diffuse.hpp
*/

#ifndef RAYTRACER_DIFFUSE_HPP
    #define RAYTRACER_DIFFUSE_HPP

    #include <utility>
    #include "Texture.hpp"
    #include "SolidColor.hpp"
    #include "Material.hpp"

namespace RayTracer {

    class Diffuse : public Material {

        public:
            std::shared_ptr<Texture> al;

        public:
            explicit Diffuse(const Math::Vector<3>& color) : al(std::make_shared<SolidColor>(color)) {}
            explicit Diffuse(std::shared_ptr<Texture> texture) : al(std::move(texture)) {}

            bool scatter(const Ray& ray,
                         const HitRecord& rec,
                         Math::Vector<3>& att,
                         Ray& scattered) const override;
    };
}

#endif // !RAYTRACER_DIFFUSE_HPP
