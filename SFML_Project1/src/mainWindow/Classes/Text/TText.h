#pragma once
#include <SFML/Graphics.hpp>
#include "../Camera/Camera.h"

///////////////////////////////////////
using namespace sf;
class TText
{
	int CountElement; // кол-во строк текста
	int Indent; // отступ друг от друга элементов
	int Size; // размер элементов
	Vector2f Coord; // координата
	std::vector<std::string> ArrText;
	sf::Font Font; // шрифт текста
	sf::Text TextStr; // текст 
	sf::Color TextColor = sf::Color::Black; // цвет текста

	TText(int FCountElement, int FSize, int FIndent, Vector2f FCoord,
		std::string FFontName, std::string FNameTextFile);
	void SetTextFromFile(std::string FNameTextFile);
	void Draw(RenderWindow& window, TCamera& Camera);
};

