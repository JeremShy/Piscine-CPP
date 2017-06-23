#include "Logger.hpp"

int	main() {
	Logger logg("pouet");

	logg.log("console", "This is a console log");
	logg.log("file", "This is a file log");
	logg.log("file", "This is another file log");
	logg.log("console", "This is another console log");
	logg.log("pouet", "Incorrect parameter example");

	return (0);
}
