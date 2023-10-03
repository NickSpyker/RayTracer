/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** Checker.hpp
*/

#ifndef RAYTRACER_CHECKER_HPP
    #define RAYTRACER_CHECKER_HPP

    #include <memory>
    #include "SolidColor.hpp"
    #include "Vector.hpp"
    #include "Texture.hpp"

namespace RayTracer
{
    class Checker : public Texture
    {
        private:
            std::shared_ptr<Texture> _even;
            std::shared_ptr<Texture> _odd;

        public:
            Checker() = default;
            ~Checker() override = default;

            Checker(const std::shared_ptr<Texture>& _even, const std::shared_ptr<Texture>& _odd);

            Checker(const Math::Vector<3>& c1, const Math::Vector<3>& c2)
            : _even(std::make_shared<RayTracer::SolidColor>(c1)), _odd(std::make_shared<RayTracer::SolidColor>(c2)) {}

            [[nodiscard]] Math::Vector<3> value(double u, double v, const Math::Vector<3>& point) const override;
    };
}

#endif // !RAYTRACER_CHECKER_HPP
