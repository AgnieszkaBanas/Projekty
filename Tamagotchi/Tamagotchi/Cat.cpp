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

void Cat::setColorIterator(int colorIterator)
{
	this->colorIterator = colorIterator;
}

void Cat::changeEnableWalking(int e)
{
	this->enableWalking = e;
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
}

void Cat::setInitialPosition()
{
	this->setTextureRect(IntRect((colorIterator) * 32, 0, 32, 32));
}

