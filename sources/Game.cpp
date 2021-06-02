#include <pch.h>
#include <Game.h>
#include <Bullet.h>
#include <Player.h>
#include <Background.h>
#include <Enemy.h>


void Game::initVariables()
{
    this->window = nullptr;
    this->player = nullptr;
    this->background = nullptr;
}

void Game::initWindow()
{
    this->videoMode.width = 800;
    this->videoMode.height = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Space Invaders");
    this->window->setFramerateLimit(60);
}

Game::Game()
{
    this->initVariables();
    this->initWindow();

    this->background = new Background("assets/spaceshooter/Backgrounds/blue.png", *this->window);
    this->player = new Player("assets/spaceshooter/PNG/playerShip2_blue.png");
}

Game::~Game()
{
    delete this->window;
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->event)) {

        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyReleased:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::spawnEnemies()
{
    if (this->enemies.size() < 10) {
        
        int slots = this->window->getSize().x / 50;

        for (int i = 0; i <= slots; i++) {
            if (i % 2 == 0) {
                Enemy* enemy = new Enemy("assets/spaceshooter/PNG/Enemies/enemyBlack1.png", sf::Vector2f(100.f, 100.f));
                enemy->setPosition(sf::Vector2f(50 * i, -enemy->getRect().height * 3));
                this->enemies.push_back(enemy);
            }
        }
    }
}

void Game::checkEnemyCollisions()
{
    for (int i = 0; i < this->enemies.size(); i++) {
        for (int j = 0; j < this->bullets.size(); j++) {
            if (this->enemies[i]->getRect().intersects(this->bullets[j]->getRect())) {
                this->enemies.erase(this->enemies.begin() + i);
                //this->bullets.erase(this->bullets.begin() + j);
                this->bullets[j]->objectCollision();
            }
        }
    }
}

void Game::spawnBullet()
{
    if (this->bulletTimer <= 0) {
        sf::Vector2f playerPos = this->player->sprite.getPosition();
        playerPos.x += this->player->sprite.getGlobalBounds().width / 2.f;
        playerPos.y -= this->player->sprite.getLocalBounds().height / 2.f;

        this->bullets.push_back(new Bullet(
            "assets/spaceshooter/PNG/Lasers/laserBlue02.png",
            "assets/spaceshooter/PNG/Lasers/laserBlue10.png",
            playerPos
        ));

        this->bulletTimer = this->bulletTimerWait;
    }
}

void Game::update()
{
    this->pollEvents();
    this->bulletTimer -= 1.f;

    this->spawnEnemies();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->spawnBullet();

    this->checkEnemyCollisions();

    for (int j = 0; j < this->bullets.size(); j++) {
        if (this->bullets[j]->collided)
            this->bullets.erase(this->bullets.begin() + j);
    }
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::render()
{
    this->window->clear();

    this->player->update(*this->window);

    this->background->render(*this->window);
    this->player->render(*this->window);

    for (auto enemy : this->enemies) {
        enemy->update();
        enemy->render(*this->window);
    }

    for (auto blt : this->bullets) {
        blt->update();
        blt->render(*this->window);
    }
        
    this->window->display();
}