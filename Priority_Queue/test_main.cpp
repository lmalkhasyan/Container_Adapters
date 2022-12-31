#include <iostream>
#include "priority_queue.h"


int main()
{
	std::cout << std::endl << "\"Test All Using/typedef members\"" << std::endl;
	// test typedef => container_type
	my::priority_queue<int>::container_type deq = {13};
	for (auto &i : deq)
	{
		std::cout << "With container_type [" << i << "] ";
	}
	std::cout << std::endl;

	// test typedef => value_compare
	my::priority_queue<int>::value_compare cmp;
	std::cout << std::boolalpha << cmp(1,3) << "== true" << std::endl; 

	// test typedef => value_type
	my::priority_queue<int>::value_type val = 5;
	std::cout << "With value_type [" << val << "] " << std::endl;

	// test typedef => size_type
	my::priority_queue<int>::size_type sz_type = 100;
	std::cout << "With size_type [" << sz_type << "] " << std::endl;

	// test typedef => referance(Container::referance)
	int a = 13;
	my::priority_queue<int>::reference rf_type = a;
	std::cout << "With referance [" << rf_type << "] " << std::endl;

	// test typedef => const_referance(Container::const_referance)
	my::priority_queue<int>::const_reference crf_type = 10;
	std::cout << "With const_referance [" << crf_type << "] " << std::endl;
	std::cout << std::endl;
	return 0;
}
