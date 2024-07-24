#include <iostream>
#include <conio.h> 
#include <windows.h> 
#include "Game.h"

Game::Game() {
    showTitleScreen();
    getchar();
    system("cls");
}

void Game::showTitleScreen() {
    std::cout << "\n\n\n\n";
    std::cout << "\t\t@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@@@\n";
    std::cout << "\t\t      @       @       @            @   @        @\n";
    std::cout << "\t\t      @       @       @           @    @        @\n";
    std::cout << "\t\t      @       @@@@@@@@@         @      @@@@@@@@@@\n";
    std::cout << "\t\t      @       @       @       @        @        @\n";
    std::cout << "\t\t      @       @       @     @          @        @\n";
    std::cout << "\t\t      @       @       @   @@@@@@@@@@@  @        @\n\n\n\n\n";
    std::cout << "\t\t        ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
    std::cout << "\t\t          �ڿ�ĳ��Ÿ�ڰ��� Made by �̵���\n";
}

void Game::start() {
    map<int, std::string, std::greater<int>> rank;
    GameTable gameTable(rank);
    gameTable.showMenu();
}

GameTable::GameTable(map<int, std::string, std::greater<int>>& rank) : currentSelection(0), rank(rank) {

    menuItems[0] = "���ӽ���";
    menuItems[1] = "���Ӽ���";
    menuItems[2] = "������";
    menuItems[3] = "��������";
}
void GameTable::gotoXY(int x, int y) {
    COORD coord{};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GameTable::showMenu() {
    while (true) {
        system("cls");
        if (!navigateMenu()) {
            break;
        }
    }
}



bool GameTable::navigateMenu() {
    const int UP_ARROW = 72;
    const int DOWN_ARROW = 80;
    const int ENTER_KEY = 13;

    for (int i = 0; i < menuCount; ++i) {
        gotoXY(10, 7 + i);
        if (i == currentSelection) {
            std::cout << "> " << menuItems[i];
        }
        else {
            std::cout << "  " << menuItems[i];
        }
    }

    int key = _getch();
    switch (key) {
    case UP_ARROW:
        currentSelection = (currentSelection - 1 + menuCount) % menuCount;
        break;
    case DOWN_ARROW:
        currentSelection = (currentSelection + 1) % menuCount;
        break;
    case ENTER_KEY:
        system("cls");
        if (currentSelection == 0) {
            User user;
            ConsoleM* p = new ConsoleM(user);
            p->start();
            delete p; 
        }
        else if (currentSelection == 1) {
            showGameInstructions();
            cout << "\n\n\n\n �ƹ� Ű�� ���� ���ư���(Enter Ű)";
            _getch();
        }
        else if (currentSelection == 2) {
            printTable();
        }
        else if (currentSelection == 3) {
            return false;
        }
        break;
    default:
        break;
    }
    return true;
}
void GameTable::scoreBoard() {
    std::ifstream infile("C:\\temp\\leaderboard.txt");

    if (!infile) {
        std::cerr << "���� ���� ����" << std::endl;
        return;
    }

    string username;
    int score;
    while (infile >> username >> score) {
        rank[score] = username; 
    }
    infile.close();


}

void GameTable::printTable() {
    scoreBoard();
    cout << "=== ������ ===\n";
    int i = 1;
    for (const auto& entry : rank) {
        cout << i << ". " << entry.second << " " << entry.first << std::endl;
        i++;
    }
    std::cout << "\n�ƹ� Ű�� ���� ���ư���";
    _getch();
}



void GameTable::showGameInstructions() {
    system("cls");
    cout << "\t\t���Ӽ���:\n\n";
    cout << "\t\t�� ������ ����Ÿ�ڿ����� '�ڿ�ĳ��'�� ��Ƽ��� �� �����Դϴ�.\n\n";
    cout << "\t\tȭ�鿡 ������ �ܾ �Է��Ͽ� ���ִ� �����Դϴ�.\n\n";
    cout << "\t\t��ȭ�� AI�� ����Ͽ� Ÿ�ڽǷ��� ����ų �� �ֽ��ϴ�.\n\n";
    cout << "\t\t@@@@@@���� �¸����� @@@@@@" << endl;
    cout << "\t\t�ܾ�6���̻��� AI���� ���� ���߸� �̱�� �˴ϴ�!\n\n\n";
    cout << "\t\t�׷� .... ȭ����@@\n\n";
    cout << "\t\t - DN Lee - ";
}
