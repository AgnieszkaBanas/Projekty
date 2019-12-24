#include "Ciastko.h"
//#include <sstream>
//#include <string>

Ciastko::Ciastko()
{
}

Ciastko::~Ciastko()
{
}

void Ciastko::rysuj(RenderWindow &window)
{
	if (!font2.loadFromFile("BebasNeue-Regular.ttf"))
	{
		// handle error
	}
	this->setFillColor(Color::Blue);
	this->setSize(Vector2f(s, w));
	this->setPosition(posX*s, posY*w);
	string strin = std::to_string(liczbaInt);
	
	liczba.setFont(font2);
	liczba.setString(strin);
	liczba.setFillColor(sf::Color::Red);
	liczba.setCharacterSize(30);
	liczba.setPosition(posX*s+7,posY*w-1);
	window.draw(*this);
	window.draw(liczba);
}

float Ciastko::jakaSzerokosc()
{
	return this->s;
}

float Ciastko::jakaWysokosc()
{
	return this->w;
}

float Ciastko::getX()
{
	return this->posX;
}

float Ciastko::getY()
{
	return this->posY;
}

void Ciastko::generujCiastko()
{
	//this->kolorCiastka = Color::Black;
	//this->setFillColor(kolorCiastka);
	liczbaInt = rand() % 9;
	float x = rand() % 10 + 1;
	float y = rand() % 10 + 1;
	this->posX = x;
	this->posY = y;
	this->setPosition(this->posX*this->s, this->posY*this->w);
}

int Ciastko::getNumber()
{
	return this->liczbaInt;
}


