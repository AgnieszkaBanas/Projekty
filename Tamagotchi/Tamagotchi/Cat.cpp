#include "Cat.h"

void Cat::moveAnimal(char direction, float moveSpeed)
{
	if (enableWalking == 1)
	{
		if (direction == 'u')
		{
			this->move(0, -moveSpeed);
			this->setTextureRect(IntRect((counterWalking * 32) + (32 * colorIterator), 32 * 1, 32, 32));
		}
		if (direction == 'd')
		{
			this->move(0, moveSpeed);
			this->setTextureRect(IntRect((counterWalking * 32) + (32 * colorIterator),32*2, 32, 32));
		}
		if (direction == 'l')
		{
			this->move(-moveSpeed, 0);
			this->setTextureRect(IntRect((counterWalking * 32) + (32 * colorIterator), 32 * 3, 32, 32));
		}
	}
	if (direction == 'r')
	{
		this->move(moveSpeed, 0);
		this->setTextureRect(IntRect((counterWalking * 32) + (32 * colorIterator), 0, 32, 32));
	}
	counterWalking++;
	if (counterWalking == 3)
	{
		counterWalking = 0;
	}
}

void Cat::eat()
{
	this->setTextureRect(IntRect((counterEating * 32) + (32 * colorIterator), 32 * 4, 32, 32));
	counterEating++;
	if (counterEating == 3)
	{
		counterEating = 0;
	}
}

void Cat::sleep()
{
	this->setTextureRect(IntRect(32 * (3+colorIterator), 0, 32, 32));
}

void Cat::play()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->moveAnimal('l', 6.0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->moveAnimal('r', 6.0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->moveAnimal('u', 6.0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->moveAnimal('d', 6.0);
	}
}

void Cat::setInitialPosition()
{
	this->setTextureRect(IntRect((colorIterator) * 32+32, 0, 32, 32));
	if (this->flagPosition == 1)
	{
		this->setPosition(posX, posY);
	}
}

