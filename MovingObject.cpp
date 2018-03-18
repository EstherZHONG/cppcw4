#include "MovingObject.h"
#include "Psyjz9Engine.h"

MovingObject::MovingObject(MainGame* pEngine, int iMapX, int iMapY) :
    DisplayableObject(pEngine), 
    m_pMainEngine(pEngine),
    m_iMapX(iMapX), 
    m_iMapY(iMapY) {
        m_iStartDrawPosX = -TILE_WIDTH/2;
        m_iStartDrawPosY = -TILE_HEIGHT/2;

        m_iDrawWidth = TILE_WIDTH;
        m_iDrawHeight = TILE_HEIGHT;
        
        m_iPreviousScreenX = m_iCurrentScreenX = iMapX*TILE_WIDTH+TILE_WIDTH/2+BASEX;
        m_iPreviousScreenY = m_iCurrentScreenY = iMapY*TILE_WIDTH+TILE_WIDTH/2+BASEY;
        m_oMover.Setup(m_iCurrentScreenX, m_iCurrentScreenY, m_iCurrentScreenX, m_iCurrentScreenY, 0, 0);
}

void MovingObject::Draw() {
    StoreLastScreenPositionForUndraw();
    int iSizeX = m_iDrawWidth/2;
    int iSizeY = m_iDrawHeight/2;

    m_pMainEngine->DrawForegroundOval(
        m_iCurrentScreenX - iSizeX,
        m_iCurrentScreenY - iSizeY,
        m_iCurrentScreenX + iSizeX-1,
        m_iCurrentScreenY + iSizeY-1,
        m_iColor
    );
}

void MovingObject::DoUpdate(int currentTime) {

    m_iPreviousScreenX = m_iCurrentScreenX;
    m_iPreviousScreenY = m_iCurrentScreenY;
    Psyjz9TileManager& tm = m_pMainEngine->GetTileManager();
    if (m_oMover.HasMovementFinished(currentTime)) {
        UpdatePosition(currentTime, tm);
        m_oMover.Calculate(currentTime);
        m_iCurrentScreenX = m_oMover.GetX();
        m_iCurrentScreenY = m_oMover.GetY();

    }
    if (!m_oMover.HasMovementFinished(currentTime)) {
        m_oMover.Calculate(currentTime);
        m_iCurrentScreenX = m_oMover.GetX();
        m_iCurrentScreenY = m_oMover.GetY();
    }
    RedrawObjects();
}
