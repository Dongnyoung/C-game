
#include "Draw.h"
#include <iomanip>

void Draw::gotoxy(int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Draw::displayWordlist(const std::vector<std::string>& v2, string userName, int userScore, int userNum, int comScore, int comNum) {
    system("cls");
    cout << "������̸� : " << userName << endl;
    cout << "�� ���� : " << userScore << " ���� ���� : " << userNum << endl;

    cout << "AI ���� : " << comScore << " ���� ����: " << comNum << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << std::setw(10) << std::setfill(' ') << v2[i * 10 + j];
        }
        std::cout << std::endl;
    }
    gotoxy(30, 30);

    cout << "�ܾ��Է� : ";

}


