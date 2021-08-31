#pragma once
#include <experimental/coroutine>
#include <cassert>
#include "MEE_Exports.h"

namespace MEE
{

	class MEE_EXPORT WaitCondition
	{
	public:
		virtual bool Evaluate() = 0;
		virtual ~WaitCondition() = default;
	};

	class MEE_EXPORT WaitForFrames : public WaitCondition
	{
	public:
		WaitForFrames(int framesToWait);
		virtual bool Evaluate();
		virtual ~WaitForFrames() = default;
	private:
		int frameWait;
		int waitedFrames = 0;
	};

	class MEE_EXPORT WaitForSeconds : public WaitCondition
	{
	public:
		WaitForSeconds(double secondsToWait);
		virtual bool Evaluate();
		virtual ~WaitForSeconds() = default;
	private:
		double secondsWait;
		double initialTime;
	};

	class MEE_EXPORT WaitUntil : public WaitCondition
	{

	};

	class MEE_EXPORT ResumableFunction
	{
	public:

		struct promise_type
		{
			using CoroutineHandler = std::experimental::coroutine_handle<promise_type>;

			auto get_return_object()
			{
				return CoroutineHandler::from_promise(*this);
			}

			auto initial_suspend() { return std::experimental::suspend_always(); }
			auto final_suspend() { return std::experimental::suspend_never(); }
			void return_void() {}

			void unhandled_exception()
			{
				std::terminate();
			}
		};

		using CoroutineHandler = std::experimental::coroutine_handle<promise_type>;

		ResumableFunction(CoroutineHandler handle);
		ResumableFunction(ResumableFunction&) = delete;
		ResumableFunction(ResumableFunction&&) = delete;

		bool Resume();

		~ResumableFunction();

	private:
		CoroutineHandler handler;
		std::shared_ptr<WaitCondition> waitCondition;
		friend class CoroutineManager;
	};

}

