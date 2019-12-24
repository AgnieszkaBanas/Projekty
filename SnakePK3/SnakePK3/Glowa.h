#pragma once
#include "ObiektDynamiczny.h"

class Glowa:public ObiektDynamiczny
{
	Color kolorGlowy;
public:
	Glowa();
	Glowa(float szerokosc,float wysokosc, Color pKolorGlowy,float pozycjaX, float pozycjaY) :ObiektDynamiczny(szerokosc, wysokosc, pozycjaX, pozycjaY)
	{
		kolorGlowy = pKolorGlowy;
	};
	virtual void idz(string kierunek);
	virtual void rysuj(RenderWindow &window);
	virtual float jakaSzerokosc();
	virtual float jakaWysokosc();
	virtual float getX();
	virtual float getY();
	virtual void ustawNowaPozycje(float x,float y);
	virtual bool sprawdzKolizje(ObiektGraficzny&obiekt);
};