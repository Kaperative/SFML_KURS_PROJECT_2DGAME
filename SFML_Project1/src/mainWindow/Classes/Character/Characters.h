#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <SFML/System/Vector2.hpp> 
#include <string.h>

using namespace sf;


class Characters { // ����� ������
private: float x = 0, y = 0;
public:
	float  w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0; //����������� (direction) �������� ������
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������
	Characters(String F, float X, float Y, float W, float H); // �����������
	void update(float time);
	float getCoordX();
	float getCoordY();
	void interactionWithMap(sf::String TileMap[25], int rows, int cols, int& ScorePlayer);
};

