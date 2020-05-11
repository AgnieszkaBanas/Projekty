#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class InterfaceElement
{
protected:
	int posX, posY;
	int size;
	string buttonText;
public:
	virtual void setParameters(string pText, int pTextSize, Color pTextColor, int pSize, int pX, int pY) = 0;
};