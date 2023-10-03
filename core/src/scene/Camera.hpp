/*
** EPITECH PROJECT, 2022
** Ray Tracer
** File description:
** Camera.hpp
*/

#ifndef CAMERA_HPP
    #define CAMERA_HPP

    #include "Ray.hpp"
    #include "Rectangle3D.hpp"
    #include "Vector.hpp"

namespace RayTracer {

    class Camera {

        public:
            double aspectRatio;
            Math::Point3D origin;
            Math::Rectangle3D screen;
            Math::Point3D lookAt;

            double _time0{0.0}, _time1{0.0};

            Math::Vector<3> u, v, w;
            double radius;

        public:
            explicit Camera(Math::Point3D lookFrom = Math::Point3D(0.0, 0.0, 0.0),
                            Math::Point3D lookAt = Math::Point3D(0.0, 0.0, -1.0),
                            Math::Vector<3> vup = Math::Vector<3>(0.0, 1.0, 0.0),
                            double fov = 80.0,
                            double aspectRatio = 16.0 / 9.0,
                            double aperture = 0.0,
                            double focus = 100.0,
                            double time0 = 0.0,
                            double time1 = 0.0);

            Camera &operator=(const Camera &other) = default;
            Camera &operator=(Camera &&other) noexcept = default;

            [[nodiscard]] Ray ray(double s, double t) const;

    };

    std::ostream &operator<<(std::ostream &os, const Camera &point);
}

#endif // !CAMERA_HPP
