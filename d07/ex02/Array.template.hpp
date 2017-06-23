#ifndef ARRAY_TEMPLATE_CLASS_H
# define ARRAY_TEMPLATE_CLASS_H

# include <string>
# include <iostream>

template <typename T>
class Array {
public:
	Array(void);
	Array(unsigned int n);
	Array(Array const & src);
	~Array(void);

	Array & operator=(Array const & rhs);

	T & operator[](unsigned int id) const;

	unsigned int size(void) const;

private:
	T				*_array;
	size_t	_size;
};

template <typename T>
Array<T>::Array(void) {
	this->_array = new T [0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int i) {
	this->_array = new T [i];
	this->_size = i;
}

template <typename T>
Array<T>::Array(Array const & src) {
	this->_size = src.size();
	this->_array = new T [this->_size];
	for (unsigned int i = 0; i < this->_size; i++) {
		this->_array[i] = src[i];
	}
}

template <typename T>
Array<T>::~Array(void) {
	delete [] this->_array;
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs) {
	delete [] this->_array;
	this->_size = rhs.size();
	this->_array = new T [this->_size];
	for (unsigned int i = 0; i < this->_size; i++) {
		this->_array[i] = rhs[i];
	}
}

template <typename T>
T & Array<T>::operator[](unsigned int id) const {
	if (id >= this->_size) {
		throw std::exception();
	}
	return (this->_array[id]);
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return (this->_size);
}

#endif
