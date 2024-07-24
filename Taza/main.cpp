#include <iostream>
#include "ConsoleManager.h"
#include "User.h"
#include "Game.h"
using namespace std;
int main() {
	system("mode con cols=100 lines=40 | title 자원캐기타자게임");
	Game game;
	game.start();

}