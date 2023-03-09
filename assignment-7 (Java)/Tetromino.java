public class Tetromino {
	private TetrominoType[][]	tetrominoArr;
	private TetrominoType	tetrominoType;

	public Tetromino(TetrominoType type) {
		this.tetrominoType = type;
		this.initialize(type);
	}

	/**
	 * @brief setter for tetromino type
	 * @param type
	 */
	public void	setTetrominoType(TetrominoType type)
	{
		if (type == TetrominoType.NONE)
			throw	new IllegalArgumentException("Invalid type.");
		else
			this.tetrominoType = type;
	}

	/**
	 * @brief get tetromino 2d array
	 * @return 2d array
	 */
	public TetrominoType[][]	getTetromino() {
		return (this.tetrominoArr);
	}

	/**
	 * @brief get tetrominotype
	 * @return enum class tetrominotype
	 */
	public TetrominoType	getTetrominoType() {
		return (this.tetrominoType);
	}

	/**
	 * @brief get row size of 2d tetromino array
	 * @return primitive integer
	 */
	public int	getRowSize() {
		return (this.tetrominoArr.length);
	}

	/**
	 * @brief initialization of tetromino vector
	 * @param type
	 */
	public void	initialize(TetrominoType type) {
		if (type == TetrominoType.I)
		{
			this.tetrominoArr = new TetrominoType[][] {
				{TetrominoType.I, TetrominoType.I, TetrominoType.I, TetrominoType.I}
			};
		}
		else if (type == TetrominoType.O)
		{
			this.tetrominoArr = new TetrominoType[][] {
				{TetrominoType.O, TetrominoType.O},
				{TetrominoType.O, TetrominoType.O}
			};
		}
		else if (type == TetrominoType.T)
		{
			this.tetrominoArr = new TetrominoType[][] {
				{TetrominoType.T, TetrominoType.T, TetrominoType.T},
				{TetrominoType.NONE, TetrominoType.T, TetrominoType.NONE}
			};
		}
		else if (type == TetrominoType.J)
		{
			this.tetrominoArr = new TetrominoType[][] {
				{TetrominoType.NONE, TetrominoType.J},
				{TetrominoType.NONE, TetrominoType.J},
				{TetrominoType.J, TetrominoType.J}
			};
		}
		else if (type == TetrominoType.L)
		{
			this.tetrominoArr = new TetrominoType[][] {
				{TetrominoType.L, TetrominoType.NONE},
				{TetrominoType.L, TetrominoType.NONE},
				{TetrominoType.L, TetrominoType.L}
			};
		}
		else if (type == TetrominoType.S)
		{
			this.tetrominoArr = new TetrominoType[][] {
				{TetrominoType.NONE, TetrominoType.S, TetrominoType.S},
				{TetrominoType.S, TetrominoType.S, TetrominoType.NONE}
			};
		}
		else if (type == TetrominoType.Z)
		{
			this.tetrominoArr = new TetrominoType[][] {
				{TetrominoType.Z, TetrominoType.Z, TetrominoType.NONE},
				{TetrominoType.NONE, TetrominoType.Z, TetrominoType.Z}
			};
		}
	}

	/**
	 * @brief L - R
	 * @param direction
	 */
	public void	rotate(String direction) {
		if (direction == "L")
		{
			/**
			 * to rotate the tetromino left
			 */
			this.rotate90();
			this.rotate90();
			this.rotate90();
		}
		else if (direction == "R")
		{
			this.rotate90();
		}
	}

	/**
	 * @brief rotate 90 degree
	 */
	private void	rotate90() {
		TetrominoType[][]	temp = new TetrominoType[this.tetrominoArr[0].length][this.tetrominoArr.length];

		for (int i = 0, j; i < temp.length; ++i) {
			for (j = 0; j < temp[0].length; ++j) {
				temp[i][j] = tetrominoArr[temp[0].length - j - 1][i];
			}
		}

		this.tetrominoArr = temp;
	}

	/**
	 * @brief to print any tetromino
	 */
	public void	print() {
		for (int i = 0, j; i < this.tetrominoArr.length; ++i) {
			for (j = 0; j < this.tetrominoArr[0].length; ++j) {
				if (this.tetrominoArr[i][j] == TetrominoType.I)
				{
					System.out.print('I');
				}
				else if (this.tetrominoArr[i][j] == TetrominoType.O)
				{
					System.out.print('O');
				}
				else if (this.tetrominoArr[i][j] == TetrominoType.T)
				{
					System.out.print('T');
				}
				else if (this.tetrominoArr[i][j] == TetrominoType.J)
				{
					System.out.print('J');
				}
				else if (this.tetrominoArr[i][j] == TetrominoType.L)
				{
					System.out.print('L');
				}
				else if (this.tetrominoArr[i][j] == TetrominoType.S)
				{
					System.out.print('S');
				}
				else if (this.tetrominoArr[i][j] == TetrominoType.Z)
				{
					System.out.print('Z');
				}
				else if (this.tetrominoArr[i][j] == TetrominoType.NONE)
				{
					System.out.print(' ');
				}
			}
			System.out.println();
		}
		System.out.println();
	}

	/**
	 * @brief can two tetrominos fit horizontally?
	 * 
	 * @param tetromino
	 * @param position
	 * @return true
	 * @return false
	 */
	public boolean	canFit(Tetromino tetromino, String position) {
		boolean	checkFit = false;
		int	thisColSize, thisRowSize, tetRowSize;

		thisRowSize = this.tetrominoArr.length;
		thisColSize = this.tetrominoArr[0].length;
		tetRowSize = tetromino.tetrominoArr.length;

		/**
		 * @brief this algorithm looks at the cross area of the collobration of two tetrominos
		 * 
		 */
		if (position == "R")
		{
			if (this.tetrominoArr[thisRowSize - 1][thisColSize - 1] == TetrominoType.NONE &&
					tetromino.tetrominoArr[tetRowSize - 1][0] != TetrominoType.NONE)
			{
				if ((thisRowSize < 2 || this.tetrominoArr[thisRowSize - 2][thisColSize - 1] == TetrominoType.NONE) &&
						(tetRowSize < 2 || tetromino.tetrominoArr[tetRowSize - 2][0] != TetrominoType.NONE))
					checkFit = true;
				else if ((thisRowSize < 2 || this.tetrominoArr[thisRowSize - 2][thisColSize - 1] != TetrominoType.NONE) &&
						(tetRowSize < 2 || tetromino.tetrominoArr[tetRowSize - 2][0] == TetrominoType.NONE))
					checkFit = true;
				else
					checkFit = false;
			}
			else if (this.tetrominoArr[thisRowSize - 1][thisColSize - 1] != TetrominoType.NONE &&
					tetromino.tetrominoArr[tetRowSize - 1][0] == TetrominoType.NONE)
			{
				if ((thisRowSize < 2 || this.tetrominoArr[thisRowSize - 2][thisColSize - 1] == TetrominoType.NONE) &&
						(tetRowSize < 2 || tetromino.tetrominoArr[tetRowSize - 2][0] != TetrominoType.NONE))
					checkFit = true;
				else if ((thisRowSize < 2 || this.tetrominoArr[thisRowSize - 2][thisColSize - 1] != TetrominoType.NONE) &&
						(tetRowSize < 2 || tetromino.tetrominoArr[tetRowSize - 2][0] == TetrominoType.NONE))
					checkFit = true;
				else
					checkFit = false;
			}
			else if (this.tetrominoArr[thisRowSize - 1][thisColSize - 1] != TetrominoType.NONE &&
					tetromino.tetrominoArr[tetRowSize - 1][0] != TetrominoType.NONE)
				checkFit = true;
		}
		else if (position == "L") /* Left posisition */
		{
			if (tetromino.tetrominoArr[thisRowSize - 1][thisColSize - 1] == TetrominoType.NONE &&
					this.tetrominoArr[tetRowSize - 1][0] != TetrominoType.NONE)
			{
				if ((tetRowSize < 2 || tetromino.tetrominoArr[thisRowSize - 2][thisColSize - 1] == TetrominoType.NONE) &&
						(thisRowSize < 2 || this.tetrominoArr[tetRowSize - 2][0] != TetrominoType.NONE))
					checkFit = true;
				else if ((tetRowSize < 2 || tetromino.tetrominoArr[thisRowSize - 2][thisColSize - 1] != TetrominoType.NONE) &&
						(thisRowSize < 2 || this.tetrominoArr[tetRowSize - 2][0] == TetrominoType.NONE))
					checkFit = true;
				else
					checkFit = false;
			}
			else if (tetromino.tetrominoArr[thisRowSize - 1][thisColSize - 1] != TetrominoType.NONE &&
					this.tetrominoArr[tetRowSize - 1][0] == TetrominoType.NONE)
			{
				if ((tetRowSize < 2 || tetromino.tetrominoArr[thisRowSize - 2][thisColSize - 1] == TetrominoType.NONE) &&
						(thisRowSize < 2 || this.tetrominoArr[tetRowSize - 2][0] != TetrominoType.NONE))
					checkFit = true;
				else if ((tetRowSize < 2 || tetromino.tetrominoArr[thisRowSize - 2][thisColSize - 1] != TetrominoType.NONE) &&
						(thisRowSize < 2 || this.tetrominoArr[tetRowSize - 2][0] == TetrominoType.NONE))
					checkFit = true;
				else
					checkFit = false;
			}
			else if (tetromino.tetrominoArr[thisRowSize - 1][thisColSize - 1] != TetrominoType.NONE &&
					this.tetrominoArr[tetRowSize - 1][0] != TetrominoType.NONE)
				checkFit = true;
		}

		return (checkFit);
	}

	/**
	 * @brief equals method override
	 * @return true
	 * @return false
	 */
	@Override
	public boolean equals(Object obj) {
		if (obj == this)
			return (true);

		if (!(obj instanceof Tetromino))
			return (false);

		Tetromino	temp = (Tetromino)obj;

		if(tetrominoArr.length == temp.tetrominoArr.length){
			for(int i=0; i < tetrominoArr.length; i++){
				if(tetrominoArr[i].length == temp.tetrominoArr[i].length){
					for(int j = 0; j < tetrominoArr[i].length; j++){
						if(tetrominoArr[i][j] != temp.tetrominoArr[i][j]){
							return (false);
						}
					}
				} else {
					return (false);
				}
			}
		} else {
			return (false);
		}
		return (true);
	}


}
