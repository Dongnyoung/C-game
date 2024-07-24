#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Draw.h"
using namespace std;
class User :public Draw {
	string word;
	int score = 0; // 점수 누적시키자
	int num = 0; // 맞춘개수
	string name;
	double tasu = 0.0;
public:
	User() : score(0), num(0), tasu(0.0) {}
	void inputword(vector<string>& v);
	int getScore() const { return score; }
	int getNum() const { return num; }
	string getName() const { return name; }
	double getTasu() { return tasu; }
	void reset();
	void setName(string name) { this->name = name; }
	void saveScoreToLeaderboard();

};
#endif