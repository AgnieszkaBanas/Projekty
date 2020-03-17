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
public:
	Interface(int pPosX, int pPosY, int pSize) : posX(pPosX), posY(pPosY), size(pSize) {};
	virtual FloatRect gGlobalBounds() = 0;
	virtual void Draw(RenderWindow &window) = 0;
	virtual void changeColor(Color textColor)=0;
	virtual bool containsMouse(Vector2f & mouse)=0;
};