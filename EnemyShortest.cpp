#include "EnemyShortest.h"
#include "MainGame.h"
#include <map>
#include <queue>

void EnemyShortest::UpdatePosition(int currentTime, Psyjz9TileManager& tm) {
    int goalX = m_pMainEngine->GetUserObject()->GetX(), goalY = m_pMainEngine->GetUserObject()->GetY();
    int x = m_iMapX, y = m_iMapY;
    std::map<int, int> parent;
    std::queue<int> to_look;
    to_look.push(x*COLS+y);
    if (x == goalX && y == goalY) {
        return;
    }
    while (!to_look.empty()) {
        int temp = to_look.front();
        to_look.pop();
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    x = temp/COLS;
                    y = temp%COLS - 1;
                    break;           
                case 1:
                    x = temp/COLS + 1;
                    y = temp%COLS;
                    break;           
                case 2:
                    x = temp/COLS;
                    y = temp%COLS + 1;
                    break;           
                case 3:
                    x = temp/COLS - 1;
                    y = temp%COLS;
                    break;           
            }
            if (x == goalX && y == goalY) {
                if (temp == m_iMapX*COLS+m_iMapY) {
                    temp = x*COLS+y;
                } else {
                    while (parent[temp] != m_iMapX*COLS+m_iMapY) {
                        temp = parent[temp];
                    }
                }
                m_oMover.Setup( 
                    m_iMapX *TILE_WIDTH + TILE_WIDTH/2 + BASEX,
                    m_iMapY *TILE_HEIGHT + TILE_HEIGHT/2 + BASEY,
                    temp/COLS *TILE_WIDTH + TILE_WIDTH/2 + BASEX,
                    temp%COLS *TILE_HEIGHT + TILE_HEIGHT/2 + BASEY,
                    currentTime,
                    currentTime+400
                );
                m_iDir = (temp/COLS - m_iMapX) == 0 ? (temp%COLS - m_iMapY) > 0 ? 2:0 : (temp/COLS - m_iMapX) > 0 ? 1:3;
                m_iMapX = temp/COLS;
                m_iMapY = temp%COLS;
                return;
            }
            switch (tm.GetValue(x, y)) {
                case COIN:
                case SPACE:
                case ODOOR:
                case KEY:
                    if (parent.find(x*COLS+y) == parent.end()) {
                        to_look.push(x*COLS+y);
                        parent.emplace(x*COLS+y, temp);
                    }
                    break;  
            }
        }
    }
}