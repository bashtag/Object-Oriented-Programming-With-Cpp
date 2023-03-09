#include <iostream>
#include "Tetromino.hpp"

using namespace	std;

Tetromino::Tetromino()
{
	this->rowSize = 0;
	this->colSize = 0;
	this->tetrominoArr = nullptr;
}

Tetromino::Tetromino(TetrominoType type)
{
	this->setTetrominoType(type);
	this->initialize(type);
}

Tetromino::Tetromino(char type)
{
	switch (type)
	{
		case 'I':
			this->setTetrominoType(TetrominoType::I);
			break;

		case 'O':
			this->setTetrominoType(TetrominoType::O);
			break;

		case 'T':
			this->setTetrominoType(TetrominoType::T);
			break;

		case 'J':
			this->setTetrominoType(TetrominoType::J);
			break;

		case 'L':
			this->setTetrominoType(TetrominoType::L);
			break;

		case 'S':
			this->setTetrominoType(TetrominoType::S);
			break;

		case 'Z':
			this->setTetrominoType(TetrominoType::Z);
			break;

		default:
			break;
	}
	this->initialize(this->getTetrominoType());
}

Tetromino::Tetromino(const Tetromino& tet)
{
	this->setTetrominoType(tet.getTetrominoType());
	this->initialize(tet.getTetrominoType());
}
Tetromino::~Tetromino()
{
	if (this->tetrominoArr != nullptr)
	{
		for (int i = 0; i < this->rowSize; ++i)
			delete[] this->tetrominoArr[i];
		delete[] this->tetrominoArr;
	}
}

void	Tetromino::setTetrominoType(TetrominoType type)
{
	if (type == TetrominoType::none)
		cerr << "Invalid type." << endl;
	else
		this->tetrominoType = type;
}

/**
 * @brief initialization of tetromino vector
 * 
 * @param type 
 */
void	Tetromino::initialize(TetrominoType type)
{
	switch (type)
	{
		case TetrominoType::I:
			this->rowSize = 1;
			this->colSize = 4;
			this->tetrominoArr = new TetrominoType*[1];
			this->tetrominoArr[0] = new TetrominoType[4];
			this->tetrominoArr[0][0] = TetrominoType::I;
			this->tetrominoArr[0][1] = TetrominoType::I;
			this->tetrominoArr[0][2] = TetrominoType::I;
			this->tetrominoArr[0][3] = TetrominoType::I;
			break;

		case TetrominoType::O:
			this->rowSize = 2;
			this->colSize = 2;
			this->tetrominoArr = new TetrominoType*[2];
			for (int i = 0; i < 2; ++i)
				this->tetrominoArr[i] = new TetrominoType[2];
			this->tetrominoArr[0][0] = TetrominoType::O;
			this->tetrominoArr[0][1] = TetrominoType::O;
			this->tetrominoArr[1][0] = TetrominoType::O;
			this->tetrominoArr[1][1] = TetrominoType::O;
			// this->tetrominoArr = {
			// 	{TetrominoType::O, TetrominoType::O},
			// 	{TetrominoType::O, TetrominoType::O}
			// };
			break;

		case TetrominoType::T:
			this->rowSize = 2;
			this->colSize = 3;
			this->tetrominoArr = new TetrominoType*[2];
			for (int i = 0; i < 2; ++i)
				this->tetrominoArr[i] = new TetrominoType[3];
			this->tetrominoArr[0][0] = TetrominoType::T;
			this->tetrominoArr[0][1] = TetrominoType::T;
			this->tetrominoArr[0][2] = TetrominoType::T;
			this->tetrominoArr[1][0] = TetrominoType::none;
			this->tetrominoArr[1][1] = TetrominoType::T;
			this->tetrominoArr[1][2] = TetrominoType::none;
			// this->tetrominoArr = {
			// 	{TetrominoType::T, TetrominoType::T, TetrominoType::T},
			// 	{TetrominoType::none, TetrominoType::T, TetrominoType::none}
			// };
			break;

		case TetrominoType::J:
			this->rowSize = 3;
			this->colSize = 2;
			this->tetrominoArr = new TetrominoType*[3];
			for (int i = 0; i < 3; ++i)
				this->tetrominoArr[i] = new TetrominoType[2];
			this->tetrominoArr[0][0] = TetrominoType::none;
			this->tetrominoArr[0][1] = TetrominoType::J;
			this->tetrominoArr[1][0] = TetrominoType::none;
			this->tetrominoArr[1][1] = TetrominoType::J;
			this->tetrominoArr[2][0] = TetrominoType::J;
			this->tetrominoArr[2][1] = TetrominoType::J;
			// this->tetrominoArr = {
			// 	{TetrominoType::none, TetrominoType::J},
			// 	{TetrominoType::none, TetrominoType::J},
			// 	{TetrominoType::J, TetrominoType::J}
			// };
			break;

		case TetrominoType::L:
			this->rowSize = 3;
			this->colSize = 2;
			this->tetrominoArr = new TetrominoType*[3];
			for (int i = 0; i < 3; ++i)
				this->tetrominoArr[i] = new TetrominoType[2];
			this->tetrominoArr[0][0] = TetrominoType::L;
			this->tetrominoArr[0][1] = TetrominoType::none;
			this->tetrominoArr[1][0] = TetrominoType::L;
			this->tetrominoArr[1][1] = TetrominoType::none;
			this->tetrominoArr[2][0] = TetrominoType::L;
			this->tetrominoArr[2][1] = TetrominoType::L;
			// this->tetrominoArr = {
			// 	{TetrominoType::L, TetrominoType::none},
			// 	{TetrominoType::L, TetrominoType::none},
			// 	{TetrominoType::L, TetrominoType::L}
			// };
			break;

		case TetrominoType::S:
			this->rowSize = 2;
			this->colSize = 3;
			this->tetrominoArr = new TetrominoType*[2];
			for (int i = 0; i < 2; ++i)
				this->tetrominoArr[i] = new TetrominoType[3];
			this->tetrominoArr[0][0] = TetrominoType::none;
			this->tetrominoArr[0][1] = TetrominoType::S;
			this->tetrominoArr[0][2] = TetrominoType::S;
			this->tetrominoArr[1][0] = TetrominoType::S;
			this->tetrominoArr[1][1] = TetrominoType::S;
			this->tetrominoArr[1][2] = TetrominoType::none;
			// this->tetrominoArr = {
			// 	{TetrominoType::none, TetrominoType::S, TetrominoType::S},
			// 	{TetrominoType::S, TetrominoType::S, TetrominoType::none}
			// };
			break;

		case TetrominoType::Z:
			this->rowSize = 2;
			this->colSize = 3;
			this->tetrominoArr = new TetrominoType*[2];
			for (int i = 0; i < 2; ++i)
				this->tetrominoArr[i] = new TetrominoType[3];
			this->tetrominoArr[0][0] = TetrominoType::Z;
			this->tetrominoArr[0][1] = TetrominoType::Z;
			this->tetrominoArr[0][2] = TetrominoType::none;
			this->tetrominoArr[1][0] = TetrominoType::none;
			this->tetrominoArr[1][1] = TetrominoType::Z;
			this->tetrominoArr[1][2] = TetrominoType::Z;
			// this->tetrominoArr = {
			// 	{TetrominoType::Z, TetrominoType::Z, TetrominoType::none},
			// 	{TetrominoType::none, TetrominoType::Z, TetrominoType::Z}
			// };
			break;
		
		default:
			break;
	}
}

/**
 * @brief L - R
 * 
 * @param direction 
 */
void	Tetromino::rotate(string direction)
{
	if (direction == "L")
	{
		/* to rotate the tetromino left */
		this->rotate90();
		this->rotate90();
		this->rotate90();
	}
	else if (direction == "R")
	{
		this->rotate90();
	}

}

/**
 * @brief rotate 90 degree
 * 
 */
void	Tetromino::rotate90()
{
	TetrominoType**	newTetromino = nullptr;
	int	newRowSize, newColSize, j;

	/* old column size */
	newRowSize = this->colSize;

	/* old row size */
	newColSize = this->rowSize;
	newTetromino = new TetrominoType*[newRowSize];

	for (int i = 0; i < newRowSize; i++)
	{
		newTetromino[i] = new TetrominoType[newColSize];
		for (j = 0; j < newColSize; j++)
			newTetromino[i][j] = tetrominoArr[newColSize - j - 1][i];
	}

	for (int i = 0; i < this->rowSize; ++i)
		delete[] this->tetrominoArr[i];
	delete[] this->tetrominoArr;
	this->tetrominoArr = nullptr;

	this->colSize = newColSize;
	this->rowSize = newRowSize;

	this->tetrominoArr = newTetromino;
}

/**
 * @brief to print any tetromino
 * 
 */
void	Tetromino::print() const
{
	int	j;

	for (int i = 0; i < this->rowSize; ++i)
	{
		for (j = 0; j < this->colSize; ++j)
		{
				switch (this->tetrominoType)
				{
					case TetrominoType::I:
						cout << CYAN_COLOUR;
						break;

					case TetrominoType::O:
						cout << YELLOW_COLOUR;
						break;

					case TetrominoType::T:
						cout << MAGENTA_COLOUR;
						break;

					case TetrominoType::J:
						cout << BLUE_COLOUR;
						break;

					case TetrominoType::L:
						cout << ORANGE_COLOUR;
						break;

					case TetrominoType::S:
						cout << GREEN_COLOUR;
						break;

					case TetrominoType::Z:
						cout << RED_COLOUR;
						break;

					default:
						break;
				}
				if (this->tetrominoArr[i][j] != TetrominoType::none)
					cout << "  " << DEFAULT_COLOUR;
				else
					cout << DEFAULT_COLOUR << "  ";
		}
		cout << '\n';
	}
	cout << endl;
}

TetrominoType*	Tetromino::operator[](int index)
{
	return (this->tetrominoArr[index]);
}

const TetrominoType*	Tetromino::operator[](int index) const
{
	return (this->tetrominoArr[index]);
}

bool	Tetromino::operator!=(const Tetromino& tetromino) const
{
	bool	isEqual = true;
	if (this->tetrominoType != tetromino.tetrominoType)
		isEqual = false;
	else if (this->colSize != tetromino.colSize ||
			this->rowSize != tetromino.rowSize)
		isEqual = false;
	else
	{
		int j;
		for (int i = 0; i < this->rowSize; ++i)
			for (j = 0; j < this->colSize; ++j)
				if (this->tetrominoArr[i][j] != tetromino.tetrominoArr[i][j])
					isEqual = false;
	}

	return (!isEqual);
}

Tetromino&	Tetromino::operator=(const Tetromino& tetromino)
{
	if (this->tetrominoArr == tetromino.tetrominoArr)
		return (*this);

	int	j;
	if (this->tetrominoArr != nullptr)
	{
		for (int i = 0; i < this->rowSize; ++i)
			delete[] this->tetrominoArr[i];
		delete[] this->tetrominoArr;
	}

	this->rowSize = tetromino.rowSize;
	this->colSize = tetromino.colSize;
	this->tetrominoArr = new TetrominoType*[this->rowSize]();
	for (int i = 0; i < this->rowSize; ++i)
	{
		this->tetrominoArr[i] = new TetrominoType[this->colSize]();
		for (j = 0; j < this->colSize; ++j)
			this->tetrominoArr[i][j] = tetromino.tetrominoArr[i][j];
	}
	
	return (*this);
}