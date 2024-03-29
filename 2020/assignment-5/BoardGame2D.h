#ifndef _BOARDGAME2D_H_
#define _BOARDGAME2D_H_

#include <string>
#include <vector>

#define COLOUR_RED "\033[0;31m"
#define COLOUR_YELLOW "\033[0;33m"
#define COLOUR_BLUE "\033[0;34m"
#define DEFAULT_COLOUR "\033[0m"

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

		/* pure virtual function (= 0)*/

		/**
		 * @brief it takes a string and plays game
		 * 
		 */
		virtual void	playUser(string) = 0;
		/**
		 * @brief it takes a string 
		 * from the user for the next move in a loop and plays the game until it is over. It also prints the board 
		 * between the moves.
		 * 
		 */
		virtual void	playUser() final;
		/**
		 * @brief it plays the game by the computer for one move
		 * 
		 */
		virtual void	playAuto() = 0;
		/**
		 * @brief It plays the game until it is over. 
		 * This one calls playAuto for all the moves.
		 * It also prints the board between the moves after some pause.
		 * 
		 */
		virtual void	playAutoAll() final;
		/**
		 * @brief prints the game on the screen
		 * starting from the top left corner of the terminal.
		 * 
		 */
		virtual void	print() const = 0;

		/**
		 * @brief it returns true if the game is ended
		 * 
		 * @return true 
		 * @return false 
		 */
		virtual bool	endGame() const = 0;
		/**
		 * @brief score value.
		 * If the game is finished, it returns 0, which is the best case.
		 * const function doesn't change anything
		 */
		virtual int	boardScore() const = 0;
		virtual void	initialize() = 0;
		/**
		 * @brief it plays all the games in the vector
		 * 
		 */
		static 	void	playVector(vector<BoardGame2D*>);

		/**
		 * @brief Print the related game infos such as how can do a valid move
		 * 
		 */
		virtual void	gameInfo() const = 0;

		/**
		 * @brief for my test results
		 * 
		 */
		virtual void	writeFile() = 0;

		/**
		 * @brief Set the Board Type object for PegSolitaire class
		 * 
		 */
		virtual void	setBoardType(int) = 0;

		/**
		 * @brief is the game finished or not
		 * 
		 */
		virtual void	isFinished() final;

		friend ostream&	operator<<(ostream&, const BoardGame2D&);
	};
}

#endif /* _BOARDGAME2D_H_ */