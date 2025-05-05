#include "character.h"

Character::Character()
{
	camera = Camera();
}

void Character::update(float deltatime)
{
	moveVector *= 0.f;

	if (move_W)
		moveVector += V3d(camera.currentDireection.x, 0.f, camera.currentDireection.z);
	if (move_S)
		moveVector -= V3d(camera.currentDireection.x, 0.f, camera.currentDireection.z);
	if (move_A)
		moveVector -= V3d(camera.currentDireection.z, 0.f, camera.currentDireection.x);
	if (move_D)
		moveVector += V3d(camera.currentDireection.z, 0.f, camera.currentDireection.x * (-1));

	moveVector.norm();
	position += moveVector * speed * deltatime;
	camera.position += moveVector * speed * deltatime;
}

