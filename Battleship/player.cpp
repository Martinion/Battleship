#include <iostream>
#include <limits>
#include "player.h"
#include "board.h"


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

    numberOfShots--;
}

void Player::play()
{
    bool playAgain;

    do
    {
        Board board;

        setDifficulty();

        board.makeBoard(numberOfShips);

        do
        {
            board.printPlayerBoard();

            std::cout << "Shots left: " << numberOfShots << std::endl;

            shoot(&board);
        }while(board.checkForShips() && numberOfShots > 0);

        if(numberOfShots == 0)
            std::cout << "you've used all your shots! Game over!!" << std::endl;
        else
            std::cout << "Conglaturations! A winner is you!!" << std::endl;

        board.printGameBoard();

        std::cout << "Do you want to play again?" << std::endl;
        playAgain = yesNoMenu();

    }while(playAgain);
}

void Player::setDifficulty()
{
    int playerChoice;

    std::cout << "What difficulty do you want?" << std::endl
              << "1: Easy" << std::endl
              << "2: Normal" << std::endl
              << "3: Hard" << std::endl
              << "4: Insane" << std::endl;
    do
    {
        std::cin >> playerChoice;
        cinSanitizer();
    }while(playerChoice > 4 && playerChoice < 1);

    switch(playerChoice)
    {
    case 1:
        numberOfShots = 30;
        numberOfShips = 10;
        break;
    case 2:
        numberOfShots = 20;
        numberOfShips = 8;
        break;
    case 3:
        numberOfShots = 10;
        numberOfShips = 5;
        break;
    default:
        numberOfShots = 3;
        numberOfShips = 3;
    }
}

bool Player::yesNoMenu()
{
    char choice;

    while(true)
    {
        std::cout << "Y/N";

        std::cin >> choice;

        cinSanitizer();

        switch(choice)
        {
        case 'y':
        case 'Y':
            return true;
            break;
        case 'n':
        case 'N':
            return false;
        }
    }
}

void Player::cinSanitizer()
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
