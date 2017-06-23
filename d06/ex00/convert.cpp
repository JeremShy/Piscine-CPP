#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cfloat>
#include <math.h>

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Please enter exactly one parameter." << std::endl;
		return (1);
	}
	std::string s = av[1];

	char type = '\0'; //c, i, f, ou d
	{
		size_t t;


		if (s == "-inff" || s == "+inff" || s == 	"nanf")
			type = 'g';
		if (s == "-inf" || s == "+inf" || s == 	"nan")
			type = 'e';

		if (!type and s.length() == 1) {
			if (isdigit(static_cast<int>(s[0])))
				type = 'i';
			else
				type = 'c';
		}

		int n = 0;

		if (!type && s.find_first_of(".") != std::string::npos)
		{
			if ((t = s.find_last_of("f")) != std::string::npos)
			{
				for (size_t i = 0; i < s.length(); i++)
				{
					if (!isdigit(static_cast<int>(s[i])))
					{
						if (s[i] == '.' and n == 0)
						{
							n = 1;
							continue;
						}
						if (i == 0 and (s[i] == '+' or s[i] == '-'))
							continue;
						if (s[i] == 'f' and i == s.length() - 1)
							continue;
						std::cout << "Error : You passed an invalid parameter " << std::endl;
						return (1);
					}
				}
				type = 'f';
			}
			else
			{
				for (size_t i = 0; i < s.length(); i++)
				{
					if (!isdigit(static_cast<int>(s[i])))
					{
						if (s[i] == '.' and n == 0)
						{
							n = 1;
							continue;
						}
						if (i == 0 and (s[i] == '+' or s[i] == '-'))
							continue;
						if (s[i] == '.' || t != s.length() - 1)
						{
							std::cout << "Error : You passed an invalid parameter" << std::endl;
							return (1);
						}
					}
				}
				type = 'd';
			}
		}
		if (!type)
		{
			for (size_t i = 0; i < s.length(); i++)
			{
				if (i == 0 and (s[i] == '+' or s[i] == '-'))
					continue;
				if (!isdigit(static_cast<int>(s[i])))
				{
					std::cout << "Error : You passed an invalid parameter" << std::endl;
					return (1);
				}
			}
			type = 'i';
		}
	}

	double tampon = 0;

	if (type == 'c')
	{
		char	c = s[0];
		int		i = static_cast<int>(c);
		if (!isprint(i))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else if (type == 'i')
	{
		int i = stoi(s);

		if (i > CHAR_MAX || i < CHAR_MIN)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(i))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(i) << std::endl;

		std::cout << "int: " << i << std::endl;

		if (i > FLT_MAX || i < FLT_MIN)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;

		if (i > DBL_MAX || i < DBL_MIN)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << static_cast<float>(i) << ".0" << std::endl;
	}
	else if (type == 'f')
	{
		float f = stof(s);
		if (f > CHAR_MAX || f < CHAR_MIN)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(f))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(f) << std::endl;

		if (f > INT_MAX || f < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;

		if (modf(f, &tampon) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;

		if (modf(static_cast<double>(f), &tampon) == 0)
			std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	else if (type == 'd')
	{
		double d = stod(s);
		if (d > CHAR_MAX || d < CHAR_MIN)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<int>(d)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl;

		if (d > INT_MAX || d < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;

		if (d > FLT_MAX || d < FLT_MIN)
			std::cout << "float: impossible" << std::endl;
		else if (modf(d, &tampon) == 0)
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(d) << std::endl;

			if (modf(d, &tampon) == 0)
				std::cout << "double: " << d << ".0" << std::endl;
			else
				std::cout << "double: " << d << std::endl;
	}
	else if (type == 'e')
	{
		if (s == "+inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inf" << std::endl;
			std::cout << "double: +inff" << std::endl;
		}
		else if (s == "-inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inf" << std::endl;
			std::cout << "double: -inff" << std::endl;
		}
		else if (s == "nan")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nan" << std::endl;
			std::cout << "double: nanf" << std::endl;
		}
	}
	else if (type == 'g')
	{
		if (s == "+inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: +inff" << std::endl;
		}
		else if (s == "-inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: -inff" << std::endl;
		}
		else if (s == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: nanf" << std::endl;
		}
	}
	return (0);
}
