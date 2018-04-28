#pragma once
// #ifndef ENEMY_OBJECT
// #define ENEMY_OBJECT

#include <vector>

#include "EnemyObject.h"
#include "JPGImage.h"

class EnemyVerti : public EnemyObject {
public:
    EnemyVerti(MainGame* pEngine, int iMapX, int iMapY) : EnemyObject(pEngine, iMapX, iMapY) {}
    ~EnemyVerti() {}
    void UpdatePosition(int currentTime, Psyjz9TileManager& tm);
private:
};

 // #endif