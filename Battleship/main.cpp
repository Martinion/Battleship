#include <ctime>
#include <cstdlib>
#include "player.h"
#include "board.h"

int main()
{
    srand(time(nullptr));

    Board board;

    board.makeBoard(5);

    board.printGameBoard();

    board.printPlayerBoard();

    Player player;

    player.play(&board);
}
