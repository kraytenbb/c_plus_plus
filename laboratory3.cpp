#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    int cellSize = 50;
    const int gridSize = 10;

    RenderWindow window(VideoMode(500, 500), "Кубы");
    RectangleShape cells[gridSize][gridSize];

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        for (int y = 0; y < gridSize; y++) {
            for (int x = 0; x < gridSize; x++) { //для каждой ячейки делаем следующее
                cells[x][y].setSize(Vector2f(cellSize - 2, cellSize - 2));// устанавливаем размер так, чтобы клетки не сливались друг с другом
                cells[x][y].setPosition(x * cellSize, y * cellSize);// соответствие координат и клеток
                cells[x][y].setFillColor(Color::Black);//цвет клеток
                cells[x][y].setOutlineColor(Color::White);//цвет границ
                cells[x][y].setOutlineThickness(1);//толщина границ

                if ((x + y) % 2 == 1 and (x + y) < 11)
                    //чтобы при любом размере сетки получился квадрат 4х4 мы заполняем ячейки ориентируясь на центр сетки
                    cells[x][y].setFillColor(Color::Green);//закрашиваем полученные клетки в зеленый

                window.draw(cells[x][y]);//метод для отрисовки
            }
        }
        window.display();
    }
    return 0;
}