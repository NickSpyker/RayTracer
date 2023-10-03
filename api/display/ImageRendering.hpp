/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** ImageRendering.hpp
*/

#ifndef RAYTRACER_IMAGE_RENDERING_HPP
    #define RAYTRACER_IMAGE_RENDERING_HPP

#include "Vector.hpp"

namespace RayTracer
{
    class ImageRendering
    {
        public:
            ImageRendering() = default;
            virtual ~ImageRendering() = default;

        public:
            ImageRendering(const ImageRendering &) = delete;
            ImageRendering &operator=(const ImageRendering &) = delete;

            virtual void writePixelColor(int x, int y, const Math::Vector<3>& rgb, int spp) = 0;
    };
}

#endif // !RAYTRACER_IMAGE_RENDERING_HPP
