/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** ObjectFactory.hpp
*/

#ifndef RAYTRACER_OBJECT_FACTORY_HPP
    #define RAYTRACER_OBJECT_FACTORY_HPP

    #include "Hittable.hpp"
    #include "Material.hpp"
    #include "Point3D.hpp"

namespace RayTracer
{
    class ObjectFactory
    {
        public:
            ObjectFactory() = delete;

            static std::shared_ptr<Hittable> createBox(const Math::Point3D& p0, const Math::Point3D& p1, const std::shared_ptr<Material>& material);

            static std::shared_ptr<Hittable> createCylinder(const Math::Point3D& center, double radius, double height, const std::shared_ptr<Material>& material);

            static std::shared_ptr<Hittable> createSphere(const Math::Point3D& center, double radius, const std::shared_ptr<Material>& material);

            static std::shared_ptr<Hittable> createCone(const Math::Point3D& center, double height, double radius, const std::shared_ptr<Material>& material);

            static std::shared_ptr<Hittable> createPlane(const Math::Point3D& p0, Math::Point3D p1, const std::shared_ptr<Material>& material);
    };
}

#endif // !RAYTRACER_OBJECT_FACTORY_HPP
