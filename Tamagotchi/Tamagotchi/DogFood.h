#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Food.h"
using namespace std;
using namespace sf;

class DogFood:public Food
{
	string a;
	Texture dogFoodTexture;
	vector<string> dogFoodTextures;
	int counterEatingFood = 0;
public:
	DogFood(int pPosX, int pPosY, int pSize) :Food(pPosX, pPosY, pSize)
	{
		for (int i = 2; i <= 8; i++)
		{
			ostringstream ss;
			ss << i;
			string str = ss.str();
			dogFoodTextures.push_back("dogFood"+str+".png");
		}
		
		if (!dogFoodTexture.loadFromFile(dogFoodTextures[counterEatingFood]))
		{
			cerr << "Error";
		}
		this->setTexture(dogFoodTexture);
		this->setPosition(posX, posY);
		this->setScale(size, size);
	}
	void Draw(RenderWindow &window);
	void eatIt(Animal *& animal);
};
