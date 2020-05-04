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
		this->setOutlineThickness(2);
		this->setOutlineColor(Color(100, 250, 10, 200));
		this->setSize(Vector2f(size,size));
	}
	void update(Animal*&animal, RenderWindow &window);
	void drawDynamicObject(RenderWindow &window);
};