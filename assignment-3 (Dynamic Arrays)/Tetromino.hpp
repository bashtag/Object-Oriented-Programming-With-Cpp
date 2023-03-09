#ifndef _TERMINO_HPP_
# define _TERMINO_HPP_

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
		Tetromino(const Tetromino&);
		~Tetromino();

		inline TetrominoType**	getTetromino() const {return (this->tetrominoArr);};
		inline TetrominoType	getTetrominoType() const {return (this->tetrominoType);};
		inline int	getRowSize() const {return (this->rowSize);};
		inline int	getColSize() const {return (this->colSize);};

		void	setTetrominoType(TetrominoType);
		
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


		TetrominoType*	operator[](int index);
		const TetrominoType*	operator[](int index) const;
		bool	operator!=(const Tetromino&) const;
		Tetromino&	operator=(const Tetromino&);

	private:
		TetrominoType	**tetrominoArr;
		TetrominoType	tetrominoType;
		int	rowSize, colSize;
		/**
		 * @brief rotate 90 degree
		 * 
		 */
		void	rotate90();
};

#endif