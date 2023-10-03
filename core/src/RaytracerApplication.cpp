/*
** EPITECH PROJECT, 2022
** RaytracerApplication
** File description:
** RaytracerApplication
*/

#include "RaytracerApplication.hpp"
#include "Configuration.hpp"
#include "HittableList.hpp"
#include "MathStandard.hpp"
#include "NoiseTexture.hpp"
#include "PPM.hpp"
#include "PlaneXY.hpp"
#include <atomic>
#include <condition_variable>
#include <libconfig.h++>
#include <utility>

namespace RayTracer {
std::ostream &operator<<(std::ostream &os,
                         const RayTracer::SceneBuilder &builder) {
  RayTracer::Camera camera = builder.getCamera();
  RayTracer::HittableList obj = builder.getScene();
  RayTracer::imageConfig_t img = builder.getImageConfig();

  os << "┌── SCENE CONFIG" << std::endl;
  os << "│" << std::endl;
  os << "├─ IMAGE" << std::endl;
  os << "│   ├─ width        = " << img.width << std::endl;
  os << "│   ├─ height       = " << img.height << std::endl;
  os << "│   ├─ depth        = " << img.depth << std::endl;
  os << "│   ├─ spp          = " << img.spp << std::endl;
  os << "│   └─ background   = {" << img.backgroundColor[0] << ", "
     << img.backgroundColor[1] << ", " << img.backgroundColor[2] << "}"
     << std::endl;
  os << "│" << std::endl;
  os << "├─ CAMERA" << std::endl;
  os << "│   ├─ aspect ratio = " << camera.aspectRatio << std::endl;
  os << "│   ├─ look from    = {" << camera.origin.x << ", " << camera.origin.y
     << ", " << camera.origin.z << "}" << std::endl;
  os << "│   ├─ look at      = {" << camera.lookAt.x << ", " << camera.lookAt.y
     << ", " << camera.lookAt.z << "}" << std::endl;
  os << "│   └─ opening time = " << camera._time1 - camera._time0 << std::endl;
  os << "│" << std::endl;
  os << "├─ TEXTURES" << std::endl;
  for (auto const &[key, val] : builder.getTextures()) {
    os << "│   ├─ " << key << std::endl;
  }
  os << "│   └─ " << builder.getTextures().size() << " texture(s)" << std::endl;
  os << "│" << std::endl;
  os << "├─ MATERIALS" << std::endl;
  for (auto const &[key, val] : builder.getMaterials()) {
    os << "│   ├─ " << key << std::endl;
  }
  os << "│   └─ " << builder.getMaterials().size() << " material(s)"
     << std::endl;
  os << "│" << std::endl;
  os << "└─ OBJECTS" << std::endl;
  for (int i{0}; i < obj.getObj().size(); i++) {
    std::string objectName = obj.getObj()[i]->getName();
    os << "    ├─ " << objectName;
    if (objectName.size() < 12) {
      for (int j{0}; j < 12 - objectName.size(); j++) {
        os << " ";
      }
    }
    os << " = " << obj.getObj()[i]->getInfo() << std::endl;
  }
  os << "    └─ " << obj.getObj().size() << " object(s)";
  os << std::endl;
  return os;
}


RaytracerApplication::~RaytracerApplication() = default;

Math::Vector<3>
RaytracerApplication::rayColor(const Ray &ray,
                               const Math::Vector<3> &backgroundColor,
                               const Hittable &world, int depth) {
  if (depth <= 0) {
    return Math::Vector<3>(0.0, 0.0, 0.0);
  }

  HitRecord rec;

  if (!world.hit(ray, 0.001, Math::infinity, rec)) {
    return backgroundColor;
  }

  Ray scattered;
  Math::Vector<3> attenuation;

  if (rec.material == nullptr) {
    throw std::runtime_error(
        "An item without materials was found, please check that all items have "
        "materials. Be careful not to put a texture instead of a material.");
  }

  Math::Vector<3> emitted = rec.material->emittedColor(
      rec.u, rec.v, Math::Vector<3>(rec.p.x, rec.p.y, rec.p.z));

  if (!rec.material->scatter(ray, rec, attenuation, scattered)) {
    return emitted;
  }

  return emitted +
         attenuation * rayColor(scattered, backgroundColor, world, depth - 1);
}

void RaytracerApplication::rayThread(int x, int y, int imageWidth,
                                     int imageHeight, int spp, int maxDepth,
                                     const Math::Vector<3> &backgroundColor,
                                     Camera &cam, HittableList &world,
                                     ImageRendering &render) {
  Math::Vector<3> color(0.0, 0.0, 0.0);

  for (int s = 0; s < spp; ++s) {
    double u = (x + Math::randomDouble()) / (imageWidth - 1);
    double v = (y + Math::randomDouble()) / (imageHeight - 1);

    Ray r = cam.ray(u, v);

    color += rayColor(r, backgroundColor, world, maxDepth);
  }

  render.writePixelColor(x, imageHeight - y - 1, color, spp);
}

void RaytracerApplication::setup(const Camera &camera,
                                 const HittableList &scene,
                                 const imageConfig_t &image) {
  this->_camera = camera;
  this->_world = scene;
  this->_image = image;
}

void RaytracerApplication::setup(const SceneBuilder &builder) {
  this->_camera = builder.getCamera();
  this->_world = builder.getScene();
  this->_image = builder.getImageConfig();

  std::cerr << builder << std::endl;
}

int RaytracerApplication::run(ImageRendering &render) {
  unsigned int numThreads = std::thread::hardware_concurrency();
  std::vector<std::thread> threads(numThreads);
  std::mutex renderMutex;
  std::atomic<int> currentLine(this->_image.height - 1);

  auto nextLineToProcess = [&]() -> int {
    std::unique_lock<std::mutex> lock(renderMutex);
    std::cerr << "\r─> Pixel lines remaining: " << currentLine + 1 << ' '
              << std::flush;
    return 0 <= currentLine ? currentLine-- : -1;
  };

  for (unsigned int i{0}; i < numThreads; i++) {
    threads[i] = std::thread([&]() {
      while (true) {
        int line = nextLineToProcess();
        if (line < 0) {
          break;
        }
        for (int x{0}; x < this->_image.width; x++) {
          this->rayThread(x, line, this->_image.width, this->_image.height,
                          this->_image.spp, this->_image.depth,
                          this->_image.backgroundColor, this->_camera,
                          this->_world, render);
        }
      }
    });
  }

  for (auto &t : threads) {
    t.join();
  }

  std::cerr << std::endl
            << std::endl
            << "─> Done, see result with command \"xdg-open [FILE]\""
            << std::endl;

  return 0;
}
} // namespace RayTracer

int main(int argc, char **argv) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: " << argv[0] << " [SCENE_FILE]" << std::endl;
            return 84;
        }
        std::string sceneFile(argv[1]);


        RayTracer::Configuration config(sceneFile);
        RayTracer::SceneBuilder world = config.loadSceneFromFile();
        RayTracer::imageConfig_t image = world.getImageConfig();
        RayTracer::PPM ppm(image.width, image.height);



        RayTracer::RaytracerApplication app;

        app.setup(world);

        app.run(ppm);
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        return 84;
    }
    return 0;
}
