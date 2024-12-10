#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    int cellSize = 50;
    const int gridSize = 10;

    RenderWindow window(VideoMode(500, 500), "Êóáû");
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
            for (int x = 0; x < gridSize; x++) { //äëÿ êàæäîé ÿ÷åéêè äåëàåì ñëåäóþùåå
                cells[x][y].setSize(Vector2f(cellSize - 2, cellSize - 2));// óñòàíàâëèâàåì ðàçìåð òàê, ÷òîáû êëåòêè íå ñëèâàëèñü äðóã ñ äðóãîì
                cells[x][y].setPosition(x * cellSize, y * cellSize);// ñîîòâåòñòâèå êîîðäèíàò è êëåòîê
                cells[x][y].setFillColor(Color::Black);//öâåò êëåòîê
                cells[x][y].setOutlineColor(Color::White);//öâåò ãðàíèö
                cells[x][y].setOutlineThickness(1);//òîëùèíà ãðàíèö

                if ((x + y) % 2 == 1 and (x + y) < 11)
                    //÷òîáû ïðè ëþáîì ðàçìåðå ñåòêè ïîëó÷èëñÿ êâàäðàò 4õ4 ìû çàïîëíÿåì ÿ÷åéêè îðèåíòèðóÿñü íà öåíòð ñåòêè
                    cells[x][y].setFillColor(Color::Green);//çàêðàøèâàåì ïîëó÷åííûå êëåòêè â çåëåíûé

                window.draw(cells[x][y]);//ìåòîä äëÿ îòðèñîâêè
            }
        }
        window.display();
    }
    return 0;
}
