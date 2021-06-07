#pragma once
#include <memory>
#include <iostream>
#include "MEG_Exports.h"
#include "MEG_Aliases.h"

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
	static void LoadAsset(std::string name, std::string path); //Determinaré el tipo segun la extension
	static bool AssetExists(std::string name);
	static void UnloadAsset(std::string name);
	static void UnloadAllAssets();
	//Load assets from file

	//Window related stuff
	static void RenameWindow(std::string name);
	static void ResizeWindow(int width,int height);
	static void SetWindowFullscren(bool status);

	//Input and Plugin will be in independent files

private:
	Game();
	std::string name;
	static std::string GetFileSuffix(const std::string& fileName);
};


