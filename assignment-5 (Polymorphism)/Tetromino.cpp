#include <iostream>
#include "Tetromino.hpp"

using namespace	std;

namespace	tg
{
	Tetromino::Tetromino()
	{}

	Tetromino::Tetromino(TetrominoType type)
	{
		this->tetrominoType = type;
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
}