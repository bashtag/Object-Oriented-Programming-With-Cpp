#include <iostream>
#include <thread>
#include <chrono>
#include "BoardGame2D.h"

using namespace	std;

namespace bg2d
{
	BoardGame2D::BoardGame2D() {}

	void	BoardGame2D::playAutoAll()
	{
		while (!this->endGame())
		{
			this->print();
			this->playAuto();
			this->writeFile();
			this_thread::sleep_for(chrono::milliseconds(700));
		}
		this->print();

		cout << "Game is finished your score is: " << this->boardScore() << endl;
	}

	void	BoardGame2D::playUser()
	{
		string	nextMove;

		while (!this->endGame() && (nextMove != "M" && nextMove != "m"))
		{
			cout << endl;
			this->gameInfo();
			this->print();
			cout << "Give me a valid move or switch the other game, enter 'M': " << endl;
			cin >> nextMove;
			cin.clear();

			if (nextMove != "M" && nextMove != "m")
				this->playUser(nextMove);
			this->writeFile();
		}

		cout << "Game is finished your score is: " << this->boardScore() << endl;
	}

	void	BoardGame2D::playVector(vector<BoardGame2D*> gameVec)
	{
		for (BoardGame2D* game : gameVec)
		{
			game->playAutoAll();
		}
	}

	ostream&	operator<<(ostream& output, const BoardGame2D& obj)
	{
		obj.print();
		return (output);
	}

	void	BoardGame2D::isFinished()
	{
		if (!this->endGame())
			cout << "The game is not finished yet!" << endl;
	}
}