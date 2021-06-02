#include <pch.h>
#include <Background.h>


Background::Background(std::string texturePath, sf::RenderTarget& target)
{
	if (!this->texture.loadFromFile(texturePath)) {
		std::cerr << "Error loading backgrounds texture";
	}

	for (int i = 0; i <= target.getSize().x / this->texture.getSize().x; i++) {
		for (int j = 0; j <= target.getSize().y / this->texture.getSize().y; j++) {
			sf::Sprite sprite;
			sprite.setTexture(this->texture);
			sprite.setPosition(this->texture.getSize().x * i, this->texture.getSize().y * j);
			this->sprites.push_back(sprite);
		}
	}
}

void Background::render(sf::RenderTarget& target)
{
	for (auto sprite : this->sprites)
		target.draw(sprite);
}