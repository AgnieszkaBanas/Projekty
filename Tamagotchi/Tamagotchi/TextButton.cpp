#include "TextButton.h"
#include <TGUI/TGUI.hpp>

void TextButton::Draw(RenderWindow & window)
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
		text.setString("GAME OVER! Your Score:");
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
	window.draw(text);
}


float TextButton::getX()
{
	return 0.0f;
}

float TextButton::getY()
{
	return 0.0f;
}


FloatRect TextButton::gGlobalBounds()
{
	return this->text.getGlobalBounds();
}


void TextButton::changeColor(Color textColor)
{
	this->textColor = textColor;
	this->text.setFillColor(textColor);
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