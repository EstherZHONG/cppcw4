#pragma once
// #ifndef ENEMY_OBJECT
// #define ENEMY_OBJECT

#include <vector>

#include "EnemyObject.h"
#include "JPGImage.h"

class EnemyHori : public EnemyObject {
public:
    EnemyHori(MainGame* pEngine, int iMapX, int iMapY) : EnemyObject(pEngine, iMapX, iMapY) { m_iDir = 1; }
    ~EnemyHori() {}
    void UpdatePosition(int currentTime, Psyjz9TileManager& tm);
private:
};

 // #endif