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

	/**
	 * Manages all time reated stuff in the engine.
	 */
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
		std::chrono::steady_clock::time_point m_t1,m_t2,m_t3;
		std::chrono::duration<double> m_initialAppTime;
		std::chrono::duration<double> m_timeUsed;
		std::chrono::duration<double> m_frameTime;
		std::chrono::duration<double> m_sleepTime;
		std::chrono::duration<double> m_sleepAdjust;
		std::chrono::duration<double> m_target;
	};
}


