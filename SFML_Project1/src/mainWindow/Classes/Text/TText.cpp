#include "TText.h"
#include <iostream>
#include <fstream>
#include <string>

TText::TText(int FCountElement, int FSize, int FIndent, Vector2f FCoord,std::string FFontName, std::string FNameTextFile)
{
	
     CountElement = FCountElement;
     Indent = FIndent;

     Coord = FCoord;
     Size = FSize;
     

     Font.loadFromFile(FFontName);
     TextStr.setFont(Font);
     TextStr.setCharacterSize(20);

    

     SetTextFromFile(FNameTextFile);
};

void TText::SetTextFromFile(std::string FNameTextFile)
{
    std::ifstream file(FNameTextFile);  // ��������� ����
    if (!file.is_open()) {  // ���������, ������� �� ������� ����
        std::cerr << "�� ������� ������� ����." << std::endl;
        exit(3434);
    }

    std::string line;
    int i = 0;
    while (std::getline(file, line)) {  // ������ ���� ���������
        ArrText[i] = line;
        i++;
    }

    file.close();  // ��������� ����

};

void TText::Draw(RenderWindow& window, TCamera& Camera)
{
    for (int i=0;i<CountElement;i++)
    {
        TextStr.setString(ArrText[i]);
        TextStr.setFillColor(TextColor);
        TextStr.setPosition(Camera.Camera.getCenter().x + Coord.x,Camera.Camera.getCenter().y + Coord.y + i * Indent + Size * i);
        window.draw(TextStr);
    }
};