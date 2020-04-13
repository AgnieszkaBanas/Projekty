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
	void setParameters(int pPosX, int pPosY, int pSize);
};
