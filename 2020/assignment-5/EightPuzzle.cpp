#include "EightPuzzle.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace	bg2d
{
	EightPuzzle::EightPuzzle()
	{}

	void	EightPuzzle::initialize()
	{
		vector<int>	temp;
		int	number;

		srand(time(NULL));

		while (temp.size() != 9)
		{
			number = rand() % 10 - 1;
			if (number != 0 && !count(temp.begin(), temp.end(), number))
			{
				temp.push_back(number);
			}
		}

		board.reserve(3);
		for (int i = 0, j = 0, k; i < 3; i++)
		{
			for (k = 0; k < 3; k++)
			{
				board[i].push_back(temp[j++]);
			}
		}
	}

	void	EightPuzzle::playUser(string move)
	{
		int	row, column;
		string	direction;

		/**
		 * Row - Column - - - Direction
		 * 
		 */

		row = static_cast<int>(move[0]) - 1;
		column = static_cast<int>(toupper(move[1])) - static_cast<int>('A');
		direction = move.substr(3);

		if (isValidMove(row, column, direction))
			makeMove(row, column, direction);
		else
			cerr << "That was not a valid move" << endl;
	}

	void	EightPuzzle::playAuto()
	{
		int	row, column;
		string	direction;

		this->randValidMove(row, column, direction);
		this->makeMove(row, column, direction);
	}

	/**
	 * @brief Get a random valid move
	 * 
	 * @param row 
	 * @param column 
	 * @param direction 
	 */
	void	EightPuzzle::randValidMove(int& row, int& column, string& direction)
	{
		do
		{
			row = rand() % 3;
			column = rand() % 3;

			switch (rand() % 4)
			{
			case 0:
				direction = "U";
				break;
			
			case 1:
				direction = "D";
				break;

			case 2:
				direction = "L";
				break;

			case 3:
				direction = "R";
				break;
			
			default:
				break;
			}
		} while (!this->isValidMove(row, column, direction));
	}

	/**
	 * @brief check if given move is valid or not
	 * 
	 * @param row 
	 * @param column 
	 * @param direction 
	 * @return true 
	 * @return false 
	 */
	bool	EightPuzzle::isValidMove(int row, int column, string direction) const
	{
		bool	isValid = true;

		if (!(row <= 2 && row >= 0) || !(column <= 2 && column >= 0))
			isValid = false;
		else if (direction == "L" || column <= 0 ||
				board[row][column - 1] != -1)
			isValid = false;
		else if (direction == "R" || column >= 2 ||
				board[row][column + 1] != -1)
			isValid = false;
		else if (direction == "U" || row <= 0 ||
				board[row - 1][column] != -1)
			isValid = false;
		else if (direction == "D" || row >= 2 ||
				board[row + 1][column] != -1)
			isValid = false;

		return (isValid);
	}

	/**
	 * @brief make this given valid move
	 * 
	 * @param row 
	 * @param column 
	 * @param direction 
	 */
	void	EightPuzzle::makeMove(int row, int column, string direction)
	{
		int	temp;

		cout << "move: " << row << ", " << column << ", " << direction << endl;

		if (direction == "U")
		{
			temp = this->board[row][column];
			this->board[row - 1][column] = temp;
			this->board[row][column] = -1;
		}
		else if (direction == "D")
		{
			temp = this->board[row][column];
			this->board[row + 1][column] == temp;
			this->board[row][column] = -1;			
		}
		else if (direction == "L")
		{
			temp = this->board[row][column];
			this->board[row][column - 1] == temp;
			this->board[row][column] = -1;			
		}
		else if (direction == "R")
		{
			temp = this->board[row][column];
			this->board[row][column + 1] == temp;
			this->board[row][column] = -1;			
		}
	}

	/**
	 * @brief better case is the smaller integer number
	 * 
	 * @return int 
	 */
	int	EightPuzzle::boardScore() const
	{
		int	j, num = 1, result = 0;

		for (int i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (board[i][j] != num)
				{
					result++;
				}
				num++;
			}

		return (result);
	}

	bool	EightPuzzle::endGame()
	{
		bool	isGameFinished = true;

		int	j, num = 1;

		for (int i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if ((i != 2 && j != 2) && board[i][j] != num)
				{
					isGameFinished = false;
				}
				num++;
			}

		return (isGameFinished);
	}

	void	EightPuzzle::print() const
	{
		int j;

		for (int i = -1; i < 3; i++)
		{
			for (j = -1; j < 3; j++)
			{
				if (i == -1 && j == -1)
					cout << " \t";
				else if (i == -1)
					cout << COLOUR_BLUE <<
						static_cast<char>(static_cast<int>('A') + j) <<
						DEFAULT_COLOUR << '\t';
				else if (j == -1)
					cout << COLOUR_BLUE <<
						i + 1 <<
						DEFAULT_COLOUR << '\t';
				else
				{
					cout << this->board[i][j] << '\t';
				}
			}
			cout << '\n';
		}
		cout << endl;
	}

	/**
	 * @brief game info for eight puzzle game
	 * 
	 */
	void	EightPuzzle::gameInfo() const
	{
		cout << "Row(1, 2, 3) - Column(A, B, C) - '-' -  Direction(U, D, L, R)" << endl;
	}
}