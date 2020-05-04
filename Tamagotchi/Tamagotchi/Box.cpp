#include "Box.h"

void Box::update(Animal *& animal, RenderWindow &window)
{
	if ((this->getPosition().x <= animal->getPosition().x+128)&&(this->getPosition().x+50 >= animal->getPosition().x+125)&& (this->getPosition().y <= animal->getPosition().y+32) && (this->getPosition().y + 50 >= animal->getPosition().y+32))
	{
		this->setFillColor(Color::Green);
	}
}

void Box::drawDynamicObject(RenderWindow & window)
{
	window.draw(*this);
}
