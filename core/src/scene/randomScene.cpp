/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** randomScene.cpp
*/

#include "MovingSphere.hpp"
#include "HittableList.hpp"
#include "Dielectric.hpp"
#include "Material.hpp"
#include "Point3D.hpp"
#include "Diffuse.hpp"
#include "Checker.hpp"
#include "Vector.hpp"
#include "Sphere.hpp"
#include "Metal.hpp"

RayTracer::HittableList randomScene()
{
    RayTracer::HittableList world;

    auto checker = std::make_shared<RayTracer::Checker>(Math::Vector<3>(0.2, 0.3, 0.1), Math::Vector<3>(0.9, 0.9, 0.9));

    world.add(std::make_shared<RayTracer::Sphere>(Math::Point3D(0,-1000,0), 1000, std::make_shared<RayTracer::Diffuse>(checker)));

    for (int i = -11; i < 11; i++)
    {
        for (int j = -11; j < 11; j++)
        {
            double mat = Math::randomDouble();
            Math::Point3D center(i + 0.9 * Math::randomDouble(), 0.2, j + 0.9 * Math::randomDouble());

            if ((center - Math::Point3D(4, 0.2, 0)).length() > 0.9)
            {
                std::shared_ptr<RayTracer::Material> material;

                if (mat < 0.8)
                {
                    Math::Vector<3> diffuse = Math::Vector<3>::random() * Math::Vector<3>::random();
                    material = std::make_shared<RayTracer::Diffuse>(diffuse);
                    Math::Point3D center2 = center + Math::Vector<3>(0.0, Math::randomDouble(0.0, 0.5), 0.0);
                    world.add(std::make_shared<RayTracer::MovingSphere>(
                            Math::Vector<3>(center.x, center.y, center.z),
                            Math::Vector<3>(center2.x, center2.y, center2.z),
                            0.0, 1.0, 0.2, material));
                }
                else if (mat < 0.95)
                {
                    auto metal = Math::Vector<3>::random(0.5, 1.0);
                    auto f = Math::randomDouble(0.0, 0.5);
                    material = std::make_shared<RayTracer::Metal>(metal, f);
                    world.add(std::make_shared<RayTracer::Sphere>(center, 0.2, material));
                }
                else
                {
                    material = std::make_shared<RayTracer::Dielectric>(1.5);
                    world.add(std::make_shared<RayTracer::Sphere>(center, 0.2, material));
                }
            }
        }
    }

    auto material1 = std::make_shared<RayTracer::Dielectric>(1.5);
    world.add(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 1, 0), 1.0, material1));

    auto material2 = std::make_shared<RayTracer::Diffuse>(Math::Vector<3>(0.4, 0.2, 0.1));
    world.add(std::make_shared<RayTracer::Sphere>(Math::Point3D(-4, 1, 0), 1.0, material2));

    auto material3 = std::make_shared<RayTracer::Metal>(Math::Vector<3>(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<RayTracer::Sphere>(Math::Point3D(4, 1, 0), 1.0, material3));

    return world;
}
