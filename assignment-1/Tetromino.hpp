#ifndef _TERMINO_HPP_
# define _TERMINO_HPP_

# include <vector>
# include <string>

// #define DEFAULT_COLOUR "\e[0m"
// #define CYAN_COLOUR "\e[0;48;2;0;255;255m"
// #define YELLOW_COLOUR "\e[0;48;2;255;255;0m"
// #define MAGENTA_COLOUR "\e[0;48;2;255;0;255m"
// #define BLUE_COLOUR "\e[0;48;2;0;0;255m"
// #define ORANGE_COLOUR "\e[0;48;2;255;129;0m"
// #define GREEN_COLOUR "\e[0;48;2;0;255;0m"
// #define RED_COLOUR "\e[0;48;2;255;0;0m"

using namespace	std;

enum class TetrominoType {
	I,
	O,
	T,
	J,
	L,
	S,
	Z,
	none
};

class	Tetromino
{
	public:
		Tetromino();
		Tetromino(TetrominoType);

		inline vector<vector<TetrominoType>>	getTetromino() const {return (tetrominoVec);};
		inline TetrominoType	getTetrominoType() const {return (tetrominoType);};
		
		/**
		 * @brief to initialize the vector
		 * 
		 */
		void	initialize(TetrominoType);

		/**
		 * @brief to rotate the tetromino (left and right)
		 * 
		 */
		void	rotate(string);


		/**
		 * @brief to print the current tetromino
		 * 
		 */
		void	print() const;

		/**
		 * @brief if the tetrominos can fit without any holes,
		 * it returns true, otherwise returns 0
		 * 
		 * @return true 
		 * @return false 
		 */
		bool	canFit(const Tetromino&, string);

		

	private:
		vector<vector<TetrominoType>>	tetrominoVec;
		TetrominoType	tetrominoType;
		/**
		 * @brief rotate 90 degree
		 * 
		 */
		void	rotate90();
};

#endif