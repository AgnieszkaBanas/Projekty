#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "DynamicObject.h"
#include "Animal.h"
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
		ostringstream ss;
		ss << counter;
		string str = ss.str();
		this->setFont(font);
		this->setFillColor(textColor);
		this->setOutlineThickness(1);
		this->setOutlineColor(Color(200, 200, 250, 200));
		this->setString(str);
		this->setCharacterSize(size);
		this->setPosition(posX, posY);
	};
	void update(Animal*&animal, RenderWindow &window);
	void Draw(RenderWindow &window);
	void setClock(int progBarValue);
	int getCounter();
};