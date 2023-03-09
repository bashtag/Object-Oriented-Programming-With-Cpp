#ifndef TETROMINO_HPP
# define TETROMINO_HPP

# include <vector>
# include <string>

# define DEFAULT_COLOUR "\e[0m"
# define CYAN_COLOUR "\e[0;48;2;0;255;255m"
# define YELLOW_COLOUR "\e[0;48;2;255;255;0m"
# define MAGENTA_COLOUR "\e[0;48;2;255;0;255m"
# define BLUE_COLOUR "\e[0;48;2;0;0;255m"
# define ORANGE_COLOUR "\e[0;48;2;255;129;0m"
# define GREEN_COLOUR "\e[0;48;2;0;255;0m"
# define RED_COLOUR "\e[0;48;2;255;0;0m"
# define GREY_COLOUR "\e[0;48;2;80;80;80m"

using namespace	std;

namespace	tg
{
	enum class TetrominoType : char {
		none,
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
			Tetromino(char); /* type */

			inline vector<vector<TetrominoType>>	getTetromino() const {return (tetrominoVec);};
			inline TetrominoType	getTetrominoType() const {return (tetrominoType);};
			inline int	getRowSize() const {return (tetrominoVec.size());};
			inline int	getColSize() const {return (tetrominoVec[0].size());};
			
			void	setTetrominoType(TetrominoType type);
			
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

			vector<TetrominoType>&	operator[](int index);
			const vector<TetrominoType>&	operator[](int index) const;
			bool	operator!=(const Tetromino&);

		private:
			vector<vector<TetrominoType>>	tetrominoVec;
			TetrominoType	tetrominoType;
			/**
			 * @brief rotate 90 degree
			 * 
			 */
			void	rotate90();
	};
}

#endif