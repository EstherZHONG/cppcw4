#pragma once
// #ifndef ENEMY_OBJECT
// #define ENEMY_OBJECT

#include <vector>

#include "EnemyObject.h"
#include "JPGImage.h"

class EnemyShortest : public EnemyObject {
public:
    EnemyShortest(MainGame* pEngine, int iMapX, int iMapY) : EnemyObject(pEngine, iMapX, iMapY) {}
    ~EnemyShortest() {}
    void UpdatePosition(int currentTime, Psyjz9TileManager& tm);
private:
};

 // #endif