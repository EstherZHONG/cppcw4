
SDL_DIR = SDL/include

CC = g++

LIBS = -I$(SDL_DIR) -D_REENTRANT -lSDL2 -lSDL2_ttf -lSDL2_image

DEPS = BaseEngine.cpp FontManager.cpp TileManager.cpp DisplayableObject.cpp JPGImage.cpp MainGame.cpp Psyjz9TileManager.cpp MovingObject.cpp UserObject.cpp EnemyObject.cpp Psyjz9Engine.cpp EnemyRandom.cpp EnemyVerti.cpp EnemyHori.cpp LevelUp.cpp GameFinish.cpp Lose.cpp EnemyShortest.cpp

OUTPUT = ./a.out

build:
	$(CC) mainfunction.cpp $(DEPS) $(LIBS) -o $(OUTPUT) -std=c++11

