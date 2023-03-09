#include "Tetris.hpp"

using namespace	std;

int	main(void)
{
	Tetris	*tetrisGame;
	int	rowSize = 0, colSize = 0, counter = 0;
	char	givenType;
	string	checkType = "IOTJLSZQR";
	bool	isFinished = false;

	srand(time(NULL)); /* for 'R' */

	/* to check inputs */
	while (rowSize < 4)
	{
		cout << "Enter the height of the tetris board: (it must be greater than 4)" << endl;
		cin >> rowSize;
		cin.clear();
		cin.ignore(0x7fffffff, '\n');

		if (rowSize < 4)
			cerr << "Give me a valid input." << endl;
	}

	while (colSize < 4)
	{
		cout << "Enter the weight of the tetris board: (it must be greater than 4)" << endl;
		cin >> colSize;
		cin.clear();
		cin.ignore(0x7fffffff, '\n');

		if (rowSize < 4)
			cerr << "Give me a valid input." << endl;
	}

	tetrisGame = new Tetris(rowSize, colSize);

	tetrisGame->printBoard();
	do
	{
		do
		{
			cout << "Give me a valid Tetromino Type (I, O, T, J, L, S, Z). R for random Tetromino, Q for quit." << tetrisGame->getTopRowSize() << endl;
			cin >> givenType;
			cin.clear();
			cin.ignore(0x7fffffff, '\n');
			givenType = toupper(givenType);

			if (checkType.find(givenType) == string::npos)
			{
				tetrisGame->clearScreen(2);
				cerr << "Give me a valid type!: ";
			}
		} while (checkType.find(givenType) == string::npos);

		if (givenType == 'R')
			givenType = Tetris::randomChType();
		
		if (!tetrisGame->isGameFinished(givenType))
		{
			tetrisGame->clearScreen(tetrisGame->getColSize() + 5);
			cout << "\e[J"; /* Delete til the end of the terminal */
			tetrisGame->takeOneTetromino(givenType);
			if (!tetrisGame->animate())
				break;
			++counter;
		}
		else
			isFinished = true;
	} while (!isFinished && !tetrisGame->isGameFinished());
	
	cout << "Game is Finished!" << endl;

	return (0);
}