#ifndef _PEGSOLITAIRE_H_
#define _PEGSOLITAIRE_H_

#include "BoardGame2D.h"

enum class CellType {none, empty, peg};

namespace bg2d
{
	class	PegSolitaire : public BoardGame2D
	{
		public:
			/* Cell class */
			class	Cell
			{
				public:
					Cell();
					Cell(int, int, CellType);	
					void	setRow(int);
					void	setColumn(int);
					void	setCellType(CellType);
					/* const means read only */
					inline int	getRow() const {return (row);};
					inline int	getColumn() const {return (column);};
					inline CellType	getCellType() const {return (cellType);};
				private:
					int	row;
					int	column;
					CellType	cellType;
			};
			/* Cell class end */

			virtual void	playUser(string);
			virtual void	playAuto();
			virtual void	print() const;
			virtual bool	endGame() const;
			virtual int		boardScore() const;
			virtual void	initialize();
			virtual void	gameInfo() const;
			virtual void	writeFile();

			PegSolitaire(); /* makes board as NULL */

			/**
			 * @brief board, row, column, direction
			 * 
			 */
			void	makeMove(int, int, string); /* making a valid move to the board */
			/**
			 * @brief board, row, column, direction
			 * 
			 */
			bool	isValidMove(int, int, string) const; /* checks if move is valid */
			/**
			 * @brief board, row, column, direction
			 * 
			 */
			void	getRandomValidMove(int&, int&, string&); /* creating a valid move for computer player */
			/**
			 * @brief to string conversion from lowercase to uppercase
			 * 
			 * @param str 
			 */
			void	stringToUppercase(string&);

			/**
			 * @brief Set the Board Type object
			 * 
			 */
			virtual void	setBoardType(int);

		private:
			/* my variables that are not accessible outside of the class */
			int	resize;
			int	boardType;
			bool	isTypeSix;
			vector <vector<Cell>> board;
	};
}

#endif