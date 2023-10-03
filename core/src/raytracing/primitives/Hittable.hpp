/*
** EPITECH PROJECT, 2022
** Hittable
** File description:
** Hittable
*/
#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <sstream>
#include "Ray.hpp"
#include <memory>
#include "AxisAlignedBoundingBox.hpp"

namespace RayTracer {

class Material;

struct HitRecord
{
    double t;
    Math::Point3D p;
    std::shared_ptr<Material> material;
    Math::Vector<3> normal;
    bool frontFace;
    double u;
    double v;

    inline void setFaceNormal(const Ray &r, const Math::Vector<3> &outwardNormal)
    {
        frontFace = r.direction.dot(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable {

    private:
        std::string _name{"undefined"};

    public:
      virtual ~Hittable() = default;

      void setName(const std::string& name)
      {
          this->_name = name;
      }

      [[nodiscard]] std::string getName() const
      {
          return this->_name;
      }

      virtual std::string getInfo()
      {
          return "unknown";
      }

      virtual bool hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const = 0;

      virtual bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const = 0;
};
} // namespace RayTracer
#endif // HITTABLE_HPP
