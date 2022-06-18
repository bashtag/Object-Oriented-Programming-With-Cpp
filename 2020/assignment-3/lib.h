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
			Cell(int, char, CellType);	
			void	setRow(int);
			void	setColumn(char);
			void	setCellType(CellType);
			inline int	getRow() const {return (row);};
			inline int	getColumn() const {return (column);};
			inline CellType	getCellType() const {return (cellType);};
		private:
			int	row;
			char	column;
			CellType	cellType;
	};
	/* Cell class end */

	PegSolitaire();
	PegSolitaire(int);
	PegSolitaire(int, int);

	void	printBoard(vector<vector<Cell>> board);
	void	makeMove(vector<vector<Cell>> &, int, int, string, bool);
	bool	isValidMove(vector<vector<Cell>>, int, int, string, bool);
	bool	isGameFinished(vector<vector<Cell>>, int);
	int	gameScore(vector<vector<Cell>>);
	void	getRandomValidMove(vector<vector<Cell>>, int&, int&, string&, bool);

	void	humanPlayerGame(vector<vector<Cell>>, int);
	void	computerGame(vector<vector<Cell>>, int);

	bool	loadFile(vector<vector<Cell>>&, const string);
	void	saveFile(vector<vector<Cell>>, const string, const bool, const int, const bool);

private:
	int	resize;
	int	boardType;
	vector <vector<Cell>> board;

};


vector<vector<PegSolitaire::Cell>>	createBoard(int boardSelection);

// void	printBoard(vector<vector<PegSolitaire::Cell>> board);

// void	makeMove(vector<vector<PegSolitaire::Cell>> &board, int row, int column, string direction, bool isSixthBoard);

void	stringToUppercase(string &str);

// bool	isValidMove(vector<vector<PegSolitaire::Cell>> board, int row, int column, string direction, bool isSixthBoard);

// bool	isGameFinished(vector<vector<PegSolitaire::Cell>> board, int boardSelection);

// int	gameScore(vector<vector<PegSolitaire::Cell>> board);

// void	humanPlayerGame(vector<vector<PegSolitaire::Cell>> board, int boardSelection);

// void	getRandomValidMove(vector<vector<PegSolitaire::Cell>> board, int &row, int &column, string &direction, bool isSixthBoard);

// void	computerGame(vector<vector<PegSolitaire::Cell>> board, int boardSelection);

// bool	loadFile(vector<vector<PegSolitaire::Cell>> &board, const string fileName);

// void	saveFile(vector<vector<PegSolitaire::Cell>> board, const string fileName, const bool isHuman, const int moveCounter, const bool isSixthBoard);

#endif /* _LIB_H_ */