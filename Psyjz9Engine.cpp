#include "Psyjz9Engine.h"

int Psyjz9Engine::GameInit() {
    cur_engine.reset(new MainGame(
        this,
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
    cur_engine->GameInit();
    // cur_engine->Start();
    return 0;
}
  