#include "Box.h"

void Box::update(Animal *& animal, RenderWindow &window)
{
	if ((this->getPosition().x <= animal->getPosition().x+64)&&(this->getPosition().x+30 >= animal->getPosition().x + 64)&& (this->getPosition().y <= animal->getPosition().y+64) && (this->getPosition().y + 30 >= animal->getPosition().y)+64)
	{
		this->setFillColor(Color::Green);
	}
}

void Box::drawDynamicObject(RenderWindow & window)
{
	window.draw(*this);
}
