#include "TestLevel.h"
#include "MEE_Global.h"
#include "TestBehaviour.h"
#include "MEE_Sprite.h"
#include "MEE_Object.h"



using MEE::ResourceManager;
using MEE::GameObject;
using MEE::Texture2D;
using MEE::Sprite;


void TestLevel::Load()
{
	auto resourceM = MEE_GLOBAL::application->GetResourceManager().lock();
	resourceM->loadTexture2D("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Sprite testS = Sprite("Regu", 0, 0, 2000, 2000);
	GameObject& regu = CreateGameObject("REGU",testS);
	regu.AddComponent<TestBehaviour>();
}

void TestLevel::Unload()
{
}
