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
};