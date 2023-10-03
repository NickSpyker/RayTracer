/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** AxisAlignedBoundingBox.cpp
*/

#include "AxisAlignedBoundingBox.hpp"

RayTracer::AxisAlignedBBox::AxisAlignedBBox(const Math::Vector<3> &a, const Math::Vector<3> &b):
_minimum(a), _maximum(b)
{}

Math::Vector<3> RayTracer::AxisAlignedBBox::min() const
{
    return this->_minimum;
}

Math::Vector<3> RayTracer::AxisAlignedBBox::max() const
{
    return this->_maximum;
}

bool RayTracer::AxisAlignedBBox::hit(const RayTracer::Ray &ray, double tMin, double tMax) const
{
    for (int i{0}; i < 3; i++)
    {
        double invDelta = 1.0f / ray.direction[i];

        double t0 = (this->_minimum[i] - ray.origin[i]) * invDelta;
        double t1 = (this->_maximum[i] - ray.origin[i]) * invDelta;

        if (invDelta < 0.0f)
        {
            std::swap(t0, t1);
        }

        tMin = tMin < t0 ? tMin : t0;
        tMax = t1 < tMax ? t1 : tMax;

        if (tMax <= tMin)
        {
            return false;
        }
    }

    return true;
}

RayTracer::AxisAlignedBBox RayTracer::AxisAlignedBBox::surroundingBox(const RayTracer::AxisAlignedBBox& box0, const RayTracer::AxisAlignedBBox& box1)
{
    Math::Vector<3> small(std::fmin(box0.min()[0], box1.min()[0]),
                          std::fmin(box0.min()[1], box1.min()[1]),
                          std::fmin(box0.min()[2], box1.min()[2]));

    Math::Vector<3> big(std::fmax(box0.max()[0], box1.max()[0]),
                        std::fmax(box0.max()[1], box1.max()[1]),
                        std::fmax(box0.max()[2], box1.max()[2]));

    return {small, big};
}
