#include <iostream>
#include <memory>
#include "MEE_Global.h"

using namespace MEE_GLOBAL;
using MEE::Application;

int main(int argc, char* args[])
{
	application = new Application;
	if (application->Init())
	{
		application->Load();
		application->Loop();
	}
	application->Stop();
	delete application;
}