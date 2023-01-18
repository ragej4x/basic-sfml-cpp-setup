#include <SFML/Graphics.hpp>

int main()
{
    // Create a window with the title "test"
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game", sf::Style::Titlebar | sf::Style::Close);

    // Create a circle shape with a radius of 50 and a red fill color
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Red);

    // Set the initial position of the shape to be in the center of the window
    shape.setPosition(400, 300);

    // Set the velocity of the shape (pixels per second)
    sf::Vector2f velocity(50.0f, 50.0f);

    // Set the time per frame
    sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
    sf::Clock clock;

    // Run the game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get the elapsed time since the last frame
        sf::Time elapsedTime = clock.restart();

        // Update the position of the shape based on its velocity
        shape.move(velocity * elapsedTime.asSeconds());

        // Check if the shape is out of bounds
        if (shape.getPosition().x > window.getSize().x - shape.getRadius() || shape.getPosition().x < shape.getRadius())
            velocity.x = -velocity.x;
        if (shape.getPosition().y > window.getSize().y - shape.getRadius() || shape.getPosition().y < shape.getRadius())
            velocity.y = -velocity.y;

        // Clear the window to a white color
        window.clear(sf::Color::White);

        // Draw the shape
        window.draw(shape);

        // Display the contents of the window on the screen
        window.display();
    }

    return 0;
}
