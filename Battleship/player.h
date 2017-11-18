#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"


class Player
{
public:
    Player();
    void play(Board* board);



private:
    void shoot(Board* board);
    void cinSanitizer();

    int numberOfHits{0};
    int NumberOfShots{10};
};

#endif // PLAYER_H
