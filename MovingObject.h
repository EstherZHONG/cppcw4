#ifndef MOVING_OBJECT
#define MOVING_OBJECT

#include "header.h"
#include "MovementPosition.h"

#include "DisplayableObject.h"
#include "Psyjz9TileManager.h"

class MainGame;

class MovingObject : public DisplayableObject
{
public:
    MovingObject(MainGame* pEngine, int iMapX, int iMapY);
    ~MovingObject() {}
    void Draw();
    // void SetMove(int dir, int currentTime);
    // void CancelMove(int dir, int currentTime);
    void DoUpdate(int currentTime);
private:
    // void Calculate(int currentTime);
protected:
    virtual void UpdatePosition(int currentTime, Psyjz9TileManager& tm) {}
    MainGame* m_pMainEngine;
    int m_iMapX;
    int m_iMapY;
    MovementPosition m_oMover;
    int m_iColor = 0xff6666;

    // int m_iDir;
    // int m_iUpdateTime;
    // int m_iUpdateScreenX;
    // int m_iUpdateScreenY;
};


#endif