#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class TCamera
{
public:
	sf::View Camera;

	void setCameraPosition(float x, float y);
	void setCameraSize(float width, float height);
	View getCamera();
	void CameraMove(float& time);
	void CameraScale(float delta);
};

