#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "lib.h"

#define COLOUR_BLUE "\033[0;34m"
#define DEFAULT_COLOUR "\033[0m"

using namespace std;

/**
 * @brief Create a Board object
 * 
 * @param boardSelection 
 * @return vector<vector<Cell>> 
 */
vector<vector<Cell>>	createBoard(int boardSelection)
{
	vector<vector<Cell>>	board;

	switch (boardSelection)
	{
		case 1:
			board = {
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none},
				{Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none},
				{Cell::peg, Cell::peg, Cell::peg, Cell::empty, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none}
			};
			break;
		
		case 2:
			board = {
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::empty, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none}
			};
			break;
			
		case 3:
			board = {
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::empty, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none}
			};
			break;
			
		case 4:
			board = {
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::empty, Cell::peg, Cell::peg, Cell::peg},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none}
			};
			break;
			
		case 5:
			board = {
				{Cell::none, Cell::none, Cell::none, Cell::none, Cell::peg, Cell::none, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none},
				{Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none},
				{Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::empty, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
				{Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::none, Cell::peg, Cell::none, Cell::none, Cell::none, Cell::none},
			};
			break;
			
		case 6:
			board = {
				{Cell::none, Cell::none, Cell::none, Cell::none, Cell::empty, Cell::none, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::none, Cell::none},
				{Cell::none, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::none},
				{Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none},
				{Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg}
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
void	printBoard(vector<vector<Cell>> board)
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
				if (board[i][j] == Cell::none)
					cout << " ";
				else if (board[i][j] == Cell::empty)
					cout << ".";
				else if (board[i][j] == Cell::peg)
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
void	makeMove(vector<vector<Cell>> &board, int row, int column, string direction, bool isSixthBoard)
{
	if (direction == "U")
	{
		board[row][column] = Cell::empty;
		board[row - 1][column] = Cell::empty;
		board[row - 2][column] = Cell::peg;
	}
	else if (direction == "D")
	{
		board[row][column] = Cell::empty;
		board[row + 1][column] = Cell::empty;
		board[row + 2][column] = Cell::peg;
	}
	else if (direction == "L")
	{
		board[row][column] = Cell::empty;
		if (isSixthBoard)
		{
			board[row][column - 2] = Cell::empty;
			board[row][column - 4] = Cell::peg;
		}
		else
		{
			board[row][column - 1] = Cell::empty;
			board[row][column - 2] = Cell::peg;
		}
	}
	else if (direction == "R")
	{
		board[row][column] = Cell::empty;
		if (isSixthBoard)
		{
			board[row][column + 2] = Cell::empty;
			board[row][column + 4] = Cell::peg;
		}
		else
		{
			board[row][column + 1] = Cell::empty;
			board[row][column + 2] = Cell::peg;
		}
	}
	else if (direction == "UL")
	{
		board[row][column] = Cell::empty;
		board[row - 1][column - 1] = Cell::empty;
		board[row - 2][column - 2] = Cell::peg;
	}
	else if (direction == "UR")
	{
		board[row][column] = Cell::empty;
		board[row - 1][column + 1] = Cell::empty;
		board[row - 2][column + 2] = Cell::peg;
	}
	else if (direction == "DL")
	{
		board[row][column] = Cell::empty;
		board[row + 1][column - 1] = Cell::empty;
		board[row + 2][column - 2] = Cell::peg;
	}
	else if (direction == "DR")
	{
		board[row][column] = Cell::empty;
		board[row + 1][column + 1] = Cell::empty;
		board[row + 2][column + 2] = Cell::empty;
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
 * @brief 
 * 
 * @param board 
 * @param in_column 
 * @param in_row 
 * @param direction 
 * @return true 
 * @return false 
 */
bool	isValidMove(vector<vector<Cell>> board, int row, int column, string direction, bool isSixthBoard)
{
	bool	isValid = true;

	/* Are given coordinates valid */
	if (row >= board.size() || row < 0)
		isValid = false;
	else if (column >= board[row].size() || column < 0)
		isValid = false;

	/* Do given coordinates correspond a peg */
	else if (board[row][column] != Cell::peg)
		isValid = false;

	/* is Move Valid */
	else if (direction == "U")
	{
		if (isSixthBoard)
			isValid = false;
		else if (row <= 1)
			isValid = false;
		else if (board[row - 1][column] != Cell::peg || board[row - 2][column] != Cell::empty)
			isValid = false;
	}
	else if (direction == "D")
	{
		if (isSixthBoard)
			isValid = false;
		else if (row >= board.size() - 2)
			isValid = false;
		else if (board[row + 1][column] != Cell::peg || board[row + 2][column] != Cell::empty)
			isValid = false;
	}
	else if (direction == "L")
	{
		if (isSixthBoard)
		{
			if (column <= 3)
				isValid = false;
			else if (board[row][column - 2] != Cell::peg || board[row][column - 4] != Cell::empty)
				isValid = false;
		}
		else if (column <= 1)
			isValid = false;
		else if (board[row][column - 1] != Cell::peg || board[row][column - 2] != Cell::empty)
			isValid = false;
	}
	else if (direction == "R")
	{
		if (isSixthBoard)
		{
			if (column >= board[row].size() - 4)
				isValid = false;
			else if (board[row][column + 2] != Cell::peg || board[row][column + 4] != Cell::empty)
				isValid = false;
		}
		else if (column >= board[row].size() - 2)
			isValid = false;
		else if (board[row][column + 1] != Cell::peg || board[row][column + 2] != Cell::empty)
			isValid = false;
	}
	/* for sixth board */
	else if (isSixthBoard && direction == "UL")
	{
		if (row <= 1 || column <= 1)
			isValid = false;
		else if (board[row - 1][column - 1] != Cell::peg || board[row - 2][column - 2] != Cell::empty)
			isValid = false;
	}
	else if (isSixthBoard && direction == "UR")
	{
		if (row <= 1 || column >= board[row].size() - 2)
			isValid = false;
		else if (board[row - 1][column + 1] != Cell::peg || board[row - 2][column + 2] != Cell::empty)
			isValid = false;
	}
	else if (isSixthBoard && direction == "DL")
	{
		if (row >= board.size() - 2 || column <= 1)
			isValid = false;
		else if (board[row + 1][column - 1] != Cell::peg || board[row + 2][column - 2] != Cell::empty)
			isValid = false;
	}
	else if (isSixthBoard && direction == "DR")
	{
		if (row >= board.size() - 2 || column >= board[row].size() - 2)
			isValid = false;
		else if (board[row + 1][column + 1] != Cell::peg || board[row + 2][column + 2] != Cell::empty)
			isValid = false;
	}

	return (isValid);
}

/**
 * @brief Are there any valid moves
 * 
 * @param board 
 * @return true 
 * @return false 
 */
bool	isGameFinished(vector<vector<Cell>> board, int boardSelection)
{
	int i, j;
	bool areMovesOver = true;

	for (i = 0; i < board.size() && areMovesOver; i++)
		for (j = 0; j < board[i].size() && areMovesOver; j++)
			if (board[i][j] == Cell::peg)
			{
				if (isValidMove(board, i, j, "U", boardSelection == 6))
					areMovesOver = false;
				else if (isValidMove(board, i, j, "D", boardSelection == 6))
					areMovesOver = false;
				else if (isValidMove(board, i, j, "L", boardSelection == 6))
					areMovesOver = false;
				else if (isValidMove(board, i, j, "R", boardSelection == 6))
					areMovesOver = false;
				else if (boardSelection == 6)
				{
					if (isValidMove(board, i, j, "UL", boardSelection == 6))
						areMovesOver = false;
					else if (isValidMove(board, i, j, "DL", boardSelection == 6))
						areMovesOver = false;
					else if (isValidMove(board, i, j, "UR", boardSelection == 6))
						areMovesOver = false;
					else if (isValidMove(board, i, j, "DR", boardSelection == 6))
						areMovesOver = false;
				}
			}

	return (areMovesOver);
}

/**
 * @brief return the count of pegs on the board
 * 
 * @param board 
 * @return int 
 */
int	gameScore(vector<vector<Cell>> board)
{
	int	score = 0;

	for (vector<Cell> singleRow : board)
	{
		for (Cell cell : singleRow)
			if (cell == Cell::peg)
				score++;
	}

	return (score);
}

/**
 * @brief Game part that plays with a human
 * 
 * @param board 
 * @param boardSelection 
 */
void	humanPlayerGame(vector<vector<Cell>> board, int boardSelection)
{
	/* user inputs */
	int	in_row;
	char	in_column, buff;
	string	direction;

	int	row, column;
	
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
		printBoard(board);
		cout << endl << "Give me a right move: ";
		
		cin >> in_row >> in_column >> buff >> direction;
		in_column = toupper(in_column);
		stringToUppercase(direction);

		row = in_row - 1;
		column = (int)in_column - 'A';

		cout << endl;

		if (isValidMove(board, row, column, direction, boardSelection == 6))
			makeMove(board, row, column, direction, boardSelection == 6);
		else
			cout << "That was not a valid move" << endl;
	} while (!isGameFinished(board, boardSelection));

	printBoard(board);
	cout << "Game Finished! Your Score is " << gameScore(board) << endl;
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
void	getRandomValidMove(vector<vector<Cell>> board, int &row, int &column, string &direction, bool isSixthBoard)
{
	do {
		row = rand() % board.size();
		column = rand() % board[row].size();

		if (!isSixthBoard)
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
	} while (!isValidMove(board, row, column, direction, isSixthBoard));

	cout << "row, column, direction => " << row << column << direction << endl;
}

/**
 * @brief Game part that plays a computer
 * 
 * @param board 
 * @param boardSelection 
 */
void	computerGame(vector<vector<Cell>> board, int boardSelection)
{
	cout << "---- Computer Game ----\n" << endl;

	int	row, column;
	string	direction;

	do {
		printBoard(board);
		getRandomValidMove(board, row, column, direction, boardSelection == 6);
		makeMove(board, row, column, direction, boardSelection == 6);
		cout << "\n" << endl;
	} while (!isGameFinished(board, boardSelection));

	printBoard(board);
	cout << "Game Finished! Score is " << gameScore(board) << endl;
}