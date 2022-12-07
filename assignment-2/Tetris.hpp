#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "Tetros.hpp"
#include <thread>
#include <chrono>

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
		 * @brief Construct a new Tetris object
		 * (row, column)
		 * 
		 */
		Tetris(int, int);

		/* Getters and Setters */
		inline int	getyCursor() const {return (this->y_cursor);};
		inline int	getxCursor() const {return (this->x_cursor);};
		inline int	getBotTetColSize() const {return (this->botTetColSize);};
		inline int	getColSize() const {return (this->colSize);};

		void	add(const Tetromino& tetromino); /* to add the tetromino to the beggining of the board */
		void	addDown(const Tetromino& tetromino); /* to add one step down with tetromino. But remove function must be called before this function. */
		void	remove(const Tetromino& tetromino); /* remove the tetromino from the board */
		bool	fitBoard(); /* fitBoard at the bottom of the board. It deletes the spaces between two tetrominos */
		bool	fit(int index); /* it makes move and rotation. */
		void	animate(); /* animate function that working with all of the tetrominos */
		void	animate(int index); /* it proceeds one-by-one */

		void	takeTetrominos(); /* take all of the tetrominos at once */
		void	takeOneTetromino(char type); /* to take just a tetromino */

		void	printBoard() const; /* to print board with ANSI and frame */
		void	clearScreen(int) const; /* to clear screen with given row size */
		void	printTetrominos() const; /* to print vertically */

		void	calcBotTetColSize(); /* to calculate bottom's width of the board */

		bool	isGameFinished(int index, char type) const; /* it takes index for last tetromino and a type for if the size is OK or not */
		static char	randomChType(); /* random type generator */

	private:
		vector<vector<TetrominoType>>	board; /* tetris board */
		vector<Tetromino>	tetrominos; /* tetrominos vector */
		Tetros	tetros; /* Tetros class for hw1 implementations */
		int	rowSize, colSize, y_cursor, x_cursor, botTetColSize; /* cursors and sizes */
		/* these are private. Because the user mustn't access these functions.*/
		inline void	setyCursor(int newX) {this->y_cursor = newX;};
		inline void	setxCursor(int newY) {this->x_cursor = newY;};
};

#endif