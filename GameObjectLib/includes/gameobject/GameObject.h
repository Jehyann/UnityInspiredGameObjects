#include "math/Vector2D.h"
#include <iostream>
#include <cmath>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
private:
    Vector2D<float> position;
    float width;
    float height;
    std::string name;

public:
    GameObject(const Vector2D<float>& pos, float w, float h);

    void SetName(const std::string& objName);
    std::string GetName() const;


    void SetPosition(const Vector2D<float>& newPosition);
    Vector2D<float> GetPosition() const;


    float GetWidth() const;
    float GetHeight() const;


    Vector2D<float> GetCenter() const;
    float GetRadius() const;
};

#endif // GAMEOBJECT_H