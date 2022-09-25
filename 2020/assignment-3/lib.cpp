#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include "lib.h"

using namespace std;

/* Cell Class */

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
{}

/* it creates the board according to board type */
PegSolitaire::PegSolitaire(int _boardType) : boardType(_boardType)
{
	if (_boardType == 6)
		isTypeSix = true;
	else
		isTypeSix = false;
	board = createBoard();
	numOfPegs = gameScore();
	numOfEmptyCells = emptyCellsCounter();
	numOfTakenPegs = 0;
	totalPegs += numOfPegs;
}

PegSolitaire::PegSolitaire(string _fileName)
{
	loadFile(_fileName);
	isTypeSix = false;
	numOfPegs = gameScore();
	numOfEmptyCells = emptyCellsCounter();
	numOfTakenPegs = 0;
	totalPegs += numOfPegs;
}

/* getters and setters */
void	PegSolitaire::setNumOfPegs(int _numOfPegs)
{
	numOfPegs = _numOfPegs;
}

void	PegSolitaire::setNumOfEmptyCells(int _numOfEmptyCells)
{
	numOfEmptyCells = _numOfEmptyCells;
}

void	PegSolitaire::setNumOfTakenPegs(int _numOfTakenPegs)
{
	numOfTakenPegs = _numOfTakenPegs;
}

/**
 * @brief Create a Board object
 *  - it has to completed -
 * @param boardSelection 
 * @return vector<vector<Cell>> 
 */
vector<vector<PegSolitaire::Cell>>	PegSolitaire::createBoard()
{
	vector<vector<Cell>>	board;

	switch (boardType)
	{
		case 1:
			board = {
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
			board = {
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
			board = {
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
			board = {
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
			board = {
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
			board = {
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

	return (board);
}

/**
 * @brief to print two dimensional vector board
 * 
 * @param board > two dimensional vector
 */
void	PegSolitaire::printBoard()
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
void	stringToUppercase(string &str)
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
bool	PegSolitaire::isValidMove(int row, int column, string direction)
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
 * @brief Are there any valid moves return true,
 * otherwise 0
 * 
 * @param board 
 * @return true 
 * @return false 
 */
bool	PegSolitaire::isGameFinished()
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
int	PegSolitaire::gameScore()
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

/**
 * @brief return the count of empty cells on the board
 * 
 * @return int 
 */
int	PegSolitaire::emptyCellsCounter()
{
	int	score = 0;

	for (auto singleRow : board)
	{
		for (Cell cell : singleRow)
			if (cell.getCellType() == CellType::empty)
				score++;
	}

	return (score);
}

/**
 * @brief Game part that plays with a human
 * - there is a problem here -
 * @param board 
 * @param boardSelection 
 * @return int 
 */
void	PegSolitaire::humanPlayerGame()
{
	/* user inputs */
	int	in_row;
	char	in_column, buff;
	string	direction;
	decltype(direction)	fileSelection, fileName;

	int	row, column;
	int	moveCounter = 0;
	
	cout << "---- Human Player Game ----" << endl << endl;

	/**
	 * example moves:
	 * B4-R
	 * C2-L
	 * 
	 *   abcdefg 
	 * 1   PPP 
	 * 2   PPP 
	 * 3 PPPPPPP 
	 * 4 P..PPPP 
	 * 5 PPPPPPP 
	 * 6   PPP 
	 * 7   PPP
	 * 
	 * for just sixth board directions are:
	 * Up Right (UP)
	 * Up Left (UL)
	 * Down Right (DR)
	 * Down Left (DL)
	 */

	do
	{
		direction = "";
		printBoard();
		cout << endl << "SAVE FILE.TXT command to save current game status to FILE.TXT file" << endl <<
			"LOAD FILE.TXT command to load the game board from FILE.TXT file" << endl <<
			"Give me a right move: ";
		cin >> in_row >> in_column >> buff >> direction;
		in_column = toupper(in_column);
		stringToUppercase(direction);

		/* it means input is not valid or input is a file selection */
		if (direction == "")
		{
			cin.clear();
			cin >> fileSelection;
			stringToUppercase(fileSelection);

			if (fileSelection.substr(0,4) == "LOAD")
			{
				board.clear();
				cin >> fileName;
				if (!loadFile(fileName))
					return;
				/* if boardSelection is 6, it can be a problem */
				if (isTypeSix == 6)
					isTypeSix = 0;
				
				/* to clear the input buffer */
				continue;
			}
			else if (fileSelection.substr(0.4) == "SAVE")
			{
				cin >> fileName;
				saveFile(fileName, true, moveCounter);
				continue;
			}
		}

		row = in_row - 1;
		column = (int)in_column - 'A';

		cout << endl;

		if (isValidMove(row, column, direction))
		{
			makeMove(row, column, direction);
			moveCounter++;
			totalPegs--;
			numOfPegs--;
			numOfEmptyCells++;
			numOfTakenPegs++;
		}
		else
			cerr << "That was not a valid move" << endl;
	} while (!isGameFinished());

	printBoard();
	cout << "Game Finished! Your Score is " << numOfPegs << endl;
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

/**
 * @brief Game part that plays a computer
 * 
 * @param board 
 * @param boardSelection 
 */
void	PegSolitaire::computerGame()
{
	cout << "---- Computer Game ----\n" << endl;

	int	row, column;
	string	direction;

	int	moveCounter = 0;
	string	fileSelection;
	string	fileName;

	do {
		printBoard();

		cout << endl << "SAVE FILE.TXT command to save current game status to FILE.TXT" << endl <<
			"LOAD FILE.TXT command to load the game board from FILE.TXT" << endl <<
			"Or Press 1 to move: " << endl;
		cin >> fileSelection;
		stringToUppercase(fileSelection);


		if (fileSelection.substr(0,4) == "LOAD")
		{
			board.clear();
			cin >> fileName;
			if (!loadFile(fileName))
				return;
			/* if boardSelection is 6, it can be a problem */
			if (isTypeSix == 6)
				isTypeSix = 0;
			
			/* to clear the input buffer */
			continue;
		}
		else if (fileSelection.substr(0,4) == "SAVE")
		{
			cin >> fileName;
			saveFile(fileName, true, moveCounter);
			continue;
		}
		cout << "aloo" << endl;
		getRandomValidMove(row, column, direction);
		makeMove(row, column, direction);
		moveCounter++;
		totalPegs--;
		numOfPegs--;
		numOfEmptyCells++;
		numOfTakenPegs++;
		cout << "\n" << endl;
	} while (!isGameFinished());

	printBoard();
	cout << "Game Finished! Score is " << numOfPegs << endl;
}

/**
 * @brief to load the game board from load_file.txt file
 * 
 * @param board 
 * @param fileName 
 * @return true -> file load successfully
 * @return false -> file wasn't able to load
 */
bool	PegSolitaire::loadFile(const string fileName)
{
	fstream	fileToLoad;
	vector<Cell>	singleRow;
	string	line;
	int	maxColumn = 0, columnCounter = 0;

	fileToLoad.open(fileName, ios::in);

	if (!fileToLoad.is_open())
	{
		cerr << "Your file cannot be found!" << endl <<
			"Program will be terminated..." << endl;
		return (false);
	}
	while (!fileToLoad.eof())
	{
		getline(fileToLoad, line);
		singleRow.clear();
		columnCounter = 0;

		for (char buff : line) {
			cout << buff;
			if (buff == ' ')
				singleRow.push_back(Cell(0, 0, CellType::none));

			else if (buff == '.')
				singleRow.push_back(Cell(0, 0, CellType::empty));

			else if (buff == 'P')
				singleRow.push_back(Cell(0, 0,CellType::peg));
			columnCounter++;
		}
		if (maxColumn < columnCounter)
			maxColumn = columnCounter;

		if (line != "")
			board.push_back(singleRow);

	}

	/* to avoid possible bugs */
	for (int i = 0; i < board.size(); i++)
		board[i].resize(maxColumn, Cell(0, 0, CellType::none));

	fileToLoad.close();

	return (true);
}

void	PegSolitaire::saveFile(const string fileName, const bool isHuman, const int moveCounter)
{
	fstream	fileToSave;

	fileToSave.open(fileName, ios::out);

	if (!fileToSave.is_open())
	{
		cerr << "File wasn't able to open" << endl;
		return;
	}

	fileToSave << "GAME TYPE:"<< endl;
	
	if (isHuman)
		fileToSave << "-> Human Player Game" << endl;
	else
		fileToSave << "-> Computer Player Game" << endl;

	fileToSave << "NUMBER OF MOVES" << endl <<
		"-> " << moveCounter << endl;

	fileToSave << "IS THE BOARD THE SIXTH BOARD" << endl;
	
	if (isTypeSix)
		fileToSave << "-> True" << endl;
	else
		fileToSave << "-> False" << endl;

	fileToSave << "BOARD:" << endl;

	for (vector<Cell> row : board)
	{
		for (Cell cell : row)
			fileToSave << (int)(cell.getCellType()) << " ";
		fileToSave << endl;
	}
}

void	PegSolitaire::play()
{
	do
	{
		cout << "Select the game type: " << endl <<
			"Human Player Game (0)" << endl <<
			"Computer Game (1)" << endl <<
			"Your choice: ";
		cin >> gameSelection;

		if (gameSelection == 1 || gameSelection == 0)
			switch (gameSelection)
			{
				case 0:
					humanPlayerGame();
					break;
				
				case 1:
					srand(time(NULL));
					computerGame();
				default:
					break;
			}
		else
			cerr << "That wasn't a valid game type!" << endl;
	} while (gameSelection != 1 && gameSelection != 0);
}

void	PegSolitaire::play(Cell cellPosition)
{
	/**
	 * @brief :) I am not a schlemiel guy
	 * 
	 */
}

void	PegSolitaire::playGame()
{
	
}
/* PegSolitaire Class ended */