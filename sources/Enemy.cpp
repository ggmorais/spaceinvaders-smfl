#include <pch.h>
#include <Enemy.h>


Enemy::Enemy(std::string texturePath, sf::Vector2f initialPos)
{
	if (!this->texture.loadFromFile(texturePath))
		std::cerr << "Error loading enemy texture.";

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(initialPos);
}

void Enemy::update()
{
	this->sprite.move(0.f, 1.f);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

const sf::FloatRect Enemy::getRect()
{
	return this->sprite.getGlobalBounds();
}

bool Enemy::collide(sf::FloatRect& other)
{
	if (this->sprite.getGlobalBounds().intersects(other))
		return true;
	
	return false;
}

void Enemy::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

sf::Vector2f Enemy::getPosition()
{
	return this->sprite.getPosition();
}