#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "InterfaceElement.h"

using namespace std;
using namespace sf;

class TextButton: public InterfaceElement
{
	Text text;
	Color textColor;
	Font font;
public:
	TextButton() {};
	void drawTextButton(RenderWindow & window);
	bool containsMouse(Vector2f & mouse);
	void setParameters(string pText, int pTextSize, Color pTextColor, int pSize, int pX, int pY);
	bool operator==(const TextButton &q) 
	{ 
		if (this->buttonText == q.buttonText)
			return true;
		else
			return false;
	};
	void changeColor(Color textColor);
};