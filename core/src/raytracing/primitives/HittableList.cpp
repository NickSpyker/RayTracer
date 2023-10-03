/*
** EPITECH PROJECT, 2022
** Ray Tracer
** File description:
** HittableList.cpp
*/

#include "HittableList.hpp"

bool RayTracer::HittableList::hit(const RayTracer::Ray &ray, double tMin, double tMax, RayTracer::HitRecord &rec) const
{
    HitRecord tempRecord;

    bool hit = false;
    double closest = tMax;

    for (const std::shared_ptr<Hittable>& obj : this->_obj)
    {
        if (!obj->hit(ray, tMin, closest, tempRecord))
            continue;
        hit = true;
        closest = tempRecord.t;
        rec = tempRecord;
    }

    return hit;
}

bool RayTracer::HittableList::boundingBox(double t0, double t1, RayTracer::AxisAlignedBBox &outputBox) const
{
    if (this->_obj.empty())
    {
        return false;
    }

    AxisAlignedBBox temp;

    bool isFist = true;
    for (const std::shared_ptr<Hittable>& obj : this->_obj)
    {
        if (!obj->boundingBox(t0, t1, temp))
        {
            return false;
        }

        outputBox = isFist ? temp : AxisAlignedBBox::surroundingBox(outputBox, temp);

        isFist = false;
    }

    return false;
}

const std::vector<std::shared_ptr<RayTracer::Hittable>>& RayTracer::HittableList::getObj() const
{
    return this->_obj;
}
