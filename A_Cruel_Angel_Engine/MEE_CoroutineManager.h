#pragma once
#include "MEE_Couroutine.h"
#include <list>
#include <memory>
#include "MEE_Exports.h"

namespace MEE
{
	class MEE_EXPORT CoroutineManager
	{
	public:
		template<class T = WaitCondition>
		void SetCurrentResumableWaitCondition(T* condition);
		void CallResumableFunction(ResumableFunction* function);
		void Update();
	private:
		ResumableFunction* currentResumable;
		std::list<ResumableFunction*> activeResumables; // im using raw pointers because i was having a strange error, should change it later
	};

	template<class T>
	void CoroutineManager::SetCurrentResumableWaitCondition(T* condition)
	{
		if (condition && currentResumable)
		{
			currentResumable->waitCondition.reset();
			currentResumable->waitCondition = std::shared_ptr<T>(condition);
		}
	}
}


