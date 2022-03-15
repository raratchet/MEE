#include "MEE_Time.h"
#include <thread>

MEE::TimeManager::TimeManager()
{
	lastFrameElapsedTime = 0.0f;
    m_initialAppTime = std::chrono::duration<double>(0);
    m_timeUsed = std::chrono::duration<double>(0);
    m_frameTime = std::chrono::duration<double>(0);
    m_sleepTime = std::chrono::duration<double>(0);
    m_sleepAdjust = std::chrono::duration<double>(0);
	SetTargetFrameRate(60);
}

unsigned int MEE::TimeManager::GetSecondsSinceApplicationStarted()
{

	return (unsigned int) m_initialAppTime.count(); // Ugly
}

double MEE::TimeManager::GetDeltaTime()
{
	return m_frameTime.count();
}

void MEE::TimeManager::StartFrame()
{
    m_t1 = std::chrono::steady_clock::now();
}

void MEE::TimeManager::EndFrame()
{
	//Based on Box2D TestBed

	m_t2 = std::chrono::steady_clock::now();
    m_timeUsed = m_t2 - m_t1;

    m_sleepTime = m_target - m_timeUsed + m_sleepAdjust;

	if (m_sleepTime > std::chrono::duration<double>(0))
		std::this_thread::sleep_for(m_sleepTime);

    m_t3 = std::chrono::steady_clock::now();

    m_frameTime = m_t3 - m_t1;

    m_sleepAdjust = 0.9 * m_sleepAdjust + 0.1 * (m_target - m_frameTime);
    m_initialAppTime = m_initialAppTime + m_frameTime;
}

void MEE::TimeManager::SetTargetFrameRate(int framerate)
{
	double value = (1.0f / framerate );
    m_target = std::chrono::duration<double>(value);
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
