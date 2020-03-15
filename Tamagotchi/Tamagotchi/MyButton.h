#pragma once
#include <fstream>
#include "GraphicalObject.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class MyButton: public GraphicalObject
{
protected:
	Font font;
	string buttonText;
public:
	MyButton(int pPosX, int pPosY, int pSize, string pText) :GraphicalObject(pPosX, pPosY, pSize)
	{
		if (!font.loadFromFile("BebasNeue-Regular.ttf"))
		{
			cout << "cos poszlo nie tak :|";
		}
		buttonText = pText;
	}
};