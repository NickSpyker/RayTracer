/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** MovingSphere.hpp
*/

#ifndef RAYTRACER_MOVING_SPHERE_HPP
    #define RAYTRACER_MOVING_SPHERE_HPP

    #include "../../../api/math/Point3D.hpp"
    #include "../../../api/math/Vector.hpp"
    #include "../material/Material.hpp"
    #include "Hittable.hpp"

namespace RayTracer
{
    class MovingSphere : public Hittable
    {
        private:
            std::shared_ptr<Material> _material;
            Math::Vector<3> _center1;
            Math::Vector<3> _center0;
            double _time0, _time1;
            double _radius;

        public:
            MovingSphere(Math::Vector<3> center0, Math::Vector<3> center1,
                         double time0, double time1,
                         double radius,
                         const std::shared_ptr<Material>& material);

            ~MovingSphere() override = default;

            bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;
            bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const override;

            [[nodiscard]] Math::Vector<3> center(double time) const;
    };
}

#endif // !RAYTRACER_MOVING_SPHERE_HPP
