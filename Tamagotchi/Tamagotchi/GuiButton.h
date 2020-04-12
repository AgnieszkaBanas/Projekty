#pragma once
#include <fstream>
//#include "Game.h"
//#include "MyButton.h"
#include <TGUI/TGUI.hpp>
using namespace std;
using namespace sf;


class GuiButton: public tgui::Button
{
	int posX, posY;
	int textSize;
	int sizeButton;
	string buttonText;
	//tgui::Button* button;
	//tgui::Button::Ptr button;
	//shared_ptr<tgui::Button> button;
public:
	GuiButton() {};
	void setParameters(int pPosX, int pPosY, int pSize, string pText, int pTextSize);
	bool containsMouse(Vector2f & mouse);
	void drawInterface(RenderWindow & window);
};
