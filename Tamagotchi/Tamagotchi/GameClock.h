#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "DynamicObject.h"
#include "Dog.h"
using namespace std;
using namespace sf;

class GameClock :public DynamicObject, public Text
{
	int counter = 0;
	Color textColor;
	Font font;
public:
	GameClock(int pPosX, int pPosY, int pSize) :DynamicObject(pPosX, pPosY, pSize)
	{
		if (!font.loadFromFile("BebasNeue-Regular.ttf"))
		{
			cout << "cos poszlo nie tak :|";
		}
		textColor = Color::Red;
	};
	void update(Dog*&dog);
	void Draw(RenderWindow &window);
};