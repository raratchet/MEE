#include "MEE_Logging.h"
#include <easylogging++.h>

static el::Logger* currentLogger;

void MEE_LOGGER::Log(const char* message)
{
	currentLogger->info(message);
}

void MEE_LOGGER::Warn(const char* message)
{
	currentLogger->warn(message);
}

void MEE_LOGGER::Error(const char* message)
{
	currentLogger->error(message);
}

void MEE_LOGGER::Fatal(const char* message)
{
	currentLogger->fatal(message);
}

void MEE_LOGGER::Print(const char* message)
{
	currentLogger->info(message);
}


INITIALIZE_EASYLOGGINGPP

void MEE_LOGGER::InitLogging()
{
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	// To set GLOBAL configurations you may use
	defaultConf.setGlobally(
		el::ConfigurationType::Format, "[MEE] %datetime -%level- %msg");
	el::Loggers::reconfigureLogger("default", defaultConf);
	
	currentLogger = el::Loggers::getLogger("default");

}

void MEE_LOGGER::CreateLogger(const std::string& logger, const std::string& format)
{
	el::Logger* el_logger = el::Loggers::getLogger(logger);

	el::Configurations defaultConf;
	defaultConf.setToDefault();
	defaultConf.setGlobally(
		el::ConfigurationType::Format, "[" + logger + "] " + format);
	el::Loggers::reconfigureLogger(el_logger, defaultConf);
}

void MEE_LOGGER::FlushLog()
{
	el::Loggers::flushAll();
}

MEE_LOGGER::ScopedLogging::ScopedLogging(const char* logger)
{
	currentLogger = el::Loggers::getLogger(logger, false);

	if (!currentLogger)
	{
		currentLogger = el::Loggers::getLogger("default");
		std::string message(logger);
		message += " - Not such logger exists.";
		currentLogger->error(message);
	}
}

MEE_LOGGER::ScopedLogging::~ScopedLogging()
{
	currentLogger = el::Loggers::getLogger("default", false);
}
