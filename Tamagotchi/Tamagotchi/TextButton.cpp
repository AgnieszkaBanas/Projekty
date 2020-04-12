#include "TextButton.h"
#include <TGUI/TGUI.hpp>

void TextButton::drawInterface(RenderWindow & window)
{
	if (buttonText == "new game")
	{
		text.setFont(font);
		text.setFillColor(textColor);
		text.setOutlineThickness(1);
		text.setOutlineColor(Color(200, 200, 250,200));
		text.setString("NEW GAME");
		text.setCharacterSize(size);
		text.setPosition(posX, posY);
	}
	if (buttonText == "game over")
	{
		text.setFont(font);
		text.setFillColor(textColor);
		text.setCharacterSize(size);
		text.setPosition(posX, posY);
		text.setString("GAME OVER!");
	}
	if (buttonText == "exit")
	{
		text.setFont(font);
		text.setFillColor(textColor);
		text.setCharacterSize(size);
		text.setPosition(posX, posY);
		text.setString("End Game");
	}
	if (buttonText == "continue game")
	{
		text.setFont(font);
		text.setFillColor(textColor);
		text.setOutlineThickness(1);
		text.setOutlineColor(Color(200, 200, 250,200));
		text.setCharacterSize(size);
		text.setPosition(posX, posY);
		text.setString("CONTINUE GAME");
	}
	if (buttonText == "back")
	{
		text.setFont(font);
		text.setFillColor(textColor);
		text.setCharacterSize(size);
		text.setPosition(posX, posY);
		text.setString("Back To Menu");
	}
	if (buttonText == "doYouWantSave")
	{
		text.setFont(font);
		text.setFillColor(textColor);
		text.setCharacterSize(size);
		text.setPosition(posX, posY);
		text.setString("Do you want save the game?");
	}
	if (buttonText == "savedGame")
	{
		text.setFont(font);
		text.setFillColor(textColor);
		text.setCharacterSize(size);
		text.setPosition(posX, posY);
		text.setString("YOU SAVED THE GAME!");
	}
	window.draw(text);
}

bool TextButton::containsMouse(Vector2f & mouse)
{
	if (this->text.getGlobalBounds().contains(mouse))
	{
		return true;
	}
	else
	{
		return false;
	}
}