/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** BoundingVolHierarchy.hpp
*/

#ifndef RAYTRACER_BOUNDING_VOLUME_HIERARCHY_HPP
    #define RAYTRACER_BOUNDING_VOLUME_HIERARCHY_HPP

    #include "HittableList.hpp"
    #include "Hittable.hpp"
    #include <iostream>

namespace RayTracer
{
    class BoundingVolHierarchy : public Hittable
    {
        private:
            std::shared_ptr<Hittable> _left;
            std::shared_ptr<Hittable> _right;
            AxisAlignedBBox _box;

        public:
            BoundingVolHierarchy()
            {
                this->setName("bvh");
            }
            ~BoundingVolHierarchy() override = default;

            BoundingVolHierarchy(const HittableList& ls, double t0, double t1);
            BoundingVolHierarchy(const std::vector<std::shared_ptr<Hittable>>& obj, size_t start, size_t end, double t0, double t1);

            static bool boxXCompare(const std::shared_ptr<Hittable>& a, const std::shared_ptr<Hittable>& b);
            static bool boxYCompare(const std::shared_ptr<Hittable>& a, const std::shared_ptr<Hittable>& b);
            static bool boxZCompare(const std::shared_ptr<Hittable>& a, const std::shared_ptr<Hittable>& b);

            bool hit(const Ray& ray, double tMin, double tMax, HitRecord& r) const override;
            bool boundingBox(double t0, double t1, AxisAlignedBBox& outputBox) const override;
    };

    inline bool boxCmp(const std::shared_ptr<Hittable>& a, const std::shared_ptr<Hittable>& b, int axis)
    {
        AxisAlignedBBox boxA;
        AxisAlignedBBox boxB;

        if (!a->boundingBox(0, 0, boxA) || !b->boundingBox(0, 0, boxB))
        {
            std::cerr << "Something went wrong, image generation will be compromised." << std::endl;
        }

        return boxA.min()[axis] < boxB.min()[axis];
    }
}

#endif // !RAYTRACER_BOUNDING_VOLUME_HIERARCHY_HPP
