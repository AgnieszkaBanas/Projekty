#include "Punkty.h"

void Punkty::rysuj(RenderWindow & window)
{
	if (!font.loadFromFile("BebasNeue-Regular.ttf"))
	{
		// handle error
	}
	punkty.setFont(font);
	punkty.setFillColor(sf::Color::Red);
	punkty.setCharacterSize(30);
	punkty.setPosition(4, 5);
	stringstream s;
	s << obecnyWynik;
	punkty.setString(s.str());
	window.draw(punkty);
}

float Punkty::jakaSzerokosc()
{
	return 0.0f;
}

float Punkty::jakaWysokosc()
{
	return 0.0f;
}

float Punkty::getX()
{
	return 0.0f;
}

float Punkty::getY()
{
	return 0.0f;
}

void Punkty::dodajPunkty(Ciastko & ciastko)
{
	obecnyWynik += ciastko.getNumber();
}



void Punkty::wyswietlNapis()
{

}
