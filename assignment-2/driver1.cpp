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
		"getTetromino inline const function(row size and column size of the vector) -> " << tetromino.getTetromino().size() << ", " << tetromino.getTetromino()[0].size() << '\n' <<
		"Operator overloading function -> " << tetromino[2].size() << endl;
	
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

	tetris.fit(0); /* rotate and move */
	this_thread::sleep_for(chrono::milliseconds(300));
	tetris.clearScreen(13);
	tetris.printBoard();

	tetris.fitBoard(); /* fit bottom like tetromino::fitboard function */
	this_thread::sleep_for(chrono::milliseconds(300));
	tetris.clearScreen(13);
	tetris.printBoard();

	newTetromino.rotate("R"); /* it makes same tetromino */
	cout << "\n------------Getters and Setters------------" << '\n' <<
		tetris.getyCursor() << ", " << tetris.getxCursor() << ", " << tetris.getBotTetColSize() << endl;
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

	tetris.calcBotTetColSize(); /* to calculate bottom's width of the board */
	cout << "botTetColSize -> " << tetris.getBotTetColSize() << '\n' << endl;

	tetris.add(Tetromino(TetrominoType::O));
	tetris.printBoard();

	tetris.printTetrominos();

	tetris = Tetris(10, 10); /* to clear */

	tetris.takeTetrominos(); /* take inputs from user and create tetrominos */
	tetris.animate(); /* all animation operations */

	cout << "isGameFinished -> " << tetris.isGameFinished(0, 'J') << endl;

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