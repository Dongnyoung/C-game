
#include "Draw.h"
#include <iomanip>

void Draw::gotoxy(int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Draw::displayWordlist(const std::vector<std::string>& v2, string userName, int userScore, int userNum, int comScore, int comNum) {
    system("cls");
    cout << "사용자이름 : " << userName << endl;
    cout << "내 점수 : " << userScore << " 맞춘 개수 : " << userNum << endl;

    cout << "AI 점수 : " << comScore << " 맞춘 개수: " << comNum << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << std::setw(10) << std::setfill(' ') << v2[i * 10 + j];
        }
        std::cout << std::endl;
    }
    gotoxy(30, 30);

    cout << "단어입력 : ";

}


