#pragma once

// #ifndef MAIN_GAME
// #define MAIN_GAME

#include <iostream>
#include <string>
#include <fstream>

#include "header.h"
#include "templates.h"
#include "config.h"

#include "EngineInterface.h"
#include "Psyjz9TileManager.h"
// #include "MovingObject.h"
#include "UserObject.h"
// #include "EnemyObject.h"
#include "EnemyRandom.h"
#include "EnemyVerti.h"
#include "EnemyHori.h"

class Psyjz9Engine;

class MainGame : public EngineInterface
{
public:
    MainGame(
        Psyjz9Engine *engine,
        bool *m_pKeyStatus,
        int m_iWindowWidth,
        int m_iWindowHeight,
        SDL_Surface *m_pForegroundSurface,
        SDL_Surface *m_pBackgroundSurface,
        SDL_Window *m_pSDL2Window,
        SDL_Renderer *m_pSDL2Renderer,
        SDL_Texture *m_pSDL2Texture,
        int stage
    ) : stage(stage), EngineInterface(
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
    ~MainGame() {}
    void SetupBackgroundBuffer();
    void KeyDown(int iKeyCode);
    // virtual void Start();
    int GameInit();
    int InitialiseObjects();
    Psyjz9TileManager& GetTileManager() { return m_oTileM; }
    void GameAction();
    void DrawStringsUnderneath();
    void DrawStringsOnTop();
    void TimeToString();
    Psyjz9Engine *GetMainEngine() { return engine; }
    void ReadMap(char data[ROWS][COLS], int num);
    void MouseDown(int iButton, int iX, int iY);
    void MouseUp(int iButton, int iX, int iY);
    void Win();
private:
    Psyjz9TileManager m_oTileM;
    int stage = 0;
    int i_PausedTime = -1;
    char m_aTimeString[9];
    int lastRedraw = 0;
    int i_UserIndex = 0;
    UserObject* GetUserObject();
    char data[ROWS][COLS];
};




// #endif