#include "DogFood.h"

void DogFood::Draw(RenderWindow & window)
{
	window.draw(*this);
}

void DogFood::eatIt(Animal *& animal)
{
	if (!dogFoodTexture.loadFromFile(dogFoodTextures[counterEatingFood]))
	{
		cerr << "Error";
	}
	this->setPosition(animal->getPosition().x + 200, animal->getPosition().y + 80);
	this->setTexture(dogFoodTexture);
	counterEatingFood++;
	if (counterEatingFood == 7)
	{
		counterEatingFood = 0;
	}
}
