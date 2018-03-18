#include "header.h"

#include <ctime>

#include "templates.h"

// Needs one of the following #includes, to include the class definition
// #include "BouncingBallMain.h"
// #include "SimpleDemo.h"
// #include "Demo1Main.h"
// #include "Demo2Main.h"
// #include "Demo3Main.h"
// #include "Demo4Main.h"
// #include "DemoAMain.h"
#include "Psyjz9Engine.h"

const int BaseScreenWidth = TILE_WIDTH*COLS+BASEX;
const int BaseScreenHeight = TILE_HEIGHT*ROWS+BASEY;


int main(int argc, char *argv[])
{
	int iResult;

	// Send random number generator with current time
	::srand(time(0));

	// Needs just one of the two following lines:
	// SimpleDemo oMain;
	// Demo1Main oMain;
	// Demo2Main oMain;
	// Demo3Main oMain;
	// Demo4Main oMain;
	// DemoAMain oMain;
	// BouncingBallMain oMain;
	Psyjz9Engine oMain;

	char buf[1024];
	sprintf( buf, "My Demonstration Program : Size %d x %d", BaseScreenWidth, BaseScreenHeight);
	iResult = oMain.Initialise( buf, BaseScreenWidth, BaseScreenHeight, "Cornerstone Regular.ttf", 24 );
	iResult = oMain.MainLoop();
	oMain.Deinitialise();

	return iResult;
}