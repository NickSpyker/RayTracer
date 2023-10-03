/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** AxisAlignedBoundingBox.hpp
*/

#ifndef RAYTRACER_AXIS_ALIGNED_BOUNDING_BOX_HPP
    #define RAYTRACER_AXIS_ALIGNED_BOUNDING_BOX_HPP

    #include "Vector.hpp"
    #include "Ray.hpp"

namespace RayTracer
{
    class AxisAlignedBBox
    {
        private:
            Math::Vector<3> _minimum;
            Math::Vector<3> _maximum;

        public:
            AxisAlignedBBox() = default;
            AxisAlignedBBox(const Math::Vector<3>& a, const Math::Vector<3>& b);
            ~AxisAlignedBBox() = default;

            [[nodiscard]] Math::Vector<3> min() const;
            [[nodiscard]] Math::Vector<3> max() const;

            [[nodiscard]] bool hit(const Ray& ray, double tMin, double tMax) const;

            static AxisAlignedBBox surroundingBox(const AxisAlignedBBox& box0, const AxisAlignedBBox& box1);
    };
}

#endif // !RAYTRACER_AXIS_ALIGNED_BOUNDING_BOX_HPP
