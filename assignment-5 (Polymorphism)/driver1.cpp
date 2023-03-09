#include "AbstractTetris.hpp"
#include "TetrisAdapter.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisVector.hpp"

#include <deque>

using namespace std;
using namespace tg;

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

void	playVector(vector<AbstractTetris*> gameVec)
{
	for (AbstractTetris* game : gameVec)
	{
		testing(game, 10);
	}
}

int	main(void)
{
	int	passDriver = 0;
	/* Tetromino Class Functions */
	
	Tetromino	tetromino; /* default constructor */
	
	tetromino.setTetrominoType(TetrominoType::none); /* type setter with error check */
	
	tetromino.setTetrominoType(TetrominoType::J); /* type setter with error check */
	
	tetromino.initialize(tetromino.getTetrominoType()); /* inline const getter function and initializer */
	
	tetromino.print(); /* to print tetromino */

	tetromino.rotate("R"); /* to rotate tetromino */
	tetromino.print();

	cout << "getRowSize inline const function -> " << tetromino.getRowSize() << '\n' <<
		"getColSize inline const function -> " << tetromino.getColSize() << '\n' <<
		"Operator overloading function -> " << static_cast<char>(tetromino[1][0]) << endl;
	
	Tetromino	newTetromino(TetrominoType::J);
	
	cout << "not-equal-to operator overloading function -> " << (newTetromino != tetromino) << endl;
	newTetromino.rotate("L");
	newTetromino.rotate("L");
	newTetromino.rotate("L");
	cout << "not-equal-to operator overloading function -> " << (newTetromino != tetromino) << endl << endl;

	/* Tetromino Class Functions ended */

	/* Tetris Class Functions */

	TetrisVector	tetris;
	tetris = TetrisVector(10, 10); /* this constructor takes row and column values. */
	cout << "getColSize function -> " << tetris.getColSize() << endl;
	tetris.draw(); /* to print tetris board */

	tetris += (newTetromino); /* to add tetromino to the beggining of the board */

	tetris.takeOneTetromino('J');
	this_thread::sleep_for(chrono::milliseconds(300));
	tetris.clearScreen(13); /* to clear screen with given row */
	tetris.draw();

	newTetromino.rotate("R"); /* it makes same tetromino */
	cout << "\n------------Getters and Setters------------" << '\n' <<
		tetris.getyCursor() << ", " << tetris.getxCursor() << ", " << tetris.getTopRowSize() << endl;
	tetris = TetrisVector(10, 10); /* to clear */

	/**
	 * @brief FOR ADDING A SINGLE TETROMINO TO THE BOARD
	 * 
	 */
	tetris += newTetromino;
	
	tetris.remove(newTetromino); /* remove the tetromino to the board */
	tetris.addDown(newTetromino); /* replace one step down */
	tetris.draw();

	tetris.remove(newTetromino);
	tetris.addDown(newTetromino);
	tetris.remove(newTetromino);
	tetris.addDown(newTetromino);
	tetris.remove(newTetromino);
	tetris.addDown(newTetromino);
	tetris.remove(newTetromino);
	tetris.addDown(newTetromino);
	tetris.remove(newTetromino);
	tetris.addDown(newTetromino);
	tetris.remove(newTetromino);
	tetris.addDown(newTetromino);
	tetris.draw();

	tetris.calcTopRowSize(); /* to calculate bottom's width of the board */
	cout << "topRowSize -> " << tetris.getTopRowSize() << '\n' << endl;

	tetris += (Tetromino(TetrominoType::O));
	tetris.draw();

	tetris = TetrisVector(10, 10); /* to clear */

	tetris.takeOneTetromino('J');
	tetris.animate(); /* all animation operations */
	cout << "last move -> type : " << static_cast<int>(tetris.lastMove().type) << "\nrotation : " << tetris.lastMove().rotation <<
		"\nrotation number : " << tetris.lastMove().rotNum << "\ndirection : " << tetris.lastMove().direction << "\ndirection Number : " << tetris.lastMove().dirNum << endl;

	cout << "Number of moves: " << tetris.numberOfMoves() << endl;;
	cout << "isGameFinished -> " << tetris.isGameFinished('J') << ", overload -> " << tetris.isGameFinished() << endl;

	AbstractTetris	*AGame;
	AGame = new TetrisAdapter<deque>(5,10);
	AGame->draw();

	while (passDriver != 1)
	{
		cout << "To pass to driver2 please enter 1: ";
		cin >> passDriver;
		cin.clear();
		cin.ignore(0x7fffffff, '\n');
	}

	/* Tetris Class Functions ended */

	return (0);
}
