#include "Ball.h"

void Ball::update(Animal*&animal)
{
	this->move(this->velocity);
	if ((this->getPosition().x - this->size <= 0)||(((this->getPosition().x + this->size <=animal->getPosition().x+172)&&(this->getPosition().x - this->size > animal->getPosition().x))&&(this->getPosition().y> animal->getPosition().y&&this->getPosition().y <= animal->getPosition().y+172)))
		velocity.x = ballVelocity;
	else if(((this->getPosition().x + this->size) >=1200)||(((this->getPosition().x + this->size == animal->getPosition().x)&&(this->getPosition().x + this->size >= animal->getPosition().x-4)) && (this->getPosition().y > animal->getPosition().y&&this->getPosition().y <= animal->getPosition().y + 172)))
		velocity.x = -ballVelocity;
	else if (((this->getPosition().y - this->size) <0)|| (((this->getPosition().y + this->size <= animal->getPosition().y + 172) && (this->getPosition().y - this->size > animal->getPosition().y)) && (this->getPosition().x > animal->getPosition().x&&this->getPosition().x <= animal->getPosition().x + 172)))
		velocity.y = ballVelocity;
	else if (((this->getPosition().y + this->size) >=800)|| (((this->getPosition().y + this->size == animal->getPosition().y) && (this->getPosition().y + this->size >= animal->getPosition().y - 4)) && (this->getPosition().x > animal->getPosition().x&&this->getPosition().x <= animal->getPosition().x + 172)))
		velocity.y = -ballVelocity;
}

void Ball::Draw(RenderWindow & window)
{
	window.draw(*this);
}
