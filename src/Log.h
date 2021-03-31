#pragma once

enum LogLevel {
	DEBUG,
	WARNING,
	ERROR
};

class Log 
{
public:
	LogLevel logLevel = DEBUG;
	void SetLogLevel(LogLevel logLevel);
	void Warn();
	void Print();
	void Error();

};