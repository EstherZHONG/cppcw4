#include "LevelUp.h"
#include "Psyjz9Engine.h"
#include "MainGame.h"

void LevelUp::SetupBackgroundBuffer() {
    FillBackground(0x000000);
}

void LevelUp::DrawStringsOnTop() {
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 100, TILE_HEIGHT*ROWS/2+BASEY - 150, "Congratulations!", 0xffffff);
    sprintf(string, "next level: level %d", stage);
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 120, TILE_HEIGHT*ROWS/2+BASEY, string, 0xffffff);
    engine->DrawForegroundString(TILE_WIDTH*COLS/2+BASEX - 140, TILE_HEIGHT*ROWS/2+BASEY + 150, "Start next level: Space", 0xffffff);
}


void LevelUp::KeyDown(int iKeyCode) {
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
                stage
            ));
            break;
    }
}
