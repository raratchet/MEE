#include "TestLevel.h"
#include "MEG_Game.h"


int main(int argc, char* args[])
{
	auto game = Game::CreateGame();
	game->AddLevel(new TestLevel);
	game->Start();
}