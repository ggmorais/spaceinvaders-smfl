#pragma once

#include <pch.h>


class Enemy
{
	private:
		sf::Texture texture;
		sf::Sprite sprite;

		float speed = 5.f;

	public:
		Enemy(std::string texturePath, sf::Vector2f initialPos);

		bool dead = false;

		void update();
		void render(sf::RenderTarget& target);
		void setPosition(sf::Vector2f position);
		sf::Vector2f getPosition();
		bool collide(sf::FloatRect& other);
		const sf::FloatRect getRect();
};