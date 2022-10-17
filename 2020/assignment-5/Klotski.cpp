#include "Klotski.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

namespace bg2d
{
	Klotski::Klotski() {}

	void	Klotski::initialize()
	{
		this->board = {
			{'B', 'A', 'A', 'C'},
			{'B', 'A', 'A', 'C'},
			{'D', 'E', 'E', 'F'},
			{'D', 'G', 'H', 'F'},
			{'I', -1, -1, 'J'},
		};
	}

	void	Klotski::print() const
	{
		int j;

		for (int i = 0; i < this->board.size(); i++)
		{
			for (j = 0; j < this->board[i].size(); j++)
			{
				switch (this->board[i][j])
				{
					case 'A':
						cout << COLOUR_RED << 'A' <<
							DEFAULT_COLOUR;
						break;

					case 'B':
						cout << COLOUR_YELLOW << 'B' <<
							DEFAULT_COLOUR;
						break;
					case 'C':
						cout << COLOUR_YELLOW << 'C' <<
							DEFAULT_COLOUR;
						break;
					case 'D':
						cout << COLOUR_YELLOW << 'D' <<
							DEFAULT_COLOUR;
						break;
					case 'E':
						cout << COLOUR_YELLOW << 'E' <<
							DEFAULT_COLOUR;
						break;
					case 'F':
						cout << COLOUR_YELLOW << 'F' <<
							DEFAULT_COLOUR;
						break;
					case 'G':
						cout << COLOUR_BLUE << 'G' <<
							DEFAULT_COLOUR;
						break;
					case 'H':
						cout << COLOUR_BLUE << 'H' <<
							DEFAULT_COLOUR;
						break;
					case 'I':
						cout << COLOUR_BLUE << 'I' <<
							DEFAULT_COLOUR;
						break;
					case 'J':
						cout << COLOUR_BLUE << 'J' <<
							DEFAULT_COLOUR;
						break;
					case -1:
						cout << ' ';
						break;
					
					default:
						break;
				}
				cout << "  ";
			}
			cout << '\n';
		}
		cout << endl;
	}

	void	Klotski::playUser(string move)
	{
		char	element;
		string	direction;

		/**
		 * element - direction
		 * 
		 */

		element = toupper(move[0]);
		direction = toupper(move[2]);

		if (this->isValidMove(element, direction))
			makeMove(element, direction);
		else
			cerr << "That was not a valid move" << endl;
	}
	
	void	Klotski::playAuto()
	{
		char	element;
		string	direction;

		srand(time(NULL));

		this->randValidMove(element, direction);
		this->makeMove(element, direction);
	}

	bool	Klotski::endGame() const
	{
		int	rowSize, colSize;

		rowSize = this->board.size();
		colSize = this->board[rowSize - 1].size();

		if (this->board[rowSize - 1][colSize - 3] == 'A' &&
			this->board[rowSize - 1][colSize - 2] == 'A')
			return (true);
		else
			return (false);
	}

	int	Klotski::boardScore() const
	{
		int	i, j;
		bool	isFind = false;
		int	rowSize, colSize;

		rowSize = this->board.size();
		colSize = this->board[rowSize - 1].size();

		for (i = 0; !isFind && i < rowSize; ++i)
			for (j = 0; !isFind && j < colSize; ++j)
				if (this->board[i][j] == 'A')
					isFind = true;
		i--;
		j--;

		return (sqrt(static_cast<float>((i - rowSize + 2) * (i - rowSize + 2) +
					(j - colSize + 3) * (j - colSize + 3))));
	}

	void	Klotski::gameInfo() const
	{
		cout << "Current board score is " << this->boardScore() << " Element - '-' - Direction(U, D, L, R)" << endl;
	}

	bool	Klotski::isValidMove(char element, string direction) const
	{
		bool	isValid = true;
		string	directions = "UDLR";
		int	i, j;
		
		if (element < 'A' || element > 'J')
			isValid = false;
		else if (direction == "U")
		{
			for (i = 0; isValid && i < this->board.size(); i++)
				for (j = 0; isValid && j < this->board[i].size(); j++)
					if (this->board[i][j] == element)
					{
						if (i == 0)
							isValid = false;
						else if (this->board[i - 1][j] != element &&
								this->board[i - 1][j] != -1)
							isValid = false;
					}
		}
		else if (direction == "D")
		{
			for (i = 0; isValid && i < this->board.size(); i++)
				for (j = 0; isValid && j < this->board[i].size(); j++)
					if (this->board[i][j] == element)
					{
						if (i == this->board.size() - 1)
							isValid = false;
						else if (this->board[i + 1][j] != element &&
								this->board[i + 1][j] != -1)
							isValid = false;
					}
		}
		else if (direction == "R")
		{
			for (i = 0; isValid && i < this->board.size(); i++)
				for (j = 0; isValid && j < this->board[i].size(); j++)
					if (this->board[i][j] == element)
					{
						if (j == this->board[i].size() - 1)
							isValid = false;
						else if (this->board[i][j + 1] != element &&
								this->board[i][j + 1] != -1)
							isValid = false;
					}
		}
		else if (direction == "L")
		{
			for (i = 0; isValid && i < this->board.size(); i++)
				for (j = 0; isValid && j < this->board[i].size(); j++)
					if (this->board[i][j] == element)
					{
						if (j == 0)
							isValid = false;
						else if (this->board[i][j - 1] != element &&
								this->board[i][j - 1] != -1)
							isValid = false;
					}
		}
		else if (directions.find(direction) == string::npos)
			isValid = false;

		return (isValid);
	}

	void	Klotski::makeMove(char element, string direction)
	{
		int	i, j;
		char	temp;

		if (direction == "U")
		{
			for (i = 1; i < this->board.size(); i++)
				for (j = 0; j < this->board[i].size(); j++)
					if (this->board[i][j] == element)
					{
						temp = this->board[i - 1][j];
						this->board[i - 1][j] = this->board[i][j];
						this->board[i][j] = temp;
					}
		}
		else if (direction == "D")
		{
			for (i = this->board.size() - 1; i >= 0; i--)
				for (j = this->board[i].size() - 1; j >= 0; j--)
					if (this->board[i][j] == element)
					{
						temp = this->board[i + 1][j];
						if (temp == -1 || temp == element)
						{
							this->board[i + 1][j] = this->board[i][j];
							this->board[i][j] = temp;
						}
					}
		}
		else if (direction == "L")
		{
			for (i = 0; i < this->board.size(); i++)
				for (j = 1; j < this->board[i].size(); j++)
					if (this->board[i][j] == element)
					{
						temp = this->board[i][j - 1];
						this->board[i][j - 1] = this->board[i][j];
						this->board[i][j] = temp;
					}
		}
		else if (direction == "R")
		{
			for (i = this->board.size() - 1; i >= 0; i--)
				for (j = this->board[i].size() - 2; j >= 0; j--)
					if (this->board[i][j] == element)
					{
						temp = this->board[i][j + 1];
						if (temp == -1 || temp == element)
						{
							this->board[i][j + 1] = this->board[i][j];
							this->board[i][j] = temp;
						}
					}
		}
	}

	void	Klotski::randValidMove(char& element, string& direction)
	{
		do
		{
			switch (rand() % 10)
			{
				case 1:
					element = 'A';
					break;
				case 2:
					element = 'B';
					break;
				case 3:
					element = 'C';
					break;
				case 4:
					element = 'D';
					break;
				case 5:
					element = 'E';
					break;
				case 6:
					element = 'F';
					break;
				case 7:
					element = 'G';
					break;
				case 8:
					element = 'I';
					break;
				case 9:
					element = 'J';
					break;
				case 0:
					element = 'H';
					break;
				
				default:
					break;
			}

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
		} while (!this->isValidMove(element, direction));
		
	}

	void	Klotski::writeFile()
	{
		fstream		file;
		file.open("KlotskiLog.txt", ios_base::app);

		int j;

		for (int i = 0; i < this->board.size(); i++)
		{
			for (j = 0; j < this->board[i].size(); j++)
			{
				switch (this->board[i][j])
				{
					case 'A':
						file << 'A';
						break;

					case 'B':
						file << 'B';
						break;
					case 'C':
						file << 'C';
						break;
					case 'D':
						file << 'D';
						break;
					case 'E':
						file << 'E';
						break;
					case 'F':
						file << 'F';
						break;
					case 'G':
						file << 'G';
						break;
					case 'H':
						file << 'H';
						break;
					case 'I':
						file << 'I';
						break;
					case 'J':
						file << 'J';
						break;
					case -1:
						file << ' ';
						break;
					
					default:
						break;
				}
				file << "  ";
			}
			file << '\n';
		}
		file << endl;

		file << "Current board score is " << this->boardScore() << " Element - '-' - Direction(U, D, L, R)" << endl;
		file << "-------------------------------------------------------------------------------------------------" << endl;

	}

	void	Klotski::setBoardType(int temp)
	{}
}