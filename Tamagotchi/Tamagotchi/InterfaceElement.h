#pragma once

class InterfaceElement
{
protected:
	int posX, posY;
	int size;
public:
	InterfaceElement(int pX, int pY, int pSize) :posX(pX), posY(pY), size(pSize) {};
};