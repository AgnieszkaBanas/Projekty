#include "GuiButton.h"

bool GuiButton::containsMouse(Vector2f & mouse)
{
	if (this->mouseOnWidget(mouse))
		return true;
	else
		return false;
}

void GuiButton::setParameters(string pText,int pTextSize, Color pTextColor, int pSize, int pX, int pY)
{
	size = pSize;
	buttonText = pText;
	posX = pX;
	posY = pY;
	textSize = pTextSize;
	this->setText(buttonText);
	this->setSize(size + 50, size);
	this->setPosition(posX, posY);

	this->setInheritedFont("BebasNeue-Regular.ttf");
	this->setTextSize(textSize);
}
