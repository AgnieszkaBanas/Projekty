#include "CatFood.h"

void CatFood::Draw(RenderWindow & window)
{
	window.draw(*this);
}

void CatFood::eatIt(Animal *& animal)
{
	if (!catFoodTexture.loadFromFile(catFoodTextures[counterEatingFood]))
	{
		cerr << "Error";
	}
	this->setPosition(animal->getPosition().x-30, animal->getPosition().y + 20);
	this->setTexture(catFoodTexture);
	//counterEatingFood++;
	if (counterEatingFood == 7)
	{
		counterEatingFood = 0;
	}
}
