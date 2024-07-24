#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio.h> // _getch() 함수 사용
#include <windows.h> // SetConsoleCursorPosition() 함수 사용
#include "User.h"
#include "ConsoleManager.h"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Game {
public:
    Game();
    void start();

private:
    void showTitleScreen();
};

class GameTable {
public:
    GameTable(map<int, string, greater<int>>& rank);
    void showMenu();
    bool navigateMenu();
    void showGameInstructions();
    void scoreBoard();
    void printTable();
private:
    map<int, string, greater<int>>& rank;
    void gotoXY(int x, int y);
    const static int menuCount = 4;
    const char* menuItems[menuCount] = { "게임시작", "게임설명", "점수판", "게임종료" };
    int currentSelection = 0;

};

#endif // GAME_H
