#pragma once
// #ifndef USER_OBJECT
// #define USER_OBJECT

#include <vector>

#include "MovingObject.h"
#include "JPGImage.h"

class UserObject : public MovingObject
{
public:
    UserObject(MainGame* pEngine, int iMapX, int iMapY): MovingObject(pEngine, iMapX, iMapY) {
        m_iColor = 0xcc00cc;
        m_iStartDrawPosY = -TILE_HEIGHT/2-30;
        m_iDrawHeight = TILE_HEIGHT+30;
        ImageData temp;
        images[0].LoadImage("mush_up.png");
        images[1].LoadImage("mush_right.png");
        images[2].LoadImage("mush_down.png");
        images[3].LoadImage("mush_left.png");
    }
    ~UserObject() {}
    void UpdatePosition(int currentTime, Psyjz9TileManager& tm);
    void Draw();
    void MouseDown() { mouse_down = true; }
    void MouseUp() { mouse_down = false; }
protected:
private:
    int m_iDir = 2;
    bool mouse_down = false;
    int i_CoinCount = 0;
    char p_cCount[3] = "0";
    ImageData mush_up, mush_right, mush_down, mush_left;
    std::vector<ImageData> images{ mush_up, mush_right, mush_down, mush_left };
};

// #endif