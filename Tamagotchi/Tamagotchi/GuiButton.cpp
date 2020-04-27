#include "GuiButton.h"

bool GuiButton::containsMouse(Vector2f & mouse)
{
	if (this->mouseOnWidget(mouse))
		return true;
	else
		return false;
}

void GuiButton::setParameters(int pPosX, int pPosY, int pSize, string pText, int pTextSize)
{
	sizeButton = pSize;
	buttonText = pText;
	posX = pPosX;
	posY = pPosY;
	textSize = pTextSize;
	this->setText(buttonText);
	this->setSize(sizeButton + 50, sizeButton);
	this->setPosition(posX, posY);

	this->setInheritedFont("BebasNeue-Regular.ttf");
	this->setTextSize(textSize);
}
