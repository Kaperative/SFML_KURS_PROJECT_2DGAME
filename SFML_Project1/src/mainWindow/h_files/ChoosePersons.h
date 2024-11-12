#pragma once

#include <SFML/Graphics.hpp>
#include "Classes/Camera/Camera.h"
#include "../Classes/Bar/Bar.h"
#include "../Classes/Text/TText.h"
using namespace sf;
bool IsPersonChoose(int NumPerson, int Arr[3]);
///////////////////////////////////////////////////////////////////
bool ChoosePerson(sf::RenderWindow& window,int** Person,int* ArrIndChoose)
{
    
    
    ArrIndChoose[0] = 6;
    ArrIndChoose[1] = 6;
    ArrIndChoose[2] = 6;
    

   
    
   

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

    int Ind=0;
    int IndChoose = 0;
    
    Bar HeroBar(6, 40, 5, Vector2f(-windowWidth/2, -windowHeight/2), 0, "src/font/Score.ttf", 
                "src/img/Character/Player/ChoosePerson.jpg", 3, std::vector<std::string>{ "1","2","3","4","5","6"});

    Bar ChooseBar(3, 40, 5, Vector2f(+windowWidth / 2-150, -windowHeight / 2), 0, "src/font/Score.ttf",
        "src/img/Character/Player/ChoosePerson.jpg", 3, std::vector<std::string>{ "F1", "F2", "F3"});



    Image InfoImage;
    InfoImage.loadFromFile("src/img/BackGround/Info.jpg");
    Texture InfoTexture;//текстура карты
    InfoTexture.loadFromImage(InfoImage);//заряжаем текстуру картинкой
    Sprite InfoSprite;//создаём спрайт для карты
    InfoSprite.setTexture(InfoTexture);//заливаем текстуру спрайтом
    InfoSprite.setScale(1.25, 1.25);
    InfoSprite.setPosition(500, 100);
   
   
    TText TextPerson( 10,30,20, Vector2f(-350,-250),"src/font/Score.ttf", "src/text/Warrior.txt");
    TText TextInfo(10, 30, 20, Vector2f(300, 250), "src/font/Score.ttf", "src/text/InfoChoose.txt");
    TextInfo.TextColor=Color(255,255,255,255);
    int ArrInd[6] = { 0,1,2,3,4,5 };
    while (42)
    {
        window.clear();
      

        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
            {
                return false;
            }
            if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Num1)
            {
                HeroBar.setNumberOfChoose(0);
                Ind = 0;
                TextPerson.SetTextFromFile("src/text/Warrior.txt");
            }

            if (event.key.code == sf::Keyboard::Num2)
            {
                HeroBar.setNumberOfChoose(1);
                Ind = 1;
                TextPerson.SetTextFromFile("src/text/Heal.txt");
            }
            if (event.key.code == sf::Keyboard::Num3)
            {
                Ind = 2;
                HeroBar.setNumberOfChoose(2);
                TextPerson.SetTextFromFile("src/text/Assasin.txt");
            }
            if (event.key.code == sf::Keyboard::Num4)
            {
                HeroBar.setNumberOfChoose(3);
                Ind = 3;
                TextPerson.SetTextFromFile("src/text/Mage.txt");
            }
            if (event.key.code == sf::Keyboard::Num5)
            {
                HeroBar.setNumberOfChoose(4);
                Ind = 4;
                TextPerson.SetTextFromFile("src/text/SpearMan.txt");
            }

            if (event.key.code == sf::Keyboard::Num6)
            {
                HeroBar.setNumberOfChoose(5);
                Ind = 5;
                TextPerson.SetTextFromFile("src/text/Woman.txt");
            }

            if (event.key.code == sf::Keyboard::F1)
            {
                ChooseBar.setNumberOfChoose(0);
                IndChoose = 0;
            }

            if (event.key.code == sf::Keyboard::F2)
            {
                ChooseBar.setNumberOfChoose(1);
                IndChoose = 1;
            }

            if (event.key.code == sf::Keyboard::F3)
            {
                ChooseBar.setNumberOfChoose(2);
                IndChoose = 2;
            }
            if (event.key.code == sf::Keyboard::Y)
            {
                if (IsPersonChoose(6, ArrIndChoose) == false)
                {
                    delete[] Person;
                    return true;
                }
            }
        }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (IsPersonChoose(HeroBar.getNumberOfChoose(), ArrIndChoose)==false)
                    ArrIndChoose[IndChoose] = HeroBar.getNumberOfChoose();

                }
            }
        }

        
        window.draw(BackGroundSprite);

        window.draw(InfoSprite);
 

        ChooseBar.Draw(window, Camera, Person, ArrIndChoose,6);
        HeroBar.Draw(window, Camera, Person, ArrInd,6);
        TextPerson.Draw(window, Camera);
        TextInfo.Draw(window, Camera);
        window.setView(Camera.getCamera());
        window.display();
        
    }
    
    return true;

}

bool IsPersonChoose(int NumPerson, int Arr[3])
{
    for (int i = 0; i < 3; i++)
    {
        if (NumPerson == Arr[i])
            return true;
    }
    return false;
};
