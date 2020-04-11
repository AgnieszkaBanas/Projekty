#include "Animal.h"

void Animal::drawAnimal(RenderWindow & window)
{
	window.draw(*this);
}

void Animal::setColorIterator(int colorIterator)
{
	this->colorIterator = colorIterator;
}

void Animal::changeEnableWalking(int e)
{
	this->enableWalking = e;
}

int Animal::getColorIterator()
{
	return this->colorIterator;
}
