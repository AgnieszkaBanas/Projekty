#include <fstream>
#include <ctime>
#include <typeinfo>
#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "GuiButton.h"
#include "ProgBar.h"
#include "Food.h"
#include "DogFood.h"
#include "CatFood.h"
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

		
		this->myInterface[0]->Draw(window);
		if (this->myInterface[0]->containsMouse(mouse))
		{
			this->myInterface[0]->changeColor(Color(100,100,100));
		}
		else
		{
			this->myInterface[0]->changeColor(Color(130,70,65));
		}

		this->myInterface[3]->Draw(window);
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

	shared_ptr<GuiButton> tab1 = dynamic_pointer_cast<GuiButton>(myInterface[10]);
	shared_ptr<GuiButton> tab2 = dynamic_pointer_cast<GuiButton>(myInterface[11]);
	shared_ptr<GuiButton> tab3 = dynamic_pointer_cast<GuiButton>(myInterface[12]);
	shared_ptr<GuiButton> tab = dynamic_pointer_cast<GuiButton>(myInterface[13]);
	shared_ptr<GuiButton> backButton = dynamic_pointer_cast<GuiButton>(myInterface[14]);

	shared_ptr<ProgBar> progBar1 = dynamic_pointer_cast<ProgBar>(myInterface[15]);
	shared_ptr<ProgBar> progBar2 = dynamic_pointer_cast<ProgBar>(myInterface[16]);
	shared_ptr<ProgBar> progBar3 = dynamic_pointer_cast<ProgBar>(myInterface[17]);

	progBar3->setValue(gameClock->getCounter());
	
	Food*food;
	if (typeid(*animal) == typeid(Cat))
	{
		food = new CatFood(1, 1,1);
	}
	else
	{
		food = new DogFood(200, 200, 1);
	}
	//picture->create("apple.png");
	Clock clock;
	Clock clockFood;
	gui.add(tab1);
	gui.add(tab2);
	gui.add(tab3);
	gui.add(tab);
	gui.add(backButton);
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
		Vector2f mouse2(Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				gameState = "save";
			if (backButton->containsMouse(mouse2))
				gameState = "menu";
		}
		
		window.clear();

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			animal->moveObject('l', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			animal->moveObject('r', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			animal->moveObject('u', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			animal->moveObject('d', 6.0);
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
		//floor.drawFloor(window);
		animal->drawPlayer(window);
		//food->Draw(window);
		gui.draw();
		
		Time time = clock.getElapsedTime();
		Time timeFood = clockFood.getElapsedTime();
		//cout << time.asSeconds() << " ";
		if (progBar1->getValue() == 100)
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
		if(tab2->containsMouse(mouse2))
		{
			flag = 1;
			animal->sleep();
			progBar2->setValue(progBar2->getValue() - 0.1);
		}
		else if(tab1->containsMouse(mouse2))
		{
			flag = 1;
			animal->eat();
			food->eatIt(animal);
			food->Draw(window);
			progBar1->setValue(progBar1->getValue() - 0.1);
		}
		else if (tab3->containsMouse(mouse2))
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
	/*
	fstream plik("scores.txt", ios::out | ios::app);
	if (plik.good() == true)
	{
		//plik << scores[1]->getScore() << " ";
		plik.close();
	}
	*/
	Event event;
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
		
		this->myInterface[1]->Draw(window);
		this->myInterface[2]->Draw(window);
		this->myInterface[2]->Draw(window);
		this->myInterface[2]->Draw(window);
		if (this->myInterface[2]->containsMouse(mouse))
		{
			this->myInterface[2]->changeColor(Color::Green);
		}
		else
		{
			this->myInterface[2]->changeColor(Color::Red);
		}
		this->myInterface[4]->Draw(window);
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
	//this->buttons[1]->resetScore();
	
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
		this->setBackground("city2.jpg");
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
	myInterface.push_back(shared_ptr<Interface>(new TextButton("game over", Color::Red, 60, 350, 400)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("exit", Color(24, 25, 40), 60, 480, 470)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("continue game", Color(0, 0, 0, 255), 100, 375, 350)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("back", Color::Red, 80, 400, 550)));
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
	myInterface.push_back(shared_ptr<Interface>(new TextButton("doYouWantSave", Color::Red, 80, 200, 550)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(450, 400, 90, "YES", 20)));
	myInterface.push_back(shared_ptr<Interface>(new GuiButton(650, 400, 90, "NO", 20)));
	myInterface.push_back(shared_ptr<Interface>(new TextButton("savedGame", Color::Red, 80, 200, 550)));
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
		animalPicture.push_back(new AnimalPicture(0, "fafik6.png", 2.5, 220, 300, 86,1));
		animalPicture.push_back(new AnimalPicture(4, "fafik6.png", 2.5, 520, 300, 86,1));
		animalPicture.push_back(new AnimalPicture(8, "fafik6.png", 2.5, 820, 300, 86,1));
	}
	else
	{
		animalPicture.push_back(new AnimalPicture(0, "cat1.png", 6, 220, 300, 32,0));
		animalPicture.push_back(new AnimalPicture(4, "cat1.png", 6, 520, 300, 32,0));
		animalPicture.push_back(new AnimalPicture(8, "cat1.png", 6, 820, 300, 32,0));
	}

	map<string,int>::iterator cur;
	Event event;
	while (gameState == "choose color")
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
		
		if (color1->containsMouse(mouse3))
		{
			cur = colorOfDog.find("brown");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (color2->containsMouse(mouse3))
		{
			
			cur = colorOfDog.find("black");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (color3->containsMouse(mouse3))
		{
			cur = colorOfDog.find("grey");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		window.draw(background);
		gui.draw();
		for (int i = 0; i < animalPicture.size(); i++)
		{
			animalPicture[i]->Draw(window);
		}
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
			animal = new Cat("cat1.png", 0, 750, 5);
			gameState = "choose color";
		}
		
		if (dogButton->containsMouse(mouse3))
		{
			animal = new Dog("fafik6.png",0,750,2);
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
	Dog*dog = dynamic_cast<Dog*>(animal);
	dog->setPosition(200, 300);
	dog->setInitialPosition();
	dog->changeEnableWalking(1);
	window.setView(window.getDefaultView());
	Ball ball(200,200,20);
	Clock clock;
	gameClock->update(dog);
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
				dog->flagPosition = 1;
				dog->setInitialPosition();
				dog->flagPosition = 0;
				dog->changeEnableWalking(0);
				gameState = "new game";
			}
		}
		sleep(milliseconds(20));
		
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			dog->moveObject('l', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dog->moveObject('r', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			dog->moveObject('u', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			dog->moveObject('d', 6.0);
		}
		window.clear();
		if (gameClock->getCounter() == 0)
		{
			dog->flagPosition = 1;
			dog->setInitialPosition();
			dog->flagPosition = 0;
			dog->changeEnableWalking(0);
			gameState = "new game";
		}
		Time time = clock.getElapsedTime();
		if (time.asSeconds() > 1)
		{
			gameClock->update(dog);
			clock.restart();
		}
		ball.update(dog);
		ball.Draw(window);
		
		gui.draw();
		gameClock->Draw(window);
		dog->drawPlayer(window);
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

		this->myInterface[19]->Draw(window);
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
		this->myInterface[22]->Draw(window);
		window.display();
	}

	this->updateGame();
}

void Game::continueGame()
{
}
