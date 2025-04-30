#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


int width = 1200;
int height = 900;

sf::RenderWindow window = { sf::VideoMode(width, height), "Poligon", sf::Style::Titlebar | sf::Style::Close };
sf::Clock tickClock = {};
float targetFrameRate = 120.f;