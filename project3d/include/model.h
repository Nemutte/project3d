#pragma once
#include "SFML/Graphics.hpp"
#include "v3.h"
#include "camera.h"

#include <vector>


#define M_PI 3.141592653589793238462643383279502884

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
	void draw(sf::RenderWindow& window, V3d pos, Camera& camera);
};