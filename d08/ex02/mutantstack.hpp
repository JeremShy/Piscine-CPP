#ifndef MUTANT_STACK_CLASS_H
# define MUTANT_STACK_CLASS_H

# include <string>
# include <iostream>
# include <algorithm>
# include <iterator>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack(void) {
		std::stack<T>();
	}

	MutantStack(MutantStack const & src) : std::stack<T>(src) {
	}

	~MutantStack(void) {

	}

	MutantStack & operator=(MutantStack const & rhs) {
		std::stack<T>::operator=(rhs);
		return (*this);
	}

	class iterator {
	public:
		iterator(void) {
			_ptr = NULL;
		}

		iterator(iterator const & src) {
			_ptr = src._ptr;
		}

		~iterator(void) {
		}

		iterator & operator=(iterator const & rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}

		T & operator*()
		{
			return *(static_cast<T *>(_ptr));
		}

		iterator & operator++()
		{
			_ptr = static_cast<T*>(_ptr) + 1;
			return (*this);
		}

		iterator operator++(int)
		{
			iterator tmp(*this);
			operator++();
			return (tmp);
		}

		iterator & operator--()
		{
			_ptr = static_cast<T*>(_ptr) - 1;
			return (*this);
		}

		iterator operator--(int)
		{
			iterator tmp(*this);
			operator--();
			return (tmp);
		}

		bool operator==(const iterator & rhs) {
			return (this->_ptr == rhs._ptr);
		}

		bool operator!=(const iterator & rhs) {
			return (this->_ptr != rhs._ptr);
		}

		T const * operator->() const{
			return _ptr;
		}

		void	setPtr(void *ptr) {
			_ptr = ptr;
		}
	private:
		void	*_ptr;
	};

	MutantStack<T>::iterator begin(void) {
		if (this->size() == 0)
			return (MutantStack<T>::iterator());

		MutantStack<T>::iterator ret;
		ret.setPtr(static_cast<T *>(&this->top()) - (this->size() - 1));
		return ret;
	}

	MutantStack<T>::iterator end(void) {
		if (this->size() == 0)
			return (MutantStack<T>::iterator());

		MutantStack<T>::iterator ret;
		ret.setPtr(static_cast<T*>(&this->top()) + 1);
		return ret;
	}

private:
};



// std::ostream& operator<<(std::ostream& os, const MutantStack & rhs);
#endif
