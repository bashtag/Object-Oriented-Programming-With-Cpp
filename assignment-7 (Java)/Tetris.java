import java.util.Arrays;
import java.util.Random;

public class Tetris {
	private TetrominoType[][]	board;
	private Tetromino[]	tetrominos;
	private Tetros	tetros = new Tetros();
	private int	rowSize, colSize, y_cursor, x_cursor, botTetColSize;
	private Random	rand;
	
	public Tetris() {
		this.rowSize = 0;
		this.colSize = 0;
		this.tetrominos = new Tetromino[0];
		rand = new Random();
	}

	public Tetris(int rowSize, int colSize) {
		this.rowSize = rowSize;
		this.colSize = colSize;
		this.tetrominos = new Tetromino[0];
		this.setyCursor(0);
		this.setxCursor(0);
		this.botTetColSize = 0;
		rand = new Random();

		this.board = new TetrominoType[this.rowSize][this.colSize];
		for (int i = 0; i < this.rowSize; ++i) {
			Arrays.fill(this.board[i], TetrominoType.NONE);
		}
	}

	public void	takeTetrominos() {
		this.tetros.takeTetrominos();;
		this.tetros.horizontallyBestFit();
	}

	/**
	 * @brief it adds tetromino to the beggining of the board
	 * 
	 * @param tetromino 
	 */
	public void	add(Tetromino tetromino)
	{
		int y_cursor = this.getyCursor(), j = 0, i;

		for (i = 0; i < tetromino.getRowSize(); ++i)
		{
			for (j = 0; j < tetromino.getTetromino()[i].length; ++j)
				this.board[i][y_cursor + j] = tetromino.getTetromino()[i][j];
		}

		this.setyCursor(y_cursor + j);
		this.setxCursor(i);
		this.tetrominos = Tetros.addElement(this.tetrominos.length, tetrominos, tetromino);
	}

	/**
	 * @brief remove the tetromino
	 * 
	 * @param tetromino 
	 */
	public void	remove(Tetromino tetromino)
	{
		int y_cursor = this.getyCursor(), i, j, tetrominoColSize, tetrominoRowSize;
		int x_cursor = this.getxCursor();

		tetrominoColSize = tetromino.getTetromino()[0].length;
		tetrominoRowSize = tetromino.getRowSize();

		for (i = 0; i < tetrominoRowSize; ++i)
		{
			for (j = 0; j < tetromino.getTetromino()[i].length; ++j)
			{
				this.board[x_cursor - tetrominoRowSize + i][y_cursor - tetrominoColSize + j] = TetrominoType.NONE;
			}
		}
		this.setyCursor(y_cursor - tetrominoColSize);
		this.setxCursor(x_cursor - tetrominoRowSize);
		/* There isn't any push_back function or removing element from my vector that holds tetrominos.
			Because if I use remove function, then I will rotate tetromino.*/
	}

	/**
	 * @brief one step down. Remove function is necessary before this function.
	 * 
	 * @param tetromino 
	 */
	public void	addDown(Tetromino tetromino)
	{
		int y_cursor, x_cursor, i, j = 0, tetColSize, tetRowSize;

		x_cursor = this.getxCursor();
		y_cursor = this.getyCursor();
		tetRowSize = tetromino.getRowSize();
		tetColSize = tetromino.getTetromino()[0].length;

		for (i = 0; i < tetRowSize; ++i)
		{
			for (j = 0; j < tetColSize; ++j)
			{
				this.board[x_cursor + 1 + i][y_cursor + j] = tetromino.getTetromino()[i][j];
			}
		}

		this.setxCursor(x_cursor + 1 + i);
		this.setyCursor(y_cursor + j);
	}

	/**
	 * @brief to fit the Tetros board.
	 *  It deletes spaces that mustn't be.
	 * 
	 */
	public boolean	fitBoard()
	{
		int	boardRowSize, k, boardColSize = 0, initColSize = 0;
		boolean	isThereSpace = false;

		boardRowSize = this.board.length;
		if (boardRowSize != 0)
		{
			boardColSize = this.board[0].length;
			initColSize = boardColSize;
		}

		for (int i = 1; i + 1 < boardColSize; i++)
		{
			/**
			 * @brief this algorithm is also handles SZ situation.
			 * It looks the last two rows.
			 * I use my brute force algorithm.
			 */
			if (this.board[boardRowSize - 1][i] == TetrominoType.NONE &&
				!(this.board[boardRowSize - 2][i] != TetrominoType.NONE &&
				this.board[boardRowSize - 2][i + 1] != TetrominoType.NONE &&
				this.board[boardRowSize - 2][i - 1] != TetrominoType.NONE))
			{
				if (this.board[boardRowSize - 1][i + 1] != TetrominoType.NONE)
				{
					if (this.board[boardRowSize - 2][i - 1] == TetrominoType.NONE)
					{
						this.board[boardRowSize - 1] = Tetros.removeTheElement(this.board[boardRowSize - 1], i);
						this.board[boardRowSize - 2] = Tetros.removeTheElement(this.board[boardRowSize - 2], i - 1);
						/* Handle the rows except two last row */
						if (boardRowSize > 2)
						{
							for (k = i - 1; this.board[boardRowSize - 3][k] != TetrominoType.NONE && k + 1 < boardColSize; k++);
							this.board[boardRowSize - 3] = Tetros.removeTheElement(this.board[boardRowSize - 3], k);
						}
						isThereSpace = true;
						this.setyCursor(this.getyCursor() - 1);
					}
					else if (this.board[boardRowSize - 2][i + 1] == TetrominoType.NONE)
					{
						this.board[boardRowSize - 1] = Tetros.removeTheElement(this.board[boardRowSize - 1], i);
						this.board[boardRowSize - 2] = Tetros.removeTheElement(this.board[boardRowSize - 2], i + 1);

						/* Handle the rows except two last row */
						if (boardRowSize > 2)
						{
							for (k = i + 1; this.board[boardRowSize - 3][k] != TetrominoType.NONE && k + 1 < boardColSize; k++);
							this.board[boardRowSize - 3] = Tetros.removeTheElement(this.board[boardRowSize - 3], k);
						}
						isThereSpace = true;
						this.setyCursor(this.getyCursor() - 1);
					}
				}

				for (k = 1; k <= 3; k++)
				{
					if (this.board[boardRowSize - k].length < initColSize)
						this.board[boardRowSize - k] = Tetros.addElement(this.board[boardRowSize - k].length, this.board[boardRowSize - k], TetrominoType.NONE);
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
	public boolean	fit(int index) {
		if (this.tetrominos[index] != this.tetros.getTetrominos()[index])
		{
			this.remove(this.tetrominos[index]);
			this.tetrominos[index].rotate("R");
			this.add(this.tetrominos[index]);
			this.tetrominos = Tetros.removeTheElement(this.tetrominos, this.tetrominos.length - 1);
		}
		else
		{
			this.remove(this.tetrominos[index]);
			this.addDown(this.tetrominos[index]);
		}

		if (x_cursor != rowSize)
			return (true);
		else
			return (false);
	}

	/**
	 * @throws InterruptedException
	 * @brief animate for all tetrominos
	 * 
	 */
	public void	animate() throws InterruptedException {
		int	prevTetSize = tetros.getPreviousTetrominos().length;

		this.printBoard();
		for (int i = 0; i < prevTetSize && getBotTetColSize() + tetros.getPreviousTetrominos()[i].getTetromino()[0].length <= this.colSize; ++i)
		{
			this.add(tetros.getPreviousTetrominos()[i]);
			this.clearScreen(this.board.length + 3);
			this.printBoard();

			do
			{
				this.clearScreen(this.board.length + 3);
				this.printBoard();
				// Thread.sleep(50);
			} while (this.fit(i));

			this.clearScreen(this.board.length + 3);
			this.printBoard();
			// Thread.sleep(50);

			this.fitBoard();
			this.clearScreen(this.board.length + 3);
			this.printBoard();

			this.calcBotTetColSize();
		}
	}

	/**
	 * @brief animate for a single tetromino
	 * 
	 * @param index 
	 * @throws InterruptedException
	 */
	public void	animate(int index) throws InterruptedException
	{
		this.printBoard();
		this.add(tetros.getPreviousTetrominos()[index]);
		this.clearScreen(this.board.length + 3);
		this.printBoard();

		do{
			this.clearScreen(this.board.length + 3);
			this.printBoard();
			// Thread.sleep(50);
		} while (this.fit(index));

		this.clearScreen(this.board.length + 3);
		this.printBoard();
		// Thread.sleep(50);

		this.fitBoard();
		this.clearScreen(this.board.length + 3);
		this.printBoard();

		this.calcBotTetColSize();
	}

	public void	printTetrominos()
	{
		for (Tetromino tetromino : this.tetrominos)
			tetromino.print();
	}

	public void	printBoard()
	{
		int	j;

		for (int i = 0; i < this.board.length + 2; ++i)
		{
			for (j = 0; j < this.board[0].length + 2; ++j)
			{
				if (i == 0 || j == 0 || i == this.board.length + 1 || j == this.board[0].length + 1)
					System.out.print(ColorType.GREY.getColorCode() + "  ");
				else
				{
					switch (this.board[i - 1][j - 1])
					{
						case I:
							System.out.print(ColorType.CYAN.getColorCode() + "  ");
							break;

						case O:
							System.out.print(ColorType.YELLOW.getColorCode() + "  ");
							break;

						case T:
							System.out.print(ColorType.MAGENTA.getColorCode() + "  ");
							break;

						case J:
							System.out.print(ColorType.BLUE.getColorCode() + "  ");
							break;

						case L:
							System.out.print(ColorType.ORANGE.getColorCode() + "  ");
							break;

						case S:
							System.out.print(ColorType.GREEN.getColorCode() + "  ");
							break;

						case Z:
							System.out.print(ColorType.RED.getColorCode() + "  ");
							break;

						case NONE:
							System.out.print("\033[0;48;2;20;20;20m" + "  ");
							break;

						default:
							break;
					}
				}
				System.out.print(ColorType.RESET.getColorCode());;
			}
			System.out.println();
		}
		System.out.println();
	}

	public void	clearScreen(int row)
	{
		System.out.print("\033[" + row + "A");
		System.out.print("\033[G");
	}

	public void	calcBotTetColSize()
	{
		int j;
		boolean	isNotNone = false;

		this.botTetColSize = 0;
		for (int i = this.board.length - 1; i >= this.board.length - 2; --i)
		{
			isNotNone = false;
			for (j = this.board[i].length - 1; j >= 0 && !isNotNone; --j)
			{
				if (this.board[i][j] != TetrominoType.NONE)
					isNotNone = true;
			}
			if (j != 0 && this.botTetColSize < j + 2)
				this.botTetColSize = j + 2;
		}
	}

	public void	takeOneTetromino(char type)
	{
		tetros.addOneTetrominoAndFit(type);
	}

	/**
	 * @brief checking the game is finished or not
	 * 
	 * @param index . last tetromino
	 * @param type . if the user gives Q or if the size is not acceptable
	 * @return true 
	 * @return false 
	 */
	public boolean	isGameFinished(int index, char type)
	{
		Tetromino	tetromino = null;
		if (type == 'Q')
			return (true);
		else if (index == 0)
			return (false);
		
		switch (type)
		{
			case 'I':
				tetromino = new Tetromino(TetrominoType.I);
				break;

			case 'O':
				tetromino = new Tetromino(TetrominoType.O);
				break;

			case 'T':
				tetromino = new Tetromino(TetrominoType.T);
				break;

			case 'J':
				tetromino = new Tetromino(TetrominoType.J);
				break;

			case 'L':
				tetromino = new Tetromino(TetrominoType.L);
				break;

			case 'S':
				tetromino = new Tetromino(TetrominoType.S);
				break;

			case 'Z':
				tetromino = new Tetromino(TetrominoType.Z);
				break;

			default:
				break;
		}
		return (this.getBotTetColSize() + tetromino.getTetromino()[0].length > this.colSize);
	}

	/**
	 * @brief random char type generator
	 * 
	 * @return char 
	 */
	public char	randomChType()
	{
		char	randChar = 'I';

		switch (rand.nextInt(7))
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

	public void	setyCursor(int newY) {
		this.y_cursor = newY;
	}

	public void	setxCursor(int newX) {
		this.x_cursor = newX;
	}

	public int	getyCursor() {
		return (this.y_cursor);
	}

	public int	getxCursor() {
		return (this.x_cursor);
	}

	public int	getBotTetColSize() {
		return (this.botTetColSize);
	}

	public int getColSize() {
		return (this.colSize);
	}

}
