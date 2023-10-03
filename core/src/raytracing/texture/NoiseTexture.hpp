/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** noiseTexture.hpp
*/

#ifndef RAYTRACER_NOISETEXTURE_HPP
    #define RAYTRACER_NOISETEXTURE_HPP

    #include "Texture.hpp"
    #include "Point3D.hpp"
    #include "Perlin.hpp"
    #include "Vector.hpp"

namespace RayTracer
{
    class NoiseTexture : public Texture
    {
        public:
            Perlin _noise{};
            double _scale{1.0};

        public:
            NoiseTexture() = default;
            ~NoiseTexture() override = default;

            explicit NoiseTexture(double scale) : _scale(scale) {}

            [[nodiscard]] Math::Vector<3> value(double u, double v, const Math::Vector<3>& point) const override
            {
                return Math::Vector<3>(1.0, 1.0, 1.0) * 0.5 * (1.0 + std::sin(
                    this->_scale * point[2] + 10.0 * this->_noise.turb(Math::Point3D(point[0], point[1], point[2]))
                ));
            }
    };
}

#endif // !RAYTRACER_NOISETEXTURE_HPP
