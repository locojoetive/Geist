#include "Log.h"

void Log::SetLogLevel(enum LogLevel logLevel) {
	this->logLevel = logLevel;
};
void Log::Warn() {};
void Log::Print() {};
void Log::Error() {};