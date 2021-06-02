#include <pch.h>
#include <Player.h>


constexpr auto PI = 3.141592653589793238463;


Player::Player(std::string texturePath)
{
	std::cout << "Loading players texture.\n";

	if (!this->texture.loadFromFile(texturePath)) {
		std::cout << "Erro loading player texture.\n";
	}

	this->sprite.setTexture(this->texture);
}

Player::~Player()
{
}

void Player::checkWallCollision(sf::RenderTarget& target)
{
	float posX = this->sprite.getPosition().x;
	float posY = this->sprite.getPosition().y;
	float width = this->sprite.getGlobalBounds().width;
	float height = this->sprite.getGlobalBounds().height;

	if (posX + width > target.getSize().x) {
		this->sprite.move(-this->speed, 0.f);
	}
	if (posX < 0) {
		this->sprite.move(this->speed, 0.f);
	}
	if (posY < 0) {
		this->sprite.move(0.f, this->speed);
	}
	if (posY + height > target.getSize().x) {
		this->sprite.move(0.f, -this->speed);
	}
}

void Player::update(sf::RenderTarget& target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->sprite.move(0.f, -this->speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->sprite.move(0.f, this->speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->sprite.move(this->speed, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->sprite.move(-this->speed, 0.f);

	this->checkWallCollision(target);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

void Player::rotate(sf::Vector2i mousePos)
{
	sf::Vector2f prevPos = this->sprite.getPosition();

	this->sprite.setPosition(this->sprite.getGlobalBounds().width / 2.f, this->sprite.getGlobalBounds().height / 2.f);
	float x = this->sprite.getPosition().x;
	float y = this->sprite.getPosition().y;

	float angle = atan2(mousePos.y - y, mousePos.x - x) * (180.0 / PI);

	std::cout << "angle: " << angle << "\n";

	this->sprite.setRotation(angle * -1);

	this->sprite.setPosition(prevPos);
}