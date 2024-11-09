#include "Bar.h"

Bar::Bar(int FCountElement, int FSizeElement, int FIndent, Vector2f FCoord, int FNapr,
    std::string FFontName, std::string FIconFile, int FScale, const std::vector<std::string>& FTextStart)
{
    CountElement = FCountElement;
    Indent = FIndent;
    
    Napr = FNapr;
    Coord = FCoord;
    SizeOfElement = FSizeElement;
    Scale = FScale;
    TextStart = FTextStart;  // Копируем вектор строк

    Font.loadFromFile(FFontName);
    TextBar.setFont(Font);
    TextBar.setCharacterSize(20);

    IconImage.loadFromFile(FIconFile);
    IconTexture.loadFromImage(IconImage);
    IconSprite.setTexture(IconTexture);
}

void Bar::Draw(RenderWindow& window, TCamera& Camera, int** Arr, int* ArrChooseIND)
{
    IconSprite.setScale(float(Scale), float(Scale));

    for (int i = 0; i < CountElement; i++) {
        // Устанавливаем позицию спрайта в зависимости от ориентации
        if (Napr == 0)  // вертикально
            IconSprite.setPosition(Camera.Camera.getCenter().x + Coord.x,
                Camera.Camera.getCenter().y + Coord.y + i * Indent + SizeOfElement * i * Scale);
        else if (Napr == 1)  // горизонтально
            IconSprite.setPosition(Camera.Camera.getCenter().x + Coord.x + i * Indent + SizeOfElement * i * Scale,
                Camera.Camera.getCenter().y + Coord.y);

        IconSprite.setColor(Color(255, 255, 255, 255));
        IconSprite.setTextureRect(IntRect(Arr[6][0], Arr[6][1], SizeOfElement, SizeOfElement - 5));
        window.draw(IconSprite);  // Рисуем задний фон

      
            IconSprite.setTextureRect(IntRect(Arr[ArrChooseIND[i]][0], Arr[ArrChooseIND[i]][1], SizeOfElement, SizeOfElement - 5));
     

        // Подсветка выбранного элемента
        if (i == NumberOfChoose) {
            IconSprite.setColor(BordChooseColor);
        }
        else {
            IconSprite.setColor(Color(255, 255, 255, 95));
        }
        window.draw(IconSprite);  // Рисуем иконку

        // Устанавливаем текст из TextStart и его позицию
        TextBar.setString(TextStart[i]);
        TextBar.setFillColor(TextColor);
        if (Napr == 0)  // вертикально
            TextBar.setPosition(Camera.Camera.getCenter().x + Coord.x,
                Camera.Camera.getCenter().y + Coord.y + i * Indent + SizeOfElement * i * Scale);
        else if (Napr == 1)  // горизонтально
            TextBar.setPosition(Camera.Camera.getCenter().x + Coord.x + i * Indent + SizeOfElement * i * Scale,
                Camera.Camera.getCenter().y + Coord.y);

        window.draw(TextBar);  // Рисуем текст
    }
}

void Bar::setNumberOfChoose(int Num)
{
    NumberOfChoose = Num;
};

int Bar::getNumberOfChoose()
{
    return NumberOfChoose;
};