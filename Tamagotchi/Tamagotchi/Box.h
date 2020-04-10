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
public:
	Box(int pPosX, int pPosY, int pBallRadius) :DynamicObject(pPosX, pPosY, pBallRadius)
	{
		this->setPosition(posX, posY);
		this->setFillColor(Color::Red);
		this->setSize(Vector2f(size,size));
	}
	void update(Animal*&animal, RenderWindow &window);
	void Draw(RenderWindow &window);
};