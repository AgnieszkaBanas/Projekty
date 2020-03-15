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
	int sizeOfImage;
	int ifCat;
public:
	AnimalPicture(int pColorIterator,string imgDirectory, int pSize,int pPosX, int pPosY, int pSizeOfImage, int pIfCat):GraphicalObject(pPosX,pPosY, pSize)
	{
		ifCat = pIfCat;
		sizeOfImage = pSizeOfImage;
		if (!texAnimals.loadFromFile(imgDirectory))
		{
			cerr << "Error";
		}
		this->setTexture(texAnimals);
		this->setPosition(posX,posY);
		this->setScale(size,size);
		this->colorIterator = pColorIterator;
		this->setTextureRect(IntRect(colorIterator*sizeOfImage, sizeOfImage*ifCat, sizeOfImage, sizeOfImage));
	}
	void Draw(RenderWindow &window);
};