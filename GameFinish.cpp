#include "GameFinish.h"
#include "Psyjz9Engine.h"
#include "MainGame.h"

void GameFinish::SetupBackgroundBuffer() {
    FillBackground(0x000000);
}

void GameFinish::DrawStringsOnTop() {
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 100, TILE_HEIGHT*ROWS/2+BASEY - 150, "Congratulations!", 0xffffff);
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 120, TILE_HEIGHT*ROWS/2+BASEY - 50, "All levels finished", 0xffffff);
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 105, TILE_HEIGHT*ROWS/2+BASEY + 50, "Restart: Space", 0xffffff);
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 70, TILE_HEIGHT*ROWS/2+BASEY + 150, "Exit: ESC", 0xffffff);
}

void GameFinish::KeyDown(int iKeyCode) {
    switch(iKeyCode) {
        case SDLK_SPACE:
            engine->SetState(std::make_unique<MainGame>(
                engine,
                m_pKeyStatus,
                m_iWindowWidth,
                m_iWindowHeight,
                m_pForegroundSurface,
                m_pBackgroundSurface,
                m_pSDL2Window,
                m_pSDL2Renderer,
                m_pSDL2Texture,
                1
            ));
            break;
        case SDLK_ESCAPE:
            engine->SetExitWithCode(0);
            break;
    }
}
