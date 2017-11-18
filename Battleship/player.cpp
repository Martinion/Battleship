#include <iostream>
#include <limits>
#include "player.h"
#include "board.h"

Player::Player()
{

}

void Player::shoot(Board* board)
{
    std::string playerChoice;
    int row;
    int column;
    bool unknownCommand;

    std::cout << "Where will you shoot? (ex: B3)" << std::endl;

    do
    {
        std::cin >> playerChoice;
        cinSanitizer();

        row = static_cast<int>(playerChoice[1]) - 49;
        column = static_cast<int>(playerChoice[0]) - 65;

        unknownCommand = board->hit(row, column, numberOfHits);

    }while(unknownCommand);

    NumberOfShots--;
}

void Player::play(Board* board)
{
    shoot(board);
}

void Player::cinSanitizer()
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
