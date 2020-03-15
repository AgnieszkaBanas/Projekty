#pragma once
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include"Dog.h"
#include "GraphicalObject.h"
using namespace sf;
using namespace std;

class Ball: public GraphicalObject, public CircleShape
{
	float ballVelocity = 5.0f;
	Vector2f velocity{ballVelocity,ballVelocity };
public:
	Ball(int pPosX,int pPosY,int pBallRadius):GraphicalObject(pPosX,pPosY,pBallRadius)
	{
		this->setRadius(size);
		this->setFillColor(Color::Red);
		this->setPosition(posX,posY);
	}
	void update(Dog*&dog);
	void Draw(RenderWindow &window);
};