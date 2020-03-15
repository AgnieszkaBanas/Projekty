#include "Ball.h"

void Ball::update(Dog*&dog)
{
	this->move(this->velocity);
	if ((this->getPosition().x - this->ballRadius <= 0)||(((this->getPosition().x + this->ballRadius <=dog->getPosition().x+172)&&(this->getPosition().x - this->ballRadius > dog->getPosition().x))&&(this->getPosition().y> dog->getPosition().y&&this->getPosition().y <= dog->getPosition().y+172)))
		velocity.x = ballVelocity;
	else if(((this->getPosition().x + this->ballRadius) >=1200)||(((this->getPosition().x + this->ballRadius == dog->getPosition().x)&&(this->getPosition().x + this->ballRadius >= dog->getPosition().x-4)) && (this->getPosition().y > dog->getPosition().y&&this->getPosition().y <= dog->getPosition().y + 172)))
		velocity.x = -ballVelocity;
	else if (((this->getPosition().y - this->ballRadius) <0)|| (((this->getPosition().y + this->ballRadius <= dog->getPosition().y + 172) && (this->getPosition().y - this->ballRadius > dog->getPosition().y)) && (this->getPosition().x > dog->getPosition().x&&this->getPosition().x <= dog->getPosition().x + 172)))
		velocity.y = ballVelocity;
	else if (((this->getPosition().y + this->ballRadius) >=800)|| (((this->getPosition().y + this->ballRadius == dog->getPosition().y) && (this->getPosition().y + this->ballRadius >= dog->getPosition().y - 4)) && (this->getPosition().x > dog->getPosition().x&&this->getPosition().x <= dog->getPosition().x + 172)))
		velocity.y = -ballVelocity;
}

void Ball::Draw(RenderWindow & window)
{
	window.draw(*this);
}
