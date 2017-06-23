#ifndef HUMAN_CLASS_H
# define HUMAN_CLASS_H

# include <string>

class Human {

public:
	Human();
	~Human(void);

	void	action(std::string const & action_name, std::string const & target);

	static void (Human::*tab[3]) (std::string const &);


private:
	void	meleeAttack(std::string const & target);
	void	rangedAttack(std::string const & target);
	void	intimidatingShout(std::string const & target);
};
typedef void (Human::*fhuman) (std::string const &);
#endif
