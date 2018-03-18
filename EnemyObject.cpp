#include "EnemyObject.h"
#include "MainGame.h"

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