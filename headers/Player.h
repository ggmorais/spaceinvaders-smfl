#pragma once


class Player
{
	private:
		float speed = 8.f;

		void checkWallCollision(sf::RenderTarget& target);

	public:
		sf::Texture texture;
		sf::Sprite sprite;

		Player(std::string texturePath);
		~Player();

		void render(sf::RenderTarget& target);
		void update(sf::RenderTarget& target);
		void rotate(sf::Vector2i mousePos);
};