#pragma once
#include <sstream>
#include "ObiektGraficzny.h"
#include "Ciastko.h"


class Punkty: public ObiektGraficzny
{
protected:
	Font font;
	Text punkty;
	int obecnyWynik = 0;
public:
	Punkty()
	{
	}
	virtual void rysuj(RenderWindow &window);
	virtual float jakaSzerokosc();
	virtual float jakaWysokosc();
	virtual float getX();
	virtual float getY();
	void dodajPunkty(Ciastko&ciastko);
	void wyswietlNapis();
};