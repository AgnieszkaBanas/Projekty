#pragma once

class GraphicalObject
{
protected:
	int posX, posY;
	int size;
public:
	GraphicalObject() {};
	GraphicalObject(int pPosX, int pPosY, int pSize) : posX(pPosX), posY(pPosY), size(pSize) {};
};