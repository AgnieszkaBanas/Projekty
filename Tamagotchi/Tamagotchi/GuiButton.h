#pragma once
#include <fstream>
#include <TGUI/TGUI.hpp>
#include "InterfaceElement.h"
using namespace std;
using namespace sf;


class GuiButton: public InterfaceElement, public tgui::Button
{
	int textSize;
public:
	//GuiButton() {};
	void setParameters(string pText, int pTextSize, Color pTextColor, int pSize, int pX, int pY);
	bool containsMouse(Vector2f & mouse);
};
