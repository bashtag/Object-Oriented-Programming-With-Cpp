#ifndef _KLOTSKI_H_
#define _KLOTSKI_H_

#include "BoardGame2D.h"

namespace bg2d
{
	class Klotski : public BoardGame2D
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

			Klotski();
			void	randValidMove(char&, string&);
			void	makeMove(char, string);
			bool	isValidMove(char, string) const;

		private:
			vector<vector<char>>	board;
	};
}

#endif