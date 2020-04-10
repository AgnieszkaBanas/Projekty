#include "Box.h"

void Box::update(Animal *& animal, RenderWindow &window)
{
	if (this->getPosition().x == animal->getPosition().x+32)
	{
		this->setFillColor(Color::Green);
	}
}

void Box::Draw(RenderWindow & window)
{
	window.draw(*this);
}
