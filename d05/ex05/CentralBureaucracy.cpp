#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void) {
	for (int i = 0; i < 20; i++) {
		this->_blocks[i].setIntern(new Intern());
	}
	_queue = new std::string[1];
	_queue[0] = ""; //TODO Verifier qu'on ajoute pas cette valeur quand on essaie.
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & src) : _queue(src._queue){
	for (int i = 0; i < 20; i++) {
		this->_blocks[i].setIntern(new Intern());
		this->_blocks[i].setSigner(src._blocks[i].getSigner());
		this->_blocks[i].setExecutor(src._blocks[i].getExecutor());
	}
}

CentralBureaucracy::~CentralBureaucracy(void) {
	for (int i = 0; i < 20; i++) {
		delete this->_blocks[i].getIntern();
	}
	delete [] this->_queue;
}

CentralBureaucracy & CentralBureaucracy::operator=(CentralBureaucracy const & rhs) {
	int i;

	for (int i = 0; i < 20; i++) {
		delete this->_blocks[i].getIntern();
	}
	delete [] this->_queue;

	i = 0;
	while (rhs._queue[i] != "") {
		i++;
	}
	_queue = new std::string[i + 1];
	i = 0;
	while (rhs._queue[i] != "") {
		_queue[i] = rhs._queue[i];
		i++;
	}
	_queue[i] = "";
	for (int i = 0; i < 20; i++) {
		this->_blocks[i].setIntern(new Intern());
		this->_blocks[i].setSigner(rhs._blocks[i].getSigner());
		this->_blocks[i].setExecutor(rhs._blocks[i].getExecutor());
	}
	return (*this);
}

void	CentralBureaucracy::queueUp(std::string name) {
	int i;
	if (name == "") {
		std::cout << "You can't add somebody with this name !" << std::endl;
		return ;
	}

	i = 0;
	while (_queue[i] != "") {
		i++;
	}
	std::string *nq = new std::string [i + 2];
	i = 0;
	while (_queue[i] != "") {
		nq[i] = _queue[i];
		i++;
	}
	nq[i] = name;
	nq[i + 1] = "";
	delete [] _queue;
	_queue = nq;
}

void	CentralBureaucracy::feed(Bureaucrat *b) {
	for (int i = 0; i < 20; i++) {
		if (_blocks[i].getSigner() == NULL) {
			_blocks[i].setSigner(b);
			return ;
		}
		if (_blocks[i].getExecutor() == NULL) {
			_blocks[i].setExecutor(b);
			return ;
		}
	}
}

void CentralBureaucracy::doBureaucracy() const {
	int i = 0;
	std::string s[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	while (_queue[i] != "") {
		try {
			_blocks[i % 20].doBureaucracy(s[rand() % 3], _queue[i]);
		} catch (OfficeBlock::CreationException & e) {
			std::cout << "There was an error while creating the form" << std::endl;
		} catch (OfficeBlock::SigningException & e) {
			std::cout << "There was an error while signing the form" << std::endl;
		} catch (OfficeBlock::ExecutingException & e) {
			std::cout << "There was an error while executing the form" << std::endl;
		}
		std::cout << "----------------------------------------------------------" << std::endl << std::endl;
		i++;
	}
}
