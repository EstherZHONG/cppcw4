#ifndef CONFIG
#define CONFIG

// enum State { MAINGAME, LEVEL_UP, LOSE, LEVEL_FINISH };

enum Tiles { WALL, COIN, SPACE, CDOOR, ODOOR, KEY };

const int ROWS = 11;
const int COLS = 15;
const int TILE_HEIGHT = 64;
const int TILE_WIDTH = 64;
const int BASEX = 25;
const int BASEY = 40;
const int TOTAL_STAGE = 3;
#endif