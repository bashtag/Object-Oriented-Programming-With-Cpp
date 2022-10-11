#include "BoardGame2D.h"

namespace bg2d
{
	class Klotski : public BoardGame2D
	{
		public:
			virtual void	playUser(string);
			virtual void	playAuto();
			virtual bool	endGame();
			virtual int	boardScore() const;
			virtual void	initialize();
			virtual void	gameInfo() const;
			virtual void	print() const;

			Klotski();
			void	randValidMove();
			void	makeMove();
			bool	isValidMove();

		private:
			vector<vector<int>>	board;
	};
}