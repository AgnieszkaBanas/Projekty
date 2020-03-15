#pragma once
#pragma once
#include <fstream>
#include "Game.h"
#include "GraphicalObject.h"
#include <TGUI/TGUI.hpp>

class Food: public GraphicalObject, public Sprite
{
	Texture texture;
public:
	Food(string imgDirectory,int pPosX, int pPosY, int pSize) :GraphicalObject(pPosX, pPosY, pSize)
	{
		if (!texture.loadFromFile(imgDirectory))
		{
			cerr << "Error";
		}
		this->setTexture(texture);
		this->setPosition(posX, posY);
		this->setScale(size, size);
	}
	void Draw(RenderWindow &window);
	void setFoodPosition(Animal*&animal);
};