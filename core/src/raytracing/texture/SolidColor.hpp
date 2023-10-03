/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** SolidColor.hpp
*/

#ifndef RAYTRACER_SOLID_COLOR_HPP
    #define RAYTRACER_SOLID_COLOR_HPP

    #include "Texture.hpp"
    #include "Vector.hpp"

namespace RayTracer
{
    class SolidColor : public Texture
    {
        private:
            Math::Vector<3> _color;

        public:
            SolidColor() = default;
            ~SolidColor() override = default;

            explicit SolidColor(const Math::Vector<3>& color);
            SolidColor(double r, double g, double b);

            [[nodiscard]] Math::Vector<3> value(double u, double v, const Math::Vector<3>& point) const override;
    };
}

#endif // !RAYTRACER_SOLID_COLOR_HPP
