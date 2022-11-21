#include "Tetros.hpp"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

Tetros::Tetros()
{
	this->tetrominoSize = 0;
}

/**
 * @brief to take tetrominos into the tetromino vector
 * 
 */
void	Tetros::takeTetrominos()
{
	char	givenType;
	string	typeHandle = "IOTJLSZ";

	while (this->tetrominoSize <= 0)
	{
		cout << "How many tetrominos?" << endl;
		cin >> this->tetrominoSize;
		cin.clear();
		cin.ignore(0x7fffffff, '\n');

		if (this->tetrominoSize <= 0)
			cerr << "Give me a valid input." << endl;
	}
	

	/* Preallocate memory */
	this->tetrominos.resize(this->tetrominoSize);

	cout << "What are the types?(I, O, T, L, J, S, Z)" << endl;
	for (int i = 0; i < this->tetrominoSize; i++)
	{
		cin >> givenType;
		givenType = toupper(givenType);

		if (typeHandle.find(givenType) == string::npos)
		{
			cerr << "Give me a valid type" << endl;
			i--;
		}
		else
			switch (givenType)
			{
				case 'I':
					this->tetrominos[i] = Tetromino(TetrominoType::I);
					break;

				case 'O':
					this->tetrominos[i] = Tetromino(TetrominoType::O);
					break;

				case 'T':
					this->tetrominos[i] = Tetromino(TetrominoType::T);
					break;

				case 'J':
					this->tetrominos[i] = Tetromino(TetrominoType::J);
					break;

				case 'L':
					this->tetrominos[i] = Tetromino(TetrominoType::L);
					break;

				case 'S':
					this->tetrominos[i] = Tetromino(TetrominoType::S);
					break;

				case 'Z':
					this->tetrominos[i] = Tetromino(TetrominoType::Z);
					break;

				default:
					break;
			}
	}

	this->previousTetrominos = this->tetrominos;
}

void	Tetros::addOneTetrominoAnFit(char type)
{
	switch (type)
	{
		case 'I':
			this->tetrominos.push_back(Tetromino(TetrominoType::I));
			this->previousTetrominos.push_back(Tetromino(TetrominoType::I));
			break;

		case 'O':
			this->tetrominos.push_back(Tetromino(TetrominoType::O));
			this->previousTetrominos.push_back(Tetromino(TetrominoType::O));
			break;

		case 'T':
			this->tetrominos.push_back(Tetromino(TetrominoType::T));
			this->previousTetrominos.push_back(Tetromino(TetrominoType::T));
			break;

		case 'J':
			this->tetrominos.push_back(Tetromino(TetrominoType::J));
			this->previousTetrominos.push_back(Tetromino(TetrominoType::J));
			break;

		case 'L':
			this->tetrominos.push_back(Tetromino(TetrominoType::L));
			this->previousTetrominos.push_back(Tetromino(TetrominoType::L));
			break;

		case 'S':
			this->tetrominos.push_back(Tetromino(TetrominoType::S));
			this->previousTetrominos.push_back(Tetromino(TetrominoType::S));
			break;

		case 'Z':
			this->tetrominos.push_back(Tetromino(TetrominoType::Z));
			this->previousTetrominos.push_back(Tetromino(TetrominoType::Z));
			break;

		default:
			break;
	}
	++(this->tetrominoSize);

	this->board.clear();
	this->horizontallyBestFit();
}

/**
 * @brief to print tetrominos vertically
 * 
 */
void	Tetros::printTetrominos() const
{
	for (Tetromino tetromino : this->tetrominos)
		tetromino.print();
}

/**
 * @brief to process all the necessary functions for the horizontally best fit
 * 
 */
void	Tetros::horizontallyBestFit()
{
	int j; /* it solves infinite loop problem */

	this->addHorizontally(this->tetrominos[0]);
	for (int i = 0; i + 1 < this->tetrominoSize; i++)
	{
		for (j = 0; j < 4 && !(this->tetrominos[i].canFit(this->tetrominos[i + 1], "R")); j++)
			this->tetrominos[i + 1].rotate("R");
		this->addHorizontally(this->tetrominos[i + 1]);
	}
	this->fitBoard();
}

/**
 * @brief 
 * 
 * @param tetromino 
 */
void	Tetros::addHorizontally(const Tetromino& tetromino)
{
	int	i, j, boardRowSize, boardColSize, tetRowSize, tetColSize;

	boardRowSize = this->board.size();
	tetRowSize = tetromino.getRowSize();
	tetColSize = tetromino[0].size();

	/**
	 * @brief if the board doesn't consist any tetromino, then initialize the board using relative tetromino
	 * 
	 */
	if (boardRowSize == 0)
	{
		switch (tetromino.getTetrominoType())
		{
			case TetrominoType::I:
				this->board = {
					{TetrominoType::I, TetrominoType::I, TetrominoType::I, TetrominoType::I}
				};
				break;

			case TetrominoType::O:
				this->board = {
					{TetrominoType::O, TetrominoType::O},
					{TetrominoType::O, TetrominoType::O}
				};
				break;

			case TetrominoType::T:
				this->board = {
					{TetrominoType::T, TetrominoType::T, TetrominoType::T},
					{TetrominoType::none, TetrominoType::T, TetrominoType::none}
				};
				break;

			case TetrominoType::J:
				this->board = {
					{TetrominoType::none, TetrominoType::J},
					{TetrominoType::none, TetrominoType::J},
					{TetrominoType::J, TetrominoType::J}
				};
				break;

			case TetrominoType::L:
				this->board = {
					{TetrominoType::L, TetrominoType::none},
					{TetrominoType::L, TetrominoType::none},
					{TetrominoType::L, TetrominoType::L}
				};
				break;

			case TetrominoType::S:
				this->board = {
					{TetrominoType::none, TetrominoType::S, TetrominoType::S},
					{TetrominoType::S, TetrominoType::S, TetrominoType::none}
				};
				break;

			case TetrominoType::Z:
				this->board = {
					{TetrominoType::Z, TetrominoType::Z, TetrominoType::none},
					{TetrominoType::none, TetrominoType::Z, TetrominoType::Z}
				};
				break;
			
			default:
				break;
		}
	}
	else
	{
		/* Increase the row size if relative tetromino is longer than board */
		while (tetRowSize > this->board.size())
			this->board.insert(this->board.begin(), vector<TetrominoType>(this->board[0].size(), TetrominoType::none));

		boardRowSize = this->board.size();

		/* Increase the column size using relative tetromino's width */
		for (i = 0; i < boardRowSize; i++)
			for (j = 0; j < tetColSize; j++)
			this->board[i].push_back(TetrominoType::none);

		boardColSize = this->board[0].size();

		/* Put the tetromino to the board */
		for (i = 0; i < tetRowSize; i++)
			for (j = 0; j < tetColSize; j++)
				this->board[boardRowSize - tetRowSize + i][boardColSize - tetColSize + j] = tetromino[i][j];
	}
}

// otltsstzlt
/**
 * @brief to fit the Tetros board.
 *  It deletes spaces that mustn't be.
 * 
 */
void	Tetros::fitBoard()
{
	int	boardRowSize, j, k;
	decltype(boardRowSize)	boardColSize;

	boardRowSize = this->board.size();
	if (boardRowSize != 0)
		boardColSize = this->board[0].size();

	for (int i = 1; i + 1 < boardColSize; i++)
	{
		/**
		 * @brief this algorithm is also handles SZ situation.
		 * It looks the last two rows.
		 * I use my brute force algorithm.
		 */
		if (this->board[boardRowSize - 1][i] == TetrominoType::none &&
			!(this->board[boardRowSize - 2][i] != TetrominoType::none &&
			this->board[boardRowSize - 2][i + 1] != TetrominoType::none &&
			this->board[boardRowSize - 2][i - 1] != TetrominoType::none))
		{
			if (this->board[boardRowSize - 1][i + 1] != TetrominoType::none)
			{
				if (this->board[boardRowSize - 2][i - 1] == TetrominoType::none)
				{
					this->board[boardRowSize - 1].erase(this->board[boardRowSize - 1].begin() + i);
					this->board[boardRowSize - 2].erase(this->board[boardRowSize - 2].begin() + i - 1);
					/* Handle the rows except two last row */
					if (boardRowSize > 2)
					{
						for (k = i - 1; this->board[boardRowSize - 3][k] != TetrominoType::none && k + 1 < boardColSize; k++);
						this->board[boardRowSize - 3].erase(this->board[boardRowSize - 3].begin() + k);
					}
				}
				else if (this->board[boardRowSize - 2][i + 1] == TetrominoType::none)
				{
					this->board[boardRowSize - 1].erase(this->board[boardRowSize - 1].begin() + i);
					this->board[boardRowSize - 2].erase(this->board[boardRowSize - 2].begin() + i + 1);
					/* Handle the rows except two last row */
					if (boardRowSize > 2)
					{
						for (k = i + 1; this->board[boardRowSize - 3][k] != TetrominoType::none && k + 1 < boardColSize; k++);
						this->board[boardRowSize - 3].erase(this->board[boardRowSize - 3].begin() + k);
					}
				}
			}
			boardColSize--;
		}
	}
}

/**
 * @brief to print the Tetros board
 * 
 */
void	Tetros::printBoard() const
{
	for (auto singleRow : this->board)
	{
		for (auto element : singleRow)
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
		cout << '\n';
	}
	cout << endl; /* endl is here because it cleans the buffer */
}
