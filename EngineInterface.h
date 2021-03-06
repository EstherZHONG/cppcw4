#pragma once

// #ifndef ENGINE_INTERFACE
// #define ENGINE_INTERFACE

#include "header.h"
#include "templates.h"
#include "config.h"

#include "BaseEngine.h"

class Psyjz9Engine;

class EngineInterface : public BaseEngine {
public:
    EngineInterface(
        Psyjz9Engine *engine,
        bool *m_pKeyStatus,
        int m_iWindowWidth,
        int m_iWindowHeight,
        SDL_Surface *m_pForegroundSurface,
        SDL_Surface *m_pBackgroundSurface,
        SDL_Window *m_pSDL2Window,
        SDL_Renderer *m_pSDL2Renderer,
        SDL_Texture *m_pSDL2Texture
    ) : BaseEngine() {
        this->engine = engine;
        this->m_pKeyStatus = m_pKeyStatus;
        this->m_iWindowWidth = m_iWindowWidth;
        this->m_iWindowHeight = m_iWindowHeight;
        this->m_pForegroundSurface = m_pForegroundSurface;
        this->m_pBackgroundSurface = m_pBackgroundSurface;
        this->m_pSDL2Window = m_pSDL2Window;
        this->m_pSDL2Renderer = m_pSDL2Renderer;
        this->m_pSDL2Texture = m_pSDL2Texture;
    }
    ~EngineInterface() {}

    void SetTime(int m_iTick) {
        this->m_iTick = m_iTick;
    }
protected:
    Psyjz9Engine *engine;

};




// #endif