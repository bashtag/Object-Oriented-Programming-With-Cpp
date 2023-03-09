#ifndef ABSTRACTTETRIS_HPP
# define ABSTRACTTETRIS_HPP

# include <iostream>
# include <string>
# include <thread>
# include <chrono>
# include <ctime>
# include <cstdlib>
# include <fstream>
# include <vector>
# include "Tetromino.hpp"

using namespace	std;

namespace	tg
{
	typedef struct
	{
		TetrominoType	type;
		char	rotation;
		int		rotNum;
		char	direction;
		int		dirNum;
	} move;

	class	AbstractTetris
	{
		public:
			AbstractTetris();

			virtual void	draw() const = 0;
			virtual void	readFromFile(string) = 0; /* filename */
			virtual void	writeToFile(string) const = 0; /* filename */
			virtual void	operator+=(const Tetromino&) = 0;
			virtual bool	animate() = 0;
			virtual move	lastMove() = 0;
			virtual int	numberOfMoves() = 0;
			virtual void	takeOneTetromino(const char&) = 0;
			virtual bool	isGameFinished() const = 0; /* it looks only first row of the board */
			virtual bool	isGameFinished(char type) const = 0; /* it takes index for last tetromino and a type for if the size is OK or not*/
			
			static char	randomChType(); /* random type generator */
			static void	clearScreen(int); /* to clear screen with given row size */
	};
}

#endif