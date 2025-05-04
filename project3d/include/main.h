#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Character.h"
#include "object.h"

int width = 1200;
int height = 900;

sf::RenderWindow window = { sf::VideoMode(width, height), "Poligon", sf::Style::Titlebar | sf::Style::Close };
sf::Clock tickClock = {};
float targetFrameRate = 120.f;

Character character = Character();
std::vector<Object> objects;

//-------------------------------------------------------------------------
const float mouseSensitivity = 0.002f;  // Czu³oœæ obrotu
float cameraAngle_alfa = 0.f;
float cameraAngle_beta = 0.f;
//-------------------------------------------------------------------------