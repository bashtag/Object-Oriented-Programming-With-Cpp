#include "Tetris.hpp"

using namespace std;

/**
 * @brief Construct a new Tetris:: Tetris object
 * 
 */
Tetris::Tetris() : rowSize(0), colSize(0), board(nullptr), tempTet('O')
{}

/**
 * @brief Construct a new Tetris:: Tetris object
 * 
 * @param rowSize 
 * @param colSize 
 */
Tetris::Tetris(int rowSize, int colSize)
{
	this->rowSize = rowSize;
	this->colSize = colSize;
	this->setyCursor(0);
	this->setxCursor(0);
	this->tempTet = Tetromino('O');

	this->board = new TetrominoType*[this->rowSize]();
	for (int i = 0; i < this->rowSize; i++)
		this->board[i] = new TetrominoType[this->colSize]();
	this->calcTopRowSize();
}

/**
 * @brief Destroy the Tetris:: Tetris object
 * 
 */
Tetris::~Tetris()
{
	if (this->board != nullptr)
	{
		for (int i = 0; i < this->rowSize; ++i)
			delete[] this->board[i];
		delete[] this->board;
	}
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
		for (j = 0; j < tetromino.getColSize(); ++j)
			if (tetromino[i][j] != TetrominoType::none)
				this->board[i][y_cursor + j] = tetromino[i][j];
	}

	this->setyCursor(y_cursor + j);
	this->setxCursor(i);
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

	tetrominoColSize = tetromino.getColSize();
	tetrominoRowSize = tetromino.getRowSize();

	for (i = 0; i < tetrominoRowSize; ++i)
	{
		for (j = 0; j < tetrominoColSize; ++j)
		{
			if (tetromino[i][j] != TetrominoType::none)
				this->board[x_cursor - tetrominoRowSize + i][y_cursor - tetrominoColSize + j] = TetrominoType::none;
		}
	}
	this->setyCursor(y_cursor - tetrominoColSize);
	this->setxCursor(x_cursor - tetrominoRowSize);
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
	tetColSize = tetromino.getColSize();

	for (i = 0; i < tetRowSize; ++i)
	{
		for (j = 0; j < tetColSize; ++j)
		{
			if (tetromino[i][j] != TetrominoType::none)
				this->board[x_cursor + 1 + i][y_cursor + j] = tetromino[i][j];
		}
	}

	this->setxCursor(x_cursor + 1 + i);
	this->setyCursor(y_cursor + j);
}

/**
 * @brief animate for a single tetromino
 * 
 * @param index 
 */
bool	Tetris::animate()
{
	char	rotation, buff;
	int	rotCount = 0, count = this->colSize;
	int	rowsToRemove = this->rowSize + 3;
	bool	overlap = false;

	while (!(rotation == 'N' || rotation == 'R' || rotation == 'L') && rotCount == 0)
	{
		cout << "Rotation and its count (\"(N-R-L)-(etc. 3)\") (N: none): ";
		++rowsToRemove;
		cin >> rotation;
		if (rotation != 'N' && rotation != 'n')
			cin >> buff >> rotCount;
		else
			rotCount = 1;
		cin.clear();
		cin.ignore(0x7fffffff, '\n');
		rotation = toupper(rotation);

		if (!(rotation != 'N' || rotation == 'R' || rotation == 'L') && rotCount == 0)
		{
			cerr << "wrong input" << endl;
			++rowsToRemove;
		}
	}

	if (rotation != 'N')
	{
		this->clearScreen(rowsToRemove);
		rowsToRemove = this->rowSize + 3;
		for (int i = 0; i < rotCount; ++i)
		{
			this->remove(this->tempTet);
			this->tempTet.rotate(string(1, rotation));
			this->add(this->tempTet);
			this->printBoard();
			this_thread::sleep_for(chrono::milliseconds(50));
			this->clearScreen(rowsToRemove);
		}
		this->printBoard();
		if (this->getTopRowSize() - this->tempTet.getRowSize() < 0)
			return (false);
	}

	do
	{
		cout << "a counting number for move to the right: ";
		++rowsToRemove;
		cin >>  count;
		cin.clear();
		cin.ignore(0x7fffffff, '\n');

		if (count + this->tempTet.getColSize() > this->colSize)
		{
			cerr << "wrong input" << endl;
			++rowsToRemove;
		}
	} while (count + this->tempTet.getColSize() > this->colSize);
	this->clearScreen(rowsToRemove);
	this->printBoard();

	this->remove(this->tempTet);
	this->setyCursor(count);
	this->add(this->tempTet);
	this_thread::sleep_for(chrono::milliseconds(50));

	this->clearScreen(this->rowSize + 3);
	this->printBoard();
	this_thread::sleep_for(chrono::milliseconds(50));
	do
	{
		this->remove(this->tempTet);
		if (this->areThereOverlap())
		{
			this->setxCursor(this->getxCursor() - 1);
			overlap = true;
		}
		this->addDown(this->tempTet);
		this->clearScreen(this->rowSize + 3);
		this->printBoard();
		this_thread::sleep_for(chrono::milliseconds(50));
	} while (!overlap);
	
	this->setyCursor(0);
	this->calcTopRowSize();
	return (true);
}

/**
 * @brief if is there any overlap among the board and tetromino
 * 
 * @return true 
 * @return false 
 */
bool	Tetris::areThereOverlap() const
{
	bool	areThere = false;
	int	x_cursor, y_cursor, tetColSize, tetRowSize, i, j;
	
	x_cursor = this->getxCursor();
	y_cursor = this->getyCursor();
	tetColSize = this->tempTet.getColSize();
	tetRowSize = this->tempTet.getRowSize();

	for (i = 0; !areThere && i < tetRowSize; ++i)
	{
		for (j = 0; !areThere && j < tetColSize; ++j)
		{
			if (x_cursor + 1 + i >= this->rowSize ||
				(this->board[x_cursor + 1 + i][y_cursor + j] != TetrominoType::none &&
				this->tempTet[i][j] != TetrominoType::none))
				areThere = true;
		}
	}

	return (areThere);
}

/**
 * @brief take one tetromino to the board
 * 
 * @param type 
 */
void	Tetris::takeOneTetromino(const char& type)
{
	this->tempTet = Tetromino(type);
	add(this->tempTet);
	this->printBoard();
}

/**
 * @brief printing board
 * 
 */
void	Tetris::printBoard() const
{
	int	j;

	for (int i = 0; i < this->rowSize + 2; ++i)
	{
		for (j = 0; j < this->colSize + 2; ++j)
		{
			if (i == 0 || j == 0 || i == this->rowSize + 1 || j == this->colSize + 1)
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

/**
 * @brief clearing screen
 * 
 * @param row 
 */
void	Tetris::clearScreen(int row) const
{
	cout << "\e[" << row << "A";
	cout << "\e[G";
	cout << "\e[J";
}

void	Tetris::calcTopRowSize()
{
	int j;
	bool	isNotNone = false;

	this->topRowSize = 0;
	for (int i = 0; !isNotNone && i < this->rowSize; ++i)
	{
		for (j = 0; !isNotNone && j < this->colSize; ++j)
			if (this->board[i][j] != TetrominoType::none)
			{
				this->topRowSize = i + 1;
				isNotNone = true;
			}
	}
	if (!isNotNone)
		this->topRowSize = this->rowSize;
}

Tetris&	Tetris::operator=(const Tetris& newTet)
{
	if (this->board == newTet.board)
		return (*this);

	int	j;
	if (this->board != nullptr)
	{
		for (int i = 0; i < this->rowSize; ++i)
			delete[] this->board[i];
		delete[] this->board;
	}

	this->rowSize = newTet.rowSize;
	this->colSize = newTet.colSize;
	this->setxCursor(0);
	this->setyCursor(0);
	this->tempTet = Tetromino('O');
	this->board = new TetrominoType*[this->rowSize]();
	for (int i = 0; i < this->rowSize; ++i)
	{
		this->board[i] = new TetrominoType[this->colSize]();
		for (j = 0; j < this->colSize; ++j)
			this->board[i][j] = newTet.board[i][j];
	}
	this->calcTopRowSize();	
	return (*this);
}

/**
 * @brief checking the game is finished or not
 * 
 * @param index -> last tetromino
 * @param type -> if the user gives Q or if the size is not acceptable
 * @return true 
 * @return false 
 */
bool	Tetris::isGameFinished(char type) const
{
	Tetromino	tetromino;
	if (type == 'Q')
		return (true);

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
	return (this->getTopRowSize() - tetromino.getRowSize() < 0);
}

/**
 * @brief to check the first row
 * 
 * @return true 
 * @return false 
 */
bool	Tetris::isGameFinished() const
{
	for (int i = 0; i < this->colSize; ++i)
		if (this->board[0][i] != TetrominoType::none)
			return (true);
	return (false);
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

Tetris&	Tetris::operator+=(const Tetromino& tetromino)
{
	this->add(tetromino);
	return (*this);
}