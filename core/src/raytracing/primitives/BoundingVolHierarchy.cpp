/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** BoundingVolHierarchy.cpp
*/

#include <algorithm>
#include "MathStandard.hpp"
#include "BoundingVolHierarchy.hpp"

RayTracer::BoundingVolHierarchy::BoundingVolHierarchy(const RayTracer::HittableList &ls, double t0, double t1):
BoundingVolHierarchy(ls.getObj(), 0, ls.getObj().size(), t0, t1)
{
    this->setName("bvh");
}

RayTracer::BoundingVolHierarchy::BoundingVolHierarchy(const std::vector<std::shared_ptr<Hittable>> &obj, size_t start, size_t end, double t0, double t1)
{
    std::vector<std::shared_ptr<Hittable>> objClone = obj;

    int axis = Math::randomInt(0, 2);

    auto cmp = axis == 0 ? boxXCompare : axis == 1 ? boxYCompare : boxZCompare;

    size_t objSpan = end - start;

    if (objSpan == 1)
    {
        this->_left = objClone.at(start);
        this->_right = objClone.at(end);
    }
    else if (objSpan == 2)
    {
        if (cmp(objClone.at(start), objClone.at(start + 1)))
        {
            this->_left = objClone.at(start);
            this->_right = objClone.at(start + 1);
        }
        else
        {
            this->_left = objClone.at(start + 1);
            this->_right = objClone.at(start);
        }
    }
    else
    {
        std::sort(objClone.begin() + int(start), objClone.begin() + int(end), cmp);

        size_t middle = start + objSpan / 2;

        this->_left = std::make_shared<BoundingVolHierarchy>(objClone, start, middle, t0, t1);
        this->_right = std::make_shared<BoundingVolHierarchy>(objClone, middle, end, t0, t1);
    }

    AxisAlignedBBox boxR;
    AxisAlignedBBox boxL;

    if (!this->_left->boundingBox(t0, t1, boxL) || !this->_right->boundingBox(t0, t1, boxR))
    {
        std::cerr << "Something went wrong, image generation will be compromised." << std::endl;
    }

    this->_box = AxisAlignedBBox::surroundingBox(boxL, boxR);

    this->setName("bvh");
}

bool RayTracer::BoundingVolHierarchy::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &r) const
{
    if (!this->_box.hit(ray, tMin, tMax))
    {
        return false;
    }

    bool hitRight = this->_right->hit(ray, tMin, tMax, r);
    bool hitLeft = this->_left->hit(ray, tMin, tMax, r);

    return hitRight || hitLeft;
}

bool RayTracer::BoundingVolHierarchy::boxXCompare(const std::shared_ptr<Hittable> &a, const std::shared_ptr<Hittable> &b)
{
    return RayTracer::boxCmp(a, b, 0);
}

bool RayTracer::BoundingVolHierarchy::boxYCompare(const std::shared_ptr<Hittable> &a, const std::shared_ptr<Hittable> &b)
{
    return RayTracer::boxCmp(a, b, 1);
}

bool RayTracer::BoundingVolHierarchy::boxZCompare(const std::shared_ptr<Hittable> &a, const std::shared_ptr<Hittable> &b)
{
    return RayTracer::boxCmp(a, b, 2);
}

bool RayTracer::BoundingVolHierarchy::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &outputBox) const
{
    outputBox = this->_box;
    return true;
}
