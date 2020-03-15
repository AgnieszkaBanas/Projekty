#pragma once
#include <fstream>
#include "Game.h"
#include "GraphicalObject.h"
#include <TGUI/TGUI.hpp>

class ProgBar: public GraphicalObject, public tgui::ProgressBar, public tgui::ProgressBarRenderer
{
public:
	ProgBar() {};
	ProgBar(int pPosX, int pPosY, int pSize) :GraphicalObject(pPosX, pPosY, pSize)
	{
		this->create();
		this->setSize(size,size+100);
		this->setValue(0);
		this->setPosition(posX, posY);
		this->setFillDirection(tgui::ProgressBar::FillDirection::BottomToTop);
		this->setFillColor(Color::Red);
		this->setBorderColor(Color::Green);
	}
};