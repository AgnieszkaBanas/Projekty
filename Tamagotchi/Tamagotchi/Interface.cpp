#include "Interface.h"
#include "TextButton.h"
#include "GuiButton.h"

/*
FloatRect Interface::gGlobalBounds()
{
	return this->text.getGlobalBounds();
}

void Interface::changeColor(Color textColor)
{
	this->textColor = textColor;
	this->text.setFillColor(textColor);
}
*/

void Interface::setParametersOfInterfaceElements()
{
	newGame.setParameters("NEW GAME", Color(24, 34, 65, 76), 120, 420, 200);
	continueGame.setParameters("CONTINUE GAME", Color(0, 0, 0, 255), 100, 375, 350);

	catButton = make_shared<GuiButton>();
	dogButton = make_shared<GuiButton>();
	catButton->setParameters(450, 400, 80, "CAT", 30);
	dogButton->setParameters(650, 400, 80, "DOG", 30);

	firstColor = make_shared<GuiButton>();
	secondColor = make_shared<GuiButton>();
	thirdColor = make_shared<GuiButton>();
	firstColor->setParameters(250, 500, 90, "1", 40);
	secondColor->setParameters(550, 500, 90, "2", 40);
	thirdColor->setParameters(850, 500, 90, "3", 40);

	eat = make_shared<GuiButton>();
	sleep = make_shared<GuiButton>();
	play = make_shared<GuiButton>();
	eat->setParameters(200, 10, 50, "EAT", 20);
	sleep->setParameters(300, 10, 50, "SLEEP", 20);
	play->setParameters(400, 10, 50, "PLAY", 20);

	hungry = make_shared<GuiButton>();
	tired = make_shared<GuiButton>();
	fun = make_shared<GuiButton>();
	hungry->setParameters(810, 40, 30, "HUNGRY", 20);
	tired->setParameters(910, 40, 30, "TIRED", 20);
	fun->setParameters(1010, 40, 30, "FUN", 20);

	progBar1 = make_shared<ProgBar>();
	progBar2 = make_shared<ProgBar>();
	progBar3 = make_shared<ProgBar>();
	progBar1->setParameters(820, 100, 50);
	progBar2->setParameters(920, 100, 50);
	progBar3->setParameters(1020, 100, 50);

	yes = make_shared<GuiButton>();
	no = make_shared<GuiButton>();
	yes->setParameters(440, 400, 90, "YES", 40);
	no->setParameters(640, 400, 90, "NO", 40);

	backToGame = make_shared<GuiButton>();
	backToGame->setParameters(800, 650, 100, "BACK TO GAME", 20);
}

void Interface::addTextButtonsMenu()
{
	textButtonsMenu.push_back(newGame);
	textButtonsMenu.push_back(continueGame);
}

void Interface::drawTextButtonsMenu(RenderWindow & window)
{
	for (int i = 0; i < textButtonsMenu.size(); i++)
	{
		textButtonsMenu[i].drawTextButton(window);
	}
}

bool Interface::doesTextButtonsMenuContainMouse(Vector2f & mouse, string buttonText)
{
	if (buttonText == "NEW GAME")
	{
		textButtonIterator = find(textButtonsMenu.begin(), textButtonsMenu.end(), newGame);
		bool wynik = textButtonIterator->containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "CONTINUE GAME")
	{
		textButtonIterator = find(textButtonsMenu.begin(), textButtonsMenu.end(), continueGame);
		bool wynik = textButtonIterator->containsMouse(mouse);
		return wynik;
	}
}

void Interface::changeColorOfTextButtonMenu(string buttonText, Color color)
{
	if (buttonText == "NEW GAME")
	{
		textButtonIterator = find(textButtonsMenu.begin(), textButtonsMenu.end(), newGame);
		textButtonIterator->changeColor(color);
	}
	if (buttonText == "CONTINUE GAME")
	{
		textButtonIterator = find(textButtonsMenu.begin(), textButtonsMenu.end(), continueGame);
		textButtonIterator->changeColor(color);
	}
}

void Interface::addTguiChooseAnimal()
{
	this->add(catButton);
	this->add(dogButton);
}

bool Interface::doesTguiChooseAnimalContainMouse(Vector2f & mouse, string buttonText)
{
	if (buttonText == "CAT")
	{
		bool wynik=catButton->containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "DOG")
	{
		bool wynik = dogButton->containsMouse(mouse);
		return wynik;
	}
}

void Interface::addTguiChooseColor()
{
	this->add(firstColor);
	this->add(secondColor);
	this->add(thirdColor);
}

bool Interface::doesTguiChooseColorContainMouse(Vector2f & mouse, string buttonText)
{
	if (buttonText == "1")
	{
		bool wynik = firstColor->containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "2")
	{
		bool wynik = secondColor->containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "3")
	{
		bool wynik = thirdColor->containsMouse(mouse);
		return wynik;
	}
}

void Interface::addElementsOfGame()
{
	this->add(eat);
	this->add(sleep);
	this->add(play);

	this->add(hungry);
	this->add(tired);
	this->add(fun);

	this->add(progBar1);
	this->add(progBar2);
	this->add(progBar3);
}

void Interface::incrementValuesOfProgBar()
{
	progBar1->incrementValue();

	progBar2->incrementValue();

	progBar3->incrementValue();
}

bool Interface::checkValuesOfProgBars()
{
	if ((progBar1->getValue() == 100) || (progBar2->getValue() == 100) || (progBar3->getValue() == 100))
	{
		return true;
	}
	else
		return false;
}

void Interface::decrementValueOfProgBar(string progBarName)
{
	if (progBarName == "EAT")
	{
		progBar1->setValue(progBar1->getValue() - 0.1);
	}
	if (progBarName == "SLEEP")
	{
		progBar2->setValue(progBar2->getValue() - 0.1);
	}
}

bool Interface::doesTguiStartGameContainMouse(Vector2f & mouse, string buttonText)
{
	if (buttonText == "EAT")
	{
		bool wynik = eat->containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "SLEEP")
	{
		bool wynik = sleep->containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "PLAY")
	{
		bool wynik = play->containsMouse(mouse);
		return wynik;
	}
}

int Interface::getValueOfProgBar(string progBarName)
{
	if (progBarName == "EAT")
	{
		return progBar1->getValue();
	}
	if (progBarName == "SLEEP")
	{
		return progBar2->getValue();
	}
	if (progBarName == "PLAY")
	{
		return progBar3->getValue();
	}
}

void Interface::addSaveElements()
{
	this->add(yes);
	this->add(no);

	wantSaveGame.setParameters("DO YOU WANT SAVE THE GAME?", Color::Red, 80, 220, 250);
}

void Interface::drawWantToSave(RenderWindow & window)
{
	wantSaveGame.drawTextButton(window);
}

bool Interface::doesTguiWantSaveGameContainMouse(Vector2f & mouse, string buttonText)
{
	if (buttonText == "YES")
	{
		bool wynik = yes->containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "NO")
	{
		bool wynik = no->containsMouse(mouse);
		return wynik;
	}
}

void Interface::addSavedGame()
{
	saveGame.setParameters("YOU SAVED THE GAME!", Color::Red, 150, 120, 280);
}

void Interface::drawSavedGame(RenderWindow & window)
{
	saveGame.drawTextButton(window);
}

void Interface::setValuesOfProgBars(string progBarName,int value)
{
	if (progBarName == "EAT")
	{
		progBar1->setValue(value);
	}
	if (progBarName == "SLEEP")
	{
		progBar2->setValue(value);
	}
	if (progBarName == "PLAY")
	{
		progBar3->setValue(value);
	}
}

void Interface::addTextButtonsGameOver()
{
	gameOver.setParameters("GAME OVER", Color::Red, 110, 400, 200);
	exitGame.setParameters("EXIT", Color(24, 25, 40), 90, 480, 300);
	backToMenu.setParameters("BACK TO MENU", Color::Red, 100, 400, 450);
}

void Interface::drawTextButtonsGameOver(RenderWindow & window)
{
	gameOver.drawTextButton(window);
	exitGame.drawTextButton(window);
	backToMenu.drawTextButton(window);
}

bool Interface::doesTextButtonGameOverContainMouse(Vector2f & mouse, string buttonText)
{
	if (buttonText == "EXIT")
	{
		bool wynik = exitGame.containsMouse(mouse);
		return wynik;
	}
	if (buttonText == "BACK TO MENU")
	{
		bool wynik = backToMenu.containsMouse(mouse);
		return wynik;
	}
}

void Interface::changeColorOfTextButtonGameOver(string buttonText, Color color)
{
	if (buttonText == "EXIT")
	{
		exitGame.changeColor(color);
	}
	if (buttonText == "BACK TO MENU")
	{
		backToMenu.changeColor(color);
	}
}

void Interface::addBackToGameButton()
{
	this->add(backToGame);
}

bool Interface::doesBackToGameButtonContainMouse(Vector2f & mouse, string buttonText)
{
	if (buttonText == "BACK TO GAME")
	{
		bool wynik = backToGame->containsMouse(mouse);
		return wynik;
	}
}

