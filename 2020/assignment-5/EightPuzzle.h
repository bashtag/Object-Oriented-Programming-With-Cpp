#include "BoardGame2D.h"

namespace bg2d
{
	class	EightPuzzle : public BoardGame2D
	{
		public:
			virtual void	playUser(string);
			virtual void	playAuto();
			virtual bool	endGame();
			virtual int	boardScore() const;
			virtual void	initialize();
			virtual void	gameInfo() const;
			virtual void	print() const;

			EightPuzzle();
			void	randValidMove(int&, int&, string&);
			void	makeMove(int, int, string);
			bool	isValidMove(int, int, string) const;

		private:
			vector<vector<int>>	board;
	};
}