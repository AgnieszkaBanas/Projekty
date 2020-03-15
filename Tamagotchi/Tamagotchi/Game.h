#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "TextButton.h"
#include "Dog.h"
#include "AnimalPicture.h"
using namespace std;
using namespace sf;

class Game
{
	vector<AnimalPicture*> dogPicture;
	Animal*animal;
	map<string,int> colorOfDog;
	View view;
	Texture backgroundTexture;
	Sprite background;
	Vector2u textureSize;  //Added to store texture size.
	Vector2u windowSize;   //Added to store window size.
	float scaleX, scaleY;
	//vector<Score*> scores;
	vector<TextButton*> buttons;
	Font font;
	string gameState;
	RenderWindow window;
public:
	Game()
	{
		gameState = "menu";
		if (!font.loadFromFile("BebasNeue-Regular.ttf"))
		{
			cout << "cos poszlo nie tak :|";
		}
		window.create(VideoMode(1200, 800), "Tamagotchi");
		
		if (!backgroundTexture.loadFromFile("bl.jpg"))
		{
			cout << "cos poszlo nie tak ba :|";
		}
		else
		{
			//textureSize = backgroundTexture.getSize(); 
			//windowSize = window.getSize();             

			//scaleX = (float)windowSize.x / textureSize.x;
			//scaleY = (float)windowSize.y / textureSize.y;     

			background.setTexture(backgroundTexture);
			background.setScale(1.0f, (float)1200 / backgroundTexture.getSize().y);
			//view.reset(FloatRect(0, 0, 1200, 800));
			//view.setViewport(FloatRect(0, 0, 0.5f, 1.0f));
			colorOfDog = { {"brown",0},{"black",4},{"grey",8} };
			dogPicture.push_back(new AnimalPicture(0, "fafik6.png", 2.5, 220, 300));
			dogPicture.push_back(new AnimalPicture(4, "fafik6.png", 2.5, 520, 300));
			dogPicture.push_back(new AnimalPicture(8, "fafik6.png", 2.5, 820, 300));
		}
	};
	void showMenu();
	void startGame();
	void gameOver();
	void updateGame();
	void addTextAndScore();
	void showScores();
	void setBackground(string bSource);
	void chooseColor();
	void chooseAnimal();
	void playground();
};