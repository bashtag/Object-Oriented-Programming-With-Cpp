#include <iostream>
#include "Tetromino.hpp"

using namespace	std;

Tetromino::Tetromino()
{}

Tetromino::Tetromino(TetrominoType type)
{
	this->tetrominoType = type;
	this->initialize(type);
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
			this->tetrominoVec = {
				{TetrominoType::I, TetrominoType::I, TetrominoType::I, TetrominoType::I}
			};
			break;

		case TetrominoType::O:
			this->tetrominoVec = {
				{TetrominoType::O, TetrominoType::O},
				{TetrominoType::O, TetrominoType::O}
			};
			break;

		case TetrominoType::T:
			this->tetrominoVec = {
				{TetrominoType::T, TetrominoType::T, TetrominoType::T},
				{TetrominoType::none, TetrominoType::T, TetrominoType::none}
			};
			break;

		case TetrominoType::J:
			this->tetrominoVec = {
				{TetrominoType::none, TetrominoType::J},
				{TetrominoType::none, TetrominoType::J},
				{TetrominoType::J, TetrominoType::J}
			};
			break;

		case TetrominoType::L:
			this->tetrominoVec = {
				{TetrominoType::L, TetrominoType::none},
				{TetrominoType::L, TetrominoType::none},
				{TetrominoType::L, TetrominoType::L}
			};
			break;

		case TetrominoType::S:
			this->tetrominoVec = {
				{TetrominoType::none, TetrominoType::S, TetrominoType::S},
				{TetrominoType::S, TetrominoType::S, TetrominoType::none}
			};
			break;

		case TetrominoType::Z:
			this->tetrominoVec = {
				{TetrominoType::Z, TetrominoType::Z, TetrominoType::none},
				{TetrominoType::none, TetrominoType::Z, TetrominoType::Z}
			};
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
	vector<vector<TetrominoType>>	newTetromino;
	int	newRowSize, newColSize, j;

	/* old column size */
	newRowSize = tetrominoVec[0].size();

	/* old row size */
	newColSize = tetrominoVec.size();
	newTetromino.resize(newRowSize);

	for (int i = 0; i < newRowSize; i++)
	{
		newTetromino[i].resize(newColSize);
		for (j = 0; j < newColSize; j++)
			newTetromino[i][j] = tetrominoVec[newColSize - j - 1][i];
	}

	this->tetrominoVec = newTetromino;
}

/**
 * @brief to print any tetromino
 * 
 */
void	Tetromino::print() const
{
	for (vector<TetrominoType> singleRow : this->tetrominoVec)
	{
		for (auto element : singleRow)
		{
				switch (element)
				{
					case TetrominoType::I:
						cout << 'I';
						break;

					case TetrominoType::O:
						cout << 'O';
						break;

					case TetrominoType::T:
						cout << 'T';
						break;

					case TetrominoType::J:
						cout << 'J';
						break;

					case TetrominoType::L:
						cout << 'L';
						break;

					case TetrominoType::S:
						cout << 'S';
						break;

					case TetrominoType::Z:
						cout << 'Z';
						break;

					case TetrominoType::none:
						cout << ' ';
						break;

					default:
						break;
				}
		}
		cout << '\n';
	}
	cout << endl;
}

/**
 * @brief can two tetrominos fit horizontally?
 * 
 * @param tetromino 
 * @param position 
 * @return true 
 * @return false 
 */
bool	Tetromino::canFit(const Tetromino& tetromino, const string position)
{
	bool	checkFit = false;
	int	thisColSize, thisRowSize, tetColSize, tetRowSize;

	thisRowSize = this->tetrominoVec.size();
	thisColSize = this->tetrominoVec[0].size();
	tetRowSize = tetromino.getTetromino().size();
	tetColSize = tetromino.getTetromino()[0].size();

	/**
	 * @brief this algorithm looks at the cross area of the collobration of two tetrominos
	 * 
	 */
	if (position == "R")
	{
		if (this->tetrominoVec[thisRowSize - 1][thisColSize - 1] == TetrominoType::none &&
				tetromino.getTetromino()[tetRowSize - 1][0] != TetrominoType::none)
		{
			if ((thisRowSize < 2 || this->tetrominoVec[thisRowSize - 2][thisColSize - 1] == TetrominoType::none) &&
					(tetRowSize < 2 || tetromino.getTetromino()[tetRowSize - 2][0] != TetrominoType::none))
				checkFit = true;
			else if ((thisRowSize < 2 || this->tetrominoVec[thisRowSize - 2][thisColSize - 1] != TetrominoType::none) &&
					(tetRowSize < 2 || tetromino.getTetromino()[tetRowSize - 2][0] == TetrominoType::none))
				checkFit = true;
			else
				checkFit = false;
		}
		else if (this->tetrominoVec[thisRowSize - 1][thisColSize - 1] != TetrominoType::none &&
				tetromino.getTetromino()[tetRowSize - 1][0] == TetrominoType::none)
		{
			if ((thisRowSize < 2 || this->tetrominoVec[thisRowSize - 2][thisColSize - 1] == TetrominoType::none) &&
					(tetRowSize < 2 || tetromino.getTetromino()[tetRowSize - 2][0] != TetrominoType::none))
				checkFit = true;
			else if ((thisRowSize < 2 || this->tetrominoVec[thisRowSize - 2][thisColSize - 1] != TetrominoType::none) &&
					(tetRowSize < 2 || tetromino.getTetromino()[tetRowSize - 2][0] == TetrominoType::none))
				checkFit = true;
			else
				checkFit = false;
		}
		else if (this->tetrominoVec[thisRowSize - 1][thisColSize - 1] != TetrominoType::none &&
				tetromino.getTetromino()[tetRowSize - 1][0] != TetrominoType::none)
			checkFit = true;
	}
	else if (position == "L") /* Left posisition */
	{
		if (tetromino.getTetromino()[thisRowSize - 1][thisColSize - 1] == TetrominoType::none &&
				this->tetrominoVec[tetRowSize - 1][0] != TetrominoType::none)
		{
			if ((tetRowSize < 2 || tetromino.getTetromino()[thisRowSize - 2][thisColSize - 1] == TetrominoType::none) &&
					(thisRowSize < 2 || this->tetrominoVec[tetRowSize - 2][0] != TetrominoType::none))
				checkFit = true;
			else if ((tetRowSize < 2 || tetromino.getTetromino()[thisRowSize - 2][thisColSize - 1] != TetrominoType::none) &&
					(thisRowSize < 2 || this->tetrominoVec[tetRowSize - 2][0] == TetrominoType::none))
				checkFit = true;
			else
				checkFit = false;
		}
		else if (tetromino.getTetromino()[thisRowSize - 1][thisColSize - 1] != TetrominoType::none &&
				this->tetrominoVec[tetRowSize - 1][0] == TetrominoType::none)
		{
			if ((tetRowSize < 2 || tetromino.getTetromino()[thisRowSize - 2][thisColSize - 1] == TetrominoType::none) &&
					(thisRowSize < 2 || this->tetrominoVec[tetRowSize - 2][0] != TetrominoType::none))
				checkFit = true;
			else if ((tetRowSize < 2 || tetromino.getTetromino()[thisRowSize - 2][thisColSize - 1] != TetrominoType::none) &&
					(thisRowSize < 2 || this->tetrominoVec[tetRowSize - 2][0] == TetrominoType::none))
				checkFit = true;
			else
				checkFit = false;
		}
		else if (tetromino.getTetromino()[thisRowSize - 1][thisColSize - 1] != TetrominoType::none &&
				this->tetrominoVec[tetRowSize - 1][0] != TetrominoType::none)
			checkFit = true;
	}

	return (checkFit);
}

vector<TetrominoType>&	Tetromino::operator[](int index)
{
	return (this->tetrominoVec[index]);
}

const vector<TetrominoType>&	Tetromino::operator[](int index) const
{
	return (this->tetrominoVec[index]);
}

bool	Tetromino::operator!=(const Tetromino& tetromino)
{
	return (this->getTetromino() != tetromino.getTetromino());
}