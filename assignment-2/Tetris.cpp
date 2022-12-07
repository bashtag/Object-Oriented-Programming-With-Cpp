#include "Tetris.hpp"

using namespace std;

Tetris::Tetris() : rowSize(0), colSize(0)
{}

Tetris::Tetris(int rowSize, int colSize)
{
	this->rowSize = rowSize;
	this->colSize = colSize;
	this->setyCursor(0);
	this->setxCursor(0);
	this->botTetColSize = 0;

	this->board.resize(this->rowSize);
	for (int i = 0; i < this->rowSize; i++)
		this->board[i].resize(this->colSize);
}

void	Tetris::takeTetrominos()
{
	this->tetros.takeTetrominos();
	this->tetros.horizontallyBestFit();
}

/**
 * @brief it adds tetromino to the beggining of the board
 * 
 * @param tetromino 
 */
void	Tetris::add(const Tetromino& tetromino)
{
	int y_cursor = this->getyCursor(), j, i;
	int	x_cursor = this->getxCursor();

	for (i = 0; i < tetromino.getRowSize(); ++i)
	{
		for (j = 0; j < tetromino[i].size(); ++j)
			this->board[i][y_cursor + j] = tetromino[i][j];
	}

	this->setyCursor(y_cursor + j);
	this->setxCursor(i);
	this->tetrominos.push_back(tetromino);
}

/**
 * @brief remove the tetromino
 * 
 * @param tetromino 
 */
void	Tetris::remove(const Tetromino& tetromino)
{
	int y_cursor = this->getyCursor(), i, j, tetrominoColSize, tetrominoRowSize;
	int x_cursor = this->getxCursor();

	tetrominoColSize = tetromino[0].size();
	tetrominoRowSize = tetromino.getRowSize();

	for (i = 0; i < tetrominoRowSize; ++i)
	{
		for (j = 0; j < tetromino[i].size(); ++j)
		{
			this->board[x_cursor - tetrominoRowSize + i][y_cursor - tetrominoColSize + j] = TetrominoType::none;
		}
	}
	this->setyCursor(y_cursor - tetrominoColSize);
	this->setxCursor(x_cursor - tetrominoRowSize);
	/* There isn't any push_back function or removing element from my vector that holds tetrominos.
		Because if I use remove function, then I will rotate tetromino.*/
}

/**
 * @brief one step down. Remove function is necessary before this function.
 * 
 * @param tetromino 
 */
void	Tetris::addDown(const Tetromino& tetromino)
{
	int y_cursor, x_cursor, i, j, tetColSize, tetRowSize;

	x_cursor = this->getxCursor();
	y_cursor = this->getyCursor();
	tetRowSize = tetromino.getRowSize();
	tetColSize = tetromino[0].size();

	for (i = 0; i < tetRowSize; ++i)
	{
		for (j = 0; j < tetColSize; ++j)
		{
			this->board[x_cursor + 1 + i][y_cursor + j] = tetromino[i][j];
		}
	}

	this->setxCursor(x_cursor + 1 + i);
	this->setyCursor(y_cursor + j);
}

/**
 * @brief fitting the bottom of the board
 * 
 * @return true 
 * @return false 
 */
bool	Tetris::fitBoard()
{
	int	boardRowSize, initColSize, k;
	decltype(boardRowSize)	boardColSize;
	bool	isThereSpace = false;

	boardRowSize = this->board.size();
	if (boardRowSize != 0)
	{
		boardColSize = this->board[0].size();
		initColSize = boardColSize;
	}

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
					isThereSpace = true;
					this->setyCursor(this->getyCursor() - 1);
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
					isThereSpace = true;
					this->setyCursor(this->getyCursor() - 1);
				}
			}
			
			for (k = 1; k <= 3; k++)
			{
				if (this->board[boardRowSize - k].size() < initColSize)
					this->board[boardRowSize - k].push_back(TetrominoType::none);
			}
			boardColSize--;
		}
	}

	return (isThereSpace);
}

/**
 * @brief Rotates and moves
 * 
 * @param index 
 * @return true 
 * @return false 
 */
bool	Tetris::fit(int index)
{
	int	x, y;

	x = this->getxCursor();
	y = this->getyCursor();
	if (this->tetrominos[index] != this->tetros.getTetrominos()[index])
	{
		this->remove(this->tetrominos[index]);
		this->tetrominos[index].rotate("R");
		this->add(this->tetrominos[index]);
		this->tetrominos.pop_back();
	}
	else
	{
		this->remove(this->tetrominos[index]);
		this->addDown(this->tetrominos[index]);
	}

	if (x_cursor != rowSize)
		return (true);
	else
		return (false);
}

/**
 * @brief animate for all tetrominos
 * 
 */
void	Tetris::animate()
{
	int	prevTetSize = tetros.getPrevTetrominos().size();

	this->printBoard();
	for (int i = 0; i < prevTetSize && getBotTetColSize() + tetros.getPrevTetrominos()[i][0].size() <= this->colSize; ++i)
	{
		this->add(tetros.getPrevTetrominos()[i]);
		this->clearScreen(this->board.size() + 3);
		this->printBoard();

		do
		{
			this->clearScreen(this->board.size() + 3);
			this->printBoard();
			this_thread::sleep_for(chrono::milliseconds(50));
		} while (this->fit(i));

		this->clearScreen(this->board.size() + 3);
		this->printBoard();
		this_thread::sleep_for(chrono::milliseconds(50));

		this->fitBoard();
		this->clearScreen(this->board.size() + 3);
		this->printBoard();

		this->calcBotTetColSize();
	}
}

/**
 * @brief animate for a single tetromino
 * 
 * @param index 
 */
void	Tetris::animate(int index)
{
	this->printBoard();
	this->add(tetros.getPrevTetrominos()[index]);
	this->clearScreen(this->board.size() + 3);
	this->printBoard();

	do{
		this->clearScreen(this->board.size() + 3);
		this->printBoard();
		this_thread::sleep_for(chrono::milliseconds(50));
	} while (this->fit(index));

	this->clearScreen(this->board.size() + 3);
	this->printBoard();
	this_thread::sleep_for(chrono::milliseconds(50));

	this->fitBoard();
	this->clearScreen(this->board.size() + 3);
	this->printBoard();

	this->calcBotTetColSize();
}

void	Tetris::printTetrominos() const
{
	for (Tetromino tetromino : this->tetrominos)
		tetromino.print();
}

void	Tetris::printBoard() const
{
	int	j;

	for (int i = 0; i < this->board.size() + 2; ++i)
	{
		for (j = 0; j < this->board[0].size() + 2; ++j)
		{
			if (i == 0 || j == 0 || i == this->board.size() + 1 || j == this->board[0].size() + 1)
				cout << GREY_COLOUR << "  ";
			else
			{
				switch (this->board[i - 1][j - 1])
				{
					case TetrominoType::I:
						cout << CYAN_COLOUR << "  ";
						break;

					case TetrominoType::O:
						cout << YELLOW_COLOUR << "  ";
						break;

					case TetrominoType::T:
						cout << MAGENTA_COLOUR << "  ";
						break;

					case TetrominoType::J:
						cout << BLUE_COLOUR << "  ";
						break;

					case TetrominoType::L:
						cout << ORANGE_COLOUR << "  ";
						break;

					case TetrominoType::S:
						cout << GREEN_COLOUR << "  ";
						break;

					case TetrominoType::Z:
						cout << RED_COLOUR << "  ";
						break;

					case TetrominoType::none:
						cout << "\e[0;48;2;20;20;20m" << "  ";
						break;

					default:
						break;
				}
			}
			cout << DEFAULT_COLOUR;
		}
		cout << '\n';
	}
	cout << endl;
}

void	Tetris::clearScreen(int row) const
{
	cout << "\e[" << row << "A";
	cout << "\e[G";
}

void	Tetris::calcBotTetColSize()
{
	int j;
	bool	isNotNone = false;

	this->botTetColSize = 0;
	for (int i = this->board.size() - 1; i >= this->board.size() - 2; --i)
	{
		isNotNone = false;
		for (j = this->board[i].size() - 1; j >= 0 && !isNotNone; --j)
		{
			if (this->board[i][j] != TetrominoType::none)
				isNotNone = true;
		}
		if (j != 0 && this->botTetColSize < j + 2)
			this->botTetColSize = j + 2;
	}
}

void	Tetris::takeOneTetromino(char type)
{
	tetros.addOneTetrominoAnFit(type);
}

/**
 * @brief checking the game is finished or not
 * 
 * @param index -> last tetromino
 * @param type -> if the user gives Q or if the size is not acceptable
 * @return true 
 * @return false 
 */
bool	Tetris::isGameFinished(int index, char type) const
{
	Tetromino	tetromino;
	if (type == 'Q')
		return (true);
	else if (index == 0)
		return (false);
	
	switch (type)
	{
		case 'I':
			tetromino = Tetromino(TetrominoType::I);
			break;

		case 'O':
			tetromino = Tetromino(TetrominoType::O);
			break;

		case 'T':
			tetromino = Tetromino(TetrominoType::T);
			break;

		case 'J':
			tetromino = Tetromino(TetrominoType::J);
			break;

		case 'L':
			tetromino = Tetromino(TetrominoType::L);
			break;

		case 'S':
			tetromino = Tetromino(TetrominoType::S);
			break;

		case 'Z':
			tetromino = Tetromino(TetrominoType::Z);
			break;

		default:
			break;
	}
	return (getBotTetColSize() + tetromino.getTetromino()[0].size() > this->colSize);
}

/**
 * @brief random char type generator
 * 
 * @return char 
 */
char	Tetris::randomChType()
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