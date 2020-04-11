#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "GraphicalObject.h"
using namespace std;
using namespace sf;

class Animal : public GraphicalObject, public Sprite
{
protected:
	int enableWalking;
	int counterWalking = 0;
	int counterEating = 0;
	int counterSleeping = 0;
	Texture animalTexture;
	int colorIterator;
public:
	Animal() {};
	int flagPosition = 0;
	Animal(string imgDirectory,int pPosX, int pPosY,int pSize) :GraphicalObject(pPosX,pPosY,pSize)
	{
		if (!animalTexture.loadFromFile(imgDirectory))
		{
			cerr << "Error";
		}
	};
	void drawAnimal(RenderWindow &window);
	void setColorIterator(int colorIterator);
	void changeEnableWalking(int e);
	int getColorIterator();
	virtual void moveAnimal(char direction, float moveSpeed) = 0;
	virtual void eat() = 0;
	virtual void sleep() = 0;
	virtual void play() = 0;
	virtual void setInitialPosition() = 0;
};
