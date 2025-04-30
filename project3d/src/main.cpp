#include "main.h"
#include "v3.h"
#include "model.h"

void update(float deltatime)
{

}
void draw()
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0; j < 5;j++)
		{
			Model model = Model();
			model.draw(window, V3d(200.f + 200.f * j, 100.f + 200.f * i, 200.f));
		}
	}
}
void Tick(float deltaTime)
{
	update(deltaTime);
	draw();
}
int main()
{
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
		}

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