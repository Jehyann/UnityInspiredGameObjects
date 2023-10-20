#include "gameiterator/GameIterator.h"

GameIterator::GameIterator(const std::vector<GameObject>& gameObjects) : gameObjects(gameObjects) {}

// gives name and position for every objects
void GameIterator::IterateAllObjects() {
    for (const GameObject& obj : gameObjects) {
        Vector2D<float> position = obj.GetPosition();
        std::string name = obj.GetName();
        std::cout << "Object '" << name << "' at (" << position.x << ", " << position.y << ")" << std::endl;
    }
}