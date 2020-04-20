#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"

int main()
{
    Game game = Game(1000, 800);

    game.Run();

    return 0;
}