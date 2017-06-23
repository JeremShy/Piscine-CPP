#ifndef ENEMY_CLASS_H
# define ENEMY_CLASS_H


#include <iostream>
#include <string>

class Enemy
{
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual ~Enemy();
		Enemy & operator=(Enemy const & rhs);

		std::string const getType() const;
		int 								getHP() const;

		virtual void takeDamage(int);

	protected:
		Enemy(void);

	private:
		int _hp;
		std::string _type;
};

#endif
