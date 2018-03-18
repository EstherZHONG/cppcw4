#pragma once

// #ifndef PSYJZ9_ENGINE
// #define PSYJZ9_ENGINE

#include <map>
#include <memory>

#include "header.h"
#include "templates.h"
#include "config.h"

#include "BaseEngine.h"
#include "MainGame.h"
#include "Menu.h"
#include "EngineInterface.h"
#include "make_unique.h" 

class Psyjz9Engine : public BaseEngine
{
public:
    Psyjz9Engine() : BaseEngine() {}
    ~Psyjz9Engine() {}
    // void SetupBackgroundBuffer() {
    //     //all stage.set
    // }
    // int InitialiseObjects() {
    //     //all objects
    // }
    int GameInit() {
        // engines.insert({
        //     MAINGAME, 
        //     std::make_unique<MainGame>(
        //         this,
        //         m_pKeyStatus,
        //         m_iWindowWidth,
        //         m_iWindowHeight,
        //         m_pForegroundSurface,
        //         m_pBackgroundSurface,
        //         m_pSDL2Window,
        //         m_pSDL2Renderer,
        //         m_pSDL2Texture
        //     )
        // });
        // engines.insert({
        //     MENU, 
        //     std::make_unique<Menu>(
        //         this,
        //         m_pKeyStatus,
        //         m_iWindowWidth,
        //         m_iWindowHeight,
        //         m_pForegroundSurface,
        //         m_pBackgroundSurface,
        //         m_pSDL2Window,
        //         m_pSDL2Renderer,
        //         m_pSDL2Texture
        //     )
        // });
        // TODO more engines
        for (auto const& p : engines) {
            p.second->GameInit();
        }
        engines[cur_engine]->Start();
        return 0;
    }
    void GameAction() {
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->GameAction();
    }
    void GameRender() {
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->GameRender();
    }
    void KeyUp(int iKeyCode) {        
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->KeyUp(iKeyCode);
    }
    void KeyDown(int iKeyCode) {
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->KeyDown(iKeyCode);
    }
    void MouseMoved(int iX, int iY) {
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->MouseMoved(iX, iY);
    }
    void MouseDown(int iButton, int iX, int iY) {
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->MouseDown(iButton, iX, iY);}
    void MouseUp(int iButton, int iX, int iY) {
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->MouseUp(iButton, iX, iY);
    }

    void SetState(State state) {
        // printf("%d\n", cur_engine);
        cur_engine = state;
        engines[cur_engine]->SetTime(GetTime());
        engines[cur_engine]->Start();
    }
    // void GameAction() { engines[cur_engine]->GameAction(); }
    // void GameAction() { engines[cur_engine]->GameAction(); }



    // Psyjz9TileManager& GetTileManager() { return engines[cur_engine]->GetTileManager(m_oTileM); }
private:
    // std::map<State, std::unique_ptr<EngineInterface>> engines;
    // State cur_engine = INIT;
    // State cur_engine = MAINGAME;
};




// #endif