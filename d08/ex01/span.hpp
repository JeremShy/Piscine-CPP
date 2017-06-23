#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

# include <iostream>
# include <vector>

class Span {
public:
	Span(unsigned int N);
	Span(Span const & src);
	~Span(void);

	Span & operator=(Span const & rhs);

	void	addNumber(int nbr);
	void	addElements(std::vector<int>::iterator const a, std::vector<int>::iterator const b);

	int	shortestSpan(void) const;
	int	longestSpan(void) const;

private:
	Span(void);

	unsigned int _N;
	std::vector<int> _vec;
};
#endif
