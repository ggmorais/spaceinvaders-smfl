#include <pch.h>
#include <Game.h>


int main()
{

    Game game;

    std::cout << "hello world!!";

    while (game.running()) {
        game.update();
        game.render();
    }

    return 0;
}