#include "Psyjz9TileManager.h"

Psyjz9TileManager::Psyjz9TileManager() : TileManager(TILE_HEIGHT, TILE_WIDTH) {
    wall.LoadImage("wall.png");
    odoor.LoadImage("odoor.png");
    cdoor.LoadImage("cdoor.png");
    key.LoadImage("key.png");
    coins[0].LoadImage("coin_0.png");
    coins[1].LoadImage("coin_1.png");
    coins[2].LoadImage("coin_2.png");
    coins[3].LoadImage("coin_3.png");
    coins[4].LoadImage("coin_4.png");
    coins[5].LoadImage("coin_5.png");

}


void Psyjz9TileManager::DrawTileAt( 
    BaseEngine* pEngine, 
    SDL_Surface* pSurface, 
    int iMapX, int iMapY,
    int iStartPositionScreenX, int iStartPositionScreenY ) const
{
    switch( GetValue(iMapX,iMapY) )
    {
        case WALL:
            wall.RenderImage(
                pEngine->GetBackground(),
                0,
                0,
                iStartPositionScreenX,
                iStartPositionScreenY,
                GetTileWidth(),
                GetTileHeight()
            );
            break;
            // pEngine->DrawBackgroundRectangle( 
            //     iStartPositionScreenX,
            //     iStartPositionScreenY, 
            //     iStartPositionScreenX + GetTileWidth() - 1,
            //     iStartPositionScreenY + GetTileHeight() - 1,
            //     0xCC6600
            // );
            // break;
        case CDOOR:
            // pEngine->DrawBackgroundRectangle( 
            //     iStartPositionScreenX,
            //     iStartPositionScreenY, 
            //     iStartPositionScreenX + GetTileWidth() - 1,
            //     iStartPositionScreenY + GetTileHeight() - 1,
            //     0xCC6600
            // );
            cdoor.RenderImage(
                pEngine->GetBackground(),
                0,
                0,
                iStartPositionScreenX,
                iStartPositionScreenY,
                GetTileWidth(),
                GetTileHeight()
            );
            break;
        case ODOOR:
            pEngine->DrawBackgroundRectangle( 
                iStartPositionScreenX,
                iStartPositionScreenY, 
                iStartPositionScreenX + GetTileWidth() - 1,
                iStartPositionScreenY + GetTileHeight() - 1,
                0Xffd9b3
            );
            // pEngine->DrawBackgroundOval(
            //     iStartPositionScreenX,
            //     iStartPositionScreenY, 
            //     iStartPositionScreenX + GetTileWidth() - 1,
            //     iStartPositionScreenY + GetTileHeight() - 1,
            //     0xcc6600
            // );
            odoor.RenderImage(
                pEngine->GetBackground(),
                0,
                0,
                iStartPositionScreenX,
                iStartPositionScreenY,
                GetTileWidth(),
                GetTileHeight()
            );
            break;
        case KEY:
            pEngine->DrawBackgroundRectangle( 
                iStartPositionScreenX,
                iStartPositionScreenY, 
                iStartPositionScreenX + GetTileWidth() - 1,
                iStartPositionScreenY + GetTileHeight() - 1,
                0Xffd9b3
            );
            // pEngine->DrawBackgroundOval(
            //     iStartPositionScreenX,
            //     iStartPositionScreenY, 
            //     iStartPositionScreenX + GetTileWidth() - 1,
            //     iStartPositionScreenY + GetTileHeight() - 1,
            //     0xff3399
            // );
            key.RenderImageWithMask(
                pEngine->GetBackground(),
                0,
                0,
                iStartPositionScreenX,
                iStartPositionScreenY,
                GetTileWidth(),
                GetTileHeight()
            );
            break;
        case SPACE:
        {
            pEngine->DrawBackgroundRectangle( 
                iStartPositionScreenX,
                iStartPositionScreenY, 
                iStartPositionScreenX + GetTileWidth() - 1,
                iStartPositionScreenY + GetTileHeight() - 1,
                0Xffd9b3
            );
            int randInt = rand()%4;
            pEngine->DrawBackgroundLine(
                iStartPositionScreenX + (GetTileWidth() - 1) * (randInt/2),
                iStartPositionScreenY + (GetTileHeight() - 1) * (randInt%2),
                iStartPositionScreenX + (GetTileWidth() - 1) * (1-randInt/2),
                iStartPositionScreenY + (GetTileHeight() - 1) * (1-randInt%2),
                0xcc6600
            );
            break;
        }
        case COIN:
        {

            int randInt = rand()%4;
            pEngine->DrawBackgroundRectangle( 
                iStartPositionScreenX,
                iStartPositionScreenY, 
                iStartPositionScreenX + GetTileWidth() - 1,
                iStartPositionScreenY + GetTileHeight() - 1,
                0Xffd9b3
            );
            pEngine->DrawBackgroundLine(
                iStartPositionScreenX + (GetTileWidth() - 1) * (randInt/2),
                iStartPositionScreenY + (GetTileHeight() - 1) * (randInt%2),
                iStartPositionScreenX + (GetTileWidth() - 1) * (1-randInt/2),
                iStartPositionScreenY + (GetTileHeight() - 1) * (1-randInt%2),
                0xcc6600
            );

            // pEngine->DrawBackgroundOval( 
            //     iStartPositionScreenX+5,
            //     iStartPositionScreenY+5, 
            //     iStartPositionScreenX + GetTileWidth() - 1 -5,
            //     iStartPositionScreenY + GetTileHeight() - 1 -5,
            //     0xffff00
            // );
            coins[coin_index].RenderImageWithMask(
                pEngine->GetBackground(),
                0,
                0,
                iStartPositionScreenX,
                iStartPositionScreenY,
                GetTileWidth(),
                GetTileHeight()
            );
            break;
        }

    }
}