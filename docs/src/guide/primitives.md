# Configuration de la scène (Primitives)

Les primitives de la scène sont définies dans la section `primitives`. Vous pouvez définir des sphères, des plans, des boîtes, des cônes et des cylindres dans cette section. Chaque primitive est définie dans une liste de primitives qui contient toutes les instances de cette primitive dans la scène. Par exemple, la liste `spheres` contient toutes les sphères dans la scène.

Les propriétés de chaque primitive sont définies dans une liste de paires clé-valeur. La clé est le nom de la propriété et la valeur est la valeur de la propriété. Voici les propriétés pour chaque primitive :

## Sphères

Les sphères sont définies avec les propriétés suivantes :

- `position` : un triplet de nombres flottants définissant la position de la sphère dans l'espace. Exemple : `position = { x = 350.0; y = 380.0; z = 350.0; }`.
- `radius` : un nombre flottant définissant le rayon de la sphère. Exemple : `radius = 50.0`.
- `material` : le nom du matériau de la sphère. Exemple : `material = "perle"`.

Voici un exemple de définition de sphères dans le fichier de configuration :

```yaml
spheres: (
    {
        position = { x = 350.0; y = 380.0; z = 350.0; };
        radius = 50.0;
        material = "perle";
    },
    {
        position = { x = 195.0; y = 240.0; z = 175.0; };
        radius = 75.0;
        material = "blue metal";
    },
    {
        position = { x = 410.0; y = 100.0; z = 075.0; };
        radius = 100.0;
        material = "glass";
    }
);
```

## Plans

Les plans sont définis avec les propriétés suivantes :

- `point1` et `point2` : deux triplets de nombres flottants définissant deux points sur le plan. Exemple : `point1 = { x = 555.0; y = 0.0; z = 0.0; }; point2 = { x = 555.0; y = 555.0; z = 555.0; }`.
- `material` : le nom du matériau du plan. Exemple : `material = "green"`.

Voici un exemple de définition de plans dans le fichier de configuration :

```yaml
planes: (
    {
        point1 = { x = 555.0; y = 0.0; z = 0.0; };
        point2 = { x = 555.0; y = 555.0; z = 555.0; };
        material = "green";
    },
    {
        point1 = { x = 0.0; y = 0.0; z = 0.0; };
        point2 = { x = 0.0; y = 555.0; z = 555.0; };
        material = "red";
    },
    {
        point1 = { x = 213.0; y = 554.0; z = 227.0; };
        point2 = { x = 343.0; y = 554.0; z = 332.0; };
        material = "light";
    },
    {
        point1 = { x = 0.0; y = 0.0; z = 0.0; };
        point2 = { x = 555.0; y = 0.0; z = 555.0; };
        material = "white";
    },
    {
        point1 = { x = 0.0; y = 555.0; z = 0.0; };
        point2 = { x = 555.0; y = 555.0; z = 555.0; };
        material = "white";
    },
    {
        point1 = { x = 0.0; y = 0.0; z = 555.0; };
        point2 = { x = 555.0; y = 555.0; z = 555.0; };
        material = "white";
    }
);
```

## Boîtes

Les boîtes sont définies avec les propriétés suivantes :

- `point1` et `point2` : deux triplets de nombres flottants définissant deux points sur la boîte. Exemple : `point1 = { x = 0.0; y = 0.0; z = 0.0; }; point2 = { x = 555.0; y = 555.0; z = 555.0; }`.
- `material` : le nom du matériau de la boîte. Exemple : `material = "white"`.
- `translate` : un triplet de nombres flottants définissant la translation de la boîte. Exemple : `translate = { x = 265.0; y = 0.0; z = 295.0; }`.

Voici un exemple de définition de boîtes dans le fichier de configuration :

```yaml
boxes: (
    {
        point1 = { x = 0.0; y = 0.0; z = 0.0; };
        point2 = { x = 165.0; y = 330.0; z = 165.0; };
        material = "white";
        rotateY = 15.0;
        translate = { x = 265.0; y = 0.0; z = 295.0; };
    },
    {
        point1 = { x = 0.0; y = 0.0; z = 0.0; };
        point2 = { x = 165.0; y = 165.0; z = 165.0; };
        material = "white";
        rotateY = -18.0;
        translate = { x = 130.0; y = 0.0; z = 65.0; };
    }
);
```

## Cônes

Les cônes sont définis avec les propriétés suivantes :

- `position` : un triplet de nombres flottants définissant la position du cône dans l'espace. Exemple : `position = { x = 350.0; y = 380.0; z = 350.0; }`.
- `radius` : un nombre flottant définissant le rayon du cône. Exemple : `radius = 50.0`.
- `height` : un nombre flottant définissant la hauteur du cône. Exemple : `height = 100.0`.
- `material` : le nom du matériau du cône. Exemple : `material = "perle"`.

Voici un exemple de définition de cônes dans le fichier de configuration :

```yaml
cones: (
    {
        position = { x = 400.0; y = 0.0; z = 400.0; };
        radius = 100.0;
        height = 300.0;
        material = "blue metal";
    }
);
```

## Cylindres

Les cylindres sont définis avec les propriétés suivantes :

- `position` : un triplet de nombres flottants définissant la position du cylindre dans l'espace. Exemple : `position = { x = 350.0; y = 380.0; z = 350.0; }`.
- `radius` : un nombre flottant définissant le rayon du cylindre. Exemple : `radius = 50.0`.
- `height` : un nombre flottant définissant la hauteur du cylindre. Exemple : `height = 100.0`.
- `material` : le nom du matériau du cylindre. Exemple : `material = "perle"`.

Voici un exemple de définition de cylindres dans le fichier de configuration :

```yaml
cylinders: (
    {
        position = { x = 100.0; y = 0.0; z = 100.0; };
        radius = 100.0;
        height = 300.0;
        material = "green";
    }
);
```

## Exemples de scènes

Voici un exemple de scène avec toutes les propriétés citées ci-dessus :

```yaml
primitives:
{
    # List of spheres
    spheres: (
        {
            position = { x = 350.0; y = 380.0; z = 350.0; };
            radius = 50.0;
            material = "perle";
        },
        {
            position = { x = 195.0; y = 240.0; z = 175.0; };
            radius = 75.0;
            material = "blue metal";
        },
        {
            position = { x = 410.0; y = 100.0; z = 075.0; };
            radius = 100.0;
            material = "glass";
        }
    );

    # List of planes
    planes: (
        {
            point1 = { x = 555.0; y = 0.0; z = 0.0; };
            point2 = { x = 555.0; y = 555.0; z = 555.0; };
            material = "green";
        },
        {
            point1 = { x = 0.0; y = 0.0; z = 0.0; };
            point2 = { x = 0.0; y = 555.0; z = 555.0; };
            material = "red";
        },
        {
            point1 = { x = 213.0; y = 554.0; z = 227.0; };
            point2 = { x = 343.0; y = 554.0; z = 332.0; };
            material = "light";
        },
        {
            point1 = { x = 0.0; y = 0.0; z = 0.0; };
            point2 = { x = 555.0; y = 0.0; z = 555.0; };
            material = "white";
        },
        {
            point1 = { x = 0.0; y = 555.0; z = 0.0; };
            point2 = { x = 555.0; y = 555.0; z = 555.0; };
            material = "white";
        },
        {
            point1 = { x = 0.0; y = 0.0; z = 555.0; };
            point2 = { x = 555.0; y = 555.0; z = 555.0; };
            material = "white";
        }
    );

    # List of boxes
    boxes: (
        {
            point1 = { x = 0.0; y = 0.0; z = 0.0; };
            point2 = { x = 165.0; y = 330.0; z = 165.0; };
            material = "white";
            rotateY = 15.0;
            translate = { x = 265.0; y = 0.0; z = 295.0; };
        },
        {
            point1 = { x = 0.0; y = 0.0; z = 0.0; };
            point2 = { x = 165.0; y = 165.0; z = 165.0; };
            material = "white";
            rotateY = -18.0;
            translate = { x = 130.0; y = 0.0; z = 65.0; };
        }
    );

    # List of cones
    cones: (
        {
            position = { x = 400.0; y = 0.0; z = 400.0; };
            radius = 100.0;
            height = 300.0;
            material = "blue metal";
        }
    );

    # List of cylinders
    cylinders: (
        {
            position = { x = 100.0; y = 0.0; z = 100.0; };
            radius = 100.0;
            height = 300.0;
            material = "green";
        }
    );
};
```