import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Tetros {
	private TetrominoType[][]	board;
	private Tetromino[]	tetrominos, previousTetrominos;
	private int	tetrominoSize;
	private Scanner	scanner;

	public Tetros() {
		scanner = new Scanner(System.in);
		this.tetrominos = new Tetromino[0];
		this.previousTetrominos = new Tetromino[0];
	}

	/**
	 * @brief Function to remove the element
	 * @param arr
	 * @param index
	 * @return
	 */ 
    public static TetrominoType[] removeTheElement(TetrominoType[] arr, int index)
    {
        if (arr == null || index < 0 || index >= arr.length)
            return arr;
 
        TetrominoType[] anotherArray = new TetrominoType[arr.length - 1];
 
        for (int i = 0, k = 0; i < arr.length; i++) {
            if (i == index) {
                continue;
            }
            anotherArray[k++] = arr[i];
        }
        return anotherArray;
    }
	
	/**
	 * @brief Function to remove the element
	 * @param arr
	 * @param index
	 * @return
	 */ 
    public static Tetromino[] removeTheElement(Tetromino[] arr, int index)
    {
        if (arr == null || index < 0 || index >= arr.length)
            return arr;
 
        Tetromino[] anotherArray = new Tetromino[arr.length - 1];
 
        for (int i = 0, k = 0; i < arr.length; i++) {
            if (i == index) {
                continue;
            }
            anotherArray[k++] = arr[i];
        }
        return anotherArray;
    }

	public static Tetromino[] addElement(int n, Tetromino arr[], Tetromino x)
	{
		int i;

		// create a new array of size n+1
		Tetromino newarr[] = new Tetromino[n + 1];

		// insert x at n+1
		for (i = 0; i < n; i++)
			newarr[i] = arr[i];

		newarr[n] = x;

		return newarr;
	}

	public static TetrominoType[] addElement(int n, TetrominoType arr[], TetrominoType x)
	{
		int i;

		// create a new array of size n+1
		TetrominoType newarr[] = new TetrominoType[n + 1];

		// insert x at n+1
		for (i = 0; i < n; i++)
			newarr[i] = arr[i];

		newarr[n] = x;

		return newarr;
	}

	public static TetrominoType[][] addElementToBegin(int row, int col, TetrominoType arr[][], TetrominoType x[])
	{
		int i, j;

		TetrominoType newarr[][] = new TetrominoType[row + 1][col];

		for (i = 0; i < col; ++i)
			newarr[0][i] = x[i];
		for (i = 0; i < row; i++)
			for (j = 0; j < col; ++j)
				newarr[i + 1][j] = arr[i][j];
		return newarr;
	}

	/**
	 * @param type
	 */
	public void	addOneTetrominoAndFit(char type) {
		switch (type)
		{
			case 'I':
				this.tetrominos = Tetros.addElement(this.tetrominos.length, this.tetrominos, new Tetromino(TetrominoType.I));
				this.previousTetrominos = Tetros.addElement(this.previousTetrominos.length, this.previousTetrominos, new Tetromino(TetrominoType.I));
				break;

			case 'O':
				this.tetrominos = Tetros.addElement(this.tetrominos.length, this.tetrominos, new Tetromino(TetrominoType.O));
				this.previousTetrominos = Tetros.addElement(this.previousTetrominos.length, this.previousTetrominos, new Tetromino(TetrominoType.O));
				break;

			case 'T':
				this.tetrominos = Tetros.addElement(this.tetrominos.length, this.tetrominos, new Tetromino(TetrominoType.T));
				this.previousTetrominos = Tetros.addElement(this.previousTetrominos.length, this.previousTetrominos, new Tetromino(TetrominoType.T));
				break;

			case 'J':
				this.tetrominos = Tetros.addElement(this.tetrominos.length, this.tetrominos, new Tetromino(TetrominoType.J));
				this.previousTetrominos = Tetros.addElement(this.previousTetrominos.length, this.previousTetrominos, new Tetromino(TetrominoType.J));
				break;

			case 'L':
				this.tetrominos = Tetros.addElement(this.tetrominos.length, this.tetrominos, new Tetromino(TetrominoType.L));
				this.previousTetrominos = Tetros.addElement(this.previousTetrominos.length, this.previousTetrominos, new Tetromino(TetrominoType.L));
				break;

			case 'S':
				this.tetrominos = Tetros.addElement(this.tetrominos.length, this.tetrominos, new Tetromino(TetrominoType.S));
				this.previousTetrominos = Tetros.addElement(this.previousTetrominos.length, this.previousTetrominos, new Tetromino(TetrominoType.S));
				break;

			case 'Z':
				this.tetrominos = Tetros.addElement(this.tetrominos.length, this.tetrominos, new Tetromino(TetrominoType.Z));
				this.previousTetrominos = Tetros.addElement(this.previousTetrominos.length, this.previousTetrominos, new Tetromino(TetrominoType.Z));
				break;

			default:
				break;
		}
		++(this.tetrominoSize);

		this.board = new TetrominoType[0][0];
		this.horizontallyBestFit();
	}

	/**
	 * @brief to print tetrominos vertically
	 * 
	 */
	public void	printTetrominos() {
		for (Tetromino tetromino : this.tetrominos)
			tetromino.print();
	}

	/**
	 * @brief to process all the necessary functions for the horizontally best fit
	 */
	public void	horizontallyBestFit() {
		int	j; /* it solves infinite loop problem */

		this.addHorizontally(this.tetrominos[0]);
		for (int i = 0; i + 1 < this.tetrominoSize; ++i) {
			for (j = 0; j < 4 && !(this.tetrominos[i].canFit(this.tetrominos[i + 1], "R")); ++j)
				this.tetrominos[i + 1].rotate("R");
			this.addHorizontally(this.tetrominos[i + 1]);
		}
		this.fitBoard();
	}

	/**
	 * @brief
	 * 
	 * @param tetromino
	 */
	public void	addHorizontally(Tetromino tetromino) {
		int	i, j, boardRowSize, boardColSize, tetRowSize, tetColSize;

		boardRowSize = this.board.length;
		tetRowSize = tetromino.getRowSize();
		tetColSize = tetromino.getTetromino()[0].length;

		/**
		 * @brief if the board doesn't consist any tetromino, then initialize the board using relative tetromino
		 * 
		 */
		if (boardRowSize == 0)
		{
			if (tetromino.getTetrominoType() == TetrominoType.I) {
				this.board = new TetrominoType[][] {
					{TetrominoType.I, TetrominoType.I, TetrominoType.I, TetrominoType.I}
				};
			}
			else if (tetromino.getTetrominoType() == TetrominoType.O) {
				this.board = new TetrominoType[][] {
					{TetrominoType.O, TetrominoType.O},
					{TetrominoType.O, TetrominoType.O}
				};
			}
			else if (tetromino.getTetrominoType() == TetrominoType.T) {
				this.board = new TetrominoType[][] {
					{TetrominoType.T, TetrominoType.T, TetrominoType.T},
					{TetrominoType.NONE, TetrominoType.T, TetrominoType.NONE}
				};
			}
			else if (tetromino.getTetrominoType() == TetrominoType.J) {
				this.board = new TetrominoType[][] {
					{TetrominoType.NONE, TetrominoType.J},
					{TetrominoType.NONE, TetrominoType.J},
					{TetrominoType.J, TetrominoType.J}
				};
			}
			else if (tetromino.getTetrominoType() == TetrominoType.L) {
				this.board = new TetrominoType[][] {
					{TetrominoType.L, TetrominoType.NONE},
					{TetrominoType.L, TetrominoType.NONE},
					{TetrominoType.L, TetrominoType.L}
				};
			}
			else if (tetromino.getTetrominoType() == TetrominoType.S) {
				this.board = new TetrominoType[][] {
					{TetrominoType.NONE, TetrominoType.S, TetrominoType.S},
					{TetrominoType.S, TetrominoType.S, TetrominoType.NONE}
				};
			}
			else if (tetromino.getTetrominoType() == TetrominoType.Z) {
				this.board = new TetrominoType[][] {
					{TetrominoType.Z, TetrominoType.Z, TetrominoType.NONE},
					{TetrominoType.NONE, TetrominoType.Z, TetrominoType.Z}
				};
			}
		}
		else
		{
			/* Increase the row size if relative tetromino is longer than board */
			while (tetRowSize > this.board.length)
			{
				TetrominoType[]	temp = new TetrominoType[this.board[0].length];
				Arrays.fill(temp, TetrominoType.NONE);
				this.board = Tetros.addElementToBegin(this.board.length, this.board[0].length, board, temp);
			}

			boardRowSize = this.board.length;

			/* Increase the column size using relative tetromino's width */
			for (i = 0; i < boardRowSize; i++)
				for (j = 0; j < tetColSize; j++)
					this.board[i] = Tetros.addElement(this.board[i].length, this.board[i], TetrominoType.NONE);

			boardColSize = this.board[0].length;

			/* Put the tetromino to the board */
			for (i = 0; i < tetRowSize; i++)
				for (j = 0; j < tetColSize; j++)
					this.board[boardRowSize - tetRowSize + i][boardColSize - tetColSize + j] = tetromino.getTetromino()[i][j];
		}
	}

	/**
	 * @brief to fit the Tetros board.
	 *  It deletes spaces that mustn't be.
	 * 
	 */
	public void	fitBoard()
	{
		int	boardRowSize, k, boardColSize = 0;

		boardRowSize = this.board.length;
		if (boardRowSize != 0)
			boardColSize = this.board[0].length;

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
					}
				}
				boardColSize--;
			}
		}
	}
	/**
	 * @brief to take tetrominos into the tetromino vector
	 */
	public void	takeTetrominos() {
		char	givenType;
		String	typeHandle = "IOTJLSZ";

		while (true) {
			System.out.println("How many tetrominos?");
			try {
				this.tetrominoSize = scanner.nextInt();
				if (this.tetrominoSize <= 0)
					throw new InputMismatchException();
				break;
			} catch (InputMismatchException e) {
				System.out.println("Give me a valid input.");
				scanner.nextLine();
				continue;
			}
		}

		/* preallocate memory */
		this.tetrominos = new Tetromino[this.tetrominoSize];

		System.out.println("What are the types?(I, O, T, L, J, S, Z)");
		for (int i = 0; i < this.tetrominoSize; ++i) {
			givenType = scanner.next().toUpperCase().charAt(0);
			
			if (typeHandle.indexOf(givenType) == -1) {
				System.out.println("Give me a valid type");
				--i;
			}
			else 
				switch (givenType)
				{
					case 'I':
						this.tetrominos[i] = new Tetromino(TetrominoType.I);
						break;

					case 'O':
						this.tetrominos[i] = new Tetromino(TetrominoType.O);
						break;

					case 'T':
						this.tetrominos[i] = new Tetromino(TetrominoType.T);
						break;

					case 'J':
						this.tetrominos[i] = new Tetromino(TetrominoType.J);
						break;

					case 'L':
						this.tetrominos[i] = new Tetromino(TetrominoType.L);
						break;

					case 'S':
						this.tetrominos[i] = new Tetromino(TetrominoType.S);
						break;

					case 'Z':
						this.tetrominos[i] = new Tetromino(TetrominoType.Z);
						break;

					default :
						break;
				}
		}

		this.previousTetrominos = this.tetrominos;
	}

	/**
	 * @brief to print the Tetros board
	 * 
	 */
	public void	printBoard()
	{
		for (var singleRow : this.board)
		{
			for (var element : singleRow)
				switch (element)
				{
					case I:
						System.out.print('I');
						break;

					case O:
						System.out.print('O');
						break;

					case T:
						System.out.print('T');
						break;

					case J:
						System.out.print('J');
						break;

					case L:
						System.out.print('L');
						break;

					case S:
						System.out.print('S');
						break;

					case Z:
						System.out.print('Z');
						break;

					case NONE:
						System.out.print(' ');
						break;

					default:
						break;
				}
			System.out.println();
		}
		System.out.println();
	}

	/**
	 * @brief getter for tetrominos array
	 * @return 1d tetromino array
	 */
	public Tetromino[] getTetrominos() {
		return tetrominos;
	}

	/**
	 * @brief getter for previous tetrominos array
	 * @return 1d tetromino array
	 */
	public Tetromino[] getPreviousTetrominos() {
		return previousTetrominos;
	}

	/**
	 * @brief getter for tetromino size
	 * @return size
	 */
	public int getTetrominoSize() {
		return tetrominoSize;
	}
}
