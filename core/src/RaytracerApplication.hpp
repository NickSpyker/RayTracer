/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** RaytracerApplication
*/

#ifndef RAYTRACER_APPLICATION_HPP
    #define RAYTRACER_APPLICATION_HPP

    #include "ImageRendering.hpp"
    #include "HittableList.hpp"
    #include "SceneBuilder.hpp"
    #include "Hittable.hpp"
    #include <iostream>
    #include <string>
    #include <vector>

namespace RayTracer
{
    class RaytracerApplication
    {
        private:
            HittableList _world{};
            Camera _camera{};
            imageConfig_t _image{};

        private:
            Math::Vector<3> rayColor(const RayTracer::Ray& ray, const Math::Vector<3>& backgroundColor, const RayTracer::Hittable& world, int depth);
            void rayThread(int x, int y, int imageWidth, int imageHeight, int spp, int maxDepth, const Math::Vector<3>& backgroundColor, RayTracer::Camera& cam, RayTracer::HittableList& world, RayTracer::ImageRendering& render);

        public:
            explicit RaytracerApplication() = default;
            ~RaytracerApplication();

            void setup(const Camera& camera, const HittableList& scene, const imageConfig_t& image);
            void setup(const SceneBuilder& builder);
            int run(ImageRendering& render);
    };
}

#endif // !RAYTRACER_APPLICATION_HPP
