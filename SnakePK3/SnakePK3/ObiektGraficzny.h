#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class ObiektGraficzny: public RectangleShape
{
protected:
	float s, w;
	float posX, posY;
public:
	ObiektGraficzny();
	ObiektGraficzny(float szerokosc, float wysokosc,float pozycjaX, float pozycjaY );
	virtual void rysuj(RenderWindow &window) = 0;
	virtual float jakaSzerokosc() = 0;
	virtual float jakaWysokosc() = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
};