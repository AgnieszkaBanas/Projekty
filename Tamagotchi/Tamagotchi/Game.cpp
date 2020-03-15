#include <fstream>
#include <ctime>
#include <typeinfo>
#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "GuiButton.h"
#include "ProgBar.h"
#include "Food.h"
#include "AnimalPicture.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/ClickableWidget.hpp>
#include "Ball.h"

float random_float(float a, float b)
{
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

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
				
				if (this->buttons[0]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
				{
					gameState = "choose animal";
				}

				if (this->buttons[3]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
				{
					gameState = "continue game";
				}
				
			}
		}
		window.clear();
		window.draw(background);

		
		this->buttons[0]->Draw(window);
		if (this->buttons[0]->containsMouse(mouse))
		{
			this->buttons[0]->changeColor(Color(100,100,100));
		}
		else
		{
			this->buttons[0]->changeColor(Color(130,70,65));
		}

		this->buttons[3]->Draw(window);
		if (this->buttons[3]->containsMouse(mouse))
		{
			this->buttons[3]->changeColor(Color(100, 100, 100));
		}
		else
		{
			this->buttons[3]->changeColor(Color(130, 70, 65));
		}
		
		window.display();
	}
	this->updateGame();
}


void Game::startGame()
{
	tgui::Gui gui(window);
	shared_ptr<GuiButton> tab1(new GuiButton(200, 10, 50, "EAT",20));
	shared_ptr<GuiButton> tab2(new GuiButton(300, 10, 50, "SLEEP",20));
	shared_ptr<GuiButton> tab3(new GuiButton(400, 10, 50, "PLAY",20));
	
	shared_ptr<GuiButton> tab(new GuiButton(800,0,250,"",20));
	shared_ptr<GuiButton> backButton(new GuiButton(900, 700, 70, "BACK",20));
	shared_ptr<ProgBar> progBar1(new ProgBar(820, 100, 50));
	shared_ptr<ProgBar> progBar2(new ProgBar(920, 100, 50));
	shared_ptr<ProgBar> progBar3(new ProgBar(1020, 100, 50));
	progBar1->setBorderColor(Color::Red);
	vector<Food*> food;
	if (typeid(*animal) == typeid(Dog))
	{
		food.push_back(new Food("dogFood2.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("dogFood3.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("dogFood4.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("dogFood5.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("dogFood6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("dogFood7.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("dogFood8.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
	}
	else
	{
		food.push_back(new Food("fafik6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("fafik6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("fafik6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("fafik6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("fafik6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("fafik6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
		food.push_back(new Food("fafik6.png", animal->getPosition().x + 200, animal->getPosition().y + 80, 1));
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
				gameState = "exit";
			if (backButton->mouseOnWidget(mouse2))
				gameState = "menu";
		}
		
		window.clear();

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			animal->moveDog('l', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			animal->moveDog('r', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			animal->moveDog('u', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			animal->moveDog('d', 6.0);
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
			progBar1->incrementValue();
			progBar2->incrementValue();
			//progBar3->incrementValue();
			clock.restart();
		}
		if(tab2->mouseOnWidget(mouse2))
		{
			animal->sleep();
			progBar2->setValue(progBar2->getValue() - 0.1);
		}
		else if(tab1->mouseOnWidget(mouse2))
		{
			food[z]->setFoodPosition(animal);
			//food[z]->Draw(window);
			animal->eat();
			progBar1->setValue(progBar1->getValue() - 0.1);
			if (timeFood.asSeconds() > 1)
			{
				z++;
				clockFood.restart();
			}
			if (z > 6)
			{
				z = 0;
			}
		}
		else if (tab3->mouseOnWidget(mouse2))
		{
			this->gameState = "play";
		}
		else
		{
			z = 0;
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
			
			if (this->buttons[2]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
			{
				gameState = "exit";
			}
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
				gameState = "start game";
			}
			if (this->buttons[4]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
			{
				gameState = "menu";
			}
			
		}
		window.clear(Color::Magenta);
		
		this->buttons[1]->Draw(window);
		this->buttons[2]->Draw(window);
		this->buttons[2]->Draw(window);
		this->buttons[2]->Draw(window);
		if (this->buttons[2]->containsMouse(mouse))
		{
			this->buttons[2]->changeColor(Color::Green);
		}
		else
		{
			this->buttons[2]->changeColor(Color::Red);
		}
		this->buttons[4]->Draw(window);
		if (this->buttons[4]->containsMouse(mouse))
		{
			this->buttons[4]->changeColor(Color::Green);
		}
		else
		{
			this->buttons[4]->changeColor(Color::Red);
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
	if (gameState == "best score")
	{
		this->showScores();
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
}

void Game::addTextAndScore()
{
	buttons.push_back(new TextButton("new game", Color(24, 34, 65, 76), 120, 420, 200));
	buttons.push_back(new TextButton("game over", Color::Red, 60, 350, 400));
	buttons.push_back(new TextButton("exit", Color(24,25,40), 60, 480, 470));
	buttons.push_back(new TextButton("continue game", Color(0, 0, 0, 255), 100, 375, 350));
	buttons.push_back(new TextButton("back", Color::Red, 80, 400, 550));
}

void Game::showScores()
{
	/*
	this->scores[0]->getScores();

	Event event;
	while (gameState == "best score")
	{
		Vector2f mouse(Mouse::getPosition(window));
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameState = "exit";
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
				gameState = "menu";
			}
			if (this->texts[4]->gGlobalBounds().contains(mouse) && event.mouseButton.button == Mouse::Left)
			{
				gameState = "menu";
			}
		}
		window.draw(background);
		this->scores[0]->Draw(window);
		this->texts[4]->Draw(window);
		if (this->texts[4]->containsMouse(mouse))
		{
			this->texts[4]->changeColor(Color::Green);
		}
		else
		{
			this->texts[4]->changeColor(Color::Red);
		}
		window.display();
	}
	this->updateGame();
	*/
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
	
	shared_ptr<GuiButton> color1(new GuiButton(250, 500, 90, "1",40));
	shared_ptr<GuiButton> color2(new GuiButton(550, 500, 90, "2",40));
	shared_ptr<GuiButton> color3(new GuiButton(850, 500, 90, "3",40));
	gui.add(color1);
	gui.add(color2);
	gui.add(color3);

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
		
		if (color1->mouseOnWidget(mouse3))
		{
			cur = colorOfDog.find("brown");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (color2->mouseOnWidget(mouse3))
		{
			
			cur = colorOfDog.find("black");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		if (color3->mouseOnWidget(mouse3))
		{
			cur = colorOfDog.find("grey");
			animal->setColorIterator(cur->second);
			animal->setInitialPosition();
			gameState = "new game";
		}
		window.draw(background);
		gui.draw();
		for (int i = 0; i < dogPicture.size(); i++)
		{
			dogPicture[i]->Draw(window);
		}
		window.display();
	}
	this->updateGame();
}

void Game::chooseAnimal()
{
	tgui::Gui gui(window);
	
	shared_ptr<GuiButton> catButton(new GuiButton(450, 400, 80, "CAT",30));
	shared_ptr<GuiButton> dogButton(new GuiButton(650, 400, 80, "DOG",30));
	//catButton->setRenderer(theme.getRenderer("catButton"));
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
		
		if (catButton->mouseOnWidget(mouse3))
		{
			animal = new Cat("cat1.png", 0, 750, 5);
			gameState = "choose color";
		}
		if (dogButton->mouseOnWidget(mouse3))
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
	Dog*dog = dynamic_cast<Dog*>(animal);
	dog->setPosition(200, 300);
	dog->changeEnableWalking(1);
	window.setView(window.getDefaultView());
	Ball ball(200,200,20);

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
		}
		sleep(milliseconds(20));
		
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			dog->moveDog('l', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dog->moveDog('r', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			dog->moveDog('u', 6.0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			dog->moveDog('d', 6.0);
		}
		window.clear();
		ball.update(dog);
		ball.Draw(window);
		dog->drawPlayer(window);
		window.display();
	}
	this->updateGame();
}
