#include "gameobject/GameObject.h"

// ------------------------------------------------------------------------------------------------------------------------------
// Default constructor position to (0, 0)
GameObject::GameObject(const Vector2D<float>& pos, float w, float h) : position(pos), width(w), height(h) {}

Vector2D<float> GameObject::GetPosition() const {
    return position;
}
void GameObject::SetPosition(const Vector2D<float>& newPosition) {
    position = newPosition;
}

// ------------------------------------------------------------------------------------------------------------------------------
void GameObject::SetName(const std::string& objName) {
    name = objName;
}
std::string GameObject::GetName() const {
    return name;
}

// ------------------------------------------------------------------------------------------------------------------------------
float GameObject::GetWidth() const {
    return width;
}
float GameObject::GetHeight() const {
    return height;
}

// ------------------------------------------------------------------------------------------------------------------------------
Vector2D<float> GameObject::GetCenter() const {
    float centerX = position.x + width / 2.0f;
    float centerY = position.y + height / 2.0f;
    return Vector2D<float>(centerX, centerY);
}
float GameObject::GetRadius() const {
    // radius is half the width
    return width / 2.0f;
}