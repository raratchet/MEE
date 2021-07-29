#pragma once
#include <chrono>

using namespace std::literals;

namespace MEE
{
	//Based on Hazel Engine
	class Timer
	{
	public:
		Timer();
		void Reset();
		float Elapsed();
		float ElapsedMillis();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};

	class Timestep
	{
	public:
		Timestep(float time = 0.0f);
		operator float() const;
		float GetSeconds() const;
		float GetMilliseconds() const;
	private:
		float m_Time;
	};

	class TimeManager
	{
	public:
		TimeManager();
		unsigned int GetSecondsSinceApplicationStarted();
		float GetDeltaTime();
		void StartFrame();
		void EndFrame();
	private:
		Timer frameTimer;
		float lastFrameElapsedTime;
		std::chrono::time_point<std::chrono::system_clock> initialAppTime;
	};
}


