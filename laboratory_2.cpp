#include <SFML/Graphics.hpp> 
#include <functional> 
#include <cmath> 
#include <string> 

using namespace std;

// ������� ��� ��������� ������� 
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // ���������� �������� ������� 

        // �������������� ��������� � �������� 
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // ���������� ����� � ������ ������ 
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    // �������� ���� 
    sf::RenderWindow window(sf::VideoMode(800, 600), "���������� ��� ������ ��������");

    // ���������� ��� �������� ���������������� ����� 
    sf::CircleShape userPoint(5); // ������ 5 �������� 
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; // ���������� ��� �������� ������������� ���������������� ����� 

    // �������� ������ 
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // ����� ��� ����������� ��������� ����� 
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    // ��� X � Y 
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); // ������ ��� X 
    xAxis[0].color = sf::Color::White; // ���� ��� 
    xAxis[1].position = sf::Vector2f(750, 300); // ����� ��� X 
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); // ������ ��� Y 
    yAxis[0].color = sf::Color::White; // ���� ��� 
    yAxis[1].position = sf::Vector2f(400, 550); // ����� ��� Y 
    yAxis[1].color = sf::Color::White;

    string place;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // �������� ����� ����� 
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // ��������� ������� ����� 
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // �������������� �������� ��������� � "��������������" 
                    float mathX = (mousePos.x - 400) / 30.0f; // ������� 30 �� X 
                    float mathY = -(mousePos.y - 300) / 100.0f; // ������� 100 �� Y 

                    // ��������� ����� ���������������� ����� 
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; // ��������, ��� ����� ���������� 

                    // ������ �������� �������������� ����� 
                    double y = round(mathY * 10);
                    double x = round(mathX);
                    if (y == x + 3 or y == -5)
                        place = "line";
                    else if (y < x + 3 and y < -5)
                        place = "1";
                    else if (y < x + 3 and y > -5)
                        place = "2";
                    else if (y > x + 3 and y > -5)
                        place = "3";
                    else if (y > x + 3 and y < -5)
                        place = "4";

                    // ���������� ������ � ������������ ����� 
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")\nPosition: " + place);
                }
            }
        }

        // ������� ������ 
        window.clear();

        // ��������� ���� 
        window.draw(xAxis);
        window.draw(yAxis);

        // ��������� �������� 
        drawGraph(window, [](float x) { return x + 3; }, -10, 10, 30, 10, sf::Color::Blue);  // y = x + 3 
        drawGraph(window, [](float x) { return -5; }, -10, 10, 30, 10, sf::Color::Red);    // y = -5 

        // ��������� ���������������� �����, ���� ��� ���������� 
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // ����������� ������ ����� 
        window.display();
    }

    return 0;
}