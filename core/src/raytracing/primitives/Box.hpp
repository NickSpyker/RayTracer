/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** Box.hpp
*/

#ifndef RAYTRACER_BOX_HPP
    #define RAYTRACER_BOX_HPP

    #include "Vector.hpp"
    #include "Point3D.hpp"
    #include "Hittable.hpp"
    #include "HittableList.hpp"

namespace RayTracer
{
    class Box : public Hittable
    {
        private:
            Math::Vector<3> _boxMin{};
            Math::Vector<3> _boxMax{};
            HittableList _sides{};

        public:
            Box()
            {
                this->setName("box");
            }
            ~Box() override = default;

            std::string getInfo() override
            {
                std::stringstream ss;
                ss << "{" << this->_boxMin[0] << ", " << this->_boxMin[1] << ", " << this->_boxMin[2]
                << "} to {"
                << this->_boxMax[0] << ", " << this->_boxMax[1] << ", " << this->_boxMax[2] << "}";
                return ss.str();
            }

            Box(const Math::Point3D& p0, const Math::Point3D& p1, const std::shared_ptr<Material>& material);

            bool hit(const Ray& ray, double tMin, double tMax, HitRecord& rec) const override;

            bool boundingBox(double t0, double t1, AxisAlignedBBox& output) const override;
    };
}

#endif // !RAYTRACER_BOX_HPP
