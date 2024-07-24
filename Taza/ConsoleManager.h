#ifndef CONSOLEMANAGER_H
#define CONSOLEMANAGER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include "User.h"
#include "Draw.h"
using namespace std;
class ConsoleM :public Draw {
private:
	vector<string> v;
	vector<string> v2;
	int com = 0;
	int comN = 0;
	User& user;
	bool running = false;
	thread inputThread;
	bool flag = true;
public:
	ConsoleM(User& u) : user(u) {}
	void fileRead(ifstream& fin);
	void gameLoop(int duraion);
	void inputLoop();
	void game();
	void run(int level, int duration);
	void random();
	void start();
	void deleteW(int duration);
};
#endif