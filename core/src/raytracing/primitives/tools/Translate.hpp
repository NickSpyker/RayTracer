/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** Translate.hpp
*/

#ifndef RAYTRACER_TRANSLATE_HPP
    #define RAYTRACER_TRANSLATE_HPP

    #include "Vector.hpp"
    #include "Hittable.hpp"

namespace RayTracer
{
    class Translate : public Hittable
    {
        private:
            std::shared_ptr<Hittable> _object{};
            Math::Vector<3> _offset{};

        public:
            Translate(std::shared_ptr<Hittable> object, const Math::Vector<3>& displacement);
            ~Translate() override = default;

            std::string getInfo() override
            {
                std::stringstream ss;
                ss << "translation{" << this->_offset[0] << ", " << this->_offset[1] << ", " << this->_offset[2] << "}, ";
                return ss.str() + this->_object->getInfo();
            }

            bool hit(const Ray& ray, double tMin, double tMax, HitRecord& rec) const override;

            bool boundingBox(double t0, double t1, AxisAlignedBBox& output) const override;
    };
}

#endif // !RAYTRACER_TRANSLATE_HPP
