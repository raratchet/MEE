#pragma once
#include <MEG_Aliases.h>
#include <MEG_Game.h>

class WinScreen : public Level
{
protected:
	Sprite* winnerImage = nullptr;
	Sprite* winBanner = nullptr;
public:
	WinScreen()
	{
		Game::LoadAsset("winBanner", "./winBanner.png");
		winBanner = new Sprite("winBanner");
	}
	void Load() override 
	{
		GameObject& banner = CreateGameObject("banner", *winBanner);
		banner.GetTransformComponent().SetPosition(20, 20);
	};
	void Unload() override {};
};

class Lancer_WinScreen : public WinScreen
{

public:
	Lancer_WinScreen() : WinScreen()
	{
		Game::LoadAsset("LancerWin", "./Lancer-Hero/HD/Hero/acquire/acquire01.png");
		winnerImage = new Sprite("LancerWin");
	}

	void Load() override 
	{
		GameObject& winner = CreateGameObject("LancerWin", *winnerImage);
		winner.GetTransformComponent().SetPosition(20, 15);
		WinScreen::Load();
	};
	void Unload() override
	{

	};
};

class Toxic_WinScreen : public WinScreen
{
public:
	Toxic_WinScreen() : WinScreen()
	{
		Game::LoadAsset("ToxicWin", "./ToxicSword/HD/Hero/acquire/acquire01.png");
		winnerImage = new Sprite("ToxicWin");
	}

	void Load() override
	{
		GameObject& winner = CreateGameObject("ToxicWin", *winnerImage);
		winner.GetTransformComponent().SetPosition(20, 15);
		WinScreen::Load();
	};

	void Unload() override
	{

	};
};
class Samurai_WinScreen : public WinScreen
{
public:
	Samurai_WinScreen() : WinScreen()
	{
		Game::LoadAsset("SamuraiWin", "./Samurai-Hero/HD/Hero/acquire/acquire01.png");
		winnerImage = new Sprite("SamuraiWin");
	}

	void Load() override
	{
		GameObject& winner = CreateGameObject("SamuraiWin", *winnerImage);
		winner.GetTransformComponent().SetPosition(20, 15);
		WinScreen::Load();
	};

	void Unload() override
	{

	};
};
class Cowboy_WinScreen : public WinScreen
{
public:
	Cowboy_WinScreen() : WinScreen()
	{
		Game::LoadAsset("CoyboyWin", "./Cowboy/HD/Hero/acquire/acquire01.png");
		winnerImage = new Sprite("CoyboyWin");
	}

	void Load() override
	{
		GameObject& winner = CreateGameObject("CoyboyWin", *winnerImage);
		winner.GetTransformComponent().SetPosition(20, 15);
		WinScreen::Load();
	};

	void Unload() override
	{

	};
};
