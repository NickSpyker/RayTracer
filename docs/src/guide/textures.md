# Configuration des textures

La configuration des textures dans le raytracer se fait via la section "textures" du fichier de configuration. Cette section permet de définir différentes textures avec leurs propriétés.

## Texture "noise"

La texture "noise" permet d'ajouter du bruit à une surface. Elle possède une propriété "scale" qui détermine l'échelle du bruit.

Exemple de configuration :

```yaml
noise: (
    {
        name = "noise";
        scale = 2.0;
    }
),
```

## Texture "solidColor"

La texture "solidColor" est une texture de couleur unie. Elle possède une propriété "color" qui détermine la couleur de la texture.

Exemple de configuration :

```yaml
solidColor: (
    {
        name = "solidTextureName";
        color = { r = 255.0; g = 255.0; b = 255.0; };
    },
    {
        name = "solidTextureName2";
        color = { r = 0.0; g = 0.0; b = 0.0; };
    }
),
```

## Texture "chessboard"

La texture "chessboard" est une texture en damier. Elle peut être configurée pour être soit en noir et blanc, soit en couleur. Elle possède les propriétés suivantes :

- "lightTexture" : le nom de la texture à utiliser pour les cases claires du damier.
- "darkTexture" : le nom de la texture à utiliser pour les cases sombres du damier.
- "lightColor" : la couleur à utiliser pour les cases claires du damier (uniquement pour la version en couleur).
- "darkColor" : la couleur à utiliser pour les cases sombres du damier (uniquement pour la version en couleur).

Exemple de configuration :

```yaml
chessboard: {
    textured: (
        {
            name = "chessBoardTextureName";
            lightTexture = "solidTextureName";
            darkTexture = "solidTextureName2";
        }
    ),
    colored: (
        {
            name = "chessBoardTextureName2";
            lightColor = { r = 255.0; g = 255.0; b = 255.0; };
            darkColor = { r = 0.0; g = 0.0; b = 0.0; };
        }
    )
}
```

Avec ces différentes textures, il est possible de créer une grande variété de matériaux pour les objets de la scène.

## Exemple de configuration

Voici un exemple de configuration pour une texture "noise" avec une échelle de 2.0, une texture "solidColor" blanche et une texture "chessboard" en noir et blanc :

```yaml
textures:
{
    noise: (
        {
            name = "noise";
            scale = 2.0;
        }
    ),
    solidColor: (
        {
            name = "solidTextureName";tu 
            color = { r = 255.0; g = 255.0; b = 255.0; };
        },
        {
            name = "solidTextureName2";
            color = { r = 0.0; g = 0.0; b = 0.0; };
        }
    ),
    chessboard: {
        textured: (
            {
                name = "chessBoardTextureName";
                lightTexture = "solidTextureName";
                darkTexture = "solidTextureName2";
            }
        ),
        colored: (
            {
                name = "chessBoardTextureName2";
                lightColor = { r = 255.0; g = 255.0; b = 255.0; };
                darkColor = { r = 0.0; g = 0.0; b = 0.0; };
            }
        )
    }
}
```

N'hésitez pas à ajuster ces valeurs en fonction de vos besoins.