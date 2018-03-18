#include "MainGame.h"
#include "Psyjz9Engine.h"

void MainGame::SetupBackgroundBuffer()
{
    FillBackground(0xffd9b3);
    char data[ROWS][COLS];
    ReadFile(data, "Stage1.txt");
    m_oTileM.SetSize( COLS, ROWS ); 
    for ( int x = 0 ; x < COLS ; x++ ) {
        for ( int y = 0 ; y < ROWS ; y++ ) {
            switch (data[y][x]) {
                case 'w':
                    m_oTileM.SetValue(x, y, WALL);
                    break;
                case ' ':
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
    // DrawBackgroundString(100, 100, "Use arrow keys to move your ball", 0xB0B0B0);
    // Redraw(true)
}

void MainGame::KeyDown(int iKeyCode) {
    switch(iKeyCode) {
        case SDLK_ESCAPE:
            i_PausedTime = GetTime();
            engine->SetState(MENU);
    }
}

void MainGame::Start() {
    // SetupBackgroundBuffer();
    IncreaseTimeOffset(i_PausedTime - GetTime());
    i_PausedTime = -1;
    Redraw(true);
}

int MainGame::InitialiseObjects()
{
    DrawableObjectsChanged();
    DestroyOldObjects();
    CreateObjectArray(2);
    StoreObjectInArray(0, new EnemyObject(this, 7, 1));
    StoreObjectInArray(1, new UserObject(this, 1, 1));
    // StoreObjectInArray( 1, new MovingObject(this, 9, 9) );
    // StoreObjectInArray( 2, new MovingObject(this, 13, 9) );
    // StoreObjectInArray( 3, new MovingObject(this, 9, 5) );
    // StoreObjectInArray( 4, new MovingObject(this, 13, 5) );
    StoreObjectInArray(2, NULL);
    return 0;
}

void MainGame::GameAction() {
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
}

void MainGame::DrawStringsUnderneath() {
    // CopyBackgroundPixels( 100/*X*/, 100/*Y*/, GetWindowWidth(), 30/*Height*/ );
    // DrawForegroundString( 250, 10, "Running", 0xffffff, NULL );
    engine->DrawBackgroundString(2*TILE_WIDTH+BASEX, TILE_HEIGHT+BASEY+20, "Use arrow keys to move your mushroom", 0xB0B0B0);
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

void MainGame::ReadFile(char data[ROWS][COLS], const char* filename) {
    std::ifstream filein(filename);
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
