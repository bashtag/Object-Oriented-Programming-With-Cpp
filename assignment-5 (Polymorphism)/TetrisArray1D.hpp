#ifndef TETRISARRAY1D_HPP
# define TETRISARRAY1D_HPP

# include "AbstractTetris.hpp"

namespace	tg
{	
	class	TetrisArray1D : public AbstractTetris
	{
		public:
			TetrisArray1D();
			/**
			 * @brief Construct a new Tetris Vector object
			 * (row, column)
			 */
			TetrisArray1D(int, int);
			/**
			 * @brief Construct a new Tetris Vector object from given file
			 * 
			 * @param fileName 
			 */
			TetrisArray1D(string fileName, int&, int&);
			/**
			 * @brief Destroy the Tetris Array 1 D object
			 * 
			 */
			~TetrisArray1D();
			/**
			 * @brief Construct a new Tetris Array 1 D object
			 * copy constructor
			 * 
			 */
			TetrisArray1D(const TetrisArray1D&);
			/**
			 * @brief rule of three
			 * 
			 * @return TetrisArray1D& 
			 */
			TetrisArray1D&	operator=(const TetrisArray1D&);

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

			void	MyRealloc(TetrominoType*& src, int newSize); /* my realloc */


		private:
			TetrominoType*	board;
			Tetromino	tempTet;
			int	rowSize, colSize, y_cursor, x_cursor, topRowSize, numOfMoves;
			move	lMove;

			void	setyCursor(int);
			void	setxCursor(int);
	};
}

#endif