#include "GuiButton.h"

bool GuiButton::containsMouse(Vector2f & mouse)
{
	if (this->mouseOnWidget(mouse))
		return true;
	else
		return false;
}

/*
void GuiButton::drawInterface(RenderWindow & window)
{
	window.draw(*this);
}
*/

void GuiButton::setParameters(int pPosX, int pPosY, int pSize, string pText, int pTextSize)
{
	//button = new tgui::Button();
	//shared_ptr<tgui::Button> p1(button);
	//button->create();
	//button = make_shared<tgui::Button>();
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
