#include "TestLevel.h"
#include "MEE_Global.h"
#include "TestBehaviour.h"
#include "MEE_Sprite.h"
#include "MEE_Object.h"



using MEE::ResourceManager;
using MEE::GameObject;
using MEE::Texture2D;
using MEE::Sprite;


void TestLevel::load()
{
	auto resourceM = MEE_GLOBAL::application->getResourceManager().lock();
	resourceM->loadTexture2D("Regu", "C:/Users/rarat/Pictures/regu.jpg");
	Sprite testS = Sprite("Regu", 0, 0, 2000, 2000);
	GameObject& regu = createGameObject("REGU",testS);
	regu.addComponent<TestBehaviour>();
}

void TestLevel::unload()
{
}
