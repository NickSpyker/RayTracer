/*
** EPITECH PROJECT, 2022
** PlaneXZ
** File description:
** PlaneXZ
*/

#ifndef PLANE_XZ_HPP
    #define PLANE_XZ_HPP

    #include "Hittable.hpp"

namespace RayTracer
{
    class PlaneXZ : public Hittable
    {
        private:
            std::shared_ptr<Material> _material{};
            double _x0, _z0;
            double _x1, _z1;
            double _y;

        public:
            ~PlaneXZ() override = default;

            std::string getInfo() override
            {
                std::stringstream ss;
                ss << "{" << _x0 << ", " << _y << ", " << _z0
                   << "} to {"
                   << _x1 << ", " << _y << ", " << _z1 << "}";
                return ss.str();
            }

            PlaneXZ(double x0, double x1, double z0, double z1, double y, const std::shared_ptr<Material>& material);

            bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;

            bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const override;
    };
}

#endif // PLANE_XZ_HPP
