#pragma once
#include <fstream>
#include <TGUI/TGUI.hpp>
using namespace std;
using namespace sf;


class GuiButton: public tgui::Button
{
	int posX, posY;
	int textSize;
	int sizeButton;
	string buttonText;
public:
	GuiButton() {};
	void setParameters(int pPosX, int pPosY, int pSize, string pText, int pTextSize);
	bool containsMouse(Vector2f & mouse);
};
