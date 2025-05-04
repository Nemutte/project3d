#include "object.h"

Object::Object() : position{V3d(0.f, 0.f, 0.f)}
{
	model = new Model();
}

Object::Object(V3d position) : position{ position }
{
	model = new Model();
}

void Object::draw(sf::RenderWindow& window, Camera& camera)
{
	model->draw(window, position, camera);
}
