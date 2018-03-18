#include "EnemyObject.h"
#include "MainGame.h"

void EnemyObject::UpdatePosition(int currentTime, Psyjz9TileManager& tm) {
    int tempX = m_iMapX, tempY = m_iMapY;
    switch (m_iDir = rand() % 4) {
        case 0:
            tempX = m_iMapX;
            tempY = m_iMapY - 1;
            break;           
        case 1:
            tempX = m_iMapX + 1;
            tempY = m_iMapY;
            break;           
        case 2:
            tempX = m_iMapX;
            tempY = m_iMapY + 1;
            break;           
        case 3:
            tempX = m_iMapX - 1;
            tempY = m_iMapY;
            break;           
    }
    switch (tm.GetValue(tempX, tempY)) {
        case COIN:
        case SPACE:
            m_oMover.Setup( 
                m_iMapX *TILE_WIDTH + TILE_WIDTH/2 + BASEX,
                m_iMapY *TILE_HEIGHT + TILE_HEIGHT/2 + BASEY,
                tempX *TILE_WIDTH + TILE_WIDTH/2 + BASEX,
                tempY *TILE_HEIGHT + TILE_HEIGHT/2 + BASEY,
                currentTime,
                currentTime+400
            );
            m_iMapX = tempX;
            m_iMapY = tempY;
            break;  
        case WALL:
            UpdatePosition(currentTime, tm);
    }
}

void EnemyObject::Draw() {
    int iSizeX = TILE_WIDTH/2;
    int iSizeY = TILE_HEIGHT/2;
    images[m_iDir].RenderImageWithMask( 
        m_pMainEngine->GetForeground(), 
        0, 
        0, 
        m_iCurrentScreenX - iSizeX, 
        m_iCurrentScreenY - iSizeY, 
        images[m_iDir].GetWidth(),
        images[m_iDir].GetHeight()
    );
    StoreLastScreenPositionForUndraw();
}