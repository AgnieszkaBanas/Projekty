#include "Glowa.h"

Glowa::Glowa()
{
	
}

void Glowa::idz(string kierunek)
{
	if (kierunek == "gora")
	{
		posY=posY-1;
	}
	if (kierunek == "dol")
	{
		posY = posY + 1;
	}
	if (kierunek == "lewo")
	{
		posX = posX - 1;
	}
	if (kierunek == "prawo")
	{
		posX = posX + 1;
	}
}


void Glowa::rysuj(RenderWindow &window)
{
	this->setFillColor(kolorGlowy);
	this->setSize(Vector2f(s, w));
	this->setPosition(posX*s, posY*w);
	window.draw(*this);
}

float Glowa::jakaSzerokosc()
{
	return this->s;
}

float Glowa::jakaWysokosc()
{
	return this->w;
}

float Glowa::getX()
{
	return this->posX;
}

float Glowa::getY()
{
	return this->posY;
}

void Glowa::ustawNowaPozycje(float x,float y)
{
}


bool Glowa::sprawdzKolizje(ObiektGraficzny & obiekt)
{
	if (this->getX() == obiekt.getX() && this->getY() == obiekt.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

