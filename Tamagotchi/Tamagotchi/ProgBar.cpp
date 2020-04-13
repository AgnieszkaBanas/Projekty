#include "ProgBar.h"

void ProgBar::setParameters(int pPosX, int pPosY, int pSize)
{
	posX = pPosX;
	posY = pPosY;
	size = pSize;
	//this->create();
	this->setSize(size, size + 100);
	
	this->setValue(0);
	
	this->setPosition(posX, posY);
	this->setFillDirection(tgui::ProgressBar::FillDirection::BottomToTop);
	this->setFillColor(Color::Red);
	this->setBorderColor(Color::Green);
}
