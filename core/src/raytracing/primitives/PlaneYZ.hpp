/*
** EPITECH PROJECT, 2022
** PlaneYZ
** File description:
** PlaneYZ
*/

#ifndef PLANE_YZ_HPP
    #define PLANE_YZ_HPP

    #include "Hittable.hpp"

namespace RayTracer
{
    class PlaneYZ : public Hittable
    {
        private:
            std::shared_ptr<Material> _material{};
            double _y0, _z0;
            double _y1, _z1;
            double _x;

        public:
            ~PlaneYZ() override = default;

            std::string getInfo() override
            {
                std::stringstream ss;
                ss << "{" << _x << ", " << _y0 << ", " << _z0
                   << "} to {"
                   << _x << ", " << _y1 << ", " << _z1 << "}";
                return ss.str();
            }

            PlaneYZ(double y0, double y1, double z0, double z1, double x, const std::shared_ptr<Material>& material);

            bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;

            bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const override;
    };
}

#endif // PLANE_YZ_HPP
