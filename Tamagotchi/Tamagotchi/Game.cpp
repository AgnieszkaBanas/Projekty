#include <fstream>
#include <ctime>
#include <typeinfo>
#include <algorithm>
#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "GuiButton.h"
#include "ProgBar.h"
#include "Food.h"
#include "DogFood.h"
#include "CatFood.h"
#include "Box.h"
#include "GameClock.h"
#include "AnimalPicture.h"
#include "DogRepository.h"
#include "CatRepository.h"  
#include "Interface.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/ClickableWidget.hpp>
#include "Ball.h"

void Game::showMenu()
{
	Event event;
	while (gameState == "menu")
	{
		Vector2f mouse(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}

			if (event.type == Event::MouseButtonReleased)
			{
				if (myInterface.doesTextButtonsMenuContainMouse(mouse, "NEW GAME"))
				{
					gameState = "choose animal";
				}
				if (myInterface.doesTextButtonsMenuContainMouse(mouse, "CONTINUE GAME"))
				{
					gameState = "continue game";
				}
				
			}
		}
		window.clear();
		window.draw(background);
		myInterface.drawTextButtonsMenu(window);
		if (myInterface.doesTextButtonsMenuContainMouse(mouse, "NEW GAME"))
		{
			myInterface.changeColorOfTextButtonMenu("NEW GAME", Color(100, 100, 100));
		}
		else
		{
			myInterface.changeColorOfTextButtonMenu("NEW GAME", Color(24, 34, 65, 76));
		}

		if (myInterface.doesTextButtonsMenuContainMouse(mouse, "CONTINUE GAME"))
		{
			myInterface.changeColorOfTextButtonMenu("CONTINUE GAME", Color(100, 100, 100));
		}
		else
		{
			myInterface.changeColorOfTextButtonMenu("CONTINUE GAME", Color(24, 34, 65, 76));
		}
		
		window.display();
	}
	this->updateGame();
}


void Game::startGame()
{
	Food*food;
	if (typeid(*animal) == typeid(Cat))
	{
		food = new CatFood(1, 300,1);
	}
	else
	{
		food = new DogFood(200, 200, 1);
	}
	
	Clock clock;
	
	int z = 0;
	int suma = 1200;
	for(int i=0;i<100;i++)
	background.setTextureRect(IntRect(0, 0, suma += 1200, 800));
	
	Vector2f position(0, 0);
	
	Event event;
	while (gameState == "new game")
	{
		Vector2f mouse(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				gameState = "save";
		}
		window.clear();

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			animal->moveAnimal('l', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			animal->moveAnimal('r', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			animal->moveAnimal('u', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			animal->moveAnimal('d', 6.0);
		}
		position.x = animal->getPosition().x + 24 - (1200 / 2);
		position.y = animal->getPosition().y + 24 - (800 / 2);
		if (position.x < 0)
		{
			position.x = 0;
		}
		if (position.y < 0)
		{
			position.y = 0;
		}
		view.reset(FloatRect(position.x, position.y, 1200,800));
		sleep(milliseconds(50));
		backgroundTexture.setRepeated(true);
		background.setTexture(backgroundTexture);
		window.setView(view);
		window.draw(background);
		
		animal->drawAnimal(window);
		myInterface.draw();
		
		Time time = clock.getElapsedTime();
		
		if (myInterface.checkValuesOfProgBars())
		{
			gameState = "game over";
		}
		if (time.asSeconds() > 0.1)
		{
			if (flag == 0)
			{
				myInterface.incrementValuesOfProgBar();
			}
			clock.restart();
		}
		
		if(myInterface.doesTguiStartGameContainMouse(mouse,"SLEEP"))
		{
			flag = 1;
			animal->sleep();
			myInterface.decrementValueOfProgBar("SLEEP");
		}
		else if(myInterface.doesTguiStartGameContainMouse(mouse, "EAT"))
		{
			flag = 1;
			animal->eat();
			food->eatIt(animal);
			food->drawFood(window);
			myInterface.decrementValueOfProgBar("EAT");
		}
		
		else if (myInterface.doesTguiStartGameContainMouse(mouse, "PLAY"))
		{
			gameClock->setClock(myInterface.getValueOfProgBar("PLAY"));
			this->gameState = "play";
		}
		
		else
		{
			flag = 0;
			animal->setInitialPosition();
		}
		
		window.display();
	}
	
	myInterface.removeAllWidgets();
	this->updateGame();
}

void Game::gameOver()
{
	Event event;
	
	while (gameState == "game over")
	{
		Vector2f mouse(Mouse::getPosition(window));

		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonReleased)
			{
				if (myInterface.doesTextButtonGameOverContainMouse(mouse, "EXIT"))
				{
					gameState = "exit";
				}
				if (myInterface.doesTextButtonGameOverContainMouse(mouse, "BACK TO MENU"))
				{
					gameState = "menu";
				}
			}
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			
		}
		window.clear(Color::Magenta);
		myInterface.drawTextButtonsGameOver(window);

		if (myInterface.doesTextButtonGameOverContainMouse(mouse, "EXIT"))
		{
			myInterface.changeColorOfTextButtonGameOver("EXIT", Color::Green);
		}
		else
		{
			myInterface.changeColorOfTextButtonGameOver("EXIT", Color::Red);
		}

		if (myInterface.doesTextButtonGameOverContainMouse(mouse, "BACK TO MENU"))
		{
			myInterface.changeColorOfTextButtonGameOver("BACK TO MENU", Color::Green);
		}
		else
		{
			myInterface.changeColorOfTextButtonGameOver("BACK TO MENU", Color::Red);
		}

		window.display();
	}
	
	this->updateGame();
}

void Game::updateGame()
{
	if (gameState == "menu")
	{
		this->setBackground("bl.jpg");
		window.setView(window.getDefaultView());
		myInterface.addTextButtonsMenu();
		this->showMenu();
	}
	if (gameState == "new game")
	{
		this->setBackground("bl3.jpg");
		myInterface.addElementsOfGame();
		this->startGame();	
	}
	if (gameState == "game over")
	{
		window.setView(window.getDefaultView());
		myInterface.addTextButtonsGameOver();
		this->gameOver();
	}
	if (gameState == "exit")
	{
		window.close();
	}
	if (gameState == "eat")
	{
		this->setBackground("kitchen.jpg");
	}
	if (gameState == "choose color")
	{
		this->setBackground("bl.jpg");
		myInterface.addTguiChooseColor();
		this->chooseColor();
	}
	if (gameState == "choose animal")
	{
		this->setBackground("bl.jpg");
		myInterface.addTguiChooseAnimal();
		this->chooseAnimal();
	}
	if (gameState == "play")
	{
		this->setBackground("grass.jpg");
		window.setView(window.getDefaultView());
		myInterface.addBackToGameButton();
		this->playground();
	}
	if (gameState == "save")
	{
		window.setView(window.getDefaultView());
		myInterface.addSaveElements();
		this->doYouWantSave();
	}
	if (gameState == "saving game")
	{
		myInterface.addSavedGame();
		this->savingGame();
	}
	if (gameState == "continue game")
	{
		myInterface.addTguiChooseAnimal();
		this->continueGame();
	}
}

void Game::addInterfaceElements()
{
	myInterface.setTarget(window);
	myInterface.setParametersOfInterfaceElements();
}

void Game::setBackground(string bSource)
{
	if (!backgroundTexture.loadFromFile(bSource))
	{
		cout << "cos poszlo nie tak ba :|";
	}
	else
	{
		background.setTexture(backgroundTexture);
		background.setScale(1.0f, (float)1200 / backgroundTexture.getSize().y);
		view.reset(FloatRect(0, 0, 1200, 800));
		view.setViewport(FloatRect(0, 0, 1.0f, 1.0f));
	}
}

void Game::chooseColor()
{
	if (typeid(*animal) == typeid(Dog))
	{
		animalPicture.push_back(AnimalPicture(0, "fafik6.png", 2.5, 220, 300, 86,1));
		animalPicture.push_back(AnimalPicture(4, "fafik6.png", 2.5, 520, 300, 86,1));
		animalPicture.push_back(AnimalPicture(8, "fafik6.png", 2.5, 820, 300, 86,1));
	}
	else
	{
		animalPicture.push_back(AnimalPicture(0, "cat1.png", 6, 220, 300, 32,0));
		animalPicture.push_back(AnimalPicture(4, "cat1.png", 6, 520, 300, 32,0));
		animalPicture.push_back(AnimalPicture(8, "cat1.png", 6, 820, 300, 32,0));
	}

	map<string,int>::iterator cur;
	Event event;
	while (gameState == "choose color")
	{
		Vector2f mouse(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
		}
		window.clear();
		
		if (myInterface.doesTguiChooseColorContainMouse(mouse,"1"))
		{
			cur = colorOfDog.find("brown");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (myInterface.doesTguiChooseColorContainMouse(mouse, "2"))
		{
			
			cur = colorOfDog.find("black");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (myInterface.doesTguiChooseColorContainMouse(mouse, "3"))
		{
			cur = colorOfDog.find("grey");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		
		window.draw(background);
		myInterface.draw();
		list<AnimalPicture> ::iterator it;
		for (it = animalPicture.begin(); it != animalPicture.end(); ++it)
		{
			(*it).Draw(window);
		}
		/*
		for (int i = 0; i < animalPicture.size(); i++)
		{
			animalPicture[i]->Draw(window);
		}
		*/
		window.display();
	}
	myInterface.removeAllWidgets();
	this->updateGame();
}

void Game::chooseAnimal()
{
	map<string, int>::iterator cur;
	Event event;
	while (gameState == "choose animal")
	{
		Vector2f mouse3(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
		}
		window.clear();
		
		if (myInterface.doesTguiChooseAnimalContainMouse(mouse3,"CAT"))
		{
			animal = new Cat("cat1.png", 0, 785, 5);
			gameState = "choose color";
		}
		
		if (myInterface.doesTguiChooseAnimalContainMouse(mouse3, "DOG"))
		{
			animal = new Dog("fafik6.png",0,780,2);
			gameState = "choose color";
		}
		window.draw(background);
		myInterface.draw();
		window.display();
	}
	myInterface.removeAllWidgets();
	this->updateGame();
}

void Game::playground()
{
	if (typeid(*animal) == typeid(Dog))
	{
		dynamicObjects.push_back(new Ball(200, 200, 20));
	}

	animal->setPosition(200, 300);
	animal->setInitialPosition();
	animal->changeEnableWalking(1);
	
	Clock clock;
	gameClock->update(animal,window);
	Event event;
	while (gameState == "play")
	{
		Vector2f mouse3(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			
			if (myInterface.doesBackToGameButtonContainMouse(mouse3,"BACK TO GAME"))
			{
				animal->flagPosition = 1;
				animal->setInitialPosition();
				animal->flagPosition = 0;
				animal->changeEnableWalking(0);
				myInterface.setValuesOfProgBars("PLAY", gameClock->getCounter());
				gameState = "new game";
			}
			
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				cout << "the right button was pressed" <<endl;
				Vector2i localPosition = Mouse::getPosition(window);
				dynamicObjects.push_back(new Box(localPosition.x, localPosition.y, 50));
			}
		}
		sleep(milliseconds(20));
		
		window.draw(background);
		if (gameClock->getCounter() == 0)
		{
			animal->flagPosition = 1;
			animal->setInitialPosition();
			animal->flagPosition = 0;
			animal->changeEnableWalking(0);
			myInterface.setValuesOfProgBars("PLAY",0);
			gameState = "new game";
		}
		Time time = clock.getElapsedTime();
		if (time.asSeconds() > 1)
		{
			gameClock->update(animal,window);
			clock.restart();
		}
		animal->play();
		for (int i = 0; i < dynamicObjects.size(); i++)
		{
			dynamicObjects[i]->update(animal, window);
			dynamicObjects[i]->drawDynamicObject(window);
		}
		myInterface.draw();
		gameClock->drawDynamicObject(window);
		animal->drawAnimal(window);
		window.display();
		window.clear();
	}
	myInterface.removeAllWidgets();
	this->updateGame();
}

void Game::doYouWantSave()
{
	Event event;
	while (gameState == "save")
	{
		Vector2f mouse(Mouse::getPosition(window));

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			
			if (myInterface.doesTguiWantSaveGameContainMouse(mouse,"NO"))
			{
				gameState = "exit";
			}
			if (myInterface.doesTguiWantSaveGameContainMouse(mouse, "YES"))
			{
				gameState = "saving game";
			}
			
		}
		window.clear(Color::Magenta);

		myInterface.drawWantToSave(window);
		myInterface.draw();
		window.display();
	}
	myInterface.removeAllWidgets();
	this->updateGame();
}

void Game::savingGame()
{
	Event event;
	if (typeid(*animal) == typeid(Dog))
	{
		repository = new DogRepository();
	}
	else
	{
		repository = new CatRepository();
	}

	repository->saveData(myInterface.getValueOfProgBar("EAT"), myInterface.getValueOfProgBar("SLEEP"), myInterface.getValueOfProgBar("PLAY"),animal->getColorIterator());
	while (gameState == "saving game")
	{
		Vector2f mouse(Mouse::getPosition(window));

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
		}
		window.clear(Color::Magenta);
		myInterface.drawSavedGame(window);
		window.display();
	}

	this->updateGame();
}

void Game::continueGame()
{
	map<string, int>::iterator cur;
	Event event;
	while (gameState == "continue game")
	{
		Vector2f mouse3(Mouse::getPosition(window));
		window.clear();

		window.draw(background);
		myInterface.draw();
		window.display();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			
			if (myInterface.doesTguiChooseAnimalContainMouse(mouse3,"DOG"))
			{
				repository = new DogRepository();
				Data data;
				data = repository->readData();
				animal = new Dog("fafik6.png", 0, 780, 2);

				myInterface.setValuesOfProgBars("EAT", data.pBV1);
				myInterface.setValuesOfProgBars("SLEEP", data.pBV2);
				myInterface.setValuesOfProgBars("PLAY", data.pBV3);
			
				animal->setColorIterator(data.color);
				animal->setInitialPosition();
				gameState = "new game";
			}
			if (myInterface.doesTguiChooseAnimalContainMouse(mouse3, "CAT"))
			{
				repository = new CatRepository();
				Data data;
				data = repository->readData();
				animal = new Cat("cat1.png", 0, 785, 5);
				animal->setColorIterator(data.color);
				animal->setInitialPosition();

				myInterface.setValuesOfProgBars("EAT", data.pBV1);
				myInterface.setValuesOfProgBars("SLEEP", data.pBV2);
				myInterface.setValuesOfProgBars("PLAY", data.pBV3);

				gameState = "new game";
			}
			
		}
	}
	myInterface.removeAllWidgets();
	this->updateGame();
}
