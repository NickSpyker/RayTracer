/*
** EPITECH PROJECT, 2022
** Camera
** File description:
** Camera
*/
#include "Camera.hpp"
#include "Point3D.hpp"
#include <libconfig.h++>
#include <utility>

namespace RayTracer {

Camera::Camera(Math::Point3D lookFrom,
               Math::Point3D lookAt,
               Math::Vector<3> vup,
               double fov,
               double aspectRatio,
               double aperture,
               double focus,
               double time0,
               double time1):
               aspectRatio(aspectRatio), _time0(time0), _time1(time1)
{
    double theta = Math::deg_to_rad(fov);
    double h = std::tan(theta / 2.0);
    double viewportHeight = 2.0 * h;
    double viewportWidth = aspectRatio * viewportHeight;

    this->w = (lookFrom - lookAt).unitVector();
    this->u = Math::Vector<3>::cross(vup, this->w).unitVector();
    this->v = Math::Vector<3>::cross(this->w, this->u);

    this->origin = lookFrom;
    this->screen.horizontalSide = this->u * viewportWidth * focus;
    this->screen.verticalSide = this->v * viewportHeight * focus;

    Math::Vector<3> o = this->origin - this->screen.horizontalSide / 2 - this->screen.verticalSide / 2 - this->w * focus;

    this->screen.origin = Math::Point3D(o[0], o[1], o[2]);

    this->radius = aperture / 2;

    this->lookAt = lookAt;
}

Ray Camera::ray(double s, double t) const
{
    Math::Vector<3> hor = this->screen.horizontalSide * s;
    Math::Vector<3> ver = this->screen.verticalSide * t;

    Math::Vector<3> r = Math::Vector<3>::randomUnitDisk() * this->radius;
    Math::Vector<3> offset = this->u * r[0] + this->v * r[1];

    return {
        this->origin + offset,
        this->screen.origin + hor + ver - this->origin - offset,
        Math::randomDouble(this->_time0, this->_time1)
    };
}

std::ostream &operator<<(std::ostream &os, const Camera &point) {
  os << "Camera(" << point.origin << ", " << point.screen << ")";
  return os;
}
} // namespace RayTracer