/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** DiffuseLight.hpp
*/

#ifndef RAYTRACER_DIFFUSE_LIGHT_HPP
    #define RAYTRACER_DIFFUSE_LIGHT_HPP

    #include "Material.hpp"
    #include "Texture.hpp"
    #include "Vector.hpp"

namespace RayTracer
{
    class DiffuseLight : public Material
    {
        private:
            std::shared_ptr<Texture> _emit{};

        public:
            explicit DiffuseLight(const std::shared_ptr<Texture>& texture);
            explicit DiffuseLight(const Math::Vector<3>& color);
            ~DiffuseLight() = default;

            bool scatter(const Ray& ray, const HitRecord& rec, Math::Vector<3>& att, Ray& scattered) const override;

            [[nodiscard]] Math::Vector<3> emittedColor(double u, double v, const Math::Vector<3>& point) const override;
    };
}

#endif // !RAYTRACER_DIFFUSE_LIGHT_HPP
