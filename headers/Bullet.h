#pragma once

#include <pch.h>


class Bullet
{
	private:
		sf::Texture texture;
		sf::Sprite sprite;

		std::string collisionTexturePath;

		float speed = 12.f;
		float collideTimerMax = 16.f;
		float collideTimer = 0.f;

	public:
		Bullet(std::string texturePath, std::string collisionTexturePath, sf::Vector2f origin);
		~Bullet();

		bool collided = false;

		void update();
		void render(sf::RenderTarget& target);
		const sf::FloatRect getRect();
		void objectCollision();
};