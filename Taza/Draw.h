
#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
class Draw {
public:
    void gotoxy(int x, int y);
    void displayWordlist(const std::vector<std::string>& v2, string userName, int userScore, int userNum, int comScore, int comNum);

};

#endif // DRAW_H
