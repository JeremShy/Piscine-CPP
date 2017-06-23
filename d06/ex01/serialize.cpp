#include <serialize.hpp>
#include <ctime>
#include <cstdlib>

void	*serialize(void)
{
	void	*addr;

	addr = operator new(sizeof(char) * 8 + sizeof(int) + sizeof(char) * 8);
	char	*t1 = reinterpret_cast<char*>(addr);
	int		*n = reinterpret_cast<int*>(reinterpret_cast<char*>(addr) + sizeof(char) * 8);
	char	*t2 = reinterpret_cast<char*>(reinterpret_cast<char*>(addr) + sizeof(char) * 8 + sizeof(int));

	std::string s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	srand(time(NULL));

	for (int i = 0; i < 8; i++)
		t1[i] = s[rand() % s.length()];

	*n = rand();

	for (int i = 0; i < 8; i++)
		t2[i] = s[rand() % s.length()];

	return (addr);
}

Data	*unserialize(void *raw)
{
	char	*t1 = reinterpret_cast<char*>(raw);
	int		*n = reinterpret_cast<int*>(reinterpret_cast<char*>(raw) + sizeof(char) * 8);
	char	*t2 = reinterpret_cast<char*>(reinterpret_cast<char*>(raw) + sizeof(char) * 8 + sizeof(int));

	Data *ret = new Data();
	ret->s1 = "";
	ret->s2 = "";

	for (int i = 0; i < 8; i++)
		ret->s1 += t1[i];

	ret->n = *n;

	for (int i = 0; i < 8; i++)
		ret->s2 += t2[i];

	return (ret);
}
