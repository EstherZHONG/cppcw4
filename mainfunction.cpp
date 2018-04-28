#include "header.h"

#include <ctime>

#include "templates.h"

#include "Psyjz9Engine.h"

const int BaseScreenWidth = TILE_WIDTH*COLS+2*BASEX;
const int BaseScreenHeight = TILE_HEIGHT*ROWS+2*BASEY;


int main(int argc, char *argv[])
{
	int iResult;

	::srand(time(0));

	Psyjz9Engine oMain;

	char buf[1024];
	sprintf( buf, "My Demonstration Program : Size %d x %d", BaseScreenWidth, BaseScreenHeight);
	iResult = oMain.Initialise( buf, BaseScreenWidth, BaseScreenHeight, "Cornerstone Regular.ttf", 24 );
	iResult = oMain.MainLoop();
	oMain.Deinitialise();

	return iResult;
}
