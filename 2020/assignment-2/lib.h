#ifndef _LIB_H_
#define _LIB_H_

#include <string>
#include <vector>

#define COLOUR_BLUE "\033[0;34m"
#define DEFAULT_COLOUR "\033[0m"

using namespace std;

enum class Cell {none, empty, peg};

vector<vector<Cell>>	createBoard(int boardSelection);

void	printBoard(vector<vector<Cell>> board);

void	makeMove(vector<vector<Cell>> &board, int row, int column, string direction, bool isSixthBoard);

void	stringToUppercase(string &str);

bool	isValidMove(vector<vector<Cell>> board, int row, int column, string direction, bool isSixthBoard);

bool	isGameFinished(vector<vector<Cell>> board, int boardSelection);

int	gameScore(vector<vector<Cell>> board);

void	humanPlayerGame(vector<vector<Cell>> board, int boardSelection);

void	getRandomValidMove(vector<vector<Cell>> board, int &row, int &column, string &direction, bool isSixthBoard);

void	computerGame(vector<vector<Cell>> board, int boardSelection);

bool	loadFile(vector<vector<Cell>> &board, const string fileName);

void	saveFile(vector<vector<Cell>> board, const string fileName, const bool isHuman, const int moveCounter, const bool isSixthBoard);

#endif /* _LIB_H_ */