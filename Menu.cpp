#include "Menu.h"
#include "Psyjz9Engine.h"


void Menu::SetupBackgroundBuffer() {
    // DrawBackgroundRectangle(300, 300, 600, 600, 0xffffff);
    // FillBackground(0xffffff);
}

void Menu::KeyDown(int iKeyCode) {
    switch(iKeyCode) {
        case SDLK_SPACE:
            // i_PausedTime = GetTime();
            engine->SetState(MAINGAME);
    }
}

void Menu::GameAction() {
    DrawForegroundRectangle(300, 300, 600, 600, 0xffffff);
    DrawForegroundString(100, 100, "you", 0x000000);

}

void Menu::GameRender() {
    SDL_UpdateTexture( m_pSDL2Texture,NULL,m_pForegroundSurface->pixels,m_pForegroundSurface->pitch );
    //SDL_RenderClear( m_pSDL2Renderer );
    SDL_RenderCopy( m_pSDL2Renderer,m_pSDL2Texture,NULL,NULL );
    SDL_RenderPresent( m_pSDL2Renderer );

}

