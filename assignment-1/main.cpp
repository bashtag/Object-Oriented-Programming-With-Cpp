#include <iostream>
#include <string>
#include "Tetromino.hpp"
#include "Tetris.hpp"
#include <thread>
#include <chrono>

using namespace	std;

int	main(void)
{
	Tetris	tetrisGame;

	tetrisGame.takeTetrominos();

	cout << "Your tetrominos:" << endl;

	tetrisGame.printTetrominos();

	cout << "Horiztontally best-fit tetrominos" << endl;

	tetrisGame.horizontallyBestFit();

	tetrisGame.printBoard();

	return (0);
}