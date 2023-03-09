#include "TetrisVector.hpp"

using namespace	std;

namespace	tg
{
	/**
	 * @brief Construct a new TetrisVector:: TetrisVector object
	 * 
	 */
	TetrisVector::TetrisVector() : rowSize(0), colSize(0), tempTet('O'), numOfMoves(0)
	{}

	/**
	 * @brief Construct a new TetrisVector:: TetrisVector object
	 * 
	 * @param rowSize 
	 * @param colSize 
	 */
	TetrisVector::TetrisVector(int rowSize, int colSize)
	{
		this->rowSize = rowSize;
		this->colSize = colSize;
		this->setyCursor(0);
		this->setxCursor(0);
		this->tempTet = Tetromino('O');
		this->numOfMoves = 0;

		this->board.resize(this->rowSize);
		for (int i = 0; i < this->rowSize; i++)
			this->board[i].resize(this->colSize);
		this->calcTopRowSize();
	}

	/**
	 * @brief Construct a new Tetris Vector:: Tetris Vector object from given file
	 * 
	 * @param fileName 
	 */
	TetrisVector::TetrisVector(string fileName, int& rowSize, int& colSize)
	{
		this->setxCursor(0);
		this->setyCursor(0);
		this->tempTet = Tetromino('O');
		this->numOfMoves = 0;

		this->readFromFile(fileName);
		this->rowSize = this->board.size();
		this->colSize = this->board[0].size();

		rowSize = this->rowSize;
		colSize = this->colSize;
		this->calcTopRowSize();
	}

	/**
	 * @brief Set a new Tetris Vector::sety Cursor object
	 * 
	 * @param newY 
	 */
	void	TetrisVector::setyCursor(int newY)
	{
		if (newY <= colSize)
			this->y_cursor = newY;
		else
			throw	invalid_argument("Invalid Argument to set y cursor");
	}

	/**
	 * @brief Set a new Tetris Vector::setx Cursor object
	 * 
	 * @param newX 
	 */
	void	TetrisVector::setxCursor(int newX)
	{
		if (newX <= rowSize)
			this->x_cursor = newX;
		else
			throw	invalid_argument("Invalid Argument to set x cursor");
	}

	/**
	 * @brief to print the board
	 * 
	 */
	void	TetrisVector::draw() const
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
	 * @brief it adds tetromino to the beggining of the board
	 * 
	 * @param tetromino 
	 */
	void	TetrisVector::operator+=(const Tetromino& tetromino)
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
	 * @brief animate for a single tetromino
	 * 
	 * @param index 
	 */
	bool	TetrisVector::animate()
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
			AbstractTetris::clearScreen(rowsToRemove);
			rowsToRemove = this->rowSize + 3;
			for (int i = 0; i < rotCount; ++i)
			{
				this->remove(this->tempTet);
				this->tempTet.rotate(string(1, rotation));
				this->operator+=(this->tempTet);
				this->draw();
				this_thread::sleep_for(chrono::milliseconds(50));
				AbstractTetris::clearScreen(rowsToRemove);
			}
			this->draw();
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
		lMove.type = this->tempTet.getTetrominoType();
		lMove.rotation = rotation;
		lMove.rotNum = rotCount;
		lMove.direction = 'R';
		lMove.dirNum = count;

		AbstractTetris::clearScreen(rowsToRemove);
		this->draw();

		this->remove(this->tempTet);
		this->setyCursor(count);
		this->operator+=(this->tempTet);
		this_thread::sleep_for(chrono::milliseconds(50));

		AbstractTetris::clearScreen(this->rowSize + 3);
		this->draw();
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
			AbstractTetris::clearScreen(this->rowSize + 3);
			this->draw();
			this_thread::sleep_for(chrono::milliseconds(50));
		} while (!overlap);
		
		++(this->numOfMoves);
		this->setyCursor(0);
		this->calcTopRowSize();
		return (true);
	}

	/**
	 * @brief Returns the last move, if there is no last move, throws exception.
	 * 
	 * @return move 
	 */
	move	TetrisVector::lastMove()
	{
		return (lMove);
	}

	/**
	 * @brief return number of moves
	 * 
	 * @return int 
	 */
	int		TetrisVector::numberOfMoves()
	{
		return (this->numOfMoves);
	}
	
	/**
	 * @brief to write the game board to given file name
	 * 
	 * @param fileName 
	 */
	void	TetrisVector::writeToFile(string fileName) const
	{
		fstream	file;
		int	j;

		file.open(fileName, ios::out);

		if (!file.is_open())
		{
			cerr << "File wasn't able to open" << endl;
			throw	exception();
		}

		for (int i = 0; i < this->rowSize; ++i)
		{
			for (j = 0; j < this->colSize; ++j)
				file << static_cast<char>(this->board[i][j]);
			file << '\n';
		}

		file.close();
	}
	
	/**
	 * @brief to load the game board from given file name
	 * 
	 * @param fileName 
	 */
	void	TetrisVector::readFromFile(string fileName)
	{
		fstream	file;
		vector<TetrominoType>	singleRow;
		string	line;

		file.open(fileName, ios::in);

		if (!file.is_open())
		{
			cerr << "Your file cannot be found!" << endl <<
				"Program will be terminated..." << endl;
			throw	exception();
		}

		while (!file.eof())
		{
			getline(file, line);
			singleRow.clear();

			for (char buff : line)
			{
				if (buff == 0)
					singleRow.push_back(TetrominoType::none);
				else if (buff == 1)
					singleRow.push_back(TetrominoType::I);
				else if (buff == 2)
					singleRow.push_back(TetrominoType::O);
				else if (buff == 3)
					singleRow.push_back(TetrominoType::T);
				else if (buff == 4)
					singleRow.push_back(TetrominoType::J);
				else if (buff == 5)
					singleRow.push_back(TetrominoType::L);
				else if (buff == 6)
					singleRow.push_back(TetrominoType::S);
				else if (buff == 7)
					singleRow.push_back(TetrominoType::Z);
			}

			if (line != "")
				this->board.push_back(singleRow);
		}

		file.close();
	}

	/**
	 * @brief remove the tetromino
	 * 
	 * @param tetromino 
	 */
	void	TetrisVector::remove(const Tetromino& tetromino)
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
	void	TetrisVector::addDown(const Tetromino& tetromino)
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
	 * @brief if is there any overlap among the board and tetromino
	 * 
	 * @return true 
	 * @return false 
	 */
	bool	TetrisVector::areThereOverlap() const
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
	void	TetrisVector::takeOneTetromino(const char& type)
	{
		this->tempTet = Tetromino(type);
		this->operator+=(this->tempTet);
		this->draw();
	}

	/**
	 * @brief calculate top row size
	 * 
	 */
	void	TetrisVector::calcTopRowSize()
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

	/**
	 * @brief checking the game is finished or not
	 * 
	 * @param index -> last tetromino
	 * @param type -> if the user gives Q or if the size is not acceptable
	 * @return true 
	 * @return false 
	 */
	bool	TetrisVector::isGameFinished(char type) const
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
	bool	TetrisVector::isGameFinished() const
	{
		for (int i = 0; i < this->colSize; ++i)
			if (this->board[0][i] != TetrominoType::none)
				return (true);
		return (false);
	}
}