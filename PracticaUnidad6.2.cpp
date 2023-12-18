// Practica Unidad 6 - Space - MAVI - Fabrizio Aguilar
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int main()
{

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Space");

	sf::Vector2f posicion(0.0f, 200.0f);
	sf::Vector2f velocidad(0.5f, 0.0f);
	const float aceleracion = 0.007f;

	bool acelerarXpos = false;
	bool acelerarXneg = false;
	bool acelerarYpos = false;
	bool acelerarYneg = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
	
				sf::Keyboard::Key key = event.key.code;

				if (key == sf::Keyboard::Left) {
					acelerarXneg = true;					
				}
				else if (key == sf::Keyboard::Right) {		
					acelerarXpos = true;					
				}
				else if (key == sf::Keyboard::Up) {				
					acelerarYneg = true;					
				}
				else if (key == sf::Keyboard::Down) {					
					acelerarYpos = true;					
				}				
			}
		
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Left) {
					acelerarXneg = false;
				}
				else if (event.key.code == sf::Keyboard::Right) {
					acelerarXpos = false;
				}
				else if (event.key.code == sf::Keyboard::Up) {
					acelerarYneg = false;
				}
				else if (event.key.code == sf::Keyboard::Down) {
					acelerarYpos = false;
				}
			}

		}
		
		float deltaTime = 1.0f / 60.0f;
		
		if (acelerarXpos) {
			velocidad.x += aceleracion * deltaTime;

		}else if (acelerarXneg) {
			velocidad.x -= aceleracion * deltaTime;
		}
		else
		if (acelerarYpos) {
			velocidad.y += aceleracion * deltaTime;
		}
		else if (acelerarYneg) {
			velocidad.y -= aceleracion * deltaTime;
		}
		
		posicion.x += velocidad.x * deltaTime;
		posicion.y += velocidad.y * deltaTime;

		if (posicion.x < 0.0f) {
			posicion.x = 0.0f;
			velocidad.x = 0.0f;
		}
		if (posicion.y < 0.0f) {
			posicion.y = 0.0f;
			velocidad.y = 0.0f;
		}
		if (posicion.x > window.getSize().x - 40.0f)  {
			posicion.x = static_cast<float>(window.getSize().x) - 40.0f;
			velocidad.x = 0.0f;
		}
		if (posicion.y > window.getSize().y - 40.0f) {
			posicion.y = static_cast<float>(window.getSize().y) - 40.0f;
			velocidad.y = 0.0f;
		}

		window.clear();
	
		sf::CircleShape ball(20.0f);
		ball.setFillColor(sf::Color::Cyan);
		ball.setPosition(posicion);
		window.draw(ball);
		
		window.display();
	}

	return 0;
}
