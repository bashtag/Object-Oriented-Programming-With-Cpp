#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "lib.h"

using namespace std;

int	main(void)
{
	vector<vector<Cell>> board;
	int	boardSelection, gameSelection;

	do
	{
		cout << "Give me a board type from 1 to 6: ";
		cin >> boardSelection;
		
		if (1 <= boardSelection && boardSelection <= 6)
		{
			board = createBoard(boardSelection);	
		}
		else
			cout << "Please try again..." << endl;
	} while (1 > boardSelection || boardSelection > 6);

	do
	{
		cout << "Select the game type: " << endl <<
			"Human Player Game (0)" << endl <<
			"Computer Game (1)" << endl <<
			"Your choice: ";
		cin >> gameSelection;

		if (gameSelection == 1 || gameSelection == 0)
			switch (gameSelection)
			{
				case 0:
					humanPlayerGame(board, boardSelection);
					break;
				
				case 1:
					srand(time(NULL));
					computerGame(board, boardSelection);
				default:
					break;
			}
		else
			cerr << "That wasn't a valid game type!" << endl;
	} while (gameSelection != 1 && gameSelection != 0);
	
	return (0);
}