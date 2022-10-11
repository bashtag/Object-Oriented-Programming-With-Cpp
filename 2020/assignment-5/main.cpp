#include <iostream>
#include "BoardGame2D.h"
#include "EightPuzzle.h"

using namespace std;
using namespace bg2d;

int	main(void)
{
	BoardGame2D*	eightPuzzle = new EightPuzzle;

	eightPuzzle->initialize();
	eightPuzzle->playUser();

	return (0);
}