#include "GameClock.h"

void GameClock::update(Animal*&animal)
{
	ostringstream ss;
	ss << counter;
	string str = ss.str();
	this->setString(str);
	counter--;
}

void GameClock::Draw(RenderWindow & window)
{
	window.draw(*this);
}

void GameClock::setClock(int progBarValue)
{
	this->counter = progBarValue;
}

int GameClock::getCounter()
{
	return this->counter;
}
