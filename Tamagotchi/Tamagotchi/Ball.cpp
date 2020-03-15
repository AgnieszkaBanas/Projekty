#include "Ball.h"

void Ball::update(Dog*&dog)
{
	this->move(this->velocity);
	if ((this->getPosition().x - this->size <= 0)||(((this->getPosition().x + this->size <=dog->getPosition().x+172)&&(this->getPosition().x - this->size > dog->getPosition().x))&&(this->getPosition().y> dog->getPosition().y&&this->getPosition().y <= dog->getPosition().y+172)))
		velocity.x = ballVelocity;
	else if(((this->getPosition().x + this->size) >=1200)||(((this->getPosition().x + this->size == dog->getPosition().x)&&(this->getPosition().x + this->size >= dog->getPosition().x-4)) && (this->getPosition().y > dog->getPosition().y&&this->getPosition().y <= dog->getPosition().y + 172)))
		velocity.x = -ballVelocity;
	else if (((this->getPosition().y - this->size) <0)|| (((this->getPosition().y + this->size <= dog->getPosition().y + 172) && (this->getPosition().y - this->size > dog->getPosition().y)) && (this->getPosition().x > dog->getPosition().x&&this->getPosition().x <= dog->getPosition().x + 172)))
		velocity.y = ballVelocity;
	else if (((this->getPosition().y + this->size) >=800)|| (((this->getPosition().y + this->size == dog->getPosition().y) && (this->getPosition().y + this->size >= dog->getPosition().y - 4)) && (this->getPosition().x > dog->getPosition().x&&this->getPosition().x <= dog->getPosition().x + 172)))
		velocity.y = -ballVelocity;
}

void Ball::Draw(RenderWindow & window)
{
	window.draw(*this);
}
