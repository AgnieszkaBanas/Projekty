#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;

int main()
{
	Game gra;
	gra.addTextAndScore();
	gra.updateGame();
}