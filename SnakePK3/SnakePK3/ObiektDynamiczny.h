#pragma once
#include <iostream>
#include "ObiektGraficzny.h"
#include "Ciastko.h"
using namespace std;

class ObiektDynamiczny: public ObiektGraficzny
{
protected:
	float oldX;
	float oldY;
public:
	ObiektDynamiczny();
	ObiektDynamiczny(float szerokosc, float wysokosc, float pozycjaX, float pozycjaY) :ObiektGraficzny(szerokosc, wysokosc,pozycjaX,pozycjaY) 
	{
		oldX = 0;
		oldY = 0;
	};
	virtual void idz(string kierunek)=0;
	virtual void ustawNowaPozycje(float x,float y) = 0;
	virtual bool sprawdzKolizje(ObiektGraficzny&obiekt) = 0;
};