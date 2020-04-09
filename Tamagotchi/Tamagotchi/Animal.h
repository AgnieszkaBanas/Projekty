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
	virtual void drawPlayer(RenderWindow &window) = 0;
	virtual void moveObject(char direction, float moveSpeed) = 0;
	virtual void eat() = 0;
	virtual void sleep() = 0;
	virtual void play() = 0;
	virtual void setInitialPosition() = 0;
	virtual void setColorIterator(int colorIterator) = 0;
	virtual int getColorIterator() = 0;
	virtual void changeEnableWalking(int e) = 0;
};
