#include <SFML/Graphics.hpp>
#include "ObiektGraficzny.h"

ObiektGraficzny::ObiektGraficzny()
{
}

ObiektGraficzny::ObiektGraficzny(float szerokosc,float wysokosc,float pozycjaX, float pozycjaY)
{
	cout << "konstrutor";
	s = szerokosc;
	w = wysokosc;
	posX = pozycjaX;
	posY = pozycjaY;
}

