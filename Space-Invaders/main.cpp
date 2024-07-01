#include <SFML/Graphics.hpp>
#include <iostream>

class Player {

private:

    int player_score = 0;
    int health = 5;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 2;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    
    int getScore() {
        return player_score;
    };

    void setScore(int newScore) {
        player_score = newScore;
    };

    int getMoveSpeed() {
        return movement_speed;
    }

    sf::Vector2f getPosition() {
        return position;
    }

    void takeDamage();
    
    void move(float offsetX) {
        position.x += offsetX;
    }
    void shootBullets();
};

int main()
{

    // Define the video mode (dimensions)
    //sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Window");

    Player player;
    player.player_texture.loadFromFile("assets/textures/player_ship.png");

    player.player_sprite.setTexture(player.player_texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            player.move(-1.0f * player.getMoveSpeed());

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

            player.move(1.0f * player.getMoveSpeed());
        }

        // Clear the window
        window.clear(sf::Color::Blue);


        player.player_sprite.setPosition(player.getPosition());
        window.draw(player.player_sprite);
        
        // Display whatever you draw
        window.display();

        
    }

    return 0;
}