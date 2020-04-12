#include "GuiButton.h"

bool GuiButton::containsMouse(Vector2f & mouse)
{
	if (this->mouseOnWidget(mouse))
		return true;
	else
		return false;
}

void GuiButton::drawInterface(RenderWindow & window)
{

}
