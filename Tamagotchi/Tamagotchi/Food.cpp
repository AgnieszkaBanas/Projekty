#include "Food.h"

void Food::Draw(RenderWindow & window)
{
	window.draw(*this);
}

void Food::setFoodPosition(Animal *& animal)
{
	this->setPosition(animal->getPosition().x + 200, animal->getPosition().y + 80);
}
