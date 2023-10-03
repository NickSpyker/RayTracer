# Configuration de la caméra

La caméra détermine la façon dont la scène est vue et rendue en image. Cette section décrit les propriétés de la caméra qui peuvent être configurées dans le fichier de configuration.

## Propriétés

- `aspectRatio` : Le rapport hauteur/largeur de l'image. Par défaut, il est défini à `1.0`.
- `lookFrom` : La position de la caméra dans l'espace 3D. Elle est définie par un vecteur de coordonnées `x`, `y` et `z`. Par défaut, elle est définie à `{ x = 278.0; y = 278.0; z = -800.0; }`.
- `lookAt` : Le point vers lequel la caméra est dirigée. Il est également défini par un vecteur de coordonnées `x`, `y` et `z`. Par défaut, il est défini à `{ x = 278.0; y = 278.0; z = 0.0; }`.
- `fov` : Le champ de vision de la caméra en degrés. Par défaut, il est défini à `40.0`.

## Exemple de configuration

Voici un exemple de configuration de la caméra :

```yaml
camera:
{
    aspectRatio = 1.0;
    lookFrom = { x = 278.0; y = 278.0; z = -800.0; };
    lookAt = { x = 278.0; y = 278.0; z = 0.0; };
    fov = 40.0;
};
```

N'hésitez pas à ajuster ces valeurs en fonction de vos besoins.