#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Engine.h"

#define LOGFILE "output.txt"
#define EXIT() Engine::DisposeSystems()
#define LOG(x) Logger::Log(x)
#define TOSTR(x) std::to_string(x)
#define ERROR(x) std::cerr << x << std::endl
#define PRINT(x)  std::cout << x << std::endl

namespace ox
{
static std::ofstream logFile;

class Logger
{
private:
    Logger();
    ~Logger();
	void static signalCallbackHandler(int signum);
	void static instanceSignalCallbacks();
	void static generateBackTrace(std::vector<char *> &vec);
public:
    static void Log(std::string stg);
    static void CreateLogFile();
    static void CloseLogFile();
};
}
#endif // LOGGER_H
