#pragma once
#include "Animal.h"

class Cat: public Animal
{
	int enableWalking;
	int counterWalking = 0;
	int counterEating = 0;
	int counterSleeping = 0;
	Texture texCat;
public:
	Cat() {};
	Cat(string imgDirectory, int pPosX, int pPosY, int pSize) :Animal(imgDirectory, pPosX, pPosY, pSize)
	{
		this->setTexture(animalTexture);
		//this->setTextureRect(IntRect((colorIterator) * 86, 86, 86, 86));
		this->setPosition(posX,posY);
		this->setScale(size,size);
		enableWalking = 0;
	}
	void drawPlayer(RenderWindow &window)
	{
		window.draw(*this);
	}
	void moveObject(char direction, float moveSpeed);
	void eat();
	void sleep();
	void play();
	void setInitialPosition();
	void setColorIterator(int colorIterator);
};