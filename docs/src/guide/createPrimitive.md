---
title: Création d'un objet primitif
---

## Introduction

Dans ce tutoriel, nous allons apprendre comment créer un objet primitif dans une scène en utilisant le code fourni.

## Prérequis

Pour suivre ce tutoriel, vous devez avoir une compréhension de base du langage C++ et des concepts du Ray Tracing.

## Étape 1 : Inclure les fichiers d'en-tête

```cpp
#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <sstream>
#include "Ray.hpp"
#include <memory>
#include "AxisAlignedBoundingBox.hpp"

// ...
```

Le bloc de code ci-dessus inclut les fichiers d'en-tête nécessaires et définit la classe `Hittable`, la structure `HitRecord` et d'autres entités requises.

## Étape 2 : Implémentation d'un objet primitif

Pour créer un objet primitif, vous devez définir une classe qui hérite de la classe `Hittable`. Voici un exemple d'implémentation :

```cpp
class Sphere : public Hittable {
public:
  Sphere(const Math::Point3D& centre, double rayon, std::shared_ptr<Material> materiau)
    : _centre(centre), _rayon(rayon), _materiau(materiau) {}

  bool hit(const Ray& rayon, double tMin, double tMax, HitRecord& rec) const override {
    // Détails de l'implémentation pour l'intersection rayon-sphère

    // ...

    return true;
  }

  bool boundingBox(double t0, double t1, AxisAlignedBBox& boiteSortie) const override {
    // Détails de l'implémentation pour le calcul de la boîte englobante

    // ...

    return true;
  }
};
```

La classe `Sphere` représente un objet primitif sphérique. Elle substitue les méthodes `hit` et `boundingBox` de la classe `Hittable` pour fournir l'implémentation nécessaire.

## Conclusion

Dans ce tutoriel, nous avons appris comment créer un objet primitif, en particulier une sphère, dans une scène en utilisant le code fourni. Vous pouvez étendre ce concept pour créer d'autres objets primitifs tels que des plans, des boîtes ou des cylindres.