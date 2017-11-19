#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"


class Player
{
public:
    void play();
private:
    void shoot(Board* board);
    void setDifficulty();
    void cinSanitizer();
    bool yesNoMenu();

    int numberOfHits{0};
    int numberOfShots{20};
    int numberOfShips{5};
};

#endif // PLAYER_H
