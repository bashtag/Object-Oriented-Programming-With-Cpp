#include "PegSolitaire.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;


/* Cell Class */
namespace bg2d
{
	PegSolitaire::Cell::Cell()
	{}

	PegSolitaire::Cell::Cell(int _row, int _column, CellType _cell) : row(_row), column(_column), cellType(_cell)
	{}

	void	PegSolitaire::Cell::setRow(int _row)
	{
		row = _row;
	}

	void	PegSolitaire::Cell::setColumn(int _column)
	{
		column = _column;
	}

	void	PegSolitaire::Cell::setCellType(CellType _cell)
	{
		cellType = _cell;
	}
	/* Cell Class ended */

	/* PegSolitaire Class */
	PegSolitaire::PegSolitaire()
	{
		this->setBoardType(3);
	}

	void	PegSolitaire::playUser(string move)
	{
		int		row, column;
		string	direction;

		row = static_cast<int>(move[0] - '0') - 1;
		column = static_cast<int>(toupper(move[1])) - static_cast<int>('A');
		direction = toupper(move[3]);

		if (isValidMove(row, column, direction))
			makeMove(row, column, direction);
		else
			cerr << "That was not a valid move" << endl;
	}

	void	PegSolitaire::playAuto()
	{
		int		row, column;
		string	direction;

		this->getRandomValidMove(row, column, direction);
		this->makeMove(row, column, direction);
	}

	/**
	 * @brief to print two dimensional vector board
	 * 
	 * @param board > two dimensional vector
	 */
	void	PegSolitaire::print() const
	{
		int	i, j;
		for (i = -1; i < (int)board.size(); i++)
		{
			for (j = -1; j < (int)board[0].size(); j++)
			{
				if (i == -1 && j == -1)
					cout << " ";
				else if (i == -1)
					cout << COLOUR_BLUE <<
						(char)('A' + j) <<
						DEFAULT_COLOUR;
				else if (j == -1)
					cout << COLOUR_BLUE <<
						1 + i <<
						DEFAULT_COLOUR;
				else
				{
					if (board[i][j].getCellType() == CellType::none)
						cout << " ";
					else if (board[i][j].getCellType() == CellType::empty)
						cout << ".";
					else if (board[i][j].getCellType() == CellType::peg)
						cout << "P";
				}
				cout << " ";
			}
			cout << endl;
		}
	}

	/**
	 * @brief Are there any valid moves return true,
	 * otherwise 0
	 * 
	 * @param board 
	 * @return true 
	 * @return false 
	 */
	bool	PegSolitaire::endGame() const
	{
		int i, j;
		bool areMovesOver = true;

		for (i = 0; i < board.size() && areMovesOver; i++)
			for (j = 0; j < board[i].size() && areMovesOver; j++)
				if (board[i][j].getCellType() == CellType::peg)
				{
					if (isValidMove(i, j, "U"))
						areMovesOver = false;
					else if (isValidMove(i, j, "D"))
						areMovesOver = false;
					else if (isValidMove(i, j, "L"))
						areMovesOver = false;
					else if (isValidMove(i, j, "R"))
						areMovesOver = false;
					else if (boardType == 6)
					{
						if (isValidMove(i, j, "UL"))
							areMovesOver = false;
						else if (isValidMove(i, j, "DL"))
							areMovesOver = false;
						else if (isValidMove(i, j, "UR"))
							areMovesOver = false;
						else if (isValidMove(i, j, "DR"))
							areMovesOver = false;
					}
				}

		return (areMovesOver);
	}

	/**
	 * @brief return the count of pegs on the board
	 * 
	 * @return int 
	 */
	int		PegSolitaire::boardScore() const
	{
		int	score = 0;

		for (auto singleRow : board)
		{
			for (Cell cell : singleRow)
				if (cell.getCellType() == CellType::peg)
					score++;
		}

		return (score);
	}

	void	PegSolitaire::initialize()
	{
		switch (boardType)
		{
			case 1:
				this->board = {
					{Cell(0, 0, CellType::none), Cell(0, 1, CellType::none), Cell(0, 2, CellType::peg), Cell(0, 3, CellType::peg), Cell(0, 4, CellType::peg), Cell(0, 5, CellType::none), Cell(0, 6, CellType::none)},
					{Cell(1, 0, CellType::none), Cell(1, 1, CellType::peg), Cell(1, 2, CellType::peg), Cell(1, 3, CellType::peg), Cell(1, 4, CellType::peg), Cell(1, 5, CellType::peg), Cell(1, 6, CellType::none)},
					{Cell(2, 0, CellType::peg), Cell(2, 1, CellType::peg), Cell(2, 2, CellType::peg), Cell(2, 3, CellType::empty), Cell(2, 4, CellType::peg), Cell(2, 5, CellType::peg), Cell(2, 6, CellType::peg)},
					{Cell(3, 0, CellType::peg), Cell(3, 1, CellType::peg), Cell(3, 2, CellType::peg), Cell(3, 3, CellType::peg), Cell(3, 4, CellType::peg), Cell(3, 5, CellType::peg), Cell(3, 6, CellType::peg)},
					{Cell(4, 0, CellType::peg), Cell(4, 1, CellType::peg), Cell(4, 2, CellType::peg), Cell(4, 3, CellType::peg), Cell(4, 4, CellType::peg), Cell(4, 5, CellType::peg), Cell(4, 6, CellType::peg)},
					{Cell(5, 0, CellType::none), Cell(5, 1, CellType::peg), Cell(5, 2, CellType::peg), Cell(5, 3, CellType::peg), Cell(5, 4, CellType::peg), Cell(5, 5, CellType::peg), Cell(5, 6, CellType::none)},
					{Cell(6, 0, CellType::none), Cell(6, 1, CellType::none), Cell(6, 2, CellType::peg), Cell(6, 3, CellType::peg), Cell(6, 4, CellType::peg), Cell(6, 5, CellType::none), Cell(6, 6, CellType::none)}
				};
				break;
			
			case 2:
				this->board = {
					{Cell(0, 0, CellType::none), Cell(0, 1, CellType::none), Cell(0, 2, CellType::none), Cell(0, 3, CellType::peg), Cell(0, 4, CellType::peg), Cell(0, 5, CellType::peg), Cell(0, 6, CellType::none), Cell(0, 7, CellType::none), Cell(0, 8, CellType::none)},
					{Cell(1, 0, CellType::none), Cell(1, 1, CellType::none), Cell(1, 2, CellType::none), Cell(1, 3, CellType::peg), Cell(1, 4, CellType::peg), Cell(1, 5, CellType::peg), Cell(1, 6, CellType::none), Cell(1, 7, CellType::none), Cell(1, 8, CellType::none)},
					{Cell(2, 0, CellType::none), Cell(2, 1, CellType::none), Cell(0, 2, CellType::none), Cell(0, 3, CellType::peg), Cell(0, 4, CellType::peg), Cell(0, 5, CellType::peg), Cell(0, 6, CellType::none), Cell(0, 7, CellType::none), Cell(0, 8, CellType::none)},
					{Cell(3, 0, CellType::peg), Cell(3, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(4, 0, CellType::peg), Cell(4, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::empty), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(5, 0, CellType::peg), Cell(5, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(6, 0, CellType::none), Cell(6, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(7, 0, CellType::none), Cell(7, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(8, 0, CellType::none), Cell(8, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)}
				};
				break;
				
			case 3:
				this->board = {
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 0, CellType::peg), Cell(1, 0, CellType::peg), Cell(1, 0, CellType::peg), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::empty), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)}
				};
				break;
				
			case 4:
				this->board = {
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 0, CellType::peg), Cell(1, 0, CellType::peg), Cell(1, 0, CellType::peg), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::empty), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)}
				};
				break;
				
			case 5:
				this->board = {
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 0, CellType::peg), Cell(1, 0, CellType::peg), Cell(1, 0, CellType::peg), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::empty), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
				};
				break;
				
			case 6:
				this->board = {
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::empty), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 0, CellType::peg), Cell(1, 1, CellType::none), Cell(1, 0, CellType::peg), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none), Cell(1, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 1, CellType::none)},
					{Cell(0, 1, CellType::none), Cell(0, 1, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none)},
					{Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg), Cell(0, 1, CellType::none), Cell(0, 0, CellType::peg)}
				};
				break;

			default:
				break;
		}
	}

	void	PegSolitaire::gameInfo() const
	{
		cout << "Current board score is " << boardScore() << " Row(1, 2, 3, ...) - Column(A, B, C, ...) - '-' -  Direction(U, D, L, R)" << endl;
	}

	/**
	 * @brief move function to move a peg with a valid move
	 * 
	 * @param board 
	 * @param row 
	 * @param column 
	 * @param direction 
	 */
	void	PegSolitaire::makeMove(int row, int column, string direction)
	{
		if (direction == "U")
		{
			board[row][column].setCellType(CellType::empty);
			board[row - 1][column].setCellType(CellType::empty);
			board[row - 2][column].setCellType(CellType::peg);
		}
		else if (direction == "D")
		{
			board[row][column].setCellType(CellType::empty);
			board[row + 1][column].setCellType(CellType::empty);
			board[row + 2][column].setCellType(CellType::peg);
		}
		else if (direction == "L")
		{
			board[row][column].setCellType(CellType::empty);
			if (isTypeSix)
			{
				board[row][column - 2].setCellType(CellType::empty);
				board[row][column - 4].setCellType(CellType::peg);
			}
			else
			{
				board[row][column - 1].setCellType(CellType::empty);
				board[row][column - 2].setCellType(CellType::peg);
			}
		}
		else if (direction == "R")
		{
			board[row][column].setCellType(CellType::empty);
			if (isTypeSix)
			{
				board[row][column + 2].setCellType(CellType::empty);
				board[row][column + 4].setCellType(CellType::peg);
			}
			else
			{
				board[row][column + 1].setCellType(CellType::empty);
				board[row][column + 2].setCellType(CellType::peg);
			}
		}
		else if (direction == "UL")
		{
			board[row][column].setCellType(CellType::empty);
			board[row - 1][column - 1].setCellType(CellType::empty);
			board[row - 2][column - 2].setCellType(CellType::peg);
		}
		else if (direction == "UR")
		{
			board[row][column].setCellType(CellType::empty);
			board[row - 1][column + 1].setCellType(CellType::empty);
			board[row - 2][column + 2].setCellType(CellType::peg);
		}
		else if (direction == "DL")
		{
			board[row][column].setCellType(CellType::empty);
			board[row + 1][column - 1].setCellType(CellType::empty);
			board[row + 2][column - 2].setCellType(CellType::peg);
		}
		else if (direction == "DR")
		{
			board[row][column].setCellType(CellType::empty);
			board[row + 1][column + 1].setCellType(CellType::empty);
			board[row + 2][column + 2].setCellType(CellType::empty);
		}
	}

	/**
	 * @brief to string conversion from lowercase to uppercase
	 * 
	 * @param str 
	 */
	void	PegSolitaire::stringToUppercase(string &str)
	{
		for (int i = 0; (str)[i]; i++)
			(str)[i] = toupper((str)[i]);
	}

	/**
	 * @brief Is the given move valid for the given board?
	 * 
	 * @param board 
	 * @param in_column 
	 * @param in_row 
	 * @param direction 
	 * @return true 
	 * @return false 
	 */
	bool	PegSolitaire::isValidMove(int row, int column, string direction) const
	{
		bool	isValid = true;
		vector<string>	directions = {"U", "D", "L", "R",
									"UL", "UR", "DL", "DR"};

		/* Are given coordinates valid */
		if (row >= board.size() || row < 0)
			isValid = false;
		else if (column >= board[row].size() || column < 0)
			isValid = false;

		/* Do given coordinates correspond a peg */
		else if (board[row][column].getCellType() != CellType::peg)
			isValid = false;

		/* is Move Valid */
		else if (direction == "U")
		{
			if (isTypeSix)
				isValid = false;
			else if (row <= 1)
				isValid = false;
			else if (board[row - 1][column].getCellType() != CellType::peg || board[row - 2][column].getCellType() != CellType::empty)
				isValid = false;
		}
		else if (direction == "D")
		{
			if (isTypeSix)
				isValid = false;
			else if (row >= board.size() - 2)
				isValid = false;
			else if (board[row + 1][column].getCellType() != CellType::peg || board[row + 2][column].getCellType() != CellType::empty)
				isValid = false;
		}
		else if (direction == "L")
		{
			if (isTypeSix)
			{
				if (column <= 3)
					isValid = false;
				else if (board[row][column - 2].getCellType() != CellType::peg || board[row][column - 4].getCellType() != CellType::empty)
					isValid = false;
			}
			else if (column <= 1)
				isValid = false;
			else if (board[row][column - 1].getCellType() != CellType::peg || board[row][column - 2].getCellType() != CellType::empty)
				isValid = false;
		}
		else if (direction == "R")
		{
			if (isTypeSix)
			{
				if (column >= board[row].size() - 4)
					isValid = false;
				else if (board[row][column + 2].getCellType() != CellType::peg || board[row][column + 4].getCellType() != CellType::empty)
					isValid = false;
			}
			else if (column >= board[row].size() - 2)
				isValid = false;
			else if (board[row][column + 1].getCellType() != CellType::peg || board[row][column + 2].getCellType() != CellType::empty)
				isValid = false;
		}
		/* for sixth board */
		else if (direction == "UL")
		{
			if (isTypeSix)
			{
				if (row <= 1 || column <= 1)
					isValid = false;
				else if (board[row - 1][column - 1].getCellType() != CellType::peg || board[row - 2][column - 2].getCellType() != CellType::empty)
					isValid = false;
			}
			else
				isValid = false;
		}
		else if (direction == "UR")
		{
			if (isTypeSix)
			{
				if (row <= 1 || column >= board[row].size() - 2)
					isValid = false;
				else if (board[row - 1][column + 1].getCellType() != CellType::peg || board[row - 2][column + 2].getCellType() != CellType::empty)
					isValid = false;
			}
			else
				isValid = false;
		}
		else if (direction == "DL")
		{
			if (isTypeSix)
			{
				if (row >= board.size() - 2 || column <= 1)
					isValid = false;
				else if (board[row + 1][column - 1].getCellType() != CellType::peg || board[row + 2][column - 2].getCellType() != CellType::empty)
					isValid = false;
			}
			else
				isValid = false;
		}
		else if (direction == "DR")
		{
			if (isTypeSix)
			{
				if (row >= board.size() - 2 || column >= board[row].size() - 2)
					isValid = false;
				else if (board[row + 1][column + 1].getCellType() != CellType::peg || board[row + 2][column + 2].getCellType() != CellType::empty)
					isValid = false;
			}
			else
				isValid = false;
		}
		else if (find(directions.begin(), directions.end(), direction) == directions.end())
			isValid = false;

		return (isValid);
	}

	/**
	 * @brief Get the Random Valid Move object
	 * 
	 * @param board 
	 * @param row 
	 * @param column 
	 * @param direction 
	 * @param isSixthBoard 
	 */
	void	PegSolitaire::getRandomValidMove(int &row, int &column, string &direction)
	{
		do {
			row = rand() % board.size();
			column = rand() % board[row].size();
			if (!isTypeSix)
			{
				switch (rand() % 4)
				{
					case 0:
						direction = "U";
						break;

					case 1:
						direction = "D";
						break;

					case 2:
						direction = "R";
						break;

					case 3:
						direction = "L";
						break;
					
					default:
						break;
				}
			}
			else
			{
				switch (rand() % 8)
				{
					case 0:
						direction = "U";
						break;

					case 1:
						direction = "D";
						break;

					case 2:
						direction = "R";
						break;

					case 3:
						direction = "L";
						break;
					
					case 4:
						direction = "UL";
						break;
					
					case 5:
						direction = "UR";
						break;
					
					case 6:
						direction = "DL";
						break;

					case 7:
						direction = "DR";
						break;

					default:
						break;
				}

			}
		} while (!isValidMove(row, column, direction));

		cout << "row, column, direction => " << row << " " << column << " " << direction << endl;
	}

	void	PegSolitaire::writeFile()
	{
		fstream		file;
		int	i, j;

		file.open("PegSolitaireLog.txt", ios_base::app);
		for (i = -1; i < (int)board.size(); i++)
		{
			for (j = -1; j < (int)board[0].size(); j++)
			{
				if (i == -1 && j == -1)
					file << " ";
				else if (i == -1)
					file << (char)('A' + j);
				else if (j == -1)
					file << 1 + i;
				else
				{
					if (board[i][j].getCellType() == CellType::none)
						file << " ";
					else if (board[i][j].getCellType() == CellType::empty)
						file << ".";
					else if (board[i][j].getCellType() == CellType::peg)
						file << "P";
				}
				file << " ";
			}
			file << endl;
		}

		file << "Current board score is " << this->boardScore() << " Row(1, 2, 3, ...) - Column(A, B, C, ...) - '-' -  Direction(U, D, L, R)" << endl;
		file << "-------------------------------------------------------------------------------------------------------------------" << endl;
	}

	void	PegSolitaire::setBoardType(int boardType)
	{
		this->boardType = boardType;
		if (boardType == 6)
			this->isTypeSix = true;
	}
}