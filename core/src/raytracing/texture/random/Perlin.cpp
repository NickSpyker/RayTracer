/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Perlin.cpp
*/

#include "MathStandard.hpp"
#include "Perlin.hpp"

void RayTracer::Perlin::permute(int *p, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int target = Math::randomInt(0, i);
        int tmp = p[i];
        p[i] = p[target];
        p[target] = tmp;
    }
}

RayTracer::Perlin::Perlin()
{
    this->_randVec3 = new Math::Vector<3>[RayTracer::Perlin::_pointCount];

    for (int i = 0; i < RayTracer::Perlin::_pointCount; i++) {
        this->_randVec3[i] = Math::Vector<3>::random(-1, 1).unitVector();
    }

    this->_permX = perlin_generate_perm();
    this->_permY = perlin_generate_perm();
    this->_permZ = perlin_generate_perm();
}

RayTracer::Perlin::~Perlin()
{
    delete[] this->_randVec3;
    delete[] this->_permX;
    delete[] this->_permY;
    delete[] this->_permZ;
}

double RayTracer::Perlin::noise(const Math::Point3D &point) const
{
    auto u = point[0] - floor(point[0]);
    auto v = point[1] - floor(point[1]);
    auto w = point[2] - floor(point[2]);

    auto i = static_cast<int>(floor(point[0]));
    auto j = static_cast<int>(floor(point[1]));
    auto k = static_cast<int>(floor(point[2]));

    Math::Vector<3> c[2][2][2];

    for (int di=0; di < 2; di++)
        for (int dj=0; dj < 2; dj++)
            for (int dk=0; dk < 2; dk++)
                c[di][dj][dk] = this->_randVec3[this->_permX[(i+di) & 255] ^ this->_permY[(j+dj) & 255] ^ this->_permZ[(k+dk) & 255]];

    return perlinInterp(c, u, v, w);
}
