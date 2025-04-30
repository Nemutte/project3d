#pragma once
#include "SFML/Graphics.hpp"
#include "v3.h"

#include <vector>

class Poligon
{
public:
	V3d points[3];
	V3d nVector;
	Poligon();
	Poligon(V3d p[3], V3d nv);
};

class Model
{
public:

	std::vector<Poligon> poligons;
	Model();
	void draw(sf::RenderWindow& window, V3d position);
};