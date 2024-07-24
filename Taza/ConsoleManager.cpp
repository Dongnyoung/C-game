// ConsoleManager.cpp
#include "ConsoleManager.h"
#include "User.h"
#include "Draw.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <thread>

using namespace std;

void ConsoleM::fileRead(ifstream& fin) {
    string line;
    while (getline(fin, line)) {
        v.push_back(line);
    }
}

void ConsoleM::random() {
    v2.clear();
    for (int i = 0; i < 50; ++i) {
        int index = rand() % v.size();
        v2.push_back(v[index]);
    }
}

void ConsoleM::deleteW(int duration) {
    Sleep(duration);
    int index = rand() % v2.size();
    v2[index] = " ";
    com += 10;
    comN++;
}

void ConsoleM::inputLoop() {

    while (running) {
        system("cls");
        gotoxy(40, 30);
        displayWordlist(v2, user.getName(), user.getScore(), user.getNum(), com, comN);
        user.inputword(v2);

    }
}

void ConsoleM::gameLoop(int duration) {

    while (running) {
        system("cls");
        displayWordlist(v2, user.getName(), user.getScore(), user.getNum(), com, comN);
        deleteW(duration);

        if (comN > 5 || user.getNum() > 5) {
            running = false;

        }
    }
}

void ConsoleM::run(int level, int duration) {

    system("cls");
    cout << level << "단계... 2초 뒤 시작합니다." << endl;
    Sleep(1000);
    system("cls");
    cout << level << "단계... 1초 뒤 시작합니다." << endl;
    Sleep(1000);
    system("cls");

    running = true;
    random();
    displayWordlist(v2, user.getName(), user.getScore(), user.getNum(), com, comN);


    inputThread = thread(&ConsoleM::inputLoop, this);
    gameLoop(duration);
    running = false;
    inputThread.join();  
    system("cls");
    cout << "게임 종료" << endl;
    cout << "내 점수 : " << user.getScore() << " 맞춘 개수 : " << user.getNum() << endl;
    cout << "AI 점수 : " << com << " 맞춘 개수: " << comN << endl;
    if (user.getNum() > comN) {
        cout << "사용자 승" << endl;
    }
    else if (user.getNum() < comN) {
        cout << "AI 승" << endl;
        cout << "사용자 패배로 게임종료" << endl;
        getchar();
        flag = false;

    }
    else {
        cout << "무승부" << endl;
    }


    user.reset();
    com = 0;
    comN = 0;
}

void ConsoleM::game() {
    while (true) {
        int n;
        cout << "단계를 선택하시오(1~4) 게임종료시 5: ";
        cin >> n;

        switch (n) {
        case 1:
            run(1, 6000);
            break;
        case 2:
            run(2, 5000);
            break;
        case 3:
            run(3, 3000);
            break;
        case 4:
            run(4, 2000);
            break;
        case 5:
            if (n == 5) {
                system("cls");
                user.saveScoreToLeaderboard();
                cout << user.getName() << "의 " << "최종점수 : " << user.getScore() << endl;
                cout << "아무키나 입력하시오." << endl;
                getchar();
                getchar();
                return;
            }

        default:
            break;
        }
        if (!flag) {
            system("cls");
            user.saveScoreToLeaderboard();
            cout << user.getName() << "의 " << "최종점수 : " << user.getScore() << endl;
            cout << "아무키나 입력하시오." << endl;
            getchar();
            break;
        }
    }
}

void ConsoleM::start() {
    srand(static_cast<unsigned int>(time(NULL)));
    const char* file = "C:\\temp\\words.txt";
    ifstream fin(file);
    if (!fin) {
        cout << "단어 파일 열기 오류" << endl;
        return;
    }
    fileRead(fin);
    fin.close();

    string userName;
    cout << "사용자 이름을 입력하시오 : ";
    getline(cin, userName);
    user.setName(userName);
    game();
}
