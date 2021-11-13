#pragma once
#include <memory>
#include <iostream>
#include "MEG_Exports.h"
#include "MEG_Aliases.h"

/**
 * Game is a fachade class that simplifies the use of MEE.
 */
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
	static AssetID LoadAsset(const char* name, const char* path); //Determinaré el tipo segun la extension
	static bool AssetExists(const char* name);
	static void UnloadAsset(const char* name);
	static void UnloadAllAssets();
	//Load assets from file

	//Window related stuff
	static void RenameWindow(const char* name);
	static void ResizeWindow(int width,int height);
	static void SetWindowFullscren(bool status);

	static double GetDeltaTime();

	//Input and Plugin will be in independent files

private:
	const char* name;
	
	Game();
	static MEE::Application* GetMainApp();
	static std::string GetFileSuffix(const std::string& fileName);

	friend class Input;
};


