/*
** EPITECH PROJECT, 2022
** Ray Tracer
** File description:
** MathStandard.hpp
*/

#ifndef RAYTRACER_MATH_STANDARD_HPP
    #define RAYTRACER_MATH_STANDARD_HPP

    #include <cmath>
    #include <limits>
    #include <random>

namespace Math {

    const double infinity = std::numeric_limits<double>::infinity();

    const double pi = 3.1415926535897932385;

    inline double deg_to_rad(double deg)
    {
        return deg * pi / 180.0;
    }

    inline double randomDouble()
    {
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);
        static std::mt19937 generator;

        return distribution(generator);
    }

    inline double randomDouble(double min, double max)
    {
        return min + (max - min) * randomDouble();
    }

    inline double clamp(double x, double min, double max)
    {
        return x < min ? min : (max < x ? max : x);
    }

    inline int randomInt(int min, int max)
    {
        return static_cast<int>(randomDouble(min, max + 1));
    }
}

#endif // !RAYTRACER_MATH_STANDARD_HPP
