/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** Cylinder.hpp
*/

#ifndef CYLINDER_HPP
    #define CYLINDER_HPP

    #include "Hittable.hpp"

namespace RayTracer
{
    class Cylinder : public Hittable
    {
        private:
            Math::Point3D center;
            double radius;
            double height;
            std::shared_ptr<Material> mat;

        public:
            Cylinder();
            Cylinder(Math::Point3D center, double radius, double height);
            Cylinder(Math::Point3D center, double radius, double height, std::shared_ptr<Material> m);

            std::string getInfo() override;

            void getCylinderUV(const Math::Vector<3> &p, double &u, double &v, double radiu) const;

            bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;
            bool boundingBox(double t0, double t1, AxisAlignedBBox &outputBox) const override;
    };

} // namespace RayTracer

#endif // CYLINDER_HPP
