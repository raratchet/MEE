#include "TestLevel.h"
#include "MEG_Game.h"
#include "MainMenu.h"


int main(int argc, char* args[])
{
	auto game = Game::CreateGame();
	game->AddLevel(new MainMenu);
	game->Start();
}