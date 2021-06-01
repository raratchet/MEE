#include<MEE_Global.h>
#include "TestLevel.h"
#include <iostream>

using namespace MEE_GLOBAL;
using MEE::Application;

int main(int argc, char* args[])
{
	application = new Application;
	if (application->init())
	{
		application->load();
		application->getSceneManager().lock()->addScene(new TestLevel);
		application->loop();
	}
	application->stop();
	delete application;
}