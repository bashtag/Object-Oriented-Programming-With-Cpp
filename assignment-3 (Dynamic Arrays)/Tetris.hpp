#ifndef TETRIS_HPP
# define TETRIS_HPP

# include "Tetromino.hpp"
# include <iostream>
# include <thread>
# include <chrono>

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
		~Tetris();

		/* Getters and Setters */
		inline int	getyCursor() const {return (this->y_cursor);};
		inline int	getxCursor() const {return (this->x_cursor);};
		inline int	getTopRowSize() const {return (this->topRowSize);};
		inline int	getColSize() const {return (this->colSize);};

		void	add(const Tetromino& tetromino); /* to add the tetromino to the beggining of the board */
		void	addDown(const Tetromino& tetromino); /* to add one step down with tetromino. But remove function must be called before this function. */
		void	remove(const Tetromino& tetromino); /* remove the tetromino from the board */
		bool	animate(); /* it proceeds one-by-one */
		bool	areThereOverlap() const;

		void	takeOneTetromino(const char&); /* take a tetromino to the starting point */

		void	printBoard() const; /* to print board with ANSI and frame */
		void	clearScreen(int) const; /* to clear screen with given row size */
		void	printTetrominos() const; /* to print vertically */

		void	calcTopRowSize(); /* to calculate bottom's width of the board */

		bool	isGameFinished() const; /* it looks only first row of the board */
		bool	isGameFinished(char type) const; /* it takes index for last tetromino and a type for if the size is OK or not */
		static char	randomChType(); /* random type generator */

		Tetris&	operator=(const Tetris&);
		Tetris&	operator+=(const Tetromino&);

	private:
		TetrominoType**	board; /* tetris board */
		Tetromino	tempTet; /* temporary tetromino */
		int	rowSize, colSize, y_cursor, x_cursor, topRowSize; /* cursors and sizes */
		/* these are private. Because the user mustn't access these functions.*/
		inline void	setyCursor(int newX) {this->y_cursor = newX;};
		inline void	setxCursor(int newY) {this->x_cursor = newY;};
};

#endif