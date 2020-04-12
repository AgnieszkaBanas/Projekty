#pragma once
#include <fstream>
#include "GraphicalObject.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Interface
{
protected:
	int posX, posY;
	int size;
	Text text;
	Color textColor;
public:
	Interface(int pPosX, int pPosY, int pSize) : posX(pPosX), posY(pPosY), size(pSize) {};
	virtual void drawInterface(RenderWindow & window) = 0;
	FloatRect gGlobalBounds();
	void changeColor(Color textColor);
	virtual bool containsMouse(Vector2f & mouse)=0;
};