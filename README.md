# Ray Tracer

## Dependencies
**libconfig.h++:**
```shell
sudo apt-get install -y libconfig++-dev
```

## Configuration of Scenes in Raytracer

This README.md file explains how to use the configuration file to generate scenes in a C++ raytracer. The configuration file contains three main sections: camera, primitives, and lights. 

### Camera Configuration

The camera section specifies the properties of the camera, including the resolution of the output image, its position, rotation, and field of view. 

- **resolution**: The width and height of the output image in pixels.
- **position**: The position of the camera in 3D space, specified by its x, y, and z coordinates.
- **rotation**: The rotation of the camera in 3D space, specified by its x, y, and z angles in degrees.
- **fieldOfView**: The field of view of the camera in degrees.

### Primitive Configuration

The primitives section defines the objects in the scene, including spheres and planes. 

- **spheres**: A list of spheres, each specified by its x, y, and z coordinates, radius, and color.
- **planes**: A list of planes, each specified by its axis (either "X", "Y", or "Z"), position along that axis, and color.

### Light Configuration

The lights section specifies the lighting properties of the scene, including ambient and diffuse lighting, and the positions of point and directional lights. 

- **ambient**: A multiplier for the ambient light in the scene.
- **diffuse**: A multiplier for the diffuse light in the scene.
- **point**: A list of point lights, each specified by its x, y, and z coordinates.
- **directional**: A list of directional lights, each specified by its x, y, and z coordinates.

### Example Configuration

Here's an example configuration file:

```c
camera:
{
    resolution = { width = 1920.0; height = 1080.0; };
    position = { x = 1.0; y = -100.0; z = 20.0; };
    rotation = { x = 0.0; y = 0.0; z = 0.0; };
    fieldOfView = 72.0;
};

primitives:
{
    spheres = (
        { x = 60.0; y = 5.0; z = 40.0; r = 25.0; color = { r = 255; g = 64; b = 64; }; },
        { x = -40.0; y = 20.0; z = -10.0; r = 35.0; color = { r = 64; g = 255; b = 64; }; }
    );

    planes = (
        { axis = "Z"; position = -20.0; color = { r = 64; g = 64; b = 255; }; }
    );
};

lights:
{
    ambient = 0.4;
    diffuse = 0.6;

    point = (
        { x = 400; y = 100; z = 500; }
    );

    directional = ();
};
```

This configuration file specifies a camera with a resolution of 1920x1080, positioned at x = 1.0, y = -100.0, z = 20.0, and facing straight ahead. The scene contains two spheres and one plane, with the spheres having colors of red and green, respectively, and the plane being blue. The lighting in the scene includes an ambient light of 0.4 and a diffuse light of 0.6, as well as a single point light at position x = 400, y = 100
