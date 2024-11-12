#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <SFML/System/Vector2.hpp> 
#include <string.h>

using namespace sf;


class Characters { // класс Игрока
private: float x = 0, y = 0;
public:
	float  w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir = 0; //направление (direction) движения игрока
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт
	Characters(String F, float X, float Y, float W, float H); // конструктор
	void update(float time);
	float getCoordX();
	float getCoordY();
	void interactionWithMap(sf::String TileMap[25], int rows, int cols, int& ScorePlayer);
};

