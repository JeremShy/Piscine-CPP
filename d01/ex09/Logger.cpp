#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Logger.hpp"

flog Logger::tab[2] = {&Logger::logToConsole, &Logger::logToFile};

Logger::Logger(std::string logfile) : _logfile(logfile) {

}

Logger::~Logger(void) {

}

void	Logger::log(std::string const & dest, std::string const & message) {

	std::string name[2] = {"console", "file"};

	int index;
	for (int i = 0; i < 3; i++) {
		if (name[i] == dest)
		{
			(this->*Logger::tab[i])(message);
			return ;
		}
	}
	std::cout << "Error: Logger::log was called with an incorrect dest parameter. (\"" << dest << "\")" << std::endl;
}


void	Logger::logToConsole(std::string const message) const {
	std::cout << Logger::makeLogEntry(message) << " " << message << std::endl;
}


void	Logger::logToFile(std::string const message) const  {
	std::fstream fs(this->_logfile, std::fstream::in | std::fstream::app);
	if (!fs.is_open()) {
		std::cerr << "Error: Error opening " << this->_logfile << " for writing." << std::endl;
		return ;
	}
	fs << Logger::makeLogEntry(message) << " " << message << std::endl;
	fs.close();
}


const std::string	Logger::makeLogEntry(std::string const message){

	time_t t = time(0);
	struct tm *now = localtime(&t);

	std::stringstream ss;
	ss << "[" <<  (now->tm_year + 1900) << std::setw(2) << std::setfill('0')
		<< (now->tm_mon + 1) << std::setw(2) << std::setfill('0') <<  now->tm_mday
		<< "_" << std::setw(2) << std::setfill('0') << now->tm_hour << std::setw(2)
		<< std::setfill('0') << now->tm_min << std::setw(2) << std::setfill('0')
		<< now->tm_sec << "]";

	return ss.str();
}
