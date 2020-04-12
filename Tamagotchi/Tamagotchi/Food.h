#pragma once
#pragma once
#include <fstream>
#include "Game.h"
#include "GraphicalObject.h"
#include <TGUI/TGUI.hpp>

class Food: public Sprite
{
protected:
	int posX, posY;
	int size;
public:
	Food(int pPosX, int pPosY, int pSize)
	{
		posX = pPosX;
		posY = pPosY;
		size = pSize;
	}
	void drawFood(RenderWindow &window);
	virtual void eatIt(Animal *& animal) = 0;
};