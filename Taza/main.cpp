#include <iostream>
#include "ConsoleManager.h"
#include "User.h"
#include "Game.h"
using namespace std;
int main() {
	system("mode con cols=100 lines=40 | title �ڿ�ĳ��Ÿ�ڰ���");
	Game game;
	game.start();

}