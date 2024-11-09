#pragma once
#include <SFML/Graphics.hpp>
#include "../Camera/Camera.h"

///////////////////////////////////////
using namespace sf;
class TText
{
	int CountElement; // ���-�� ����� ������
	int Indent; // ������ ���� �� ����� ���������
	int Size; // ������ ���������
	Vector2f Coord; // ����������
	std::vector<std::string> ArrText;
	sf::Font Font; // ����� ������
	sf::Text TextStr; // ����� 
	sf::Color TextColor = sf::Color::Black; // ���� ������

	TText(int FCountElement, int FSize, int FIndent, Vector2f FCoord,
		std::string FFontName, std::string FNameTextFile);
	void SetTextFromFile(std::string FNameTextFile);
	void Draw(RenderWindow& window, TCamera& Camera);
};

