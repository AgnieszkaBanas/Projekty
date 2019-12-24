#include "Ogon.h"
#include "Glowa.h"

void Ogon::idz(string kierunek)
{
	
}

void Ogon::rysuj(RenderWindow &window)
{
	this->setFillColor(kolorOgona);
	this->setSize(Vector2f(s, w));
	this->setPosition(posX*s, posY*w);
	window.draw(*this);
}

float Ogon::jakaSzerokosc()
{
	return this->s;
}

float Ogon::jakaWysokosc()
{
	return this->w;
}

float Ogon::getX()
{
	return this->posX;
}

float Ogon::getY()
{
	return this->posY;
}

void Ogon::ustawNowaPozycje(float x,float y)
{
	oldX =this->posX;
	oldY = this->posY;

	this->posX = x;
	this->posY = y;
	this->setPosition(this->posX*this->s, this->posY*this->w);
}


bool Ogon::sprawdzKolizje(ObiektGraficzny & obiekt)
{
	if (obiekt.getX() == this->getX() && obiekt.getY() == this->getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Ogon::getOldX()
{
	return oldX;
}

float Ogon::getOldY()
{
	return oldY;
}


