#ifndef COLLIDER_H
#define COLLIDER_H

#include "gameobject/GameObject.h"

class Collider {
public:
    Collider();
    virtual void OnCollision(GameObject& other) const;

    bool CheckCollision(const GameObject& object1, const GameObject& object2);
    bool CheckSquareCollision(const GameObject& square1, const GameObject& square2);
    bool CheckCircleCollision(const GameObject& circle1, const GameObject& circle2);
    bool CheckSquareCircleCollision(const GameObject& square, const GameObject& circle);
};

#endif // COLLIDER_H