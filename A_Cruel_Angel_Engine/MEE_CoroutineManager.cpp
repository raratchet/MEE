#include "MEE_CoroutineManager.h"


void MEE::CoroutineManager::CallResumableFunction(ResumableFunction* function)
{

	activeResumables.push_back(function); // Debo evaluar si las llamadas las inicio desde aquí
}

void MEE::CoroutineManager::Update()
{
	std::list<ResumableFunction*> concludedResumables;

	for (auto resFunc : activeResumables)
	{
		if (resFunc->waitCondition)
		{
			if (resFunc->waitCondition->Evaluate())
			{
				assert(resFunc->handler);
				currentResumable = resFunc;
				resFunc->Resume();
				if (resFunc->handler.done())
					concludedResumables.push_back(resFunc);
			}
		}
		else
		{
			currentResumable = resFunc;
			resFunc->Resume();
			if (resFunc->handler.done())
				concludedResumables.push_back(resFunc);
		}

	}

	for (auto concludedRes : concludedResumables)
	{
		activeResumables.remove(concludedRes);
		delete concludedRes;
	}

	concludedResumables.clear();
	currentResumable = nullptr;
}
