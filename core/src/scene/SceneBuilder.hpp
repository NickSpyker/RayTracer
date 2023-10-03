/*
** EPITECH PROJECT, 2022
** RayTracer
** File description:
** SceneBuilder.hpp
*/

#ifndef RAYTRACER_SCENE_BUILDER_HPP
    #define RAYTRACER_SCENE_BUILDER_HPP

    #include "HittableList.hpp"
    #include "Material.hpp"
    #include "Hittable.hpp"
    #include "Texture.hpp"
    #include "Camera.hpp"
    #include <ostream>
    #include <vector>
    #include <string>
    #include <map>

namespace RayTracer
{
    typedef struct {
        double x;
        double y;
        double z;
    } point3d_t;

    typedef struct {
        double r;
        double g;
        double b;
    } color_t;

    typedef struct {
        int height;
        int width;
        int depth;
        int spp;
        Math::Vector<3> backgroundColor;
    } imageConfig_t;

    typedef struct {
        double aspectRatio;
        double openingTime;
        point3d_t lookFrom;
        point3d_t lookAt;
        point3d_t upAxis;
        double aperture;
        double focus;
        double fov;
    } cameraConfig_t;

    class SceneBuilder
    {
        private:
            imageConfig_t _config{};
            cameraConfig_t _camera{};

            std::map<std::string, std::shared_ptr<Texture>> _textures{};
            std::map<std::string, std::shared_ptr<Material>> _materials{};
            HittableList _objects{};

        public:
            SceneBuilder();
            ~SceneBuilder() = default;

            // Getters:
            [[nodiscard]] Camera getCamera() const;
            [[nodiscard]] HittableList getScene() const;
            [[nodiscard]] imageConfig_t getImageConfig() const;
            [[nodiscard]] cameraConfig_t getCameraConfig() const;
            [[nodiscard]] std::map<std::string, std::shared_ptr<Texture>> getTextures() const;
            [[nodiscard]] std::map<std::string, std::shared_ptr<Material>> getMaterials() const;

            // Image:
            SceneBuilder& imageConfig(const imageConfig_t& config);
            SceneBuilder& imageSize(int width, int height);
            SceneBuilder& imageWidth(int width);
            SceneBuilder& imageHeight(int height);
            SceneBuilder& imageWidthWithAspectRatio(double aspectRatio);
            SceneBuilder& imageHeightWithAspectRatio(double aspectRatio);
            SceneBuilder& imageDepth(int depth);
            SceneBuilder& imageSamplesPerPixel(int samplesPerPixel);
            SceneBuilder& imageBackgroundColor(Math::Vector<3> color);

            // Camera:
            SceneBuilder& cameraConfig(const cameraConfig_t& config);
            SceneBuilder& cameraAspectRatio(double aspectRatio);
            SceneBuilder& cameraOpeningTime(double time);
            SceneBuilder& cameraLookFrom(point3d_t point);
            SceneBuilder& cameraLookAt(point3d_t lookAt);
            SceneBuilder& cameraUpAxis(point3d_t vUp);
            SceneBuilder& cameraAperture(double aperture);
            SceneBuilder& cameraFocus(double focus);
            SceneBuilder& cameraFOV(double fov);

            // Textures:
            SceneBuilder& addTexture(const std::string& setTextureName, const std::shared_ptr<RayTracer::Texture>& texture);
            SceneBuilder& addSolidColorTexture(const std::string& setTextureName, color_t rgb);
            SceneBuilder& addChessBoardTexture(const std::string& setTextureName, color_t rgbLight, color_t rgbDark);
            SceneBuilder& addChessBoardTexture(const std::string& setTextureName, const std::string& textureLight, const std::string &textureDark);
            SceneBuilder& addNoiseTexture(const std::string &setTextureName, double scale = 1.0);

            // Materials:
            SceneBuilder& addMaterial(const std::string& materialName, const std::shared_ptr<RayTracer::Material>& material);
            SceneBuilder& addGlassMaterial(const std::string& materialName, double refraction);
            SceneBuilder& addSolidMaterial(const std::string& materialName, color_t rgb);
            SceneBuilder& addSolidMaterial(const std::string& materialName, const std::string& textureName);
            SceneBuilder& addMetalMaterial(const std::string& materialName, color_t rgb, double fuzz);

            // Lights:
            SceneBuilder& addDirectionalLightMaterial(const std::string& materialName, color_t rgb);
            SceneBuilder& addDirectionalLightMaterial(const std::string& materialName, const std::string& textureName);
            SceneBuilder& setAmbianceLight(color_t rgb);

            // Objects:
            SceneBuilder& addObject(const std::shared_ptr<RayTracer::Hittable>& obj);
            SceneBuilder& addSphere(point3d_t pos, double radius, const std::string& material);
            SceneBuilder& addPlane(point3d_t p0, point3d_t p1, const std::string& material);
            SceneBuilder& addBox(point3d_t p0, point3d_t p1, const std::string& material);
            SceneBuilder& addCylinder(point3d_t pos, double radius, double height, const std::string& material);
            SceneBuilder& addCone(point3d_t pos, double radius, double height, const std::string& material);

            // Transform utils:
            SceneBuilder& translate(point3d_t trs);
            SceneBuilder& rotateY(double angle);
    };

    std::ostream& operator<<(std::ostream& os, const SceneBuilder& builder);
}

#endif // !RAYTRACER_SCENE_BUILDER_HPP
