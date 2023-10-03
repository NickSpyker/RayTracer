/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** PPM.hpp
*/

#ifndef RAYTRACER_PPM_HPP
    #define RAYTRACER_PPM_HPP

    #include <map>
    #include <mutex>
    #include <thread>
    #include <sstream>
    #include <iostream>
    #include "ImageRendering.hpp"

namespace RayTracer
{
    class PPM : public ImageRendering
    {
        private:
            std::map<int, Math::Vector<3>> _colorMap{};
            std::string _buffer{};
            std::mutex _mutex{};
            int _screenWidth;
            int _lead{0};

        private:
            void format(const Math::Vector<3>& rgb, int spp)
            {
                double r = rgb.e[0];
                double g = rgb.e[1];
                double b = rgb.e[2];

                double scale = 1.0 / spp;
                r = sqrt(scale * r);
                g = sqrt(scale * g);
                b = sqrt(scale * b);

                int ri = static_cast<int>(256 * Math::clamp(r, 0.0, 0.999));
                int gi = static_cast<int>(256 * Math::clamp(g, 0.0, 0.999));
                int bi = static_cast<int>(256 * Math::clamp(b, 0.0, 0.999));

                std::stringstream ss;

                ss << ri << ' ' << gi << ' ' << bi << std::endl;

                this->_buffer += ss.str();
            }

        public:
            explicit PPM(int screenWidth, int screenHeight) : _screenWidth(screenWidth)
            {
                std::cout
                    << "P3" << std::endl
                    << screenWidth << ' ' << screenHeight << std::endl
                    << 255 << std::endl;
            }

            ~PPM() override = default;

            void writePixelColor(int x, int y, const Math::Vector<3>& rgb, int spp) override
            {
                std::unique_lock<std::mutex> lock(this->_mutex);
                int position = y * this->_screenWidth + x;

                if (position == this->_lead)
                {
                    format(rgb, spp);
                    this->_lead++;

                    while (this->_colorMap.find(this->_lead) != this->_colorMap.end())
                    {
                        format(this->_colorMap[this->_lead], spp);
                        this->_colorMap.erase(_lead);
                        this->_lead++;
                    }

                    std::cout << this->_buffer;
                    this->_buffer.clear();
                }
                else
                {
                    this->_colorMap.insert({position, rgb});
                }
            }
    };
}

#endif // !RAYTRACER_PPM_HPP
