#pragma once
// #ifndef ENEMY_OBJECT
// #define ENEMY_OBJECT

#include <vector>

#include "EnemyObject.h"
#include "JPGImage.h"

class EnemyRandom : public EnemyObject {
public:
    EnemyRandom(MainGame* pEngine, int iMapX, int iMapY) : EnemyObject(pEngine, iMapX, iMapY) {}
    ~EnemyRandom() {}
    void UpdatePosition(int currentTime, Psyjz9TileManager& tm);
private:
};

 // #endif