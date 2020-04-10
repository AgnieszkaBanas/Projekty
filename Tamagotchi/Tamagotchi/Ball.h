#pragma once
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include"Animal.h"
#include "DynamicObject.h"
using namespace sf;
using namespace std;

class Ball: public DynamicObject, public CircleShape
{
	float ballVelocity = 5.0f;
	Vector2f velocity{ballVelocity,ballVelocity };
public:
	Ball(int pPosX,int pPosY,int pBallRadius):DynamicObject(pPosX,pPosY,pBallRadius)
	{
		this->setRadius(size);
		this->setFillColor(Color::Red);
		this->setPosition(posX,posY);
	}
	void update(Animal*&animal, RenderWindow &window);
	void Draw(RenderWindow &window);
};