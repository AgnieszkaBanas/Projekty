#include "CatFood.h"

void CatFood::eatIt(Animal *& animal)
{
	if (!catFoodTexture.loadFromFile(catFoodTextures[counterEatingFood]))
	{
		cerr << "Error";
	}
	this->setPosition(animal->getPosition().x-30, animal->getPosition().y + 45);
	this->setTexture(catFoodTexture);
	counterEatingFood++;
	if (counterEatingFood == 9)
	{
		counterEatingFood = 0;
	}
}
