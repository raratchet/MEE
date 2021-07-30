#include "MEE_Time.h"
#include <thread>

MEE::TimeManager::TimeManager()
{
	lastFrameElapsedTime = 0.0f;
	initialAppTime = std::chrono::duration<double>(0);
	timeUsed = std::chrono::duration<double>(0);
	frameTime = std::chrono::duration<double>(0);
	sleepTime = std::chrono::duration<double>(0);
	sleepAdjust = std::chrono::duration<double>(0);
	target = std::chrono::duration<double>(1 / 60);
}

unsigned int MEE::TimeManager::GetSecondsSinceApplicationStarted()
{

	return (unsigned int) initialAppTime.count(); // Ugly
}

double MEE::TimeManager::GetDeltaTime()
{
	return frameTime.count();
}

void MEE::TimeManager::StartFrame()
{
	t1 = std::chrono::steady_clock::now();
}

void MEE::TimeManager::EndFrame()
{
	//Based on Box2D TestBed

	t2 = std::chrono::steady_clock::now();
	timeUsed = t2 - t1;

	sleepTime = target - timeUsed + sleepAdjust;

	if (sleepTime > std::chrono::duration<double>(0))
		std::this_thread::sleep_for(sleepTime);

	t3 = std::chrono::steady_clock::now();

	frameTime = t3 - t1;

	sleepAdjust = 0.9 * sleepAdjust + 0.1 * (target - frameTime);
	initialAppTime = initialAppTime + frameTime;
}

MEE::Timer::Timer()
{
	Reset();
}
void MEE::Timer::Reset()
{
	m_Start = std::chrono::high_resolution_clock::now();
}
float MEE::Timer::Elapsed()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
}
float MEE::Timer::ElapsedMillis()
{
	return Elapsed() * 1000.0f;
}

MEE::Timestep::Timestep(float time): m_Time(time)
{
}

MEE::Timestep::operator float() const 
{ 
	return m_Time; 
}

float MEE::Timestep::GetSeconds() const 
{ 
	return m_Time; 
}

float MEE::Timestep::GetMilliseconds() const 
{ 
	return m_Time * 1000.0f; 
}
