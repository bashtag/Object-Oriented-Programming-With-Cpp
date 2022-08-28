#ifndef _LIB_H_
#define _LIB_H_

#include <string>
#include <vector>

#define COLOUR_BLUE "\033[0;34m"
#define DEFAULT_COLOUR "\033[0m"

using namespace std;

enum class CellType {none, empty, peg};

class	PegSolitaire
{
public:
	/* Cell class */
	class	Cell
	{
		public:
			Cell();
			Cell(int, int, CellType);	
			void	setRow(int);
			void	setColumn(int);
			void	setCellType(CellType);
			/* const means read only */
			inline int	getRow() const {return (row);};
			inline int	getColumn() const {return (column);};
			inline CellType	getCellType() const {return (cellType);};
		private:
			int	row;
			int	column;
			CellType	cellType;
	};
	/* Cell class end */

	PegSolitaire(); /* makes board as NULL */
	PegSolitaire(int); /* makes the board according to board type*/
	PegSolitaire(int, int);
	PegSolitaire(string); /* loads from file */

	vector<vector<Cell>>	createBoard(); /* creating board according to board selection 1-6 */
	void	printBoard(); /* printing board */
	/**
	 * @brief board, row, column, direction
	 * 
	 */
	void	makeMove(int, int, string); /* making a valid move to the board */
	/**
	 * @brief board, row, column, direction
	 * 
	 */
	bool	isValidMove(int, int, string); /* checks if move is valid */
	bool	isGameFinished(); /* checks is there any valid move on the board */
	int	gameScore(); /* return the game score of the table */
	int	emptyCellsCounter(); /* return the number of emtyp cells */
	
	/**
	 * @brief board, row, column, direction
	 * 
	 */
	void	getRandomValidMove(int&, int&, string&); /* creating a valid move for computer player */

	void	humanPlayerGame(); /* initializing a human game */
	void	computerGame(); /* initializing a computer game */

	/* file functions */
	bool	loadFile(const string); /* loading file from txt file */
	void	saveFile(const string, const bool, const int); /* saving the status of the game to the txt file */

	/* Getter and Setters for state of the board */
	void	setNumOfPegs(int);
	void	setNumOfEmptyCells(int);
	void	setNumOfTakenPegs(int);

	inline int	getNumOfPegs() const {return (numOfPegs);};
	inline int	getNumOfEmptyCells() const {return (numOfEmptyCells);};
	inline int	getNumOfTakenPegs() const {return (numOfTakenPegs);};
	/* Getter and Setters ended */

	/* const cannot using with static member function */
	inline static int	getTotalPegs() {return (totalPegs);};

	/* game functions */
	void	play(); /* plays automatically for a single step */
	void	play(Cell); /* takes a cell position and it plays from the user for a single step*/
	/**
	 * @brief plays the game by asking the user the board type first then automatically plays the game until it ends
	 */
	void	playGame();

private:
	/* my variables that are not accessible outside of the class */
	int	resize;
	int	boardType;
	bool	isTypeSix;
	int	numOfPegs, numOfEmptyCells, numOfTakenPegs;
	int	gameSelection;
	/* When static keyword is used, variable or data members or functions can not be modified again.
	 * It is allocated for the lifetime of program.
	 * Static functions can be called directly by using class name.
	 */
	/* num of total pegs remain in boards (maybe played more than one game) */
	static int	totalPegs;
	vector <vector<Cell>> board;

};

void	stringToUppercase(string &str);

#endif /* _LIB_H_ */

// vector<vector<PegSolitaire::Cell>>	createBoard(int boardSelection);

// void	printBoard(vector<vector<PegSolitaire::Cell>> board);

// void	makeMove(vector<vector<PegSolitaire::Cell>> &board, int row, int column, string direction, bool isSixthBoard);

// bool	isValidMove(vector<vector<PegSolitaire::Cell>> board, int row, int column, string direction, bool isSixthBoard);

// bool	isGameFinished(vector<vector<PegSolitaire::Cell>> board, int boardSelection);

// int	gameScore(vector<vector<PegSolitaire::Cell>> board);

// void	humanPlayerGame(vector<vector<PegSolitaire::Cell>> board, int boardSelection);

// void	getRandomValidMove(vector<vector<PegSolitaire::Cell>> board, int &row, int &column, string &direction, bool isSixthBoard);

// void	computerGame(vector<vector<PegSolitaire::Cell>> board, int boardSelection);

// bool	loadFile(vector<vector<PegSolitaire::Cell>> &board, const string fileName);

// void	saveFile(vector<vector<PegSolitaire::Cell>> board, const string fileName, const bool isHuman, const int moveCounter, const bool isSixthBoard);