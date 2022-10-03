#ifndef _BOARDGAME2D_H_
#define _BOARDGAME2D_H_

#include <string>

using namespace std;

/**
 * @brief 2D board games
 * 
 */
namespace bg2d
{
	class BoardGame2D
	{
	private:
	public:
		BoardGame2D();
		~BoardGame2D();

		void	playUser(string);
		virtual void	playUser() final;

	};
}

#endif /* _BOARDGAME2D_H_ */