#include "collider/Collider.h"

Collider::Collider() {}

void Collider::OnCollision(GameObject& other) const {

}

// check if 2 objects are touching each other OR are overlapping (work with square and rectangle)
bool Collider::CheckCollision(const GameObject& object1, const GameObject& object2) {
    Vector2D<float> position1 = object1.GetPosition();
    Vector2D<float> position2 = object2.GetPosition();

    float width1 = object1.GetWidth();
    float height1 = object1.GetHeight();

    float width2 = object2.GetWidth();
    float height2 = object2.GetHeight();

    if (position1.x <= position2.x + width2 && position1.x + width1 >= position2.x &&
        position1.y <= position2.y + height2 && position1.y + height1 >= position2.y) {
        return true;
    }

    return false;
}

bool Collider::CheckSquareCollision(const GameObject& square1, const GameObject& square2) {
    return CheckCollision(square1, square2);
}

bool Collider::CheckCircleCollision(const GameObject& circle1, const GameObject& circle2) {
    Vector2D<float> center1 = circle1.GetCenter();
    Vector2D<float> center2 = circle2.GetCenter();

    float radius1 = circle1.GetRadius();
    float radius2 = circle2.GetRadius();

    // distance between the centers of the circles
    float dx = center1.x - center2.x;
    float dy = center1.y - center2.y;
    float distance = static_cast<float>(std::sqrt(dx * dx + dy * dy));

    // if the distance between the centers is less than the sum of the 2 radii, they touch
    if (distance <= radius1 + radius2) {
        return true;
    }

    return false;
}

// work only if it's a square (use of diagonal) and not if it's a rectangle
bool Collider::CheckSquareCircleCollision(const GameObject& square, const GameObject& circle) {
    Vector2D<float> squarePosition = square.GetPosition();
    Vector2D<float> circlePosition = circle.GetPosition();
    float squareWidth = square.GetWidth();
    float circleRadius = circle.GetRadius();

    // coordinates of the center of the square
    float squareCenterX = squarePosition.x + (squareWidth / 2);
    float squareCenterY = squarePosition.y + (squareWidth / 2);

    // distance between the center of the square and the center of the circle
    float dx = squareCenterX - circlePosition.x;
    float dy = squareCenterY - circlePosition.y;
    float distance = static_cast<float>(std::sqrt(dx * dx + dy * dy));

    // half the diagonal of the square
    float squareDiagonal = static_cast<float>(std::sqrt(2) * (squareWidth / 2));

    // if the distance between the centers is less than the sum of the radius of the circle and half the diagonal of the square, they touch
    if (distance <= circleRadius + (squareDiagonal / 2)) {
        return true;
    }

    return false;
}