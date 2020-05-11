#include "ProgBar.h"

void ProgBar::setParameters(string pText, int pTextSize, Color pTextColor, int pSize, int pX, int pY)
{
	posX = pX;
	posY = pY;
	size = pSize;
	//this->create();
	this->setSize(size, size + 100);
	
	this->setValue(0);
	
	this->setPosition(posX, posY);
	this->setFillDirection(tgui::ProgressBar::FillDirection::BottomToTop);
	this->setFillColor(Color::Red);
	this->setBorderColor(Color::Green);
}
