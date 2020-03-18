#include "Dog.h"
#include "Ball.h"

void Dog:: moveObject(char direction, float moveSpeed)
{
	if (enableWalking == 1)
	{
		if (direction == 'u')
		{
			this->move(0, -moveSpeed);
			this->setTextureRect(IntRect((counterWalking * 86) + (86 * colorIterator), 86 * 2, 86, 86));
		}
		if (direction == 'd')
		{
			this->move(0, moveSpeed);
			this->setTextureRect(IntRect((counterWalking * 86) + (86 * colorIterator), 0, 86, 86));
		}
		if (direction == 'l')
		{
			this->move(-moveSpeed, 0);
			this->setTextureRect(IntRect((counterWalking * 86) + (86 * colorIterator), 86 * 3, 86, 86));
		}
	}
	if (direction == 'r')
	{
		this->move(moveSpeed, 0);
		this->setTextureRect(IntRect((counterWalking * 86)+(86 * colorIterator), 86 * 1, 86, 86));
	}
	counterWalking++;
	if (counterWalking == 4)
	{
		counterWalking = 0;
	}
}

void Dog::eat()
{
	this->setTextureRect(IntRect((counterEating * 86) + (86 * colorIterator), 86 * 6, 86, 86));
	counterEating++;
	if (counterEating == 3)
	{
		counterEating = 0;
	}
	//progBar1->setValue(progBar1->getValue() - 0.1);
}

void Dog::sleep()
{
	this->setTextureRect(IntRect((counterSleeping * 86) + (86 * colorIterator), 86 * 7, 86, 86));
	counterSleeping++;
	if (counterSleeping == 2)
	{
		counterSleeping = 0;
	}
}

void Dog::play()
{
	
}

void Dog::setInitialPosition()
{
	this->setTextureRect(IntRect((colorIterator) * 86, 86, 86, 86));
	if (this->flagPosition == 1)
	{
		this->setPosition(posX, posY);
	}
}

void Dog::setColorIterator(int colorIterator)
{
	this->colorIterator = colorIterator;
}

void Dog::changeEnableWalking(int e)
{
	this->enableWalking = e;
}

int Dog::getColorIterator()
{
	return this->colorIterator;
}
