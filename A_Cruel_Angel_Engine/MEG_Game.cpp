#include "MEG_Game.h"
#include "MEE_Global.h"

MEE::Application* mainApp; //Esto no deberia ser asi

Game::Game()
{

}

MEE::Application* Game::GetMainApp()
{
	return mainApp;
}

std::shared_ptr<Game> Game::CreateGame()
{
	std::shared_ptr<Game> game(new Game);

	//DO POINTER THINGY
	mainApp = new MEE::Application;
	MEE_GLOBAL::application = mainApp; //THIS CAN BE FIXED
	  
	bool gameInit = game->Init();
	//Assert gameInit

	return game;
}

void Game::LoadLevel(Level* level)
{
	AddLevel(level);
}

void Game::AddLevel(Level* level)
{
	auto scenes = mainApp->GetSceneManager().lock();
	if (scenes)
	{
		scenes->AddScene(level);
	}
}

void Game::RemoveCurrentLevel()
{
}

void Game::LoadAsset(std::string name, std::string path)
{
	//Assetr resourcemanager
	auto resourceManager = mainApp->GetResourceManager().lock();

	std::string suffix = GetFileSuffix(path);

	if (suffix == "jpg")
	{
		resourceManager->LoadTexture2D(name, path);
	}
	//las demas opciones
}

bool Game::AssetExists(std::string name)
{
	return false;
}

void Game::UnloadAsset(std::string name)
{
}

void Game::UnloadAllAssets()
{
}

void Game::RenameWindow(std::string name)
{
}

void Game::ResizeWindow(int width, int height)
{
}

void Game::SetWindowFullscren(bool status)
{
}


bool Game::Init()
{
	bool success = true;

	success = mainApp->Init();
	if (success)
	{
		mainApp->Load();
	}

	return success;
}

void Game::Start()
{
	mainApp->Loop();
	mainApp->Stop();
}

void Game::Stop()
{
}

void Game::StopGame()
{
}

std::string Game::GetFileSuffix(const std::string& fileName)
{
	auto dot = fileName.find_last_of('.') + 1;
	std::string fileSuffix = fileName.substr(dot);

	return fileSuffix;
}
