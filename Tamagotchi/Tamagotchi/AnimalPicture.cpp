#include "AnimalPicture.h"

void AnimalPicture::Draw(RenderWindow & window)
{
	this->setTexture(texAnimals);
	window.draw(*this);
}
