#pragma once

#include <pch.h>


class Background
{
	private:
		sf::Texture texture;
		std::vector<sf::Sprite> sprites;

	public:
		Background(std::string texturePath, sf::RenderTarget& target);

		void render(sf::RenderTarget& target);
};