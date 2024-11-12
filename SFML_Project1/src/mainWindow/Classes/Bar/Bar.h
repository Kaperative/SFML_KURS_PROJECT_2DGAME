
#pragma once
#include "../Camera/Camera.h"
#include <SFML/Graphics.hpp>
	using namespace sf;
	class Bar
	{
	public:
		int CountElement; // кол-во элементов
		int Indent; // отступ друг от друга элементов
		int NumberOfChoose=0; // номер выбранного элемента
		int SizeOfElement; // размер элементов
		Vector2f Coord; // координата 
		int Napr; // направление отрисовки (0 - вертикально  ....  1 - горизонтально)
		int Scale;// увелечение размера
		std::vector<std::string> TextStart;
		sf::Font Font; // шрифт текста
		sf::Text TextBar; // текст 
		sf::Color BordChooseColor = Color(255, 255, 255, 255); // цвет выбранного элемента
		sf::Color TextColor = sf::Color::Black; // цвет текста
	
		~Bar()
		{

		};
		Image IconImage;
		Texture IconTexture;
		Sprite IconSprite;

		Bar(int FCountElement, int FSizeElement, int FIndent, Vector2f FCoord, int FNapr,
			std::string FFontName, std::string FIconFile, int FScale, const std::vector<std::string>& FTextStart);

		void Draw(RenderWindow& window, TCamera& Camera, int** Arr, int* ArrChooseIND, int IndBack);
		void setNumberOfChoose(int Num);
		int getNumberOfChoose();
	};




