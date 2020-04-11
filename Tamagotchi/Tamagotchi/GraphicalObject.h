#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "GraphicalObject.h"
using namespace std;
using namespace sf;

class GraphicalObject
{
protected:
	int posX, posY;
	int size;
public:
	GraphicalObject() {};
	GraphicalObject(int pPosX, int pPosY, int pSize) : posX(pPosX), posY(pPosY), size(pSize) {};
};