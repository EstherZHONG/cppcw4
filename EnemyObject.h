#pragma once
// #ifndef ENEMY_OBJECT
// #define ENEMY_OBJECT

#include <vector>

#include "MovingObject.h"
#include "JPGImage.h"

class EnemyObject : public MovingObject
{
public:
    EnemyObject(MainGame* pEngine, int iMapX, int iMapY): MovingObject(pEngine, iMapX, iMapY) {
        images[0].LoadImage("enemy_up.png");
        images[1].LoadImage("enemy_right.png");
        images[2].LoadImage("enemy_down.png");
        images[3].LoadImage("enemy_left.png");
    }
    ~EnemyObject() {}
    void Draw();
    // void UpdatePosition(int currentTime, Psyjz9TileManager& tm);
protected:
    int m_iDir = 2;
    ImageData enemy_up, enemy_right, enemy_down, enemy_left;
    std::vector<ImageData> images{ enemy_up, enemy_right, enemy_down, enemy_left };
 };

 // #endif