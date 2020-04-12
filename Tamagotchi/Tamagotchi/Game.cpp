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
				
				if (this->myInterface[0]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
				{
					gameState = "choose animal";
				}

				if (this->myInterface[3]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
				{
					gameState = "continue game";
				}
				
			}
		}
		window.clear();
		window.draw(background);

		this->myInterface[0]->drawInterface(window);
		if (this->myInterface[0]->containsMouse(mouse))
		{
			this->myInterface[0]->changeColor(Color(100,100,100));
		}
		else
		{
			this->myInterface[0]->changeColor(Color(130,70,65));
		}

		this->myInterface[3]->drawInterface(window);
		if (this->myInterface[3]->containsMouse(mouse))
		{
			this->myInterface[3]->changeColor(Color(100, 100, 100));
		}
		else
		{
			this->myInterface[3]->changeColor(Color(130, 70, 65));
		}
		
		window.display();
	}
	this->updateGame();
}


void Game::startGame()
{
	tgui::Gui gui(window);

	shared_ptr<GuiButton> buttonEat = dynamic_pointer_cast<GuiButton>(myInterface[10]);
	shared_ptr<GuiButton> buttonSleep = dynamic_pointer_cast<GuiButton>(myInterface[11]);
	shared_ptr<GuiButton> buttonPlay = dynamic_pointer_cast<GuiButton>(myInterface[12]);
	shared_ptr<GuiButton> whiteBox = dynamic_pointer_cast<GuiButton>(myInterface[13]);

	shared_ptr<GuiButton> l1 = dynamic_pointer_cast<GuiButton>(myInterface[23]);
	shared_ptr<GuiButton> l2 = dynamic_pointer_cast<GuiButton>(myInterface[24]);
	shared_ptr<GuiButton> l3 = dynamic_pointer_cast<GuiButton>(myInterface[25]);

	shared_ptr<GuiButton> backButton = dynamic_pointer_cast<GuiButton>(myInterface[14]);

	shared_ptr<ProgBar> progBar1 = dynamic_pointer_cast<ProgBar>(myInterface[15]);
	shared_ptr<ProgBar> progBar2 = dynamic_pointer_cast<ProgBar>(myInterface[16]);
	shared_ptr<ProgBar> progBar3 = dynamic_pointer_cast<ProgBar>(myInterface[17]);

	progBar3->setValue(gameClock->getCounter());
	
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
	
	gui.add(buttonEat);
	gui.add(buttonSleep);
	gui.add(buttonPlay);
	gui.add(whiteBox);
	gui.add(l1);
	gui.add(l2);
	gui.add(l3);
	//gui.add(backButton);
	gui.add(progBar1);
	gui.add(progBar2);
	gui.add(progBar3);
	int z = 0;
	int suma = 1200;
	for(int i=0;i<100;i++)
	background.setTextureRect(IntRect(0, 0, suma += 1200, 800));
	
	//backgroundTexture.setRepeated(true);
	Vector2f position(0, 0);
	
	Event event;
	while (gameState == "new game")
	{
		Vector2f mouse(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				gameState = "save";
			if (backButton->containsMouse(mouse))
				gameState = "menu";
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
		
		gui.draw();
		
		Time time = clock.getElapsedTime();
		
		if ((progBar1->getValue() == 100)||(progBar2->getValue() == 100)||(progBar3->getValue() == 100))
		{
			gameState = "game over";
		}
		if (time.asSeconds() > 0.1)
		{
			if (flag == 0)
			{
				progBar1->incrementValue();

				progBar2->incrementValue();

				progBar3->incrementValue();
			}
			clock.restart();
		}
		if(buttonSleep->containsMouse(mouse))
		{
			flag = 1;
			animal->sleep();
			progBar2->setValue(progBar2->getValue() - 0.1);
		}
		else if(buttonEat->containsMouse(mouse))
		{
			flag = 1;
			animal->eat();
			food->eatIt(animal);
			food->drawFood(window);
			progBar1->setValue(progBar1->getValue() - 0.1);
		}
		else if (buttonPlay->containsMouse(mouse))
		{
			gameClock->setClock(progBar3->getValue());
			this->gameState = "play";
		}
		else
		{
			flag = 0;
			animal->setInitialPosition();
		}
		window.display();
	}
	this->updateGame();
}

void Game::gameOver()
{
	Event event;
	window.setView(window.getDefaultView());
	while (gameState == "game over")
	{
		Vector2f mouse(Mouse::getPosition(window));

		while (window.pollEvent(event))
		{
			
			if (this->myInterface[2]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
			{
				gameState = "exit";
			}
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			if (this->myInterface[4]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
			{
				gameState = "menu";
			}
			
		}
		window.clear(Color::Magenta);
		
		this->myInterface[1]->drawInterface(window);
		this->myInterface[2]->drawInterface(window);
		this->myInterface[2]->drawInterface(window);
		this->myInterface[2]->drawInterface(window);

		if (this->myInterface[2]->containsMouse(mouse))
		{
			this->myInterface[2]->changeColor(Color::Green);
		}
		else
		{
			this->myInterface[2]->changeColor(Color::Red);
		}
		this->myInterface[4]->drawInterface(window);
		if (this->myInterface[4]->containsMouse(mouse))
		{
			this->myInterface[4]->changeColor(Color::Green);
		}
		else
		{
			this->myInterface[4]->changeColor(Color::Red);
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
		this->showMenu();
	}
	if (gameState == "new game")
	{
		this->setBackground("bl3.jpg");
		this->startGame();	
	}
	if (gameState == "game over")
	{
		window.setView(window.getDefaultView());
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
		this->chooseColor();
	}
	if (gameState == "choose animal")
	{
		this->setBackground("bl.jpg");
		this->chooseAnimal();
	}
	if (gameState == "play")
	{
		this->setBackground("grass.jpg");
		this->playground();
	}
	if (gameState == "save")
	{
		this->doYouWantSave();
	}
	if (gameState == "saving game")
	{
		this->savingGame();
	}
	if (gameState == "continue game")
	{
		this->continueGame();
	}
}

void Game::addTextAndScore()
{
	myInterface.push_back(shared_ptr<Interface>(new TextButton("new game", Color(24, 34, 65, 76), 120, 420, 200)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("game over", Color::Red, 110, 400, 200)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("exit", Color(24, 25, 40), 90, 480, 300)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("continue game", Color(0, 0, 0, 255), 100, 375, 350)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("back", Color::Red, 100, 400, 450)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(450, 400, 80, "CAT", 30)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(650, 400, 80, "DOG", 30)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(250, 500, 90, "1", 40)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(550, 500, 90, "2", 40)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(850, 500, 90, "3", 40)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(200, 10, 50, "EAT", 20)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(300, 10, 50, "SLEEP", 20)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(400, 10, 50, "PLAY", 20)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(800, 0, 250, "", 20)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(900, 700, 70, "BACK", 20)));
	myInterface.push_back(shared_ptr<Interface>(new ProgBar(820, 100, 50)));
	myInterface.push_back(shared_ptr<Interface>(new ProgBar(920, 100, 50)));
	myInterface.push_back(shared_ptr<Interface>(new ProgBar(1020, 100, 50)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(900, 600, 70, "BACK TO GAME", 20)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("doYouWantSave", Color::Red, 80, 220, 250)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(440, 400, 90, "YES", 40)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(640, 400, 90, "NO", 40)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("savedGame", Color::Red, 80, 200, 550)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(810, 40, 30, "HUNGRY", 20)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(910, 40, 30, "TIRED", 20)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(1010, 40, 30, "FUN", 20)));
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
	tgui::Gui gui(window);

	shared_ptr<GuiButton> color1 = dynamic_pointer_cast<GuiButton>(myInterface[7]);
	shared_ptr<GuiButton> color2 = dynamic_pointer_cast<GuiButton>(myInterface[8]);
	shared_ptr<GuiButton> color3 = dynamic_pointer_cast<GuiButton>(myInterface[9]);
	
	gui.add(color1);
	gui.add(color2);
	gui.add(color3);

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
		
		if (color1->containsMouse(mouse))
		{
			cur = colorOfDog.find("brown");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (color2->containsMouse(mouse))
		{
			
			cur = colorOfDog.find("black");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (color3->containsMouse(mouse))
		{
			cur = colorOfDog.find("grey");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		window.draw(background);
		gui.draw();
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
	this->updateGame();
}

void Game::chooseAnimal()
{
	tgui::Gui gui(window);

	shared_ptr<GuiButton> catButton = dynamic_pointer_cast<GuiButton>(myInterface[5]);
	shared_ptr<GuiButton> dogButton = dynamic_pointer_cast<GuiButton>(myInterface[6]);
	gui.add(catButton);
	gui.add(dogButton);
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
		
		if (catButton->containsMouse(mouse3))
		{
			animal = new Cat("cat1.png", 0, 785, 5);
			gameState = "choose color";
		}
		
		if (dogButton->containsMouse(mouse3))
		{
			animal = new Dog("fafik6.png",0,780,2);
			gameState = "choose color";
		}
		window.draw(background);
		gui.draw();
		window.display();
	}
	this->updateGame();
}

void Game::playground()
{
	tgui::Gui gui(window);
	shared_ptr<GuiButton> backToGameButton = dynamic_pointer_cast<GuiButton>(myInterface[18]);
	
	gui.add(backToGameButton);
	if (typeid(*animal) == typeid(Dog))
	{
		dynamicObjects.push_back(new Ball(200, 200, 20));
	}

	animal->setPosition(200, 300);
	animal->setInitialPosition();
	animal->changeEnableWalking(1);
	window.setView(window.getDefaultView());
	
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
			if (backToGameButton->containsMouse(mouse3))
			{
				animal->flagPosition = 1;
				animal->setInitialPosition();
				animal->flagPosition = 0;
				animal->changeEnableWalking(0);
				gameState = "new game";
			}
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				cout << "the right button was pressed" <<endl;
				sf::Vector2i localPosition = sf::Mouse::getPosition(window);
				dynamicObjects.push_back(new Box(localPosition.x, localPosition.y, 50));
			}
		}
		sleep(milliseconds(20));
		
		window.clear();
		window.draw(background);
		if (gameClock->getCounter() == 0)
		{
			animal->flagPosition = 1;
			animal->setInitialPosition();
			animal->flagPosition = 0;
			animal->changeEnableWalking(0);
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
	
		gui.draw();
		gameClock->drawDynamicObject(window);
		animal->drawAnimal(window);
		window.display();
	}
	this->updateGame();
}

void Game::doYouWantSave()
{
	tgui::Gui gui(window);
	shared_ptr<GuiButton> buttonYes = dynamic_pointer_cast<GuiButton>(myInterface[20]);
	shared_ptr<GuiButton> buttonNo = dynamic_pointer_cast<GuiButton>(myInterface[21]);
	gui.add(buttonYes);
	gui.add(buttonNo);
	window.setView(window.getDefaultView());

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
			if (buttonNo->containsMouse(mouse))
			{
				gameState = "exit";
			}
			if (buttonYes->containsMouse(mouse))
			{
				gameState = "saving game";
			}
		}
		window.clear(Color::Magenta);

		this->myInterface[19]->drawInterface(window);
		gui.draw();
		window.display();
	}

	this->updateGame();
}

void Game::savingGame()
{
	shared_ptr<ProgBar> progBar1 = dynamic_pointer_cast<ProgBar>(myInterface[15]);
	shared_ptr<ProgBar> progBar2 = dynamic_pointer_cast<ProgBar>(myInterface[16]);
	shared_ptr<ProgBar> progBar3 = dynamic_pointer_cast<ProgBar>(myInterface[17]);

	Event event;
	if (typeid(*animal) == typeid(Dog))
	{
		repository = new DogRepository();
	}
	else
	{
		repository = new CatRepository();
	}
	repository->saveData(progBar1->getValue(), progBar2->getValue(), progBar3->getValue(),animal->getColorIterator());
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
		this->myInterface[22]->drawInterface(window);
		window.display();
	}

	this->updateGame();
}

void Game::continueGame()
{
	tgui::Gui gui(window);

	shared_ptr<GuiButton> catButton = dynamic_pointer_cast<GuiButton>(myInterface[5]);
	shared_ptr<GuiButton> dogButton = dynamic_pointer_cast<GuiButton>(myInterface[6]);
	shared_ptr<ProgBar> progBar1 = dynamic_pointer_cast<ProgBar>(myInterface[15]);
	shared_ptr<ProgBar> progBar2 = dynamic_pointer_cast<ProgBar>(myInterface[16]);
	shared_ptr<ProgBar> progBar3 = dynamic_pointer_cast<ProgBar>(myInterface[17]);
	gui.add(catButton);
	gui.add(dogButton);
	map<string, int>::iterator cur;
	Event event;
	while (gameState == "continue game")
	{
		Vector2f mouse3(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			if (dogButton->containsMouse(mouse3))
			{
				repository = new DogRepository();
				Data data;
				data = repository->readData();
				animal = new Dog("fafik6.png", 0, 780, 2);
				progBar1->setValue(data.pBV1);
				progBar2->setValue(data.pBV2);
				progBar3->setValue(data.pBV3);
				animal->setColorIterator(data.color);
				gameState = "new game";
			}
			if (catButton->containsMouse(mouse3))
			{
				repository = new CatRepository();
				Data data;
				data = repository->readData();
				animal = new Cat("cat1.png", 0, 785, 5);
				animal->setColorIterator(data.color);
				progBar1->setValue(data.pBV1);
				progBar2->setValue(data.pBV2);
				progBar3->setValue(data.pBV3);
				gameState = "new game";
			}
		}
		window.clear();

		window.draw(background);
		gui.draw();
		window.display();
	}
	this->updateGame();
}
