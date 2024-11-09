#include <SFML/Graphics.hpp>
#include "Const/ConstWindow.h"
#include "h_files/ChoosePersons.h"


using namespace sf;


//////////////////////////////////////////////////////////////////////
void main()
{

    
   
    RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Solo leveling", sf::Style::Fullscreen);

    int ArrPerson[3];
    int** PersonRectangle = new int* [7]; // выделение памяти под двумерный массив
    for (int i = 0; i < 7; i++) {
        PersonRectangle[i] = new int[2];
    }
    // Выбор героев для дальнейшей игры
    if (ChoosePerson(window,PersonRectangle,ArrPerson) == false)
    {
        window.close();
    }


    while (window.isOpen())
    {
        window.clear();

       

       
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       

        window.display();
    }
}