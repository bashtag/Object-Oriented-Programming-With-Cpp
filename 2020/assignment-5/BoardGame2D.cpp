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
			this_thread::sleep_for(chrono::milliseconds(700));
		}
		this->print();
	}

	void	BoardGame2D::playUser()
	{
		string	nextMove;

		this->gameInfo();
		while (!this->endGame())
		{
			this->print();
			cout << "Give me a valid move: " << endl;
			cin >> nextMove;
			cin.clear();

			this->playUser(nextMove);
		}
	}

	void	playVector(vector<BoardGame2D*> gameVec)
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
}