#include <ctime>
#include <cstdlib>
#include "player.h"
#include "board.h"

int main()
{
    srand(time(nullptr));

    Player player;

    player.play();
}
