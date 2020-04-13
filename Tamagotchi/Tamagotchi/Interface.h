#pragma once
#include <fstream>
#include "GraphicalObject.h"
#include <SFML/Graphics.hpp>
#include <TGUI/Gui.hpp>
#include <vector>
#include "GuiButton.h"
#include "TextButton.h"
#include "ProgBar.h"
using namespace std;
using namespace sf;

class Interface: public tgui::Gui
{
	vector<TextButton> textButtonsMenu;
	vector<TextButton>::iterator textButtonIterator;
	shared_ptr<GuiButton> catButton;
	shared_ptr<GuiButton> dogButton;

	shared_ptr<GuiButton> firstColor;
	shared_ptr<GuiButton> secondColor;
	shared_ptr<GuiButton> thirdColor;
	
	shared_ptr<GuiButton> eat;
	shared_ptr<GuiButton> sleep;
	shared_ptr<GuiButton> play;

	shared_ptr<GuiButton> hungry;
	shared_ptr<GuiButton> tired;
	shared_ptr<GuiButton> fun;

	shared_ptr<ProgBar> progBar1;
	shared_ptr<ProgBar> progBar2;
	shared_ptr<ProgBar> progBar3;

	TextButton newGame;
	TextButton continueGame;

	TextButton wantSaveGame;
	shared_ptr<GuiButton> yes;
	shared_ptr<GuiButton> no;

	TextButton saveGame;

	TextButton gameOver;
	TextButton exitGame;
	TextButton backToMenu;

	shared_ptr<GuiButton> backToGame;
public:
	Interface(){};
	void setParametersOfInterfaceElements();
	void addTextButtonsMenu();
	void drawTextButtonsMenu(RenderWindow & window);
	bool doesTextButtonsMenuContainMouse(Vector2f & mouse, string buttonText);
	void changeColorOfTextButtonMenu(string buttonText, Color color);
	void addTguiChooseAnimal();
	bool doesTguiChooseAnimalContainMouse(Vector2f & mouse, string buttonText);
	void addTguiChooseColor();
	bool doesTguiChooseColorContainMouse(Vector2f & mouse, string buttonText);
	void addElementsOfGame();
	void incrementValuesOfProgBar();
	bool checkValuesOfProgBars();
	void decrementValueOfProgBar(string progBarName);
	bool doesTguiStartGameContainMouse(Vector2f & mouse, string buttonText);
	int getValueOfProgBar(string progBarName);
	void addSaveElements();
	void drawWantToSave(RenderWindow & window);
	bool doesTguiWantSaveGameContainMouse(Vector2f & mouse, string buttonText);
	void addSavedGame();
	void drawSavedGame(RenderWindow & window);
	void setValuesOfProgBars(string progBarName,int value);
	void addTextButtonsGameOver();
	void drawTextButtonsGameOver(RenderWindow & window);
	bool doesTextButtonGameOverContainMouse(Vector2f & mouse, string buttonText);
	void changeColorOfTextButtonGameOver(string buttonText, Color color);
	void addBackToGameButton();
	bool doesBackToGameButtonContainMouse(Vector2f & mouse, string buttonText);
};