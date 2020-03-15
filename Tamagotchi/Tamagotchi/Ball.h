#pragma once
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include"Dog.h"
using namespace sf;
using namespace std;

class Ball: public CircleShape
{
	int ballRadius;
	float ballVelocity = 5.0f;
	Vector2f velocity{ballVelocity,ballVelocity };
public:
	Ball(int pBallRadius)
	{
		ballRadius = pBallRadius;
		this->setRadius(ballRadius);
		this->setFillColor(Color::Red);
		this->setPosition(200,200);
	}
	void update(Dog*&dog);
	void Draw(RenderWindow &window);
};