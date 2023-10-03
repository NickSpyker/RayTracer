# Configuration des matériaux

Les matériaux définissent la façon dont les surfaces apparaissent dans la scène, en définissant comment la lumière est réfléchie, réfractée, absorbée ou diffusée. Dans cette section, nous vous montrerons comment configurer les différents types de matériaux dans votre projet de raytracing.

## Matériaux directionnels

Les matériaux directionnels définissent la lumière qui est réfléchie dans une direction spécifique. Vous pouvez configurer un matériau directionnel en définissant sa couleur ou en lui ajoutant une texture. Voici un exemple de configuration pour un matériau directionnel :

```yaml
directionalLight:
{
    textured: (
        {
            name = "directionalLightMaterialName";
            texture = "chessBoardTextureName";
        }
    ),
    colored: (
        {
            name = "light";
            color = { r = 15.0; g = 15.0; b = 15.0; };
        }
    )
}
```

Dans cet exemple, nous avons défini un matériau directionnel avec une texture d'échiquier nommée "chessBoardTextureName". Si vous voulez définir une couleur pour votre matériau directionnel, vous pouvez utiliser la propriété `colored` et définir une couleur RVB.

## Matériaux en verre

Les matériaux en verre définissent la façon dont la lumière est réfractée lorsqu'elle traverse un objet transparent. Vous pouvez configurer un matériau en verre en définissant son indice de réfraction. Voici un exemple de configuration pour un matériau en verre :

```yaml
glass:
{
    name = "glass";
    refraction = 1.5;
}
```

Dans cet exemple, nous avons défini un matériau en verre avec un indice de réfraction de 1,5.

## Matériaux métalliques

Les matériaux métalliques définissent la façon dont la lumière est réfléchie sur une surface métallique. Vous pouvez configurer un matériau métallique en définissant sa couleur et sa valeur de flou. Voici un exemple de configuration pour un matériau métallique :

```yaml
metal:
{
    name = "blue metal";
    color = { r = 0.2; g = 0.4; b = 0.8; };
    fuzz = 0.1;
}
```

Dans cet exemple, nous avons défini un matériau métallique de couleur bleue avec une valeur de flou de 0,1.

## Matériaux solides

Les matériaux solides définissent la façon dont la lumière est réfléchie sur une surface non métallique. Vous pouvez configurer un matériau solide en définissant sa couleur ou en lui ajoutant une texture. Voici un exemple de configuration pour un matériau solide :

```yaml
solid: {
    textured: (
        {
            name = "perle";
            texture = "noise";
        }
    ),
    colored: (
        {
            name = "red";
            color = { r = 0.65; g = 0.05; b = 0.05; };
        },
        {
            name = "white";
            color = { r = 0.73; g = 0.73; b = 0.73; };
        },
        {
            name = "green";
            color = { r = 0.12; g = 0.45; b = 0.15; };
        }
    )
}
```

Dans cet exemple, nous avons défini un matériau solide avec une texture de bruit nommée "noise". Si vous voulez définir une couleur pour votre matériau solide, vous pouvez utiliser la propriété `colored` et définir une couleur RVB.

## Exemple de configuration

Voici un exemple de configuration de matériaux :

```yaml
materials:
{
    directionalLight: {
        textured: (
            {
                name = "directionalLightMaterialName";
                texture = "chessBoardTextureName";
            }
        ),
        colored: (
            {
                name = "light";
                color = { r = 15.0; g = 15.0; b = 15.0; };
            }
        )
    },
    glass: (
        {
            name = "glass";
            refraction = 1.5;
        }
    ),
    metal: (
        {
            name = "blue metal";
            color = { r = 0.2; g = 0.4; b = 0.8; };
            fuzz = 0.1;
        }
    ),
    solid: {
        textured: (
            {
                name = "perle";
                texture = "noise";
            }
        ),
        colored: (
            {
                name = "red";
                color = { r = 0.65; g = 0.05; b = 0.05; };
            },
            {
                name = "white";
                color = { r = 0.73; g = 0.73; b = 0.73; };
            },
            {
                name = "green";
                color = { r = 0.12; g = 0.45; b = 0.15; };
            }
        )
    }
}
```