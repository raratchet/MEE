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
		double GetDeltaTime();
		void StartFrame();
		void EndFrame();
		void SetTargetFrameRate(int framerate);
	private:
		float lastFrameElapsedTime;
		std::chrono::steady_clock::time_point t1,t2,t3;
		std::chrono::duration<double> initialAppTime;
		std::chrono::duration<double> timeUsed;
		std::chrono::duration<double> frameTime;
		std::chrono::duration<double> sleepTime;
		std::chrono::duration<double> sleepAdjust;
		std::chrono::duration<double> target;
	};
}


