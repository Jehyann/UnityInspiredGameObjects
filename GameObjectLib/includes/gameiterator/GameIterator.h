#pragma once

#include <vector>
#include "gameobject/GameObject.h"

class GameIterator {
public:
    GameIterator(const std::vector<GameObject>& gameObjects);

    void IterateAllObjects();

private:
    const std::vector<GameObject>& gameObjects;
};