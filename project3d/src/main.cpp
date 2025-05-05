#include "main.h"
#include "v3.h"
#include "model.h"

void update(float deltatime)
{
	character.update(deltatime);
}
void draw()
{
	for(Object &obj:objects)
		obj.draw(window, character.camera);
}
void Tick(float deltaTime)
{
	update(deltaTime);
	draw();
}
int main()
{
	for (int i = 0; i< 5; i++)
		for (int j = 0; j< 5; j++)
			objects.push_back(Object({ -500.f + 200 * i, -400.f + 200 * j, 200.f }));

	//-------------------------------------------------------------------------
	window.setMouseCursorVisible(false);
	sf::Vector2i center(window.getSize().x / 2, window.getSize().y / 2);
	sf::Mouse::setPosition(center, window);
	//-------------------------------------------------------------------------
	tickClock.restart();
	float accumutatedTime = 0.f;
	float targetDeltaTime = 1.f / targetFrameRate;


	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::EventType::Closed)
				window.close();
			else if (windowEvent.type == sf::Event::KeyPressed)
			{
				if (windowEvent.key.code == sf::Keyboard::Escape)
					window.close();
				V3d mVector = { 0.f, 0.f, 0.f };
				character.moveVector *= 0.f;
				if (windowEvent.key.code == sf::Keyboard::W)
					character.move_W = true;
				if (windowEvent.key.code == sf::Keyboard::S)
					character.move_S = true;
				if (windowEvent.key.code == sf::Keyboard::A)
					character.move_A = true;
				if (windowEvent.key.code == sf::Keyboard::D)
					character.move_D = true;
			}
			else if (windowEvent.type == sf::Event::KeyReleased)
			{
				if (windowEvent.key.code == sf::Keyboard::W)
					character.move_W = false;
				if(windowEvent.key.code == sf::Keyboard::S)
					character.move_S = false;
				if(windowEvent.key.code == sf::Keyboard::A)
					character.move_A = false;
				if(windowEvent.key.code == sf::Keyboard::D)
					character.move_D = false;
			}
		}
		//-------------------------------------------------------------------------
		// Pozycja myszy
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2i delta = mousePos - center;

		// Zmieniamy yaw i pitch na podstawie ruchu myszy
		cameraAngle_alfa += delta.x * mouseSensitivity;
		cameraAngle_beta += delta.y * mouseSensitivity;
		// Ograniczamy pitch, ¿eby kamera siê nie "przewróci³a"
		const float pitchLimit = M_PI / 2.0f - 0.01f;
		if (cameraAngle_beta > pitchLimit) cameraAngle_beta = pitchLimit;
		if (cameraAngle_beta < -pitchLimit) cameraAngle_beta = -pitchLimit;

		character.camera.SetAngles(cameraAngle_alfa, cameraAngle_beta);

		// Reset pozycji myszy do œrodka
		sf::Mouse::setPosition(center, window);

		//-------------------------------------------------------------------------
		float frameDeltaTime = tickClock.restart().asSeconds();
		accumutatedTime += frameDeltaTime;

		if (accumutatedTime > targetDeltaTime)
		{
			window.clear();
			Tick(targetDeltaTime);
			window.display();
			//printf("| FPS: %f \n", 1.f / accumutatedTime);
			accumutatedTime = 0.f;
		}
	}
	return 0;

}