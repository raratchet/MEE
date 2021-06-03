#include<MEE_Global.h>
#include "TestLevel.h"
#include <iostream>

using namespace MEE_GLOBAL;
using MEE::Application;

int main(int argc, char* args[])
{
	application = new Application;
	if (application->Init())
	{
		application->Load();
		application->GetSceneManager().lock()->AddScene(new TestLevel);
		application->Loop();
	}
	application->Stop();
	delete application;
}