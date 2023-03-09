#ifndef TETRISADAPTER_HPP
# define TETRISADAPTER_HPP

# include "AbstractTetris.hpp"

namespace	tg
{	
	template <template <class G, class = allocator<G>> class T>
	class	TetrisAdapter : public AbstractTetris
	{
		public:
			TetrisAdapter();
			/**
			 * @brief Construct a new Tetris Vector object
			 * (row, column)
			 */
			TetrisAdapter(int, int);
			/**
			 * @brief Construct a new Tetris Vector object from given file
			 * 
			 * @param fileName 
			 */
			TetrisAdapter(string fileName, int&, int&);

			virtual void	draw() const;
			virtual void	readFromFile(string); /* filename */
			virtual void	writeToFile(string) const; /* filename */
			virtual void	operator+=(const Tetromino&);
			virtual bool	animate();
			virtual move	lastMove();
			virtual int	numberOfMoves();
			virtual void	takeOneTetromino(const char&); /* take a tetromino to the starting point*/
			virtual bool	isGameFinished() const; /* it looks only first row of the board */
			virtual bool	isGameFinished(char type) const; /* it takes index for last tetromino and a type for if the size is OK or not */

			inline int	getyCursor() const {return (this->y_cursor);};
			inline int	getxCursor() const {return (this->x_cursor);};
			inline int	getTopRowSize() const {return (this->topRowSize);};
			inline int	getColSize() const {return (this->colSize);};

			/**
			 * @brief to add one step down with tetromino. 
			 * But remove function must be called before this function.
			 * 
			 */
			void	addDown(const Tetromino&);
			/**
			 * @brief  remove the tetromino from the board 
			 * 
			 */
			void	remove(const Tetromino&);
			bool	areThereOverlap() const;

			void	calcTopRowSize(); /* to calculate bottom's width of the board */

		private:
			T<TetrominoType>	board;
			Tetromino	tempTet;
			int	rowSize, colSize, y_cursor, x_cursor, topRowSize, numOfMoves;
			move	lMove;

			void	setyCursor(int);
			void	setxCursor(int);
	};

}


namespace	tg
{
	/**
	 * @brief Construct a new TetrisAdapter:: TetrisAdapter object
	 * 
	 */
	template <template <class G, class = allocator<G>> class T>
	TetrisAdapter<T>::TetrisAdapter() : rowSize(0), colSize(0), tempTet('O'), numOfMoves(0)
	{}

	/**
	 * @brief Construct a new TetrisAdapter:: TetrisAdapter object
	 * 
	 * @param rowSize 
	 * @param colSize 
	 */
	template <template <class G, class = allocator<G>> class T>
	TetrisAdapter<T>::TetrisAdapter(int rowSize, int colSize)
	{
		this->rowSize = rowSize;
		this->colSize = colSize;
		this->setyCursor(0);
		this->setxCursor(0);
		this->tempTet = Tetromino('O');
		this->numOfMoves = 0;

		this->board.resize((this->rowSize) * (this->colSize));
		this->calcTopRowSize();
	}

	/**
	 * @brief Construct a new Tetris Vector:: Tetris Vector object from given file
	 * 
	 * @param fileName 
	 */
	template <template <class G, class = allocator<G>> class T>
	TetrisAdapter<T>::TetrisAdapter(string fileName, int& rowSize, int& colSize)
	{
		this->x_cursor = 0;
		this->y_cursor = 0;
		this->tempTet = Tetromino('O');
		this->numOfMoves = 0;
		this->rowSize = 0;
		this->colSize = 0;

		this->readFromFile(fileName);

		rowSize = this->rowSize;
		colSize = this->colSize;
		this->calcTopRowSize();
	}

	/**
	 * @brief Set a new Tetris Vector::sety Cursor object
	 * 
	 * @param newY 
	 */
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::setyCursor(int newY)
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
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::setxCursor(int newX)
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
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::draw() const
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
					switch (this->board[this->colSize * (i - 1) + (j - 1)])
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
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::operator+=(const Tetromino& tetromino)
	{
		int y_cursor = this->getyCursor(), j, i;
		int	x_cursor = this->getxCursor();

		for (i = 0; i < tetromino.getRowSize(); ++i)
		{
			for (j = 0; j < tetromino.getColSize(); ++j)
				if (tetromino[i][j] != TetrominoType::none)
					this->board[(this->colSize * i) + y_cursor + j] = tetromino[i][j];
					// this->board[(i + 1) * (y_cursor + j + 1) - 1] = tetromino[i][j];
		}

		this->setyCursor(y_cursor + j);
		this->setxCursor(i);
	}

	/**
	 * @brief animate for a single tetromino
	 * 
	 * @param index 
	 */
	template <template <class G, class = allocator<G>> class T>
	bool	TetrisAdapter<T>::animate()
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
	template <template <class G, class = allocator<G>> class T>
	move	TetrisAdapter<T>::lastMove()
	{
		return (this->lMove);
	}

	/**
	 * @brief return number of moves
	 * 
	 * @return int 
	 */
	template <template <class G, class = allocator<G>> class T>
	int		TetrisAdapter<T>::numberOfMoves()
	{
		return (this->numOfMoves);
	}
	
	/**
	 * @brief to write the game board to given file name
	 * 
	 * @param fileName 
	 */
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::writeToFile(string fileName) const
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
				file << static_cast<char>(this->board[(this->colSize * i) + (j)]);
			file << '\n';
		}

		file.close();
	}
	
	/**
	 * @brief to load the game board from given file name
	 * 
	 * @param fileName 
	 */
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::readFromFile(string fileName)
	{
		fstream	file;
		vector<TetrominoType>	singleRow;
		string	line;
		int	lineSize, fRowSize = 0, i;

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
			lineSize = 0;
			++fRowSize;

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
				++lineSize;
			}

			if (line != "")
			{
				this->board.resize(fRowSize * lineSize);

				this->rowSize = fRowSize;
				this->colSize = lineSize;

				for (i = 0; i < lineSize; ++i)
					this->board[(lineSize * (fRowSize - 1)) + (i)] = singleRow[i];
			}
		}

		file.close();
	}

	/**
	 * @brief remove the tetromino
	 * 
	 * @param tetromino 
	 */
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::remove(const Tetromino& tetromino)
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
					this->board[this->colSize * (x_cursor - tetrominoRowSize + i) + (y_cursor - tetrominoColSize + j)] = TetrominoType::none;
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
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::addDown(const Tetromino& tetromino)
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
					this->board[this->colSize * (x_cursor + 1 + i) + (y_cursor + j)] = tetromino[i][j];
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
	template <template <class G, class = allocator<G>> class T>
	bool	TetrisAdapter<T>::areThereOverlap() const
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
					(this->board[this->colSize * (x_cursor + 1 + i) + (y_cursor + j)] != TetrominoType::none &&
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
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::takeOneTetromino(const char& type)
	{
		this->tempTet = Tetromino(type);
		this->operator+=(this->tempTet);
		this->draw();
	}

	/**
	 * @brief calculate top row size
	 * 
	 */
	template <template <class G, class = allocator<G>> class T>
	void	TetrisAdapter<T>::calcTopRowSize()
	{
		int j;
		bool	isNotNone = false;

		this->topRowSize = 0;
		for (int i = 0; !isNotNone && i < this->rowSize; ++i)
		{
			for (j = 0; !isNotNone && j < this->colSize; ++j)
				if (this->board[this->colSize * (i) + (j)] != TetrominoType::none)
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
	template <template <class G, class = allocator<G>> class T>
	bool	TetrisAdapter<T>::isGameFinished(char type) const
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
	template <template <class G, class = allocator<G>> class T>
	bool	TetrisAdapter<T>::isGameFinished() const
	{
		for (int i = 0; i < this->colSize; ++i)
			if (this->board[i] != TetrominoType::none)
				return (true);
		return (false);
	}

}

#endif