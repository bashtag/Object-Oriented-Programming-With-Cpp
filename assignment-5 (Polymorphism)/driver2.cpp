#include "TetrisVector.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisAdapter.hpp"

using namespace	std;
using namespace	tg;

void	testing(AbstractTetris* tetrisGame, int colSize);

int	main(void)
{
	AbstractTetris	*tetrisGame;
	int	rowSize = 0, colSize = 0, counter = 0;
	char	givenType;
	string	checkType = "IOTJLSZQR";
	char	isFile = 0;
	char	gameType = 0;

	srand(time(NULL)); /* for 'R' */

	while (gameType != 'V' && gameType != '1' && gameType != 'A')
	{
		cout << "Enter the game type: (V for vector, 1 for array1D, A for adaptor)" << endl;
		cin >> gameType;
		cin.clear();
		cin.ignore(0x7fffffff, '\n');
		gameType = toupper(gameType);

		if (gameType != 'V' && gameType != '1' && gameType != 'A')
			cerr << "Give me a valid input." << endl;
	}

	while (isFile != '1' && isFile != '0')
	{
		cout << "Enter the game type: (Saved file (1) or not (0))" << endl;
		cin >> isFile;
		isFile = toupper(isFile);
		cin.clear();
		cin.ignore(0x7fffffff, '\n');

		if (isFile != '1' && isFile != '0')
			cerr << "Give me a valid input." << endl;
	}

	if (isFile == '1')
	{
		if (gameType == 'V')
			tetrisGame = new TetrisVector("kayit.txt", rowSize, colSize);
		else if (gameType == '1')
			tetrisGame = new TetrisArray1D("kayit.txt", rowSize, colSize);
		else if (gameType == 'A')
			tetrisGame = new TetrisAdapter<vector>("kayit.txt", rowSize, colSize);
	}
	else
	{
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

		if (gameType == 'V')
			tetrisGame = new TetrisVector(rowSize, colSize);
		else if (gameType == '1')
			tetrisGame = new TetrisArray1D( rowSize, colSize);
		else if (gameType == 'A')
			tetrisGame = new TetrisAdapter<vector>(rowSize, colSize);
	}

	testing(tetrisGame, colSize);
	
	tetrisGame->writeToFile("kayit.txt");
	cout << "Game is Finished!" << endl;

	return (0);
}

void	testing(AbstractTetris* tetrisGame, int colSize)
{
	char givenType;
	bool	isFinished = false;
	int	counter = 0;
	string	checkType = "IOTJLSZQR";

	tetrisGame->draw();
	do
	{
		do
		{
			cout << "Give me a valid Tetromino Type (I, O, T, J, L, S, Z). R for random Tetromino, Q for quit." << endl;
			cin >> givenType;
			cin.clear();
			cin.ignore(0x7fffffff, '\n');
			givenType = toupper(givenType);

			if (checkType.find(givenType) == string::npos)
			{
				AbstractTetris::clearScreen(2);
				cerr << "Give me a valid type!: ";
			}
		} while (checkType.find(givenType) == string::npos);

		if (givenType == 'R')
			givenType = AbstractTetris::randomChType();
		
		if (!tetrisGame->isGameFinished(givenType))
		{
			AbstractTetris::clearScreen(colSize + 5);
			cout << "\e[J"; /* Delete til the end of the terminal */
			tetrisGame->takeOneTetromino(givenType);
			if (!tetrisGame->animate())
				break;
			++counter;
		}
		else
			isFinished = true;
	} while (!isFinished && !tetrisGame->isGameFinished());
}