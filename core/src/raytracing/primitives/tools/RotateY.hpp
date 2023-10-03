/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** RotateY.hpp
*/

#ifndef RAYTRACER_ROTATE_Y_HPP
    #define RAYTRACER_ROTATE_Y_HPP

    #include "Hittable.hpp"

namespace RayTracer
{
    class RotateY : public Hittable
    {
        private:
            std::shared_ptr<Hittable> _object{};
            AxisAlignedBBox box{};
            double angle{};
            double sinTheta{};
            double cosTheta{};
            bool hashBox{};

        public:
            RotateY(std::shared_ptr<Hittable> object, double angle);
            ~RotateY() override = default;

            std::string getInfo() override
            {
                std::stringstream ss;
                ss << "rotation{" << this->angle << "}, ";
                return ss.str() + this->_object->getInfo();
            }

            bool hit(const Ray& ray, double tMin, double tMax, HitRecord& rec) const override;

            bool boundingBox(double t0, double t1, AxisAlignedBBox& output) const override;
    };
}

#endif // !RAYTRACER_ROTATE_Y_HPP
