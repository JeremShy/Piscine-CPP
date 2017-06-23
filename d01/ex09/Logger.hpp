#ifndef LOGGER_CLASS_H
# define LOGGER_CLASS_H

# include <string>

class Logger {

public:
	Logger(std::string logfile);
	~Logger(void);

	void	log(std::string const & dest, std::string const & message);

	static void (Logger::*tab[2]) (std::string const) const;

private:
	void											logToFile(std::string const message) const ;
	void											logToConsole(std::string const message) const;
	static const std::string	makeLogEntry(std::string const message);

	std::string	_logfile;
};

typedef void (Logger::*flog) (std::string const ) const;


#endif
