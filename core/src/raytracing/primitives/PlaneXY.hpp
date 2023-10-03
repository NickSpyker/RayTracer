/*
** EPITECH PROJECT, 2022
** PlaneXY
** File description:
** PlaneXY
*/

#ifndef PLANE_XY_HPP
    #define PLANE_XY_HPP

    #include "Hittable.hpp"

namespace RayTracer
{
    class PlaneXY : public Hittable
    {
        private:
            std::shared_ptr<Material> _material{};
            double _x0, _y0;
            double _x1, _y1;
            double _z;

        public:
            ~PlaneXY() override = default;

            std::string getInfo() override
            {
                std::stringstream ss;
                ss << "{" << _x0 << ", " << _y0 << ", " << _z
                   << "} to {"
                   << _x1 << ", " << _y1 << ", " << _z << "}";
                return ss.str();
            }

            PlaneXY(double x0, double x1, double y0, double y1, double z, const std::shared_ptr<Material>& material);

            bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;

            bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const override;
    };
}

#endif // PLANE_XY_HPP
