#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;

int main()
{
	/*
	Vector2f position(0, 0);
	Vector2i screenDismension(800, 600);
	RenderWindow Window(VideoMode(800, 600), "Tamagotchi");
	Texture bTexture;
	Sprite bImage;
	if (!bTexture.loadFromFile("bl.jpg"))
	{
		cout << "cos poszlo nie tak ba :|";
	}
	bImage.setTexture(bTexture);
	bImage.setScale(1.0f,(float)screenDismension.x/bTexture.getSize().y);

	RectangleShape rec(Vector2f(20,20));
	rec.setFillColor(Color::Red);
	
	View view;
	view.reset(FloatRect(0, 0, screenDismension.x, screenDismension.y));
	view.setViewport(FloatRect(0, 0, 0.5f, 1.0f));
	Clock clock;
	float moveSpeed = 10000.0f;

	while (Window.isOpen())
	{
		clock.restart();
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();

		} //while
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			rec.move(moveSpeed*clock.getElapsedTime().asSeconds(), 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			rec.move(-moveSpeed*clock.getElapsedTime().asSeconds(), 0);
		}
		position.x = rec.getPosition().x + 10 - (screenDismension.x / 2);
		position.y = rec.getPosition().x + 10 - (screenDismension.y / 2);
		if (position.x < 0)
		{
			position.x = 0;
		}
		if (position.y < 0)
		{ 
			position.y = 0;
		}
		view.reset(FloatRect(position.x, position.y, screenDismension.x, screenDismension.y));
		Window.setView(view);
		Window.draw(bImage);
		Window.draw(rec);
		Window.display();
		Window.clear();
	} //whi
	*/
	Game gra;
	gra.addTextAndScore();
	gra.updateGame();

}