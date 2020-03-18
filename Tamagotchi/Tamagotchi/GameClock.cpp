#include "GameClock.h"

void GameClock::update(Dog *& dog)
{
	ostringstream ss;
	ss << counter;
	string str = ss.str();
	this->setFont(font);
	this->setFillColor(textColor);
	this->setOutlineThickness(1);
	this->setOutlineColor(Color(200, 200, 250, 200));
	this->setString(str);
	this->setCharacterSize(size);
	this->setPosition(posX, posY);
}

void GameClock::Draw(RenderWindow & window)
{
	window.draw(*this);
}
