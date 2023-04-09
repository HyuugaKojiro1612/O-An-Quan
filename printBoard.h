#ifndef PRINTBOARD_H
#define PRINTBOARD_H


#include <string>
using namespace std;

string idx_player0 = "                 [1]          [2]          [3]          [4]           [5] \n";
string idx_player1 = "                 [11]         [10]         [9]          [8]           [7] \n";
string line1 = "     &------|------------|------------|------------|------------|------------|------& \n";
string line2 = "    &       |            |            |            |            |            |       & \n";
string line3 = "   &        |     05     |     05     |     05     |     05     |     05     |        & \n";
string line4 = "  &         |            |            |            |            |            |         & \n";
string line5 = " &    10    |------------|------------|------------|------------|------------|    10    & \n";
string line6 = "  &         |            |            |            |            |            |         & \n";
string line7 = "   &        |     05     |     05     |     05     |     05     |     05     |        & \n";
string line8 = "    &       |            |            |            |            |            |       & \n";
string line9 = "     &------|------------|------------|------------|------------|------------|------& \n";

string line3_start = "   &        |     ";
string line3_mid = "     |     ";
string line3_end = "     |        & \n";

string line5_start = " &    ";
string line5_mid = "    |------------|------------|------------|------------|------------|    ";
string line5_end = "    & \n";

string toString(int num) {
    if (num < 10) return "0" + to_string(num);
    else return to_string(num);
}

#endif