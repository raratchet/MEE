#include "TestLevel.h"
#include "MEG_Game.h"


int main(int argc, char* args[])
{
	auto wasd = LoadLibraryW(L"Mod_Ed_Engine.dll"); ///////SUUUUUUUPER TEMPORAL SE NECESITAN MACROS
	auto game = Game::CreateGame();
	game->AddLevel(new TestLevel);
	game->Start();
}