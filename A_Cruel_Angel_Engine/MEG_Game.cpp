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
	if (scenes) //Should be assert
	{
		scenes->AddScene(level);
	}
}

void Game::RemoveCurrentLevel()
{
	auto scenes = mainApp->GetSceneManager().lock();

	if (scenes)
	{
		scenes->QuitScene();
	}
}

AssetID Game::LoadAsset(std::string name, std::string path)
{
	//Assetr resourcemanager
	auto resourceManager = mainApp->GetResourceManager().lock();

	std::string suffix = GetFileSuffix(path);

	if (suffix == "jpg")
	{
		return resourceManager->LoadTexture2D(name, path);
	}
	else if (suffix == "png")
	{
		return resourceManager->LoadTexture2D(name, path);
	}
	//las demas opciones

	return 0;
}

bool Game::AssetExists(std::string name)
{
	return false;
}

void Game::UnloadAsset(std::string name)
{
	auto resourceManager = mainApp->GetResourceManager().lock();

	resourceManager->Unload(name);
}

void Game::UnloadAllAssets()
{
	auto resourceManager = mainApp->GetResourceManager().lock();

	resourceManager->Clear();
}

void Game::RenameWindow(std::string name)
{
	auto window = mainApp->GetWindow().lock();

	window->SetWindowName(name);
}

void Game::ResizeWindow(int width, int height)
{
	auto window = mainApp->GetWindow().lock();

	window->SetWindowSize(width, height);
}

void Game::SetWindowFullscren(bool status)
{
	auto window = mainApp->GetWindow().lock();

	window->SetFullscreenMode(status);
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
	mainApp->Stop();
}

void Game::StopGame()
{
	mainApp->Stop();
}

std::string Game::GetFileSuffix(const std::string& fileName)
{
	auto dot = fileName.find_last_of('.') + 1;
	std::string fileSuffix = fileName.substr(dot);

	return fileSuffix;
}
