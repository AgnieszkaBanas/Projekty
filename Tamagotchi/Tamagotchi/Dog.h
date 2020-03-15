#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animal.h"
using namespace std;
using namespace sf;

class Dog : public Animal
{
	int enableWalking;
	int counterWalking = 0;
	int counterEating = 0;
	int counterSleeping = 0;
public:
	Dog() {};
	Dog(string imgDirectory, int pPosX, int pPosY,int pSize):Animal(imgDirectory,pPosX,pPosY,pSize)
	{
		this->setTexture(animalTexture);
		this->setPosition(posX,posY);
		this->setScale(size,size);
		enableWalking = 0;
	}
	void drawPlayer(RenderWindow &window)
	{
		window.draw(*this);
	}
	void moveDog(char direction, float moveSpeed);
	void eat();
	void sleep();
	void play();
	void setInitialPosition();
	void setColorIterator(int colorIterator);
	void changeEnableWalking(int e);
};