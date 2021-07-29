#include "MEE_Time.h"

MEE::TimeManager::TimeManager()
{
	initialAppTime = std::chrono::system_clock::now();
}

unsigned int MEE::TimeManager::GetSecondsSinceApplicationStarted()
{
	return 0;
}

float MEE::TimeManager::GetDeltaTime()
{
	return lastFrameElapsedTime;
}

void MEE::TimeManager::StartFrame()
{
	frameTimer = Timer();
}

void MEE::TimeManager::EndFrame()
{
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
