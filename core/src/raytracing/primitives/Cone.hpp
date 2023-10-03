/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Cone.hpp
*/

#ifndef RAYTRACER_CONE_HPP
    #define RAYTRACER_CONE_HPP

    #include "Vector.hpp"
    #include "Hittable.hpp"

namespace RayTracer
{
    class Cone : public Hittable
    {
        private:
            std::shared_ptr<Material> _mat;
            Math::Vector<3> _center;
            double _height;
            double _radius;

        public:
            Cone(Math::Vector<3> center, double height, double radius, std::shared_ptr<Material> m);
            ~Cone() override = default;

            std::string getInfo() override;

            bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;

            static void getConeUV(const Math::Vector<3> &p, double &u, double &v);
            bool boundingBox(double t0, double t1, AxisAlignedBBox &outputBox) const override;
    };
}

#endif // !RAYTRACER_CONE_HPP
