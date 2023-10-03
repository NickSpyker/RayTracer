/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** SceneBuilder.cpp
*/

#include "SceneBuilder.hpp"

#include "Box.hpp"
#include "Checker.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "Dielectric.hpp"
#include "Diffuse.hpp"
#include "DiffuseLight.hpp"
#include "Metal.hpp"
#include "NoiseTexture.hpp"
#include "PlaneXY.hpp"
#include "PlaneXZ.hpp"
#include "PlaneYZ.hpp"
#include "RotateY.hpp"
#include "SolidColor.hpp"
#include "Sphere.hpp"
#include "Translate.hpp"
#include <utility>
#include "Point3D.hpp"
#include "ObjectFactory.hpp"

RayTracer::SceneBuilder::SceneBuilder() {
  // Default image config:
  this->_config = {225, 400, 100, 50, Math::Vector<3>(0.0, 0.0, 0.0)};

  // Default camera config:
  this->_camera = {
      16.0 / 9.0, 0.0, {0.0, 0.0, 10.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0.0,
      100.0,      70.0};
}

RayTracer::Camera RayTracer::SceneBuilder::getCamera() const {
  return RayTracer::Camera(
      Math::Point3D(this->_camera.lookFrom.x, this->_camera.lookFrom.y,
                    this->_camera.lookFrom.z),
      Math::Point3D(this->_camera.lookAt.x, this->_camera.lookAt.y,
                    this->_camera.lookAt.z),
      Math::Vector<3>(this->_camera.upAxis.x, this->_camera.upAxis.y,
                      this->_camera.upAxis.z),
      this->_camera.fov, this->_camera.aspectRatio, this->_camera.aperture,
      this->_camera.focus, 0.0, this->_camera.openingTime);
}

RayTracer::HittableList RayTracer::SceneBuilder::getScene() const {
  return this->_objects;
}

RayTracer::imageConfig_t RayTracer::SceneBuilder::getImageConfig() const {
  return this->_config;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::imageConfig(const RayTracer::imageConfig_t &config) {
  this->_config = config;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::imageBackgroundColor(Math::Vector<3> color) {
  this->_config.backgroundColor = std::move(color);
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::imageSize(int width,
                                                            int height) {
  this->_config.width = width;
  this->_config.height = height;
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::imageWidth(int width) {
  this->_config.width = width;
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::imageHeight(int height) {
  this->_config.height = height;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::imageWidthWithAspectRatio(double aspectRatio) {
  this->_config.width = int(double(this->_config.height) * aspectRatio);
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::imageHeightWithAspectRatio(double aspectRatio) {
  this->_config.height = int(double(this->_config.width) / aspectRatio);
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::imageDepth(int depth) {
  this->_config.depth = depth;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::imageSamplesPerPixel(int samplesPerPixel) {
  this->_config.spp = samplesPerPixel;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::cameraConfig(const RayTracer::cameraConfig_t &config) {
  this->_camera = config;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::cameraAspectRatio(double aspectRatio) {
  this->_camera.aspectRatio = aspectRatio;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::cameraOpeningTime(double time) {
  this->_camera.openingTime = time;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::cameraLookFrom(point3d_t point) {
  this->_camera.lookFrom = point;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::cameraLookAt(point3d_t lookAt) {
  this->_camera.lookAt.x = lookAt.x;
  this->_camera.lookAt.y = lookAt.y;
  this->_camera.lookAt.z = lookAt.z;
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::cameraUpAxis(point3d_t vUp) {
  this->_camera.upAxis.x = vUp.x;
  this->_camera.upAxis.y = vUp.y;
  this->_camera.upAxis.z = vUp.z;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::cameraAperture(double aperture) {
  this->_camera.aperture = aperture;
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::cameraFocus(double focus) {
  this->_camera.focus = focus;
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::cameraFOV(double fov) {
  this->_camera.fov = fov;
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::addTexture(
    const std::string &setTextureName,
    const std::shared_ptr<RayTracer::Texture> &texture) {
  this->_textures[setTextureName] = texture;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addSolidColorTexture(const std::string &setTextureName,
                                              color_t rgb) {
  this->_textures[setTextureName] =
      std::make_shared<RayTracer::SolidColor>(rgb.r, rgb.g, rgb.b);
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::addChessBoardTexture(
    const std::string &setTextureName, color_t rgbLight, color_t rgbDark) {
  this->_textures[setTextureName] = std::make_shared<RayTracer::Checker>(
      Math::Vector<3>(rgbLight.r, rgbLight.g, rgbLight.b),
      Math::Vector<3>(rgbDark.r, rgbDark.g, rgbDark.b));
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addChessBoardTexture(const std::string &setTextureName,
                                              const std::string &textureLight,
                                              const std::string &textureDark) {
  this->_textures[setTextureName] = std::make_shared<RayTracer::Checker>(
      this->_textures[textureLight], this->_textures[textureDark]);
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addNoiseTexture(const std::string &setTextureName,
                                         double scale) {
  this->_textures[setTextureName] =
      std::make_shared<RayTracer::NoiseTexture>(scale);
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::addMaterial(
    const std::string &materialName,
    const std::shared_ptr<RayTracer::Material> &material) {
  this->_materials[materialName] = material;
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addGlassMaterial(const std::string &materialName,
                                          double refraction) {
  this->_materials[materialName] =
      std::make_shared<RayTracer::Dielectric>(refraction);
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addSolidMaterial(const std::string &materialName,
                                          color_t rgb) {
  this->_materials[materialName] = std::make_shared<RayTracer::Diffuse>(
      Math::Vector<3>(rgb.r, rgb.g, rgb.b));
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addSolidMaterial(const std::string &materialName,
                                          const std::string &textureName) {
  this->_materials[materialName] =
      std::make_shared<RayTracer::Diffuse>(this->_textures[textureName]);
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addMetalMaterial(const std::string &materialName,
                                          color_t rgb, double fuzz) {
  this->_materials[materialName] = std::make_shared<RayTracer::Metal>(
      Math::Vector<3>(rgb.r, rgb.g, rgb.b), fuzz);
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::addDirectionalLightMaterial(
    const std::string &materialName, color_t rgb) {
  this->_materials[materialName] = std::make_shared<RayTracer::DiffuseLight>(
      Math::Vector<3>(rgb.r, rgb.g, rgb.b));
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::addDirectionalLightMaterial(
    const std::string &materialName, const std::string &textureName) {
  this->_materials[materialName] =
      std::make_shared<RayTracer::DiffuseLight>(this->_textures[textureName]);
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::setAmbianceLight(color_t rgb) {
  this->_config.backgroundColor[0] = rgb.r;
  this->_config.backgroundColor[1] = rgb.g;
  this->_config.backgroundColor[2] = rgb.b;
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::addObject(
    const std::shared_ptr<RayTracer::Hittable> &obj) {
  this->_objects.add(obj);
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addSphere(point3d_t pos, double radius,
                                   const std::string &material) {
    this->_objects.add(
            RayTracer::ObjectFactory::createSphere(
                    Math::Point3D(pos.x, pos.y, pos.z),
                    radius,
                    this->_materials[material]
            )
    );
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addPlane(point3d_t p0, point3d_t p1,
                                  const std::string &material) {
    this->_objects.add(
            RayTracer::ObjectFactory::createPlane(
                    Math::Point3D(p0.x, p0.y, p0.z),
                    Math::Point3D(p1.x, p1.y, p1.z),
                    this->_materials[material]
            )
    );
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addBox(point3d_t p0, point3d_t p1,
                                const std::string &material) {
    this->_objects.add(
            RayTracer::ObjectFactory::createBox(
                    Math::Point3D(p0.x, p0.y, p0.z),
                    Math::Point3D(p1.x, p1.y, p1.z),
                    this->_materials[material]
            )
    );
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addCylinder(RayTracer::point3d_t pos, double radius,
                                     double height,
                                     const std::string &material) {
    this->_objects.add(
            RayTracer::ObjectFactory::createCylinder(
                    Math::Point3D(pos.x, pos.y, pos.z),
                    radius,
                    height,
                    this->_materials[material]
            )
    );
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::addCone(RayTracer::point3d_t pos, double radius,
                                 double height, const std::string &material) {
    this->_objects.add(
            RayTracer::ObjectFactory::createCone(
                    Math::Point3D(pos.x, pos.y, pos.z),
                    height,
                    radius,
                    this->_materials[material]
            )
    );
  return *this;
}

RayTracer::SceneBuilder &
RayTracer::SceneBuilder::translate(RayTracer::point3d_t trs) {
  this->_objects.back() = std::make_shared<RayTracer::Translate>(
      this->_objects.back(), Math::Vector<3>(trs.x, trs.y, trs.z));
  return *this;
}

RayTracer::SceneBuilder &RayTracer::SceneBuilder::rotateY(double angle) {
  this->_objects.back() =
      std::make_shared<RayTracer::RotateY>(this->_objects.back(), angle);
  return *this;
}
RayTracer::cameraConfig_t RayTracer::SceneBuilder::getCameraConfig() const {
  return this->_camera;
}
std::map<std::string, std::shared_ptr<RayTracer::Texture>>
RayTracer::SceneBuilder::getTextures() const {
  return this->_textures;
}
std::map<std::string, std::shared_ptr<RayTracer::Material>>
RayTracer::SceneBuilder::getMaterials() const {
  return this->_materials;
}
