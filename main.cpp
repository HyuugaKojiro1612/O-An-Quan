//#include <iostream>
#include "OAnQuan.h"
#include "OAnQuan.cpp"
//using namespace std;



void OAnQuan() {
    Board board;
    Player* P = new Player[2];
    cout << "TRO CHOI O AN QUAN\n\n";
    board.printBoard();
    int turn = 1;
    do {
        cout << "\n\nLuot: " << to_string(turn) <<", player" <<to_string(int(board.flag)) <<":";
        P[board.flag].moves(board);
        cout << "\nPlayer1: " << to_string(P[1].point) << "\n";
        board.printBoard();
        cout << "\nPlayer0: " << to_string(P[0].point);
        ++turn;
    } while(board.checkEndGame() != true);

    // summarise
    for (int i = 1; i <= 5; ++i) {
        P[0].point += board.sqr[i];
    }
    for (int i = 7; i <= 11; ++i) {
        P[1].point += board.sqr[i];
    }

    if (P[0].point > P[1].point) {
        cout << "\nPlayer0 chien thang!";
    }
    else if (P[0].point < P[1].point) {
        cout << "\nPlayer1 chien thang!";
    }
    else {
        cout << "Ket qua hoa.";
    }
}



int main() {
    OAnQuan();
    
    cout << endl;
    system("pause");
    return 0;
}