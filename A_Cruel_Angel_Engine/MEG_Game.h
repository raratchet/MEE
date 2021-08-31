#pragma once
#include <memory>
#include <iostream>
#include "MEG_Exports.h"
#include "MEG_Aliases.h"

#include "MEE_Couroutine.h" //Move to other place

class MEG_EXPORT Game
{
public:
	static std::shared_ptr<Game> CreateGame();
	bool Init();
	void Start();
	void Stop();
	static void StopGame();
	//Scene Manager Related Stuff
	void LoadLevel(Level* level);
	static void AddLevel(Level* level);
	static void RemoveCurrentLevel();
	//ResourceManager Related Stuff
	static AssetID LoadAsset(std::string name, std::string path); //Determinaré el tipo segun la extension
	static bool AssetExists(std::string name);
	static void UnloadAsset(std::string name);
	static void UnloadAllAssets();
	//Load assets from file

	//Window related stuff
	static void RenameWindow(std::string name);
	static void ResizeWindow(int width,int height);
	static void SetWindowFullscren(bool status);

	static double GetDeltaTime();


#define WaitForSeconds(x) MEE::WaitForSeconds* wait = new MEE::WaitForSeconds(x);\
						  Game::SetCurrentResumableFunctionCondition(wait);\
						  co_await std::experimental::suspend_always();

#define WaitForFrames(x) MEE::WaitForFrames* wait = new MEE::WaitForFrames(x);\
						  Game::SetCurrentResumableFunctionCondition(wait);\
						  co_await std::experimental::suspend_always();


	static void InitResumableFunction(MEE::ResumableFunction* function);

	//Input and Plugin will be in independent files
	template <class T = MEE::WaitCondition>
	static void SetCurrentResumableFunctionCondition(T* waitCondition);
private:
	std::string name;
	
	Game();
	static MEE::Application* GetMainApp();
	static std::string GetFileSuffix(const std::string& fileName);



	friend class Input;
};

template<class T>
void Game::SetCurrentResumableFunctionCondition(T* waitCondition)
{
	auto coManager = GetMainApp()->GetCoroutines().lock();

	coManager->SetCurrentResumableWaitCondition(waitCondition); // Check if this is a memory leak
}


