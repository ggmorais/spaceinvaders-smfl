#pragma once

#include <Player.h>
#include <Bullet.h>
#include <Enemy.h>
#include <Background.h>


class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event event;
        
        Background* background;
        Player* player;
        std::vector<Bullet*> bullets;
        std::vector<Enemy*> enemies;
        float bulletTimerWait = 8.f;
        float bulletTimer = 0.f;

        void initVariables();
        void initWindow();

    public:
        Game();
        ~Game();

        const bool running() const;

        void update();
        void render();
        void pollEvents();
        void spawnBullet();
        void spawnEnemies();
        void checkEnemyCollisions();
};