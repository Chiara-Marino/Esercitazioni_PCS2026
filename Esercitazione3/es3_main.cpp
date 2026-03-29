#include <iostream>
#include "rational_es3.hpp"

int main(void)
{
	rational<int> r(0,0);
	std::cout << r << "\n";
	
	rational<int> v(1,0);
	std::cout << v << "\n";
	std::cout << (v*=r)<< "\n";
	return 0;
}