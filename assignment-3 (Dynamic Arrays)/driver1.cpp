#include "Tetris.hpp"

using namespace	std;

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

	Tetris	tetris; /* Default constructor */
	tetris = Tetris(10, 10); /* this constructor takes row and column values. */
	cout << "getColSize function -> " << tetris.getColSize() << endl;
	tetris.printBoard(); /* to print tetris board */

	tetris.add(newTetromino); /* to add tetromino to the beggining of the board */

	tetris.takeOneTetromino('J');
	this_thread::sleep_for(chrono::milliseconds(300));
	tetris.clearScreen(13); /* to clear screen with given row */
	tetris.printBoard();

	newTetromino.rotate("R"); /* it makes same tetromino */
	cout << "\n------------Getters and Setters------------" << '\n' <<
		tetris.getyCursor() << ", " << tetris.getxCursor() << ", " << tetris.getTopRowSize() << endl;
	tetris = Tetris(10, 10); /* to clear */

	/**
	 * @brief FOR ADDING A SINGLE TETROMINO TO THE BOARD
	 * 
	 */
	tetris += newTetromino;
	
	tetris.remove(newTetromino); /* remove the tetromino to the board */
	tetris.addDown(newTetromino); /* replace one step down */
	tetris.printBoard();

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
	tetris.printBoard();

	tetris.calcTopRowSize(); /* to calculate bottom's width of the board */
	cout << "topRowSize -> " << tetris.getTopRowSize() << '\n' << endl;

	tetris.add(Tetromino(TetrominoType::O));
	tetris.printBoard();

	tetris = Tetris(10, 10); /* to clear */

	tetris.takeOneTetromino('J');
	tetris.animate(); /* all animation operations */

	cout << "isGameFinished -> " << tetris.isGameFinished('J') << ", overload -> " << tetris.isGameFinished() << endl;

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