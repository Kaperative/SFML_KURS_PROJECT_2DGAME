#pragma once

#include <../SFML/Graphics.hpp>
#include "../Classes/Camera/Camera.h"
#include "../Classes/Bar/Bar.h"
#include "../Classes/Text/TText.h"
using namespace sf;

int IsWantTraining(sf::RenderWindow& window)
{
    int** ArrRectangle = new int* [3]; // выделение памяти под двумерный массив
    for (int i = 0; i < 3; i++) {
        ArrRectangle[i] = new int[2];
    }
    ArrRectangle[0][0] = 0;
    ArrRectangle[0][1] = 0;
    ArrRectangle[1][0] = 60;

    ArrRectangle[1][1] = 0;
    ArrRectangle[2][0] = 0;
    ArrRectangle[2][1] = 60;

    int ArrInd[2] = { 0,1 };

    Image BackGroundImage;
    BackGroundImage.loadFromFile("src/img/BackGround/Choose.jpg");
    Texture BackGroundTexture;
    BackGroundTexture.loadFromImage(BackGroundImage);
    Sprite BackGroundSprite;
    BackGroundSprite.setTexture(BackGroundTexture);
    BackGroundSprite.setScale(2, 2);

    TCamera Camera;
    Camera.setCameraSize(windowWidth, windowHeight);
    Camera.setCameraPosition(windowWidth / 2, windowHeight / 2);

    Bar ChooseBar(2, 60, 50, Vector2f(-windowWidth/4, -windowHeight/4), 1, "src/font/Score.ttf",
        "src/img/BackGround/YesNo.png", 8, std::vector<std::string>{ "Y", "N"});


 
    TText TextInfo(10, 60, 20, Vector2f(360, 250), "src/font/Score.ttf", "src/text/InfoChooseTraining.txt");
    TextInfo.TextColor = Color(255, 255, 255, 255);
    while (42)
    {
        window.clear();


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                delete(ArrRectangle);
                return -1;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Y)
                {
                    ChooseBar.setNumberOfChoose(0);
                }
                if (event.key.code == sf::Keyboard::N)
                {
                    ChooseBar.setNumberOfChoose(1);
                }
                if (event.key.code == sf::Keyboard::Enter)
                {
                    return ChooseBar.getNumberOfChoose();
                }
            }


        }

        window.setView(Camera.getCamera());
        window.draw(BackGroundSprite);
        ChooseBar.Draw(window, Camera, ArrRectangle, ArrInd,2);
        TextInfo.Draw(window, Camera);
        window.display();

    }

    return true;
};