#include "TextButton.h"
#include <TGUI/TGUI.hpp>

void TextButton::drawTextButton(RenderWindow & window)
{
	window.draw(text);
}

bool TextButton::containsMouse(Vector2f & mouse)
{
	if (this->text.getGlobalBounds().contains(mouse))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TextButton::setParameters(string ptextState, Color pTextColor, int pTextSize, int pX, int pY)
{
	posX = pX;
	posY = pY;
	size = pTextSize;
	textColor = pTextColor;
	if (!font.loadFromFile("BebasNeue-Regular.ttf"))
	{
		cout << "cos poszlo nie tak :|";
	}
	buttonText = ptextState;

	text.setFont(font);
	text.setFillColor(textColor);
	text.setCharacterSize(size);
	text.setPosition(posX, posY);
	text.setOutlineThickness(1);
	text.setOutlineColor(Color(200, 200, 250, 200));
	text.setString(buttonText);
}

void TextButton::changeColor(Color textColor)
{
	//this->textColor = textColor;
	this->text.setFillColor(textColor);
}
