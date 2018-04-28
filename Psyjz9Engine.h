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
#include "EngineInterface.h"
#include "make_unique.h" 

class Psyjz9Engine : public BaseEngine {
public:
    Psyjz9Engine() : BaseEngine() {}
    ~Psyjz9Engine() {}
    int GameInit();
    void GameAction() {
        cur_engine->SetTime(GetTime());
        cur_engine->GameAction();
    }
    void GameRender() {
        cur_engine->SetTime(GetTime());
        cur_engine->GameRender();
    }
    void KeyUp(int iKeyCode) {        
        cur_engine->SetTime(GetTime());
        cur_engine->KeyUp(iKeyCode);
    }
    void KeyDown(int iKeyCode) {
        cur_engine->SetTime(GetTime());
        cur_engine->KeyDown(iKeyCode);
    }
    void MouseMoved(int iX, int iY) {
        cur_engine->SetTime(GetTime());
        cur_engine->MouseMoved(iX, iY);
    }
    void MouseDown(int iButton, int iX, int iY) {
        cur_engine->SetTime(GetTime());
        cur_engine->MouseDown(iButton, iX, iY);}
    void MouseUp(int iButton, int iX, int iY) {
        cur_engine->SetTime(GetTime());
        cur_engine->MouseUp(iButton, iX, iY);
    }

    void SetState(std::unique_ptr<EngineInterface> newEngine) {
        cur_engine.reset(newEngine.release());
        cur_engine->SetTime(GetTime());
        cur_engine->GameInit();
    }
private:
    std::unique_ptr<EngineInterface> cur_engine;
};




// #endif