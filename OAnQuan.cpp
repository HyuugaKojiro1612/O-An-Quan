//#include <iostream>
#include "OAnQuan.h"
//using namespace std;

void Player::moveClockwise(Board& board, int start) {
    int next;
    int temp = board.sqr[start];
    board.sqr[start] = 0;
    while (temp > 0) {
        if (start == 0) start = 11;
        else --start;

        ++board.sqr[start];
        --temp;
    }

    if (start == 0) next = 11;
    else next = start - 1;

    if (next == 0 || next == 6) {
        return;
    } 
    else if (board.sqr[next] != 0) {
        moveClockwise(board, next);
    }
    else {
        if (next == 0) next = 11;
        else --next;

        if (board.sqr[next] == 0) {
            return;
        }
        else {
            consumeClockwise(board, next);
        }
    }
}

void Player::moveCounterClockwise(Board& board, int start) {
    int next;
    int temp = board.sqr[start];
    board.sqr[start] = 0;
    while (temp > 0) {
        if (start == 11) start = 0;
        else ++start;

        ++board.sqr[start];
        --temp;
    }

    if (start == 11) next = 0;
    else next = start + 1;

    if (next == 0 || next == 6) {
        return;
    } 
    else if (board.sqr[next] != 0) {
        moveCounterClockwise(board, next);
    }
    else {
        if (next == 11) next = 0;
        else ++next;

        if (board.sqr[next] == 0) {
            return;
        }
        else {
            consumeCounterClockwise(board, next);
        }
    }
}

void Player::consumeClockwise(Board& board, int idx ) {
    this->point += board.sqr[idx];
    board.sqr[idx] = 0;
    if (idx == 1 || idx == 7) return;
    else if (idx == 0) {
        if (board.sqr[11] == 0 && board.sqr[10] != 0) {
            consumeClockwise(board, 10);
        }
    }
    else if (board.sqr[idx - 1] == 0 && board.sqr[idx - 2] != 0) {
        consumeClockwise(board, idx - 2);
    }
}

void Player::consumeCounterClockwise(Board& board, int idx ) {
    this->point += board.sqr[idx];
    board.sqr[idx] = 0;
    if (idx == 5 || idx == 11) return;
    else if (idx == 10) {
        if (board.sqr[11] == 0 && board.sqr[0] != 0) {
            consumeCounterClockwise(board, 0);
        }
    }
    else if (board.sqr[idx + 1] == 0 && board.sqr[idx + 2] != 0) {
        consumeCounterClockwise(board, idx + 2);
    }
}

void Player::checkEmptySqr(Board& board) {
    // checkEmptySqr algorithm starts
    if (board.flag == 0) {
        if (board.sqr[1] != 0 || board.sqr[2] != 0 || board.sqr[3] != 0 || board.sqr[4] != 0 || board.sqr[5] != 0) {
            return;
        }
        for (int i = 1; i <= 5; ++i) {
            board.sqr[i] = 1;
        }
    }
    else if (board.flag == 1) {
        if (board.sqr[7] != 0 || board.sqr[8] != 0 || board.sqr[9] != 0 || board.sqr[10] != 0 || board.sqr[11] != 0) {
            return;
        }
        for (int i = 7; i <= 11; ++i) {
            board.sqr[i] = 1;
        }
    }
    this->point -= 5;
    cout << "\nRai quan dau luot.\n";
    board.printBoard();
    // checkEmptySqr algorithm ends

}

void Board::checkPlayer(int idx) {
    while (true) {
        if (idx >= 1 && idx <= 5) {
            if (this->flag == 0) return;
            else {
                cout << "\nMoi ban nhap lai dia chi o: ";
                cin >> idx;
            }
        }
        else if (idx >= 7 && idx <= 11) {
            if (this->flag == 1) return;
            else {
                cout << "\nMoi ban nhap lai dia chi o: ";
                cin >> idx;
            } 
        }
    }
}

bool Board::checkEndGame() {
    if (this->sqr[0] == 0 && this->sqr[6] == 0) {
        return true;
    }
    else {
        this->flag = !(this->flag);
        return false;
    }
}

void Player::moves(Board& board) {
    checkEmptySqr(board);
    int idx, direction;
    cout << "\nMoi ban chon o de boc quan: ";
    cin >> idx;
    board.checkPlayer(idx);

    cout << "\nMoi ban chon huong de rai quan: ";
    cin >> direction;
    if (direction == 0) moveClockwise(board, idx);
    else if (direction == 1) moveCounterClockwise(board, idx);
}
