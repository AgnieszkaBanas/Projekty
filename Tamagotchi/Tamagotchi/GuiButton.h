#pragma once
#include <fstream>
#include "Game.h"
#include "GraphicalObject.h"
#include <TGUI/TGUI.hpp>
using namespace std;

class GuiButton: public GraphicalObject, public tgui::Button
{
	string tText;
public:
	GuiButton(int pPosX, int pPosY, int pSize, string pText) :GraphicalObject(pPosX, pPosY, pSize)
	{
		tText = pText;
		this->create();
		this->setText(tText);
		this->setSize(size+50,size);
		this->setPosition(posX, posY);
		
		this->setInheritedFont("BebasNeue-Regular.ttf");
		this->setTextSize(20);
	};
};