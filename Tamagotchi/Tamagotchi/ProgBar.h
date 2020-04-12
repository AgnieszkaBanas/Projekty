#pragma once
#include <fstream>
#include "Game.h"
#include "Interface.h"
#include <TGUI/TGUI.hpp>


class ProgBar: public Interface, public tgui::ProgressBar, public tgui::ProgressBarRenderer
{
	
public:
	//ProgBar() {};
	ProgBar(int pPosX, int pPosY, int pSize) :Interface(pPosX, pPosY, pSize)
	{
		this->create();
		this->setSize(size,size+100);
		this->setValue(0);
		this->setPosition(posX, posY);
		this->setFillDirection(tgui::ProgressBar::FillDirection::BottomToTop);
		this->setFillColor(Color::Red);
		this->setBorderColor(Color::Green);
	}
	bool containsMouse(Vector2f & mouse);
	void drawInterface(RenderWindow & window);
};