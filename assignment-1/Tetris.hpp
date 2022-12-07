#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "Tetromino.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Game Class.
 * 	It makes operations which are related the game.
 * 
 */
class Tetris
{
	public:
		Tetris();

		/**
		 * @brief Get the Tetrominos object
		 * 
		 * @return vector<Tetromino> 
		 */
		inline vector<Tetromino>	getTetrominos() {return (this->tetrominos);};

		/**
		 * @brief Get the Tetromino Size object
		 * 
		 * @return int 
		 */
		inline int	getTetrominoSize() const {return (this->tetrominoSize);};

		void	takeTetrominos(); /* user inputs */
		void	printTetrominos() const; /* to print vertically */
		void	horizontallyBestFit();
		void	addHorizontally(Tetromino); /* adding tetrominos horizontally into the board */
		void	fitBoard(); /* to fit the board */
		void	printBoard() const;

	private:
		vector<vector<TetrominoType>>	board;
		vector<Tetromino>	tetrominos;
		int	tetrominoSize;
};

#endif