#include "Logger.h"

#include <signal.h>
#include <execinfo.h>

#define PRINT(x)  std::cout << x << std::endl


Logger::Logger()
{

}

void Logger::Log(std::string stg)
{
#ifndef RELEASE
    PRINT(stg);
#endif
    logFile << stg << std::endl;
}

void Logger::CreateLogFile()
{
    logFile.open(LOGFILE,std::ios_base::out);
    if(!logFile.is_open())
    {
        PRINT("Couldn't not create the log file! Exiting!");
        exit(1);
    }
	instanceSignalCallbacks();
}

void Logger::CloseLogFile()
{
    logFile.close();
}

Logger::~Logger()
{

}


void Logger::instanceSignalCallbacks()
{
	signal(SIGSEGV,signalCallbackHandler);
}

void Logger::generateBackTrace(std::vector<char *> &vec)
{

	const int maxbtsize = 64;
	int logsize = 0;
	void *bt[maxbtsize];
	char ** logTrace;
	logsize = backtrace(bt,maxbtsize);
	logTrace = backtrace_symbols(bt,maxbtsize);
	for(int i = 0; i < logsize; ++i)
		vec.push_back(logTrace[i]);

}

void Logger::signalCallbackHandler(int signum)
{
	std::vector<char *> vec;

	PRINT("Signal Number Received: " << signum << " \nClosing");
	generateBackTrace(vec);
	Log("***** BACKTRACE *****");
	for(auto bt : vec)
		Log(bt);
	Log("***** END *****");
	for(auto bt : vec)
		delete bt;
	
	EXIT(signum);
}
