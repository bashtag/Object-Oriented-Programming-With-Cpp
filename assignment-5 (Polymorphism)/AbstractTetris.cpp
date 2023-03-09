#include "AbstractTetris.hpp"

using namespace	std;

namespace	tg
{
	AbstractTetris::AbstractTetris() {}

	/**
	 * @brief to clear screen
	 * 
	 * @param row 
	 */
	void	AbstractTetris::clearScreen(int row)
	{
		cout << "\e[" << row << "A";
		cout << "\e[G";
		cout << "\e[J";
	}

	/**
	 * @brief random char type generator
	 * 
	 * @return char 
	 */
	char	AbstractTetris::randomChType()
	{
		char	randChar = 'I';

		switch (rand() % 7)
		{
			case 0:
				randChar = 'I';
				break;

			case 1:
				randChar = 'O';
				break;

			case 2:
				randChar = 'T';
				break;

			case 3:
				randChar = 'J';
				break;

			case 4:
				randChar = 'L';
				break;

			case 5:
				randChar = 'S';
				break;

			case 6:
				randChar = 'Z';
				break;
			
			default:
				break;
		}

		return (randChar);
	}
}
