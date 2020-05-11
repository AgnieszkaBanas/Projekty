#pragma once
#include <fstream>
//#include "Game.h"
#include "InterfaceElement.h"
#include <TGUI/TGUI.hpp>
using namespace std;
using namespace sf;

class ProgBar: public InterfaceElement, public tgui::ProgressBar, public tgui::ProgressBarRenderer
{
public:
	//ProgBar(){};
	void setParameters(string pText, int pTextSize, Color pTextColor, int pSize, int pX, int pY);
};
