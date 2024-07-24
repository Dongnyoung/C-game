#include "User.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>
#include <Windows.h>

using namespace std;


void User::inputword(vector<string>& v) {
    string word;
    gotoxy(40, 30);
    getline(cin, word);
    gotoxy(40 + word.length(), 30);
    cout << word;

    auto it = find(v.begin(), v.end(), word);
    if (it != v.end()) {
        *it = " "; 
        score += 10;
        num += 1;
    }

}

void User::reset() {
    num = 0;
}
void User::saveScoreToLeaderboard() {
    ofstream outfile("C:\\temp\\leaderboard.txt"); 
    if (outfile.is_open()) {
        outfile << name << " " << score << endl;
        outfile.close();
    }
}