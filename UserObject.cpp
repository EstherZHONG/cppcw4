#include "UserObject.h"
#include "Psyjz9Engine.h"

void UserObject::UpdatePosition(int currentTime, Psyjz9TileManager& tm) {
    switch (tm.GetValue(m_iMapX, m_iMapY)) {
        case COIN:
            tm.UpdateTile(m_pMainEngine, m_iMapX, m_iMapY, SPACE);
            sprintf(p_cCount, "%d", ++i_CoinCount);
            break;
        case KEY:
            tm.UpdateTile(m_pMainEngine, m_iMapX, m_iMapY, SPACE);
            tm.UpdateTile(m_pMainEngine, tm.GetDoorX(), tm.GetDoorY(), ODOOR);
            break;
        case ODOOR:
            m_pMainEngine->Win();
            break;
    }

    bool flag = false;
    int tempX = m_iMapX, tempY = m_iMapY;
    if (mouse_down) {
        flag = true;
        int mouseX = m_pMainEngine->GetMainEngine()->GetCurrentMouseX(), mouseY = m_pMainEngine->GetMainEngine()->GetCurrentMouseY();
        // printf("%d %d;%d %d\n", mouseX, mouseY, m_iCurrentScreenX, m_iCurrentScreenY);
        mouseX -= m_iCurrentScreenX;
        mouseY -= m_iCurrentScreenY;
        if (mouseX > 0) {
            if (mouseX + mouseY > 0 && mouseX - mouseY > 0) {
                tempX += 1;
                m_iDir = 1;
            } else {
                tempY += mouseY > 0 ? 1:-1;
                m_iDir = mouseY > 0 ? 2:0;
            }
        } else {
            if (mouseX + mouseY < 0 && mouseX - mouseY < 0) {
                tempX -= 1;
                m_iDir = 3;
            } else {
                tempY += mouseY > 0 ? 1:-1;
                m_iDir = mouseY > 0 ? 2:0;
            }
        }
    } else {
        if (m_pMainEngine->IsKeyPressed(SDLK_UP)) {
            tempX = m_iMapX;
            tempY = m_iMapY - 1;
            m_iDir = 0;
            flag = true;        
        } else if (m_pMainEngine->IsKeyPressed(SDLK_RIGHT)) {
            tempX = m_iMapX + 1;
            tempY = m_iMapY;
            m_iDir = 1;
            flag = true;
        } else if (m_pMainEngine->IsKeyPressed(SDLK_DOWN)) {
            tempX = m_iMapX;
            tempY = m_iMapY + 1;
            m_iDir = 2;
            flag = true;
        } else if (m_pMainEngine->IsKeyPressed(SDLK_LEFT)) {
            tempX = m_iMapX - 1;
            tempY = m_iMapY;
            m_iDir = 3;
            flag = true;
        }
    }

    if (flag) {
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
        }
    }
}

void UserObject::Draw() {
    int iSizeX = TILE_WIDTH/2;
    int iSizeY = TILE_HEIGHT/2;
    // m_pMainEngine->DrawForegroundOval(
    //         m_iCurrentScreenX - iSizeX,
    //         m_iCurrentScreenY - iSizeY,
    //         m_iCurrentScreenX + iSizeX-1,
    //         m_iCurrentScreenY + iSizeY-1,
    //         m_iColor
    // );
    images[m_iDir].RenderImageWithMask( 
        m_pMainEngine->GetForeground(), 
        0, 
        0, 
        m_iCurrentScreenX - iSizeX, 
        m_iCurrentScreenY - iSizeY, 
        images[m_iDir].GetWidth(),
        images[m_iDir].GetHeight()
    );
    m_pMainEngine->GetMainEngine()->DrawForegroundString(m_iCurrentScreenX - 8, m_iCurrentScreenY - iSizeY - 30, p_cCount, 0xfff166);
    StoreLastScreenPositionForUndraw();

}
