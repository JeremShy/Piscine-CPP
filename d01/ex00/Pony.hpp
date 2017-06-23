#ifndef PONY_CLASS_H
# define PONY_CLASS_H

# include <string>

class Pony {
public:
	Pony(void);
	Pony(std::string name);
	~Pony(void);

	void walk(int distance);
	void talk(std::string str);

private:
	std::string   _name;
	unsigned long _mane_color;
	unsigned long _fur_color;
	bool			 	  _winged;
	bool					_unicorn;
};

#endif
