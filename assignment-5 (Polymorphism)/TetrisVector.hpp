#ifndef TETRISVECTOR_HPP
# define TETRISVECTOR_HPP

# include "AbstractTetris.hpp"

namespace	tg
{	
	class	TetrisVector : public AbstractTetris
	{
		public:
			TetrisVector();
			/**
			 * @brief Construct a new Tetris Vector object
			 * (row, column)
			 */
			TetrisVector(int, int);
			/**
			 * @brief Construct a new Tetris Vector object from given file
			 * 
			 * @param fileName 
			 */
			TetrisVector(string fileName, int&, int&);

			virtual void	draw() const;
			virtual void	readFromFile(string); /* filename */
			virtual void	writeToFile(string) const; /* filename */
			virtual void	operator+=(const Tetromino&);
			virtual bool	animate();
			virtual move	lastMove();
			virtual int	numberOfMoves();
			virtual void	takeOneTetromino(const char&); /* take a tetromino to the starting point*/
			virtual bool	isGameFinished() const; /* it looks only first row of the board */
			virtual bool	isGameFinished(char type) const; /* it takes index for last tetromino and a type for if the size is OK or not */

			inline int	getyCursor() const {return (this->y_cursor);};
			inline int	getxCursor() const {return (this->x_cursor);};
			inline int	getTopRowSize() const {return (this->topRowSize);};
			inline int	getColSize() const {return (this->colSize);};

			/**
			 * @brief to add one step down with tetromino. 
			 * But remove function must be called before this function.
			 * 
			 */
			void	addDown(const Tetromino&);
			/**
			 * @brief  remove the tetromino from the board 
			 * 
			 */
			void	remove(const Tetromino&);
			bool	areThereOverlap() const;

			void	calcTopRowSize(); /* to calculate bottom's width of the board */
		private:
			vector<vector<TetrominoType>>	board;
			Tetromino	tempTet;
			int	rowSize, colSize, y_cursor, x_cursor, topRowSize, numOfMoves;
			move	lMove;

			void	setyCursor(int);
			void	setxCursor(int);
	};
}

#endif