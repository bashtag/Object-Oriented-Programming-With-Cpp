#include <iostream>
#include "BoardGame2D.h"
#include "EightPuzzle.h"
#include "Klotski.h"
#include "PegSolitaire.h"

using namespace std;
using namespace bg2d;

int	main(void)
{
	vector<BoardGame2D*>	boardGames;

	BoardGame2D*	pegSolitaire_t0 = new PegSolitaire;
	pegSolitaire_t0->initialize();

	BoardGame2D*	pegSolitaire_t1 = new PegSolitaire;
	pegSolitaire_t1->setBoardType(5);
	pegSolitaire_t1->initialize();
	boardGames.push_back(pegSolitaire_t1);

	BoardGame2D*	pegSolitaire_t2 = new PegSolitaire;
	pegSolitaire_t2->setBoardType(6);
	pegSolitaire_t2->initialize();
	boardGames.push_back(pegSolitaire_t2);
	

	BoardGame2D*	klotski_t0 = new Klotski;
	klotski_t0->initialize();

	BoardGame2D*	klotski_t1 = new Klotski;
	klotski_t1->initialize();
	boardGames.push_back(klotski_t1);

	BoardGame2D*	klotski_t2 = new Klotski;
	klotski_t2->initialize();
	boardGames.push_back(klotski_t2);

	BoardGame2D*	eightPuzzle_t0 = new EightPuzzle;
	eightPuzzle_t0->initialize();

	BoardGame2D*	eightPuzzle_t1 = new EightPuzzle;
	eightPuzzle_t1->initialize();
	boardGames.push_back(eightPuzzle_t1);

	BoardGame2D*	eightPuzzle_t2 = new EightPuzzle;
	eightPuzzle_t2->initialize();
	boardGames.push_back(eightPuzzle_t2);


	pegSolitaire_t0->playUser();
	pegSolitaire_t0->isFinished();

	klotski_t0->playUser();
	klotski_t0->isFinished();

	eightPuzzle_t0->playUser();
	eightPuzzle_t0->isFinished();

	BoardGame2D::playVector(boardGames);

	return (0);
}