#include <iostream>
#include <string>

template<typename T, typename F>
void	iter(T *array, size_t ln, F fn) {
	for (size_t i = 0; i < ln; i++) {
		fn(array[i]);
	}
}

void	f1(int i) {
	std::cout << i * 2 << std::endl;
}

template<typename T>
void	f2(T i) {
	std::cout << i + i << std::endl;
}

int main() {
	int tab[] = {1, 4, 21};
	iter(tab, 3, f1);

	std::cout << std::endl;

	std::string tab2[] = {"Hello", "Hi", "Alola"};
	iter(tab2, 3, f2<std::string>);
}
