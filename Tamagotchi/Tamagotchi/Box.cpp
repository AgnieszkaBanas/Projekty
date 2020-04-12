#include "Box.h"

void Box::update(Animal *& animal, RenderWindow &window)
{
	if ((this->getPosition().x < animal->getPosition().x+32)&&(this->getPosition().x+50 > animal->getPosition().x + 32))
	{
		this->setFillColor(Color::Green);
	}
}

void Box::drawDynamicObject(RenderWindow & window)
{
	window.draw(*this);
}
