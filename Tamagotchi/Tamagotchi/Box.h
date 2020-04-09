#pragma once
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include"Animal.h"
#include "DynamicObject.h"
using namespace sf;
using namespace std;

class Box: public DynamicObject, public RectangleShape
{
	Box(int pPosX, int pPosY, int pBallRadius) :DynamicObject(pPosX, pPosY, pBallRadius)
	{
		
	}
	void update(Animal*&animal);
	void Draw(RenderWindow &window);
};