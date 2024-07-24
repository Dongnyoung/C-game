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
    std::cout << "\t\t        게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n";
    std::cout << "\t\t          자원캐기타자게임 Made by 이동녕\n";
}

void Game::start() {
    map<int, std::string, std::greater<int>> rank;
    GameTable gameTable(rank);
    gameTable.showMenu();
}

GameTable::GameTable(map<int, std::string, std::greater<int>>& rank) : currentSelection(0), rank(rank) {

    menuItems[0] = "게임시작";
    menuItems[1] = "게임설명";
    menuItems[2] = "점수판";
    menuItems[3] = "게임종료";
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
            cout << "\n\n\n\n 아무 키나 눌러 돌아가기(Enter 키)";
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
        std::cerr << "파일 열기 오류" << std::endl;
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
    cout << "=== 점수판 ===\n";
    int i = 1;
    for (const auto& entry : rank) {
        cout << i << ". " << entry.second << " " << entry.first << std::endl;
        i++;
    }
    std::cout << "\n아무 키나 눌러 돌아가기";
    _getch();
}



void GameTable::showGameInstructions() {
    system("cls");
    cout << "\t\t게임설명:\n\n";
    cout << "\t\t이 게임은 한컴타자연습의 '자원캐기'를 모티브로 한 게임입니다.\n\n";
    cout << "\t\t화면에 나오는 단어를 입력하여 없애는 게임입니다.\n\n";
    cout << "\t\t진화된 AI와 대결하여 타자실력을 향상시킬 수 있습니다.\n\n";
    cout << "\t\t@@@@@@게임 승리조건 @@@@@@" << endl;
    cout << "\t\t단어6개이상을 AI보다 먼저 맞추면 이기게 됩니다!\n\n\n";
    cout << "\t\t그럼 .... 화이팅@@\n\n";
    cout << "\t\t - DN Lee - ";
}
