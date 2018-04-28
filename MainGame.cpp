#include "MainGame.h"
#include "Psyjz9Engine.h"
#include "LevelUp.h"
#include "GameFinish.h"
#include "Lose.h"

void MainGame::SetupBackgroundBuffer() {
    FillBackground(0xffd9b3);
    ReadMap(data, stage);
    m_oTileM.SetSize( COLS, ROWS ); 
    for ( int x = 0 ; x < COLS ; x++ ) {
        for ( int y = 0 ; y < ROWS ; y++ ) {
            switch (data[y][x]) {
                case 'w':
                    m_oTileM.SetValue(x, y, WALL);
                    break;
                case 'r':
                case 'v':
                case 'h':
                case 's':
                    i_UserIndex++;
                case ' ':
                case 'u':
                    m_oTileM.SetValue(x, y, SPACE);
                    break;
                case 'c':
                    m_oTileM.SetValue(x, y, COIN);
                    break;
                case 'd':
                    m_oTileM.SetValue(x, y, CDOOR);
                    m_oTileM.SetDoorX(x);
                    m_oTileM.SetDoorY(y);                    
                    break;
                case 'k':
                    m_oTileM.SetValue(x, y, KEY);
                    break;
            }
        }
    }
    m_oTileM.SetBaseTilesPositionOnScreen( BASEX, BASEY );
    m_oTileM.DrawAllTiles( this, this->GetBackground(), 0, 0, COLS-1, ROWS-1 );
}

void MainGame::KeyDown(int iKeyCode) {
    switch(iKeyCode) {
        case SDLK_SPACE:
            if (i_PausedTime < 0) {
                i_PausedTime = GetTime();
            } else {
                IncreaseTimeOffset(i_PausedTime - GetTime());
                i_PausedTime = -1;
                Redraw(true);
            }
        break;
    }
}

int MainGame::GameInit() {
    SetTimeOffset(-GetTime());
    SetupBackgroundBuffer();
    InitialiseObjects();
    return 0;
}

int MainGame::InitialiseObjects() {
    DrawableObjectsChanged();
    DestroyOldObjects();
    CreateObjectArray(i_UserIndex+2);
    int temp = 0;
    for ( int x = 0 ; x < COLS ; x++ ) {
        for ( int y = 0 ; y < ROWS ; y++ ) {
            switch (data[y][x]) {
                case 'r':
                    StoreObjectInArray(temp++, new EnemyRandom(this, x, y));
                    break;
                case 'v':
                    StoreObjectInArray(temp++, new EnemyVerti(this, x, y));
                    break;
                case 'h':
                    StoreObjectInArray(temp++, new EnemyHori(this, x, y));
                    break;
                case 's':
                    StoreObjectInArray(temp++, new EnemyShortest(this, x, y));
                    break;
                case 'u':
                    StoreObjectInArray(i_UserIndex, new UserObject(this, x, y));
                    break;
            }
        }
    }
    StoreObjectInArray(i_UserIndex+1, NULL);
    StoreObjectInArray(i_UserIndex+2, NULL);
    return 0;
}

void MainGame::GameAction() {
    if (havewin) {
        ++stage;
        DestroyOldObjects();
        if (stage > TOTAL_STAGE) {
            engine->SetState(std::make_unique<GameFinish>(
                engine,
                m_pKeyStatus,
                m_iWindowWidth,
                m_iWindowHeight,
                m_pForegroundSurface,
                m_pBackgroundSurface,
                m_pSDL2Window,
                m_pSDL2Renderer,
                m_pSDL2Texture
            ));
            return;
        } else {
            engine->SetState(std::make_unique<LevelUp>(
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
            return;
        }
    } else if (havelose) {
        engine->SetState(std::make_unique<Lose>(
            engine,
            m_pKeyStatus,
            m_iWindowWidth,
            m_iWindowHeight,
            m_pForegroundSurface,
            m_pBackgroundSurface,
            m_pSDL2Window,
            m_pSDL2Renderer,
            m_pSDL2Texture
        ));
        return;
    }

    if (GetModifiedTime() > 1000 && create) {
        create = false;
        StoreObjectInArray(i_UserIndex+1, GetDisplayableObject(i_UserIndex));
        StoreObjectInArray(i_UserIndex, new EnemyShortest(this, 1, 1));
        i_UserIndex++;
    }

    if (i_PausedTime < 0) {
        if (!IsTimeToActWithSleep()) {
            return;
        }
        SetTimeToAct(15);
        UpdateAllObjects(GetModifiedTime());
        if (GetModifiedTime() - lastRedraw > 300) { 
            lastRedraw = GetModifiedTime();  
            m_oTileM.AddCoinIndex();
            m_oTileM.DrawAllTiles(this, this->GetBackground(), 0, 0, COLS-1, ROWS-1);
            DrawStringsUnderneath();
            CopyAllBackgroundBuffer();
        }
    } else {
        DrawForegroundRectangle(400, 290, 600, 390, 0x802b00);
        engine->DrawForegroundString(460, 330, "paused", 0xffddcc);
        SDL_UpdateTexture( m_pSDL2Texture,NULL,m_pForegroundSurface->pixels,m_pForegroundSurface->pitch );
        SDL_RenderCopy( m_pSDL2Renderer,m_pSDL2Texture,NULL,NULL );
        SDL_RenderPresent( m_pSDL2Renderer );

    }

}

void MainGame::DrawStringsUnderneath() {
    engine->DrawBackgroundString(2*TILE_WIDTH+BASEX, TILE_HEIGHT+BASEY+20, "Use arrow keys to control", 0xB0B0B0);
}
void MainGame::DrawStringsOnTop() {
    if ( GetModifiedTime()/10 % 10 == 0 ) {
        TimeToString();
        CopyBackgroundPixels( TILE_WIDTH+BASEX, BASEY+10, 200, 30);
        Redraw(true);
    }
    engine->DrawForegroundString(TILE_WIDTH+BASEX, BASEY+20, m_aTimeString, 0x000000);
}

void MainGame::TimeToString() {
    int time = GetModifiedTime()/1000;
    int sec = time % 60;
    time /= 60;
    int min = time % 60;
    time /= 60;
    sprintf(m_aTimeString, "%02d:%02d:%02d", time, min, sec);
}

void MainGame::ReadMap(char data[ROWS][COLS], int num) {
    char string[20];
    sprintf(string, "Stage_map_%d.txt", num);
    std::ifstream filein(string);
    std::string buf;
    if (filein.is_open()) {
        for (int i = 0; i < ROWS; ++i) {
            getline(filein, buf);
            for (int j = 0; j < COLS; ++j) {
                data[i][j] = buf[j];
            }
        }
        filein.close();
    }
}
void MainGame::MouseDown(int iButton, int iX, int iY) {
    if (iButton == SDL_BUTTON_LEFT) {
        GetUserObject()->MouseDown();
    }
}
void MainGame::MouseUp(int iButton, int iX, int iY) {
    if (iButton == SDL_BUTTON_LEFT) {
        GetUserObject()->MouseUp();
    }
}

UserObject* MainGame::GetUserObject() {
    return static_cast<UserObject*>(GetDisplayableObject(i_UserIndex));
}

void MainGame::Win() {
    havewin = true;
}
void MainGame::LoseGame() {
    havelose = true;
}

