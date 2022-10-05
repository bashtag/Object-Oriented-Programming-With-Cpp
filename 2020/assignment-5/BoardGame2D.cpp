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
			this->playAuto();
			this->print();
		}
		this_thread::sleep_for(chrono::milliseconds(700));
	}

	void	BoardGame2D::playUser()
	{
		string	nextMove;

		while (!this->endGame())
		{
			cout << "Give me a move: " << endl;
			cin >> nextMove;
			cin.clear();

			this->playUser(nextMove);
		}
	}

	void	BoardGame2D::print()
	{
		cout << (*this);
	}

	void	playVector(vector<BoardGame2D*> gameVec)
	{
		for (BoardGame2D* game : gameVec)
		{
			game->playAutoAll();
		}
	}
}