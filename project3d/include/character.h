#pragma once

#include "camera.h"
#include "v3.h"

class Character
{
public:
	float speed = 200.f;
	V3d position = { 0.f, 0.f, 0.f };
	V3d moveVector = { 0.f, 0.f, 0.f };
	bool move_W = false;
	bool move_S = false;
	bool move_A = false;
	bool move_D = false;
	Camera camera;

	Character();
	void update(float deltatime);
};