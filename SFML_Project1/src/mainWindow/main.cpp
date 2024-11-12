#include <SFML/Graphics.hpp>
#include "Const/ConstWindow.h"
#include "h_files/ChoosePersons.h"
#include "h_files/IsWillBeTraining.h"
#include "Locations/Training/h_files/TrainingLocation.h"

using namespace sf;

RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Solo leveling", sf::Style::Fullscreen);
//////////////////////////////////////////////////////////////////////
void main()
{

    // Выбор героев для дальнейшей игры
     if (ChoosePerson(window) == false) { window.close(); exit(0); }
    int ChooseOfTraining = IsWantTraining(window);
    if (ChooseOfTraining == -1) { window.close(); }
    else if (ChooseOfTraining == 0) { if (GameInLocation(window, 0) == -1) { window.close(); } } // Training is true
    else if (ChooseOfTraining == 1) {  } // training is false
   
    

    exit(0);
}