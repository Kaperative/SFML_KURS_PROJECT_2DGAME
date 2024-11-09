#pragma once

#include <SFML/Graphics.hpp>
#include "Classes/Camera/Camera.h"
#include "../Classes/Bar/Bar.h"

using namespace sf;
bool IsPersonChoose(int NumPerson, int Arr[3]);
///////////////////////////////////////////////////////////////////
bool ChoosePerson(sf::RenderWindow& window,int** Person,int* ArrIndChoose)
{
    
    
    ArrIndChoose[0] = 6;
    ArrIndChoose[1] = 6;
    ArrIndChoose[2] = 6;
    

   
    Person[0][0] = 0;
    Person[0][1] = 0;

    Person[1][0] = 45;
    Person[1][1] = 0;

    Person[2][0] = 90;
    Person[2][1] = 0;

    Person[3][0] = 135;
    Person[3][1] = 0;

    Person[4][0] = 180;
    Person[4][1] = 0;

    Person[5][0] = 225;
    Person[5][1] = 0;

    Person[6][0] = 270;
    Person[6][1] = 0;

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
    
    Bar HeroBar(6, 45, 5, Vector2f(-windowWidth/2, -windowHeight/2), 0, "src/font/Score.ttf", 
                "src/img/Character/Player/ChoosePerson.jpg", 3, std::vector<std::string>{ "1","2","3","4","5","6"});

    Bar ChooseBar(3, 45, 5, Vector2f(+windowWidth / 2-150, -windowHeight / 2), 0, "src/font/Score.ttf",
        "src/img/Character/Player/ChoosePerson.jpg", 3, std::vector<std::string>{ "F1", "F2", "F3"});



    Image InfoImage;
    InfoImage.loadFromFile("src/img/BackGround/Info.jpg");//загружаем файл для карты
    Texture InfoTexture;//текстура карты
    InfoTexture.loadFromImage(InfoImage);//заряжаем текстуру картинкой
    Sprite InfoSprite;//создаём спрайт для карты
    InfoSprite.setTexture(InfoTexture);//заливаем текстуру спрайтом
    InfoSprite.setScale(1.25, 1.25);
    InfoSprite.setPosition(500, 100);

    std::string InfoText[7] = { "Assasin Gamunkul \n Tarantiez","Hyesos","Gondon","Bezdar","IGgg","Gigi","" };
 

    std::string HelpText[6] = { "Take Y for Choose","Take N for UnChoose","Take R for random Choosing" };
   
    Font FontInfo;
    if (!FontInfo.loadFromFile("src/font/Score.ttf"))
        exit(1232333);
    Text FontText(" 1", FontInfo, 25);


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
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.delta < 0)
                    Camera.CameraScale((float)1.6);
                else if (event.mouseWheelScroll.delta > 0)
                    Camera.CameraScale((float)1/1.6);
            }
            if (event.key.code == sf::Keyboard::Num1)
            {
                HeroBar.setNumberOfChoose(0);
                Ind = 0;
            }

            if (event.key.code == sf::Keyboard::Num2)
            {
                HeroBar.setNumberOfChoose(1);
                Ind = 1;
            }
            if (event.key.code == sf::Keyboard::Num3)
            {
                Ind = 2;
                HeroBar.setNumberOfChoose(2);
            }
            if (event.key.code == sf::Keyboard::Num4)
            {
                HeroBar.setNumberOfChoose(3);
                Ind = 3;
            }
            if (event.key.code == sf::Keyboard::Num5)
            {
                HeroBar.setNumberOfChoose(4);
                Ind = 4;
            }

            if (event.key.code == sf::Keyboard::Num6)
            {
                HeroBar.setNumberOfChoose(5);
                Ind = 5;
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
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (IsPersonChoose(HeroBar.getNumberOfChoose(), ArrIndChoose)==false)
                    ArrIndChoose[IndChoose] = HeroBar.getNumberOfChoose();

                }
            }
        }

        
        window.draw(BackGroundSprite);

        window.draw(InfoSprite);
       
		FontText.setFillColor(Color(240, 40, 40, 255));
		for (int i=0;i<3;i++)
		{
			FontText.setPosition(windowWidth-400, 50*(i+1));
			FontText.setString(HelpText[i]);
		
			window.draw(FontText);
			
		}

		FontText.setFillColor(Color(40, 40, 40, 255));
		FontText.setPosition(640, 340);
		FontText.setString(InfoText[Ind]);
        window.draw(FontText);

        ChooseBar.Draw(window, Camera, Person, ArrIndChoose);
        HeroBar.Draw(window, Camera, Person, ArrInd);
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
