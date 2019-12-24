#pragma once
#include "ObiektDynamiczny.h"

class Ogon: public ObiektDynamiczny
{
	Color kolorOgona;
	float oldX;
	float oldY;

public:
	Ogon(float szerokosc,float wysokosc, Color pKolorOgona,float pozycjaX,float pozycjaY) :ObiektDynamiczny(szerokosc, wysokosc,pozycjaX,pozycjaY)
	{
		kolorOgona = pKolorOgona;
		oldX = 0;
		oldY = 0;
	};
	virtual void idz(string kierunek);
	virtual void rysuj(RenderWindow &window);
	virtual float jakaSzerokosc();
	virtual float jakaWysokosc();
	virtual float getX();
	virtual float getY();
	virtual void ustawNowaPozycje(float x,float y);
	virtual bool sprawdzKolizje(ObiektGraficzny&obiekt);
	float getOldX();
	float getOldY();
};