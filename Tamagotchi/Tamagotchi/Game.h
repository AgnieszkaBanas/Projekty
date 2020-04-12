#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
//#include <memory>
#include "TextButton.h"
#include "Repository.h"
#include "Dog.h"
#include "AnimalPicture.h"
#include "GameClock.h"
#include "Interface.h"
using namespace std;
using namespace sf;

class Game
{
	Repository*repository;
	int flag = 0;
	list<AnimalPicture> animalPicture;
	Animal*animal;
	map<string,int> colorOfDog;
	View view;
	Texture backgroundTexture;
	Sprite background;
	Vector2u textureSize;  //Added to store texture size.
	Vector2u windowSize;   //Added to store window size.
	float scaleX, scaleY;
	//vector<Score*> scores;
	//vector<shared_ptr<Interface>> myInterface;
	Interface myInterface;
	//vector<TextButton*> buttons;
	Font font;
	string gameState;
	vector<DynamicObject*> dynamicObjects;
	GameClock*gameClock = new GameClock(600, 30, 90);
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
			//myInterface.push_back(shared_ptr<Interface>(new GuiButton(1,1,1,"",1)));
		}
	};
	void showMenu();
	void startGame();
	void gameOver();
	void updateGame();
	void addTextAndScore();
	void setBackground(string bSource);
	void chooseColor();
	void chooseAnimal();
	void playground();
	void doYouWantSave();
	void savingGame();
	void continueGame();
};