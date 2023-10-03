/*
** EPITECH PROJECT, 2022
** nicolas.spijkerman@epitech.eu
** File description:
** Perlin.hpp
*/

#ifndef RAYTRACER_PERLIN_HPP
    #define RAYTRACER_PERLIN_HPP

    #include "Point3D.hpp"
    #include "Vector.hpp"

namespace RayTracer
{
    class Perlin
    {
        private:
            static const int _pointCount = 256;
            Math::Vector<3>* _randVec3 = nullptr;
            int* _permX = nullptr;
            int* _permY = nullptr;
            int* _permZ = nullptr;

        private:
            static int* perlin_generate_perm()
            {
                int *p = new int[_pointCount];

                for (int i{0}; i < _pointCount; i++)
                {
                    p[i] = i;
                }
                permute(p, _pointCount);
                return p;
            }

            static double perlinInterp(Math::Vector<3> c[2][2][2], double u, double v, double w) {
                auto uu = u*u*(3-2*u);
                auto vv = v*v*(3-2*v);
                auto ww = w*w*(3-2*w);
                auto accum = 0.0;

                for (int i=0; i < 2; i++)
                    for (int j=0; j < 2; j++)
                        for (int k=0; k < 2; k++) {
                            Math::Vector<3> weight_v(u-i, v-j, w-k);
                            accum += (i*uu + (1-i)*(1-uu))
                                     * (j*vv + (1-j)*(1-vv))
                                     * (k*ww + (1-k)*(1-ww))
                                     * c[i][j][k].dot(weight_v);
                        }

                return accum;
            }

            static void permute(int* p, int n);

        public:
            Perlin();
            ~Perlin();

            [[nodiscard]] double noise(const Math::Point3D& point) const;

            double turb(const Math::Point3D& p, int depth = 7) const
            {
                auto accum = 0.0;
                auto temp_p = p;
                auto weight = 1.0;

                for (int i = 0; i < depth; i++) {
                    accum += weight * noise(temp_p);
                    weight *= 0.5;
                    temp_p = Math::Point3D(2 * temp_p.x, 2 * temp_p.y, 2 * temp_p.z);
                }

                return std::fabs(accum);
            }
    };
}

#endif // !RAYTRACER_PERLIN_HPP
