#include <iostream> 
#include <SFML/Graphics.hpp>
#include "../../../Classes/Character/Characters.h"
#include "../Const/TrainingMap.h"
#include <Math.h>
#include "../../../Classes/Camera/Camera.h"
#include "../../../Const/ConstWindow.h"
#include "../../../h_files/PlayerEvents.h"
#include "../../../Classes/Bar/Bar.h"
#include "../../../Const/ItemsConst.h"
#include "../../../Const/RecPerson.h"
using namespace sf;


int GameInLocation(sf::RenderWindow& window,int NumOfMap)
{

    //////////      RIGHTBAR    ///////////////////////////////////////////////////////////////////////
    int** Person = new int* [7]; // выделение памяти под двумерный массив for RIGHTBAR
    for (int i = 0; i < 7; i++) {
        Person[i] = new int[2] {i*45,0};
    }
    Bar PersonBar(3, 40, 5, Vector2f(+windowWidth / 2 - 150, -windowHeight / 2), 0, "src/font/Score.ttf",
        "src/img/Character/Player/ChoosePerson.jpg", 3, std::vector<std::string>{ "F1", "F2", "F3"});
    ///////////////////////////////////////////////////////////////////////////////////////////////////


    //////////      LeftBar1    ///////////////////////////////////////////////////////////////////////
    int** Items = new int* [NumOfItemsInGame]; // выделение памяти под двумерный массив for RIGHTBAR
    for (int i = 0; i < 7; i++) {
        Items[i] = new int[2] {i * 40, 0};
    }
    Bar ItemsBar(6, 40, 5, Vector2f(-windowWidth / 2, -windowHeight / 2), 0, "src/font/Score.ttf",
        "src/img/Character/Player/Items.jpg", 3, std::vector<std::string>{ "1", "2", "3", "4", "5", "6"});
   
    ///////////////////////////////////////////////////////////////////////////////////////////////////


    //////////      LeftBar2    ///////////////////////////////////////////////////////////////////////
    int** Skills = new int* [7]; // выделение памяти под двумерный массив for RIGHTBAR
    for (int i = 0; i < 7; i++) {
        Skills[i] = new int[2] {i * 45, 0};
    }
    Bar SkillsBar(3, 40, 5, Vector2f(-windowWidth / 2 + 150, -windowHeight / 2), 0, "src/font/Score.ttf",
        "src/img/Character/Player/ChoosePerson.jpg", 3, std::vector<std::string>{ "Z", "X", "C"});
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    Characters Player("src/img/Character/Player/Choose.jpg", 150, 150, 50.0, 50.0);
   


    TCamera Camera;
    Camera.setCameraSize(windowWidth, windowHeight);
    Camera.setCameraPosition(Player.getCoordX(), Player.getCoordY());
    float CurrentFrame = 0;//хранит текущий кадр
    Clock clock;
   
    Image map_image;
    map_image.loadFromFile("src/img/Map/map.png");//загружаем файл для карты
    Texture map;//текстура карты
    map.loadFromImage(map_image);//заряжаем текстуру картинкой
    Sprite s_map;//создаём спрайт для карты
    s_map.setTexture(map);//заливаем текстуру спрайтом

    int DeltWidthImgPers = PersonRect[ArrIndChoose[0]][0];
    int DeltHeightImgPers = PersonRect[ArrIndChoose[0]][1];
    Player.sprite.setTextureRect(IntRect(50 * int(CurrentFrame) + DeltWidthImgPers, 0 + DeltHeightImgPers, 43, 47));
    while (42)
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        window.clear();
        int Num=0;
        
        PlayerChooseItem(ItemsBar);
        PlayerMove(CurrentFrame, time, Camera, Player, DeltWidthImgPers, DeltHeightImgPers);
        Num = PlayerChooseHero(DeltWidthImgPers, DeltHeightImgPers, PersonRect, ArrIndChoose);
        if (Num != -1)
        {

            PersonBar.setNumberOfChoose(Num);

            Player.sprite.setTextureRect(IntRect(50 * int(CurrentFrame) + DeltWidthImgPers, 0 + DeltHeightImgPers, 43, 47));
            window.draw(Player.sprite);//рисуем спрайт объекта p класса player
        }
        Player.update(time);//оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться
        Player.interactionWithMap(TrainingMap, 25, 40, ScorePlayer);
        window.setView(Camera.getCamera());
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                return -1;
            }

        }
        s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
        for (int i = -100; i < 100; i++)
            for (int j = -100; j < 100; j++)
            {
               
               
                s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(s_map);//рисуем квадратики на экран
            }

        for (int i = 0; i < HEIGHT_MAP_Training; i++)
            for (int j = 0; j < WIDTH_MAP_Training; j++)
            {
                if (TrainingMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
                if (TrainingMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
                if ((TrainingMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


                s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(s_map);//рисуем квадратики на экран
            }
        window.draw(Player.sprite);//рисуем спрайт объекта p класса player
        PersonBar.Draw(window, Camera, Person, ArrIndChoose, 6);
        SkillsBar.Draw(window, Camera, Skills, ArrSkills, 6);
        ItemsBar.Draw(window, Camera, Items, ArrItems, 6);
       
        window.display();
    }

    
}



