#ifndef OANQUAN_H
#define OANQUAN_H
#include <iostream>
#include "printBoard.h"
using namespace std;


class Board {
public:
    int sqr[12];
    bool flag;

    Board() {
        for (int i = 0; i < 12; ++i) {
            if (i == 0 || i == 6) sqr[i] = 10;
            else sqr[i] = 5;
        }

        flag = true;
    }

    void printBoard() {
        cout << idx_player1;
        cout << line1 << line2;
        cout << line3_start << toString(sqr[11])
            << line3_mid << toString(sqr[10])
            << line3_mid << toString(sqr[9])
            << line3_mid << toString(sqr[8])
            << line3_mid << toString(sqr[7]) << line3_end;
        cout << line4;
        cout << line5_start << toString(sqr[0])
            << line5_mid << toString(sqr[6]) << line5_end;
        cout << line6;
        cout << line3_start << toString(sqr[1])
            << line3_mid << toString(sqr[2])
            << line3_mid << toString(sqr[3])
            << line3_mid << toString(sqr[4])
            << line3_mid << toString(sqr[5]) << line3_end;
        cout << line8 << line9;
        cout << idx_player0;
    }



    void checkPlayer(int idx);

    bool checkEndGame();
};


class Player {
public:
    int point;

    Player() : point(0) {}

    
    
    void moveClockwise(Board& board, int idx);

    void moveCounterClockwise(Board& board, int idx);

    void consumeClockwise(Board& board, int idx);

    void consumeCounterClockwise(Board& board, int idx);

    void checkEmptySqr(Board& board);

    void moves(Board& board);

};
#endif