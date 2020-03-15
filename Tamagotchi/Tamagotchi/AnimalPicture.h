#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "GraphicalObject.h"
using namespace std;
using namespace sf;

class AnimalPicture: public GraphicalObject, public Sprite
{
	int colorIterator;
	Texture texAnimals;
public:
	AnimalPicture(int pColorIterator,string imgDirectory, int pSize,int pPosX, int pPosY):GraphicalObject(pPosX,pPosY, pSize)
	{
		if (!texAnimals.loadFromFile(imgDirectory))
		{
			cerr << "Error";
		}
		this->setTexture(texAnimals);
		this->setPosition(posX,posY);
		this->setScale(size,size);
		this->colorIterator = pColorIterator;
		this->setTextureRect(IntRect(colorIterator*86, 86, 86, 86));
	}
	void Draw(RenderWindow &window);
};