#include "character.h"

Character::Character()
{
	camera = Camera();
}

void Character::update(float deltatime)
{
	moveVector.norm();
	position += moveVector * speed * deltatime;
	camera.position += moveVector * speed * deltatime;
}

