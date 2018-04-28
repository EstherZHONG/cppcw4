#pragma once

// #ifndef MOVING_OBJECT
// #define MOVING_OBJECT

#include "header.h"
#include "MovementPosition.h"

#include "DisplayableObject.h"
#include "Psyjz9TileManager.h"

class MainGame;

class MovingObject : public DisplayableObject {
public:
    MovingObject(MainGame* pEngine, int iMapX, int iMapY);
    ~MovingObject() {}
    void Draw();
    void DoUpdate(int currentTime);
    int GetX() { return m_iMapX; }
    int GetY() { return m_iMapY; }

private:
protected:
    virtual void UpdatePosition(int currentTime, Psyjz9TileManager& tm) {}
    MainGame* m_pMainEngine;
    int m_iMapX;
    int m_iMapY;
    MovementPosition m_oMover;
    int m_iColor = 0xff6666;
};


// #endif