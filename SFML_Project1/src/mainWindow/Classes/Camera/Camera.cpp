#include "Camera.h"
#include <SFML/Graphics.hpp>

void TCamera::setCameraPosition(float x, float y)
{
	Camera.setCenter(x, y);
}
void TCamera::setCameraSize(float width, float height)
{
	Camera.reset(FloatRect(0, 0, width, height));
}
View TCamera::getCamera()
{
	return Camera;
}

void TCamera::CameraMove(float& time)
{

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		Camera.move(-time * 0.1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		Camera.move(time * 0.1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		Camera.move(0, -time * 0.1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		Camera.move(0, time * 0.1);
	}

};

void TCamera::CameraScale(float delta)
{
	Camera.zoom(delta);
};