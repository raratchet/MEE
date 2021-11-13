/*****************************************************************//**
 * \file   MEE_Logging.h
 * \brief  Contains all logging related functions
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include "MEE_Exports.h"
#include <string>

/**
 * This namespace is a fachade for easylogging.
 */
namespace MEE_LOGGER
{
	void MEE_EXPORT Log(const char* message);
	void MEE_EXPORT Warn(const char* message);
	void MEE_EXPORT Error(const char* message);
	void MEE_EXPORT Fatal(const char* message);
	void MEE_EXPORT Print(const char* message);

	struct MEE_EXPORT ScopedLogging
	{
		ScopedLogging(const char* logger);
		~ScopedLogging();
	};

#ifdef MEE_ENGINE
	void InitLogging();
	void CreateLogger(const std::string& logger, const std::string& format = "%datetime - %level - %msg");
	void FlushLog();
#endif // MEE_ENGINE
}
