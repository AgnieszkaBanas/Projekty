#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Food.h"
using namespace std;
using namespace sf;

class CatFood : public Food
{
	Texture catFoodTexture;
	vector<string> catFoodTextures;
	int counterEatingFood = 0;
public:
	CatFood(int pPosX, int pPosY, int pSize) :Food(pPosX, pPosY, pSize)
	{
		for (int i = 1; i <= 9; i++)
		{
			ostringstream ss;
			ss << i;
			string str = ss.str();
			catFoodTextures.push_back("catFood" + str + ".png");
		}

		if (!catFoodTexture.loadFromFile(catFoodTextures[counterEatingFood]))
		{
			cerr << "Error";
		}
		this->setTexture(catFoodTexture);
		this->setPosition(posX, posY);
		this->setScale(size, size);
	}
	void eatIt(Animal *& animal);
};
