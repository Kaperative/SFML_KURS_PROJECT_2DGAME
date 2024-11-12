
#pragma once
#include "../Camera/Camera.h"
#include <SFML/Graphics.hpp>
	using namespace sf;
	class Bar
	{
	public:
		int CountElement; // ���-�� ���������
		int Indent; // ������ ���� �� ����� ���������
		int NumberOfChoose=0; // ����� ���������� ��������
		int SizeOfElement; // ������ ���������
		Vector2f Coord; // ���������� 
		int Napr; // ����������� ��������� (0 - �����������  ....  1 - �������������)
		int Scale;// ���������� �������
		std::vector<std::string> TextStart;
		sf::Font Font; // ����� ������
		sf::Text TextBar; // ����� 
		sf::Color BordChooseColor = Color(255, 255, 255, 255); // ���� ���������� ��������
		sf::Color TextColor = sf::Color::Black; // ���� ������
	
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




