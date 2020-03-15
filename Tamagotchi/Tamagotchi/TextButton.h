#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "GraphicalObject.h"

using namespace std;
using namespace sf;

class TextButton: public GraphicalObject
{
	Font font;
	Text text;
	Color textColor;
	string textState;
public:
	//MButton() {};
	TextButton(string ptextState, Color pTextColor, int pTextSize, int pX, int pY):GraphicalObject(pX,pY,pTextSize)
	{
		textColor = pTextColor;
		textState = ptextState;
	};
	void Draw(RenderWindow &window);
	float getX();
	float getY();
	FloatRect gGlobalBounds();
	void changeColor(Color textColor);
	bool containsMouse(Vector2f & mouse);
};