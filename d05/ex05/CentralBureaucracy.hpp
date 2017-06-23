#ifndef CENTRAL_BUREAUCRACY_CLASS_H
# define CENTRAL_BUREAUCRACY_CLASS_H

# include <string>
# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "OfficeBlock.hpp"

class CentralBureaucracy {
public:
	CentralBureaucracy(void);
	CentralBureaucracy(CentralBureaucracy const & src);
	~CentralBureaucracy(void);

	CentralBureaucracy & operator=(CentralBureaucracy const & rhs);

	void				feed(Bureaucrat*);
	void				queueUp(std::string name);
	void 				doBureaucracy(void) const;

private:
	OfficeBlock	_blocks[20];
	std::string	*_queue;
};
std::ostream& operator<<(std::ostream& os, const CentralBureaucracy & rhs);
#endif
