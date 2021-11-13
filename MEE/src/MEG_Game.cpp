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

	mainApp = new MEE::Application;
	  
	bool gameInit = game->Init();
	
	if (!gameInit)
		return nullptr;

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

AssetID Game::LoadAsset(const char* name, const char* path)
{
	//Assetr resourcemanager
	auto resourceManager = mainApp->GetResourceManager().lock();

	std::string suffix = GetFileSuffix(std::string(path));

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

bool Game::AssetExists(const char* name)
{
	return false;
}

void Game::UnloadAsset(const char* name)
{
	auto resourceManager = mainApp->GetResourceManager().lock();

	resourceManager->Unload(name);
}

void Game::UnloadAllAssets()
{
	auto resourceManager = mainApp->GetResourceManager().lock();

	resourceManager->Clear();
}

void Game::RenameWindow(const char* name)
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

double Game::GetDeltaTime()
{
	auto tm = mainApp->GetTimeManager().lock();
	return tm->GetDeltaTime();
}


bool Game::Init()
{
	bool success = true;

	success = mainApp->Init();
	if (success)
	{
		mainApp->Load();
	}
	else
	{
		std::cout << "[MEG] Game couldn't initialize. Aborting!" << std::endl;
		mainApp->Stop();
		delete mainApp;
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
