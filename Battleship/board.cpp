#include <iostream>
#include <cstdlib>
#include "board.h"

Board::Board()
{

}

int Board::randomRow()
{
    return rand()%(M-2)+1;
}

int Board::randomColumn()
{
    return rand()%(N-2)+1;
}

void Board::makeEmptyBoard()
{
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            gameBoard[i][j] = BLANK;
        }
    }
}

bool Board::checkForShips()
{
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(gameBoard[i][j] == SHIP)
                return true;
        }
    }
    return false;
}

bool Board::hit(int row, int column, int &hit)
{
    if(row < 0 || row >= M || column < 0 || column >= N)
    {
        std::cout << "Unknown command. Type again" << std::endl;
        return true;
    }

    switch(gameBoard[row][column])
    {
    case ' ':
    case 'M':
    case 'H':
        std::cout << "You missed!" << std::endl;
        gameBoard[row][column] = MISS;
        return false;
    case 'S':
        std::cout << "You hit!" << std::endl;
        gameBoard[row][column] = HIT;
        hit++;
        return false;
    default:
        std::cout << "Unexpected error";
        return true;
    }
}

void Board::makeBoard(int numberOfShips)
{
    makeEmptyBoard();

    for(int i = 0; i < numberOfShips; i++)
    {
        bool shipPlaced{false};

        do
        {
            int tempRow = randomRow();
            int tempColumn = randomColumn();

            int orientation = rand()%2;
            int orientation2 = 1 - orientation;

            if(gameBoard[tempRow][tempColumn] == BLANK && gameBoard[tempRow + orientation][tempColumn + orientation2] == BLANK && gameBoard[tempRow - orientation][tempColumn - orientation2] == BLANK)
            {
                gameBoard[tempRow][tempColumn] = SHIP;
                gameBoard[tempRow + orientation][tempColumn + orientation2] = SHIP;
                gameBoard[tempRow - orientation][tempColumn - orientation2] = SHIP;
                shipPlaced = true;
            }
        }while(!shipPlaced);
    }
}

void Board::writeLetters()
{
    std::cout << "  |";

    for(int i = 0; i < N; i++)
    {
        std::cout << static_cast<char>(i + 65) << "|";
    }
    std::cout << std::endl << std::endl;
}

void Board::printGameBoard()
{
    for(int i = 0; i < M; i++)
    {
        std::cout << i + 1 << " ";

        for(int j = 0; j < N; j++)
        {
            std::cout << "|" << gameBoard[i][j];
        }
        std::cout << "|" << std::endl;
    }

    writeLetters();
}

void Board::printPlayerBoard()
{
    for(int i = 0; i < M; i++)
    {
        std::cout << i + 1 << " ";

        for(int j = 0; j < N; j++)
        {
            if(gameBoard[i][j] != SHIP)
                std::cout << "|" << gameBoard[i][j];
            else
                std::cout << "|" << BLANK;
        }
        std::cout << "|" << std::endl;
    }

    writeLetters();
}

int Board::letterToNumber(char letter)
{
    return static_cast<int>(letter)-65;
}
