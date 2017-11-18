#ifndef BOARD_H
#define BOARD_H


class Board
{
public:
    Board();
    void printGameBoard();
    void makeBoard(int numberOfShips);
    void printPlayerBoard();
    bool hit(int row, int column, int &hit);


private:
    int letterToNumber(char letter);
    void writeLetters();
    int randomColumn();
    int randomRow();
    void makeEmptyBoard();

    static const int M{6}, N{6};
    const char BLANK{' '};
    const char HIT{'H'};
    const char SHIP{'S'};
    const char MISS{'M'};
    char gameBoard[M][N];
};

#endif // BOARD_H
