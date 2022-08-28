#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "lib.h"

using namespace std;

int	PegSolitaire::totalPegs = 0;

int	main(void)
{
	PegSolitaire pegSolitaire;
	int	boardSelection;

	do
	{
		cout << "Give me a board type from 1 to 6: ";
		cin >> boardSelection;
		
		if (1 <= boardSelection && boardSelection <= 6)
		{
			pegSolitaire = PegSolitaire(boardSelection);
		}
		else
			cout << "Please try again..." << endl;
	} while (1 > boardSelection || boardSelection > 6);

	pegSolitaire.play();

	return (0);
}