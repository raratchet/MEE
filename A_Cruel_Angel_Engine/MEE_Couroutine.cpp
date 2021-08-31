#include "MEE_Couroutine.h"
#include "MEE_Global.h"	

MEE::ResumableFunction::ResumableFunction(CoroutineHandler handle) : handler(handle)
{
	assert(handler);
}

bool MEE::ResumableFunction::Resume()
{
	if (!handler.done())
	{
		handler.resume();
	}

	return !handler.done();
}

MEE::ResumableFunction::~ResumableFunction()
{
    handler.destroy();
}

MEE::WaitForFrames::WaitForFrames(int framesToWait): frameWait(framesToWait)
{
}

bool MEE::WaitForFrames::Evaluate()
{
	if (waitedFrames >= frameWait)
	{
		return true;
	}
	else
	{
		waitedFrames++;
		return false;
	}
}

MEE::WaitForSeconds::WaitForSeconds(double secondsToWait): secondsWait(secondsToWait)
{
	auto time = MEE_GLOBAL::application->GetTimeManager().lock();
	initialTime = time->GetSecondsSinceApplicationStarted(); // I need a double one
}

bool MEE::WaitForSeconds::Evaluate()
{
	auto time = MEE_GLOBAL::application->GetTimeManager().lock();
	auto currentTime = time->GetSecondsSinceApplicationStarted();

	if ((currentTime - initialTime) >= secondsWait)
	{
		return true;
	}
	else
	{
		return false;
	}
}

