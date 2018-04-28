#include "Lose.h"
#include "Psyjz9Engine.h"
#include "MainGame.h"

void Lose::SetupBackgroundBuffer() {
    FillBackground(0x000000);
}

void Lose::DrawStringsOnTop() {
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 90, TILE_HEIGHT*ROWS/2+BASEY - 100, "You lose", 0xffffff);
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 120, TILE_HEIGHT*ROWS/2+BASEY , "Restart: Space", 0xffffff);
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 75, TILE_HEIGHT*ROWS/2+BASEY + 100, "Exit: ESC", 0xffffff);
}

void Lose::KeyDown(int iKeyCode) {
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
