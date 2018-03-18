#pragma once

// #ifndef MENU_GAME
// #define MENU_GAME

#include "header.h"
#include "templates.h"
#include "config.h"

#include "EngineInterface.h"
class Psyjz9Engine;

class Menu : public EngineInterface
{
public:
    Menu(
        Psyjz9Engine *engine,
        bool *m_pKeyStatus,
        int m_iWindowWidth,
        int m_iWindowHeight,
        SDL_Surface *m_pForegroundSurface,
        SDL_Surface *m_pBackgroundSurface,
        SDL_Window *m_pSDL2Window,
        SDL_Renderer *m_pSDL2Renderer,
        SDL_Texture *m_pSDL2Texture
    ) : EngineInterface(
        engine,
        m_pKeyStatus,
        m_iWindowWidth,
        m_iWindowHeight,
        m_pForegroundSurface,
        m_pBackgroundSurface,
        m_pSDL2Window,
        m_pSDL2Renderer,
        m_pSDL2Texture
    ) {}
   ~Menu() {}
    void SetupBackgroundBuffer();
    void KeyDown(int iKeyCode);
    void GameAction();
    void GameRender();
private:
    // Psyjz9TileManager m_oTileM; 
    // Psyjz9Engine *engine;

};




// #endif