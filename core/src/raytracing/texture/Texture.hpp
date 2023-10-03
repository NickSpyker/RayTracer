/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** Texture.hpp
*/

#ifndef RAYTRACER_TEXTURE_HPP
    #define RAYTRACER_TEXTURE_HPP

    #include "Vector.hpp"

namespace RayTracer
{
    class Texture
    {
        public:
            Texture() = default;
            virtual ~Texture() = default;

            [[nodiscard]] virtual Math::Vector<3> value(double u, double v, const Math::Vector<3>& point) const = 0;
    };
}

#endif // !RAYTRACER_TEXTURE_HPP
