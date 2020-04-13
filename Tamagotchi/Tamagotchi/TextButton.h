#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
//#include "MyButton.h"

using namespace std;
using namespace sf;

class TextButton
{
	int posX, posY;
	int size;
	Text text;
	Color textColor;
	Font font;
	string buttonText;
public:
	TextButton() {};
	void drawTextButton(RenderWindow & window);
	bool containsMouse(Vector2f & mouse);
	void setParameters(string ptextState, Color pTextColor, int pTextSize, int pX, int pY);
	bool operator==(const TextButton &q) 
	{ 
		if (this->buttonText == q.buttonText)
			return true;
		else
			return false;
	};
	void changeColor(Color textColor);
};