#include "Interface.h"

FloatRect Interface::gGlobalBounds()
{
	return this->text.getGlobalBounds();
}

void Interface::changeColor(Color textColor)
{
	this->textColor = textColor;
	this->text.setFillColor(textColor);
}
