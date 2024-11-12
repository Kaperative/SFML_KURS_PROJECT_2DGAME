#include <SFML/Graphics.hpp>
#include "Const/ConstWindow.h"
#include "h_files/ChoosePersons.h"
#include "h_files/IsWillBeTraining.h"

using namespace sf;
RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Solo leveling", sf::Style::Fullscreen);
//////////////////////////////////////////////////////////////////////
void main()
{
    int ArrPerson[3];
    int** PersonRectangle = new int* [7]; // выделение памяти под двумерный массив
    for (int i = 0; i < 7; i++) {
        PersonRectangle[i] = new int[2] {45*i,0};
    }

    // Выбор героев для дальнейшей игры
   // if (ChoosePerson(window, PersonRectangle, ArrPerson) == false) { window.close(); exit(0); }
    int ChooseOfTraining = IsWantTraining(window);

    if (ChooseOfTraining == -1) { window.close(); }
    else if (ChooseOfTraining==0) {    /* KOD TRENIROVKI */ }
    else if (ChooseOfTraining == 1) {/* SKIP TRENIROVKY */ }
    exit(0);
}