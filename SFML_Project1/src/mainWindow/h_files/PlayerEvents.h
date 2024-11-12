#include <SFML/Graphics.hpp>
#include "../Classes/Camera/Camera.h"
#include "../Classes/Character/Characters.h"
void PlayerMove(float& CurrentFrame, float& time, TCamera& Camera, Characters& p, int& DeltWidthImgPers, int& DeltHeightImgPers)
{

	///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		p.dir = 1; p.speed = 0.1;  //dir =1 - направление вверх, speed =0.1 - скорость движения. Заметьте - время мы уже здесь ни на что не умножаем и нигде не используем каждый раз

		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		p.sprite.setTextureRect(IntRect(50 * int(CurrentFrame) + DeltWidthImgPers, 48 + DeltHeightImgPers, 43, 47)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
		Camera.setCameraSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		Camera.setCameraPosition(p.getCoordX(), p.getCoordY());
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		p.dir = 0; p.speed = 0.1;//направление вправо, см выше
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		p.sprite.setTextureRect(IntRect(50 * int(CurrentFrame) + DeltWidthImgPers, 96 + DeltHeightImgPers, 43, 47));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
		Camera.setCameraSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		Camera.setCameraPosition(p.getCoordX(), p.getCoordY());
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		p.dir = 3; p.speed = 0.1;//направление вниз, см выше
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		p.sprite.setTextureRect(IntRect(50 * int(CurrentFrame) + DeltWidthImgPers, 144 + DeltHeightImgPers, 43, 47));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
		Camera.setCameraSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		Camera.setCameraPosition(p.getCoordX(), p.getCoordY());
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		p.dir = 2; p.speed = 0.1;
		CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
		if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
		p.sprite.setTextureRect(IntRect(50 * int(CurrentFrame) + DeltWidthImgPers, 0 + DeltHeightImgPers, 43, 47)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
		Camera.setCameraSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		Camera.setCameraPosition(p.getCoordX(), p.getCoordY());

	}


};


int PlayerChooseHero(int& DeltWidthImgPers, int& DeltHeightImgPers, int Person[6][2], int Arr[3])
{

	if (Keyboard::isKeyPressed(Keyboard::F1)) {
		DeltWidthImgPers = Person[Arr[0]][0];
		DeltHeightImgPers = Person[Arr[0]][1];
		return 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::F2)) {
		DeltWidthImgPers = Person[Arr[1]][0];
		DeltHeightImgPers = Person[Arr[1]][1];
		return 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::F3)) {
		DeltWidthImgPers = Person[Arr[2]][0];
		DeltHeightImgPers = Person[Arr[2]][1];
		return 2;
	}

	return -1;
}

int PlayerChooseItem(Bar& FItemsBar)
{
	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
		FItemsBar.setNumberOfChoose(0);
		return 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num2)) {
		FItemsBar.setNumberOfChoose(1);
		return 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num3)) {
		FItemsBar.setNumberOfChoose(2);
		return 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num4)) {
		FItemsBar.setNumberOfChoose(3);
		return 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num5)) {
		FItemsBar.setNumberOfChoose(4);
		return 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num6)) {
		FItemsBar.setNumberOfChoose(5);
		return 0;
	}
	
    
    


	return -1;
}

