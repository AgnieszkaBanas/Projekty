#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "MyButton.h"

using namespace std;
using namespace sf;

class TextButton: public MyButton
{
	Text text;
	Color textColor;
public:
	//MButton() {};
	TextButton(string ptextState, Color pTextColor, int pTextSize, int pX, int pY):MyButton(pX,pY,pTextSize,ptextState)
	{
		textColor = pTextColor;
	};
	void Draw(RenderWindow &window);
	float getX();
	float getY();
	FloatRect gGlobalBounds();
	void changeColor(Color textColor);
	bool containsMouse(Vector2f & mouse);
};