#include "GuiButton.h"

FloatRect GuiButton::gGlobalBounds()
{
	return FloatRect();
}

void GuiButton::Draw(RenderWindow & window)
{
}

void GuiButton::changeColor(Color textColor)
{
}

bool GuiButton::containsMouse(Vector2f & mouse)
{
	if (this->mouseOnWidget(mouse))
		return true;
	else
		return false;
}
