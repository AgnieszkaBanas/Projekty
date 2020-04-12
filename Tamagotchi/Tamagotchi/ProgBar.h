#pragma once
#include <fstream>
//#include "Game.h"
//#include "Interface.h"
#include <TGUI/TGUI.hpp>
using namespace std;
using namespace sf;

class ProgBar: public tgui::ProgressBar, public tgui::ProgressBarRenderer
{
	int posX, posY, size;
public:
	//ProgBar() {};
	ProgBar(){};
	bool containsMouse(Vector2f & mouse);
	void drawInterface(RenderWindow & window);
	void setParameters(int pPosX, int pPosY, int pSize);
};
