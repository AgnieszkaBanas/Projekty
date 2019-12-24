#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h> 
#include <time.h>
#include "ObiektGraficzny.h"
#include "Ciastko.h"
#include "Waz.h"
#include "Punkty.h"
using namespace std;
using namespace sf;


int main()
{
	Clock playClock;
	float elapsedPauseTime = 0;

	Clock gameClock;
	float elapsedGameTime = 0.0f;
	float timeStep;
	Clock clock;
	Clock pauseTime;

	timeStep = 0.2f;
	//sf::Clock clock;
	//const float timeStep = 1 / 60.f;
	float x = 0.0;
	float y = 0.0;
	bool wynik;
	bool wynik2;
	bool wynik3;
	int i = 0;
	Punkty punkty;
	Ciastko ciastko(30.f, 30.f, Color::Red, 7.f, 7.f);
	Waz waz(30.f, 30.f, Color::Green, 4.f, 4.f);
	waz.dodajOgon();
	sf::RenderWindow window(VideoMode(800,600),"Snake");
	sf::Event event;
	while (window.isOpen())
	{
		
		/*
		while (clock.getElapsedTime().asSeconds() < timeStep)
			sf::sleep(sf::milliseconds(70));
		clock.restart();
		*/
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			
		}
		window.clear();

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			waz.idzWezem("lewo");
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			waz.idzWezem("prawo");
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			waz.idzWezem("gora");
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			waz.idzWezem("dol");
		}
		sf::sleep(sf::milliseconds(60));
		elapsedGameTime += gameClock.restart().asSeconds();
		Time time = clock.getElapsedTime();
		cout << time.asSeconds() << " ";
		//Dont update game when it's paused
		/*
		while (elapsedGameTime > timeStep)
		{
			elapsedGameTime -= timeStep;
		}
		*/
		if (time.asSeconds() > 3)
		{
			waz.dodajOgon();
			clock.restart();
		}
		wynik=waz.czyWazZjadlCiastko(ciastko);
		wynik2 = waz.sprawdzKolizjeZOgonem();
		wynik3 = waz.sprawdzKolizjeZeSciana();
		if(wynik2 == true)
		{
		
		while (!(Keyboard::isKeyPressed(Keyboard::Escape)))
		{
			window.clear(Color::Magenta);
			punkty.wyswietlNapis();
			window.display();
		}
		window.close();
		}
		if (wynik3 == true)
		{
			exit(0);
		}
		if (wynik == true)
		{
			punkty.dodajPunkty(ciastko);
			ciastko.generujCiastko();
			waz.dodajOgon();
		}
		ciastko.rysuj(window);
		waz.rysujWeza(window);
		punkty.rysuj(window);
		window.display();
	}
	
}	