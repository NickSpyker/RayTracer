/*
** EPITECH PROJECT, 2022
** Ray Tracer
** File description:
** HittableList.hpp
*/

#ifndef RAYTRACER_HITTABLE_LIST_HPP
    #define RAYTRACER_HITTABLE_LIST_HPP

    #include <vector>
    #include <memory>
    #include "Hittable.hpp"

namespace RayTracer {

    class HittableList : public Hittable {

        private:
            // Usage of shared pointers,
            // because it allows multiple geometries to share a common instance.
            std::vector<std::shared_ptr<Hittable>> _obj{};

        public:
            HittableList()
            {
                this->setName("objects list");
            }
            ~HittableList() override = default;

            explicit HittableList(const std::shared_ptr<Hittable>& obj)
            {
                this->add(obj);
            }

            void clear()
            {
                this->_obj.clear();
            }

            std::shared_ptr<Hittable>& back()
            {
                return this->_obj.back();
            }

            void add(const std::shared_ptr<Hittable>& obj)
            {
                this->_obj.push_back(obj);
            }

            bool hit(const Ray& ray, double tMin, double tMax, HitRecord& rec) const override;

            bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const override;

            [[nodiscard]] const std::vector<std::shared_ptr<Hittable>>& getObj() const;
    };
}

#endif // !RAYTRACER_HITTABLE_LIST_HPP
