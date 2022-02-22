#include "MEG_Game.h"
#include "MainMenu.h"

int main(int argc, char* args[])
{
	if (auto game = Game::CreateGame())
	{
		game->AddLevel(new MainMenu);
		game->Start();
	}
}