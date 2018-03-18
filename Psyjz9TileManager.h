#pragma once

// #ifndef PSYJZ9_TILE_MANAGER
// #define PSYJZ9_TILE_MANAGER

#include "header.h"
#include "config.h"

#include "TileManager.h"
#include "JPGImage.h"

class Psyjz9TileManager : public TileManager 
{
public:
    Psyjz9TileManager();
    ~Psyjz9TileManager() {}
    int GetDoorX() { return doorX; }
    int GetDoorY() { return doorY; }
    void SetDoorX(int value) { doorX = value; }
    void SetDoorY(int value) { doorY = value; }
    void AddCoinIndex() { coin_index = (++coin_index)%6; }
private:
    void DrawTileAt( 
        BaseEngine* pEngine, 
        SDL_Surface* pSurface, 
        int iMapX, int iMapY,
        int iStartPositionScreenX, int iStartPositionScreenY) const;
    int doorX = 0;
    int doorY = 0;
    ImageData wall, cdoor, odoor, key, coin_0, coin_1, coin_2, coin_3, coin_4, coin_5;
    ImageData coins[6] = { coin_0, coin_1, coin_2, coin_3, coin_4, coin_5 };
    int coin_index = 0;
};



// #endif