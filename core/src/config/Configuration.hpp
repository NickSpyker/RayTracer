/*
** EPITECH PROJECT, 2022
** Configuration
** File description:
** Configuration
*/
#ifndef RAYTRACER_CONFIGURATION_HPP
#define RAYTRACER_CONFIGURATION_HPP

#include "HittableList.hpp"
#include "SceneBuilder.hpp"
#include <fstream>
#include <iostream>
#include <libconfig.h++>

namespace RayTracer {
class Configuration {
public:
  Configuration(std::string path);
  ~Configuration() = default;

  Configuration(const Configuration &) = delete;

  void loadTextures(SceneBuilder &builder, const libconfig::Setting &textures);

  void loadMaterials(SceneBuilder &builder, const libconfig::Setting &setting);

  void loadPrimitives(SceneBuilder &builder, const libconfig::Setting &setting);

  void loadImageConfig(SceneBuilder &builder, const libconfig::Setting &setting);

        void loadCameraConfig(SceneBuilder &builder, const libconfig::Setting &setting);

  point3d_t getPoint3d(const libconfig::Setting &setting);

  Math::Vector<3> getRGB(const libconfig::Setting &setting);

  color_t getRGBColor(const libconfig::Setting &setting);

  Configuration &operator=(const Configuration &) = delete;

  SceneBuilder loadSceneFromFile();

private:
  std::string _path;
  libconfig::Config cfg;
};
} // namespace RayTracer

#endif // RAYTRACER_CONFIGURATION_HPP
