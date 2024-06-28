#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Window");



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Cyan);

        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(400, 300); // Set position
        window.draw(circle);

        sf::ConvexShape polygon;

        polygon.setPointCount(3);  // Set the number of points (triangle = 3 points)

        // Define the position of the triangle's points
        polygon.setPoint(0, sf::Vector2f(300, 300));
        polygon.setPoint(1, sf::Vector2f(350, 200));
        polygon.setPoint(2, sf::Vector2f(400, 300));

        polygon.setFillColor(sf::Color::Blue);
        polygon.setPosition(800, 300); // Set position
        window.draw(polygon);

        sf::RectangleShape square(sf::Vector2f(100.0f, 100.0f));

        square.setFillColor(sf::Color::Red);
        square.setPosition(100, 100); // Set position
        window.draw(square);


        // Display whatever you draw
        window.display();
    }

    return 0;
}