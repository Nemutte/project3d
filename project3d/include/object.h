#pragma once
#include "v3.h"
#include "model.h"

class Object
{
public:
	V3d position;
	Model* model;

	Object();
	Object(V3d position);
	void draw(sf::RenderWindow& window, Camera& camera);

};