#ifndef TETROS_HPP
#define TETROS_HPP

#include "Tetromino.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Class for the Board that have been fitted.
 * 	It makes operations which are related to fit.
 * 
 */
class Tetros
{
	public:
		Tetros();

		/**
		 * @brief Get the Tetrominos object
		 * 
		 * @return vector<Tetromino> 
		 */
		inline vector<Tetromino>	getTetrominos() {return (this->tetrominos);};
		inline vector<Tetromino>	getPrevTetrominos() const {return (this->previousTetrominos);};

		/**
		 * @brief Get the Tetromino Size object
		 * 
		 * @return int 
		 */
		inline int	getTetrominoSize() const {return (this->tetrominoSize);};

		void	takeTetrominos(); /* user inputs */
		void	addOneTetrominoAnFit(char);
		void	printTetrominos() const; /* to print vertically */
		void	horizontallyBestFit();
		void	addHorizontally(const Tetromino&); /* adding tetrominos horizontally into the board */
		void	fitBoard(); /* to fit the board */
		void	printBoard() const;

	private:
		vector<vector<TetrominoType>>	board;
		vector<Tetromino>	tetrominos;
		vector<Tetromino>	previousTetrominos;
		int	tetrominoSize;
};

#endif