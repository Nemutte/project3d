#include "model.h"

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
	poligons.push_back(Poligon(poligon, V3d(0.f, -100.f, 0.f)));
	poligon[0] = tops[5];
	poligon[1] = tops[7];
	poligon[2] = tops[6];
	poligons.push_back(Poligon(poligon, V3d(0.f, -100.f, 0.f)));
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
	poligon[1] = tops[6];
	poligon[2] = tops[2];
	poligons.push_back(Poligon(poligon, V3d(0.f, -100.f, 0.f)));
	poligon[0] = tops[7];
	poligon[1] = tops[3];
	poligon[2] = tops[2];
	poligons.push_back(Poligon(poligon, V3d(0.f, -100.f, 0.f)));
}

void Model::draw(sf::RenderWindow& window, V3d position)
{
	std::vector<sf::Vertex> sh;
	float d = 1000;
	sf::Color c = sf::Color(255, 255, 255);
	for (Poligon &pol : poligons)
	{
		float xp, yp;
		V3d realPosition;
		for (int i = 0; i < 3; i++) {
			realPosition = position + pol.points[i];
			xp = (realPosition.x * d) / (realPosition.z + d);
			yp = (realPosition.y * d) / (realPosition.z + d);
			sf::Vertex vertex = sf::Vertex({ xp, yp });
			vertex.color = c;
			sh.push_back(vertex);
		}
		c.r -= 20;
		c.g -= 20;
		c.b -= 20;
	}
	window.draw(&sh[0], sh.size(), sf::Triangles);
}
