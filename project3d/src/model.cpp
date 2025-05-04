#include "model.h"
#include <math.h>


Poligon::Poligon()
{
	points[0] = { 0.f, 0.f, 0.f };
	points[1] = { 0.f, 0.f, 0.f };
	points[2] = { 0.f, 0.f, 0.f };
	nVector = { 0.f, 0.f, 0.f }; 
}
Poligon::Poligon(V3d p[3], V3d nv) : nVector{ nv }
{
	points[0] = p[0];
	points[1] = p[1];
	points[2] = p[2];
}
Model::Model()
{
	V3d tops[8] = { { -50.f, 50.f, 50.f },
					{ 50.f, 50.f, 50.f },
					{ 50.f, -50.f, 50.f },
					{ -50.f, -50.f, 50.f },
					{ -50.f, 50.f, -50.f },
					{ 50.f, 50.f, -50.f },
					{ 50.f, -50.f, -50.f },
					{ -50.f, -50.f, -50.f },
	};
	V3d poligon[3];
	/*
	*/
	poligon[0] = tops[0];
	poligon[1] = tops[1];
	poligon[2] = tops[2];
	poligons.push_back(Poligon(poligon, V3d(0.f, 0.f, 100.f)));
	poligon[0] = tops[0];
	poligon[1] = tops[3];
	poligon[2] = tops[2];
	poligons.push_back(Poligon(poligon, V3d(0.f, 0.f, 100.f)));
	poligon[0] = tops[5];
	poligon[1] = tops[1];
	poligon[2] = tops[2];
	poligons.push_back(Poligon(poligon, V3d(100.f, 0.f, 0.f)));
	poligon[0] = tops[5];
	poligon[1] = tops[6];
	poligon[2] = tops[2];
	poligons.push_back(Poligon(poligon, V3d(100.f, 0.f, 0.f)));
	poligon[0] = tops[4];
	poligon[1] = tops[5];
	poligon[2] = tops[6];
	poligons.push_back(Poligon(poligon, V3d(0.f, 0.f, -100.f)));
	poligon[0] = tops[4];
	poligon[1] = tops[7];
	poligon[2] = tops[6];
	poligons.push_back(Poligon(poligon, V3d(0.f, 0.f, -100.f)));
	poligon[0] = tops[4];
	poligon[1] = tops[0];
	poligon[2] = tops[3];
	poligons.push_back(Poligon(poligon, V3d(-100.f, 0.f, 0.f)));
	poligon[0] = tops[4];
	poligon[1] = tops[7];
	poligon[2] = tops[3];
	poligons.push_back(Poligon(poligon, V3d(-100.f, 0.f, 0.f)));
	poligon[0] = tops[4];
	poligon[1] = tops[0];
	poligon[2] = tops[1];
	poligons.push_back(Poligon(poligon, V3d(0.f, 100.f, 0.f)));
	poligon[0] = tops[4];
	poligon[1] = tops[5];
	poligon[2] = tops[1];
	poligons.push_back(Poligon(poligon, V3d(0.f, 100.f, 0.f)));
	poligon[0] = tops[7];
	poligon[1] = tops[2];
	poligon[2] = tops[6];
	poligons.push_back(Poligon(poligon, V3d(0.f, -100.f, 0.f)));
	poligon[0] = tops[7];
	poligon[1] = tops[3];
	poligon[2] = tops[2];
	poligons.push_back(Poligon(poligon, V3d(0.f, -100.f, 0.f)));
	/*
	*/
}
void Model::draw(sf::RenderWindow& window, V3d pos, Camera& camera)
{
	std::vector<sf::Vertex> sh;
	float d = camera.viewerDistance;
	sf::Color c = sf::Color(255, 255, 255);
	for (Poligon &pol : poligons)
	{
		V3d vectorToPoligon = pol.points[0] + pos - camera.position;

		float angleToPoligon = V3d::angleBetween(pol.nVector, vectorToPoligon);
		if (angleToPoligon > M_PI / 2.f )
		{
			for (int i = 0; i < 3; i++) 
			{
				V3d realPosition = pol.points[i] + pos;
				V3d perspectivPosition = camera.Projectle(realPosition);
				sf::Vertex vertex = sf::Vertex({ perspectivPosition.x, perspectivPosition.y });
				vertex.color = c;
				sh.push_back(vertex);
			}
			c.r -= 20;
			c.g -= 20;
			c.b -= 20;
		}
	}
	if(sh.size() % 3 == 0 && sh.size() != 0)
		window.draw(&sh[0], sh.size(), sf::Triangles);
}
