#pragma once
#include <fstream>
#include "Interface.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class MyButton: public Interface
{
protected:
	Font font;
	string buttonText;
public:
	MyButton(int pPosX, int pPosY, int pSize, string pText) :Interface(pPosX, pPosY, pSize)
	{
		if (!font.loadFromFile("BebasNeue-Regular.ttf"))
		{
			cout << "cos poszlo nie tak :|";
		}
		buttonText = pText;
	}
};