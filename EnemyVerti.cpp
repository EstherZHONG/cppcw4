#include "EnemyVerti.h"

void EnemyVerti::UpdatePosition(int currentTime, Psyjz9TileManager& tm) {
    int tempX = m_iMapX, tempY = m_iMapY;
    switch (m_iDir) {
        case 0:
            tempX = m_iMapX;
            tempY = m_iMapY - 1;
            break;           
        case 2:
            tempX = m_iMapX;
            tempY = m_iMapY + 1;
            break;           
    }
    switch (tm.GetValue(tempX, tempY)) {
        case COIN:
        case SPACE:
        case ODOOR:
        case KEY:
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
        case CDOOR: 
        case WALL:
            m_iDir = (m_iDir+2) % 4;
            UpdatePosition(currentTime, tm);
            break;
    }
}