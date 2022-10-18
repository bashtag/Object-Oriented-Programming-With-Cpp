#ifndef _EIGHTPUZZLE_H_
#define _EIGHTPUZZLE_H_

#include "BoardGame2D.h"

namespace bg2d
{
	class	EightPuzzle : public BoardGame2D
	{
		public:
			virtual void	playUser(string);
			virtual void	playAuto();
			virtual bool	endGame() const;
			virtual int	boardScore() const;
			virtual void	initialize();
			virtual void	gameInfo() const;
			virtual void	print() const;
			virtual void	writeFile();
			virtual void	setBoardType(int);

			EightPuzzle();
			void	randValidMove(int&, int&, string&);
			void	makeMove(int, int, string);
			bool	isValidMove(int, int, string) const;

		private:
			vector<vector<int>>	board;
	};
}

#endif