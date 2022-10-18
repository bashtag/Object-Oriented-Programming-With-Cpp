#ifndef _TERMINO_HPP_
#define _TERMINO_HPP_

#include <vector>

#define DEFAULT_COLOUR "\e[0m"
#define CYAN_COLOUR "\e[0;48;2;0;255;255m"
#define YELLOW_COLOUR "\e[0;48;2;255;255;0m"
#define MAGENTA_COLOUR "\e[0;48;2;255;0;255m"
#define BLUE_COLOUR "\e[0;48;2;0;0;255m"
#define ORANGE_COLOUR "\e[0;48;2;255;129;0m"
#define GREEN_COLOUR "\e[0;48;2;0;255;0m"
#define RED_COLOUR "\e[0;48;2;255;0;0m"

enum class TetrominoType {
	I,
	O,
	T,
	J,
	L,
	S,
	Z
};

class	Tetromino
{
	public:
		Tetromino();
		Tetromino(TetrominoType);

		/**
		 * @brief to rotate the tetromino (left and right)
		 * 
		 */
		void	rotate(int);

		/**
		 * @brief to print the current tetromino
		 * 
		 */
		void	print();

		

	private:
		vector<vector<TetrominoType>>	tetrominoPieces;

};

#endif