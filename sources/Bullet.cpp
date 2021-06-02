#include <pch.h>
#include <Bullet.h>


Bullet::Bullet(std::string texturePath, std::string collisionTexturePath, sf::Vector2f origin)
{
	if (!this->texture.loadFromFile(texturePath))
		std::cerr << "Error loading bullet texture.";

	this->collisionTexturePath = collisionTexturePath;

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(origin.x - this->sprite.getGlobalBounds().width / 2, origin.y);
}

Bullet::~Bullet()
{
	std::cout << "Destroying!!" << "\n";
}

void Bullet::update()
{
	if (this->collideTimer > 0) {
		if (this->collideTimer >= this->collideTimerMax) {
			this->collided = true;
			std::cout << "Collide!" << "\n";
		}

		this->collideTimer += 1;

		return;
	}

	this->sprite.move(0.f, -this->speed);

	if (this->sprite.getPosition().x < 0)
		this->collided = true;
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

const sf::FloatRect Bullet::getRect()
{
	return this->sprite.getGlobalBounds();
}

void Bullet::objectCollision()
{
	this->collideTimer = 1.f;

	sf::Vector2f prevPos = this->sprite.getPosition();

	this->texture.loadFromFile(this->collisionTexturePath);
	this->sprite.setTexture(this->texture, true);
	prevPos.x -= this->sprite.getGlobalBounds().width / 5;
	this->sprite.setPosition(prevPos);
}
