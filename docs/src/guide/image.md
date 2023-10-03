# Configuration de l'image

Pour créer une image avec votre raytracer, vous devez configurer ses propriétés dans un fichier de configuration. Les propriétés de l'image incluent sa hauteur, sa largeur, sa profondeur, le nombre d'échantillons par pixel et la couleur de fond.

Le format de fichier de configuration est simple : il s'agit d'un fichier texte avec des paires clé-valeur. La clé est le nom de la propriété et la valeur est sa valeur. Voici un exemple de configuration pour l'image :

```yaml
image:
{
    height = 300;
    width = 300;
    depth = 100;
    samplesPerPixel = 50;
    backgroundColor = { r = 0.0; g = 0.0; b = 0.0; };
}
```

Dans cet exemple, l'image a une hauteur de 300 pixels, une largeur de 300 pixels et une profondeur de 100. Le nombre d'échantillons par pixel est de 50 et la couleur de fond est noire.

## Propriétés de l'image

Voici la signification des propriétés de l'image :

- `height` : la hauteur de l'image en pixels.
- `width` : la largeur de l'image en pixels.
- `depth` : la profondeur de l'image, utilisée pour les images en 3D.
- `samplesPerPixel` : le nombre d'échantillons par pixel. Plus ce nombre est élevé, plus l'image sera précise mais le temps de rendu sera plus long.
- `backgroundColor` : la couleur de fond de l'image. Cette propriété est un objet avec trois propriétés : `r`, `g` et `b`, qui définissent les composantes rouge, verte et bleue de la couleur.

## Exemple de configuration

Voici un exemple de configuration pour une image en 3D avec une hauteur de 600 pixels, une largeur de 800 pixels, une profondeur de 200, 100 échantillons par pixel et un fond blanc :

```yaml
image:
{
    height = 600;
    width = 800;
    depth = 200;
    samplesPerPixel = 100;
    backgroundColor = { r = 1.0; g = 1.0; b = 1.0; };
}
```

N'hésitez pas à ajuster ces valeurs en fonction de vos besoins.