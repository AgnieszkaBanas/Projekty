#pragma once
#include "ObiektGraficzny.h"

class Ciastko: public ObiektGraficzny
{
protected:
	Color kolorCiastka;
	Text liczba;
	Font font2;
	int liczbaInt=1;
public:
	Ciastko();
	Ciastko(float szerokosc,float wysokosc, Color kolorC,float pozycjaX, float pozycjaY) :ObiektGraficzny(szerokosc, wysokosc,pozycjaX,pozycjaY)
	{
		kolorCiastka = kolorC;
	};
	~Ciastko();
	virtual void rysuj(RenderWindow &window);
	virtual float jakaSzerokosc();
	virtual float jakaWysokosc();
	virtual float getX();
	virtual float getY();
	void generujCiastko();
	int getNumber();
};