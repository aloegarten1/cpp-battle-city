#include <iostream>

void swap_int(int* a, int* b)
{
	if(a == b) { return; }
	int dst = *a;
	(*a) = (*b);
	(*b) = dst;
}

int main()
{
	int a = 4, b = 5;
	std::cout << a << b << std::endl;
	swap_int(&a, &b);
	std::cout << a << b << std::endl;
}

