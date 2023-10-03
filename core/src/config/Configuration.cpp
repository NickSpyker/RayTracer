/*
** EPITECH PROJECT, 2022
** Configuration
** File description:
** Configuration
*/
#include "Configuration.hpp"
#include "SceneBuilder.hpp"
#include "iostream"
#include <utility>

namespace RayTracer {

SceneBuilder Configuration::loadSceneFromFile() {
  SceneBuilder builder;
  this->cfg.readFile(this->_path.c_str());
  const libconfig::Setting &root = this->cfg.getRoot();

  if (root.exists("image")) {
    const libconfig::Setting &image = root["image"];

    this->loadImageConfig(builder, image);
  }

  if (root.exists("camera")) {
    const libconfig::Setting &camera = root["camera"];

    this->loadCameraConfig(builder, camera);
  }

  if (root.exists("textures")) {
    const libconfig::Setting &textures = root["textures"];

    this->loadTextures(builder, textures);
  }

  if (root.exists("materials")) {
    const libconfig::Setting &materials = root["materials"];

    this->loadMaterials(builder, materials);
  }

  if (root.exists("primitives")) {
    const libconfig::Setting &primitives = root["primitives"];

    this->loadPrimitives(builder, primitives);
  }

  return builder;
}

void Configuration::loadTextures(SceneBuilder &builder,
                                 const libconfig::Setting &textures) {
  if (textures.exists("noise")) {
    const libconfig::Setting &noise = textures["noise"];

    for (int i = 0; i < noise.getLength(); i++) {
      const libconfig::Setting &texture = noise[i];
      std::string name = "";
      double scale = 1.0;

      if (texture.exists("name"))
        texture.lookupValue("name", name);
      if (texture.exists("scale"))
        texture.lookupValue("scale", scale);

      if (name.empty())
        throw std::runtime_error("Texture name is empty");
      builder.addNoiseTexture(name, scale);
    }
  }
  if (textures.exists("solidColor")) {
    const libconfig::Setting &solidColor = textures["solidColor"];

    for (int i = 0; i < solidColor.getLength(); i++) {
      const libconfig::Setting &texture = solidColor[i];
      std::string name = "";
      color_t color = {0.0, 0.0, 0.0};

      if (texture.exists("name"))
        texture.lookupValue("name", name);
      if (texture.exists("color"))
        color = this->getRGBColor(texture["color"]);

      if (name.empty())
        throw std::runtime_error("Texture name is empty");
      builder.addSolidColorTexture(name, color);
    }
  }
  if (textures.exists("chessboard")) {
    if (textures["chessboard"].exists("textured")) {
      for (int i = 0; i < textures["chessboard"]["textured"].getLength(); i++) {
        const libconfig::Setting &texture =
            textures["chessboard"]["textured"][i];
        std::string name = "";
        std::string lightTextureName = "";
        std::string darkTextureName = "";

        if (texture.exists("name"))
          texture.lookupValue("name", name);
        if (texture.exists("lightTexture"))
          texture.lookupValue("lightTexture", lightTextureName);
        if (texture.exists("darkTexture"))
          texture.lookupValue("darkTexture", darkTextureName);

        if (name.empty())
          throw std::runtime_error("Texture name is empty");
        if (lightTextureName.empty())
          throw std::runtime_error("Light texture name is empty");
        if (darkTextureName.empty())
          throw std::runtime_error("Dark texture name is empty");

        builder.addChessBoardTexture(name, lightTextureName, darkTextureName);
      }
    }
    if (textures["chessboard"].exists("colored")) {
      for (int i = 0; i < textures["chessboard"]["colored"].getLength(); i++) {
        const libconfig::Setting &texture =
            textures["chessboard"]["colored"][i];
        std::string name = "";
        color_t lightColor = {0.0, 0.0, 0.0};
        color_t darkColor = {0.0, 0.0, 0.0};

        if (texture.exists("name"))
          texture.lookupValue("name", name);
        if (texture.exists("lightColor"))
          lightColor = this->getRGBColor(texture["lightColor"]);
        if (texture.exists("darkColor"))
          darkColor = this->getRGBColor(texture["darkColor"]);

        if (name.empty())
          throw std::runtime_error("Texture name is empty");
        builder.addChessBoardTexture(name, lightColor, darkColor);
      }
    }
  }
}

Configuration::Configuration(std::string path) : _path(std::move(path)) {}
point3d_t Configuration::getPoint3d(const libconfig::Setting &setting) {
  point3d_t point;
  point.x = 0.0;
  point.y = 0.0;
  point.z = 0.0;

  if (setting.exists("x"))
    setting.lookupValue("x", point.x);
  if (setting.exists("y"))
    setting.lookupValue("y", point.y);
  if (setting.exists("z"))
    setting.lookupValue("z", point.z);
  return point;
}

void Configuration::loadImageConfig(SceneBuilder &builder,
                                    const libconfig::Setting &setting) {
  if (setting.exists("height"))
    builder.imageHeight(setting["height"]);
  if (setting.exists("width"))
    builder.imageWidth(setting["width"]);
  if (setting.exists("depth"))
    builder.imageDepth(setting["depth"]);
  if (setting.exists("samplesPerPixel"))
    builder.imageSamplesPerPixel(setting["samplesPerPixel"]);
  if (setting.exists("backgroundColor"))
    builder.imageBackgroundColor(this->getRGB(setting["backgroundColor"]));
}

Math::Vector<3> Configuration::getRGB(const libconfig::Setting &setting) {
  Math::Vector<3> rgb;
  rgb.e[0] = 0.0;
  rgb.e[1] = 0.0;
  rgb.e[2] = 0.0;

  if (setting.exists("r"))
    setting.lookupValue("r", rgb.e[0]);
  if (setting.exists("g"))
    setting.lookupValue("g", rgb.e[1]);
  if (setting.exists("b"))
    setting.lookupValue("b", rgb.e[2]);
  return rgb;
}

void Configuration::loadCameraConfig(RayTracer::SceneBuilder &builder,
                                     const libconfig::Setting &setting) {
  if (setting.exists("aspectRatio")) {
    builder.cameraAspectRatio(setting["aspectRatio"]);
  }
  if (setting.exists("openingTime")) {
    builder.cameraOpeningTime(setting["openingTime"]);
  }
  if (setting.exists("lookFrom")) {
    builder.cameraLookFrom(this->getPoint3d(setting["lookFrom"]));
  }
  if (setting.exists("lookAt")) {
    builder.cameraLookAt(this->getPoint3d(setting["lookAt"]));
  }
  if (setting.exists("upAxis")) {
    builder.cameraUpAxis(this->getPoint3d(setting["upAxis"]));
  }
  if (setting.exists("aperture")) {
    builder.cameraAperture(setting["aperture"]);
  }
  if (setting.exists("focus")) {
    builder.cameraFocus(setting["focus"]);
  }
  if (setting.exists("fov")) {
    builder.cameraFOV(setting["fov"]);
  }
}

color_t Configuration::getRGBColor(const libconfig::Setting &setting) {
  color_t color;
  color.r = 0.0;
  color.g = 0.0;
  color.b = 0.0;

  if (setting.exists("r"))
    setting.lookupValue("r", color.r);
  if (setting.exists("g"))
    setting.lookupValue("g", color.g);
  if (setting.exists("b"))
    setting.lookupValue("b", color.b);
  return color;
}
void Configuration::loadMaterials(SceneBuilder &builder,
                                  const libconfig::Setting &setting) {
  if (setting.exists("directionalLight")) {
    if (setting["directionalLight"].exists("textured")) {
      for (int i = 0; i < setting["directionalLight"]["textured"].getLength();
           i++) {
        const libconfig::Setting &material =
            setting["directionalLight"]["textured"][i];
        std::string name = "";
        std::string textureName = "";

        if (material.exists("name"))
          material.lookupValue("name", name);
        if (material.exists("texture"))
          material.lookupValue("texture", textureName);

        if (name.empty())
          throw std::runtime_error("Material name is empty");
        if (textureName.empty())
          throw std::runtime_error("Texture name is empty");
        builder.addDirectionalLightMaterial(name, textureName);
      }
    }
    if (setting["directionalLight"].exists("colored")) {
      for (int i = 0; i < setting["directionalLight"]["colored"].getLength();
           i++) {
        const libconfig::Setting &material =
            setting["directionalLight"]["colored"][i];
        std::string name = "";
        color_t color = {0.0, 0.0, 0.0};

        if (material.exists("name"))
          material.lookupValue("name", name);
        if (material.exists("color"))
          color = this->getRGBColor(material["color"]);

        if (name.empty())
          throw std::runtime_error("Material name is empty");
        builder.addDirectionalLightMaterial(name, color);
      }
    }
  }
  if (setting.exists("glass")) {
    for (int i = 0; i < setting["glass"].getLength(); i++) {
      const libconfig::Setting &material = setting["glass"][i];
      std::string name = "";
      double refraction = 0.0;

      if (material.exists("name"))
        material.lookupValue("name", name);
      if (material.exists("refraction"))
        material.lookupValue("refraction", refraction);

      if (name.empty())
        throw std::runtime_error("Material name is empty");
      builder.addGlassMaterial(name, refraction);
    }
  }
  if (setting.exists("metal")) {
    for (int i = 0; i < setting["metal"].getLength(); i++) {
      const libconfig::Setting &material = setting["metal"][i];
      std::string name = "";
      color_t color = {0.0, 0.0, 0.0};
      double fuzziness = 0.0;

      if (material.exists("name"))
        material.lookupValue("name", name);
      if (material.exists("color"))
        color = this->getRGBColor(material["color"]);
      if (material.exists("fuzziness"))
        material.lookupValue("fuzziness", fuzziness);
      if (name.empty())
        throw std::runtime_error("Material name is empty");
      builder.addMetalMaterial(name, color, fuzziness);
    }
  }
  if (setting.exists("solid")) {
    if (setting["solid"].exists("textured")) {
      for (int i = 0; i < setting["solid"]["textured"].getLength(); i++) {
        const libconfig::Setting &material = setting["solid"]["textured"][i];
        std::string name = "";
        std::string textureName = "";

        if (material.exists("name"))
          material.lookupValue("name", name);
        if (material.exists("texture"))
          material.lookupValue("texture", textureName);

        if (name.empty())
          throw std::runtime_error("Material name is empty");
        if (textureName.empty())
          throw std::runtime_error("Texture name is empty");
        builder.addSolidMaterial(name, textureName);
      }
    }
    if (setting["solid"].exists("colored")) {
      for (int i = 0; i < setting["solid"]["colored"].getLength(); i++) {
        const libconfig::Setting &material = setting["solid"]["colored"][i];
        std::string name = "";
        color_t color = {0.0, 0.0, 0.0};

        if (material.exists("name"))
          material.lookupValue("name", name);
        if (material.exists("color"))
          color = this->getRGBColor(material["color"]);

        if (name.empty())
          throw std::runtime_error("Material name is empty");
        builder.addSolidMaterial(name, color);
      }
    }
  }
}
void Configuration::loadPrimitives(SceneBuilder &builder,
                                   const libconfig::Setting &setting) {
  if (setting.exists("spheres")) {
    for (int i = 0; i < setting["spheres"].getLength(); i++) {
      const libconfig::Setting &primitive = setting["spheres"][i];
      point3d_t position = {0.0, 0.0, 0.0};
      double radius = 0.0;
      std::string materialName = "";

      if (primitive.exists("position"))
        position = this->getPoint3d(primitive["position"]);
      if (primitive.exists("radius"))
        primitive.lookupValue("radius", radius);
      if (primitive.exists("material"))
        primitive.lookupValue("material", materialName);

      if (materialName.empty())
        throw std::runtime_error("Material name is empty");
      builder.addSphere(position, radius, materialName);

      if (primitive.exists("rotateY")) {
        double angle = 0.0;
        primitive.lookupValue("rotateY", angle);
        builder.rotateY(angle);
      }
      if (primitive.exists("translate")) {
        point3d_t translation = {0.0, 0.0, 0.0};
        translation = this->getPoint3d(primitive["translate"]);
        builder.translate(translation);
      }
    }
  }
  if (setting.exists("planes")) {
    for (int i = 0; i < setting["planes"].getLength(); i++) {
      const libconfig::Setting &primitive = setting["planes"][i];
      point3d_t point1 = {0.0, 0.0, 0.0};
      point3d_t point2 = {0.0, 0.0, 0.0};
      std::string materialName = "";

      if (primitive.exists("point1"))
        point1 = this->getPoint3d(primitive["point1"]);
      if (primitive.exists("point2"))
        point2 = this->getPoint3d(primitive["point2"]);
      if (primitive.exists("material"))
        primitive.lookupValue("material", materialName);

      if (materialName.empty())
        throw std::runtime_error("Material name is empty");
      builder.addPlane(point1, point2, materialName);

      if (primitive.exists("rotateY")) {
        double angle = 0.0;
        primitive.lookupValue("rotateY", angle);
        builder.rotateY(angle);
      }
      if (primitive.exists("translate")) {
        point3d_t translation = {0.0, 0.0, 0.0};
        translation = this->getPoint3d(primitive["translate"]);
        builder.translate(translation);
      }
    }
  }
  if (setting.exists("boxes")) {
    for (int i = 0; i < setting["boxes"].getLength(); i++) {
      const libconfig::Setting &primitive = setting["boxes"][i];
      point3d_t point1 = {0.0, 0.0, 0.0};
      point3d_t point2 = {0.0, 0.0, 0.0};
      std::string materialName = "";

      if (primitive.exists("point1"))
        point1 = this->getPoint3d(primitive["point1"]);
      if (primitive.exists("point2"))
        point2 = this->getPoint3d(primitive["point2"]);
      if (primitive.exists("material"))
        primitive.lookupValue("material", materialName);

      if (materialName.empty())
        throw std::runtime_error("Material name is empty");
      builder.addBox(point1, point2, materialName);

      if (primitive.exists("rotateY")) {
        double angle = 0.0;
        primitive.lookupValue("rotateY", angle);
        builder.rotateY(angle);
      }
      if (primitive.exists("translate")) {
        point3d_t translation = {0.0, 0.0, 0.0};
        translation = this->getPoint3d(primitive["translate"]);
        builder.translate(translation);
      }
    }
  }

  if (setting.exists("cones")) {
    for (int i = 0; i < setting["cones"].getLength(); i++) {
      const libconfig::Setting &primitive = setting["cones"][i];
      point3d_t position = {0.0, 0.0, 0.0};
      double radius = 0.0;
      double height = 0.0;
      std::string materialName = "";

      if (primitive.exists("position"))
        position = this->getPoint3d(primitive["position"]);
      if (primitive.exists("radius"))
        primitive.lookupValue("radius", radius);
      if (primitive.exists("height"))
        primitive.lookupValue("height", height);
      if (primitive.exists("material"))
        primitive.lookupValue("material", materialName);

      if (materialName.empty())
        throw std::runtime_error("Material name is empty");
      builder.addCone(position, radius, height, materialName);

      if (primitive.exists("rotateY")) {
        double angle = 0.0;
        primitive.lookupValue("rotateY", angle);
        builder.rotateY(angle);
      }
      if (primitive.exists("translate")) {
        point3d_t translation = {0.0, 0.0, 0.0};
        translation = this->getPoint3d(primitive["translate"]);
        builder.translate(translation);
      }
    }
  }

  if (setting.exists("cylinders")) {
    for (int i = 0; i < setting["cylinders"].getLength(); i++) {
      const libconfig::Setting &primitive = setting["cylinders"][i];
      point3d_t position = {0.0, 0.0, 0.0};
      double radius = 0.0;
      double height = 0.0;
      std::string materialName = "";

      if (primitive.exists("position"))
        position = this->getPoint3d(primitive["position"]);
      if (primitive.exists("radius"))
        primitive.lookupValue("radius", radius);
      if (primitive.exists("height"))
        primitive.lookupValue("height", height);
      if (primitive.exists("material"))
        primitive.lookupValue("material", materialName);

      if (materialName.empty())
        throw std::runtime_error("Material name is empty");
      builder.addCylinder(position, radius, height, materialName);

      if (primitive.exists("rotateY")) {
        double angle = 0.0;
        primitive.lookupValue("rotateY", angle);
        builder.rotateY(angle);
      }
      if (primitive.exists("translate")) {
        point3d_t translation = {0.0, 0.0, 0.0};
        translation = this->getPoint3d(primitive["translate"]);
        builder.translate(translation);
      }
    }
  }
}

}; // namespace RayTracer