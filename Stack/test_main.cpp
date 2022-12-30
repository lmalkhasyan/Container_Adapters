#include <iostream>
#include "stack.h"


int main()
{
	std::cout << std::endl << "\"Test All Using/typedef members\"" << std::endl;
	// test typedef => container_type
	my::stack<int>::container_type deq = {13};
	for (auto &i : deq)
	{
		std::cout << "With container_type [" << i << "] ";
	}
	std::cout << std::endl;

	// test typedef => value_type
	my::stack<int>::value_type val = 5;
	std::cout << "With value_type [" << val << "] " << std::endl;

	// test typedef => size_type
	my::stack<int>::size_type sz_type = 100;
	std::cout << "With size_type [" << sz_type << "] " << std::endl;

	// test typedef => referance(Container::referance)
	int a = 13;
	my::stack<int>::reference rf_type = a;
	std::cout << "With referance [" << rf_type << "] " << std::endl;

	// test typedef => const_referance(Container::const_referance)
	my::stack<int>::const_reference crf_type = 10;
	std::cout << "With const_referance [" << crf_type << "] " << std::endl;
	std::cout << std::endl;

	std::cout << "\"Test All Ctor members\"" << std::endl;
	my::stack<int> stack_def;
	std::cout << "Def ctor (1)" << std::endl;

	std::deque<int> deq2 {3, 1, 4, 1, 5};
	my::stack<int> st2(deq2);
	std::cout << "container ctor (2)" << std::endl;

	my::stack<int> st3(std::move(deq2));
	std::cout << "container move ctor (3)" << std::endl;
	
	my::stack<int> st4(st3);
	std::cout << "container copy ctor (4)" << std::endl;
	
	my::stack<int> st5(std::move(st3));
	std::cout << "container copy ctor (5)" << std::endl;

	const auto il = {2, 7, 1, 8, 2};
    my::stack<int> c4 { il.begin(), il.end() }; 
	std::cout << "ctor with iterators (6)" << std::endl;
	std::cout << std::endl;

	std::cout << "\"Test All  member Functions\"" << std::endl;
	std::deque<int> deq5 {3, 1, 4, 1, 5};
	my::stack<int> cc1(deq5);
	my::stack<int> cc2;
	std::cout << "Operator=" << std::endl;
	std::cout << "size before op= SIZE=" << cc2.size() << std::endl;
	cc2 = cc1;
	std::cout << "size after op= SIZE=" << cc2.size() << std::endl;
	
	my::stack<int> cc3;
	std::cout << "Move Operator=" << std::endl;
	std::cout << "size before move op= SIZE=" << cc3.size() << std::endl;
	cc3 = std::move(cc1);
	std::cout << "size after move op= SIZE=" << cc3.size() << std::endl;
	std::cout << "not valid objecy size after move op= SIZE=" << cc1.size() << std::endl;
	
	my::stack<int> st01;
	st01.push(1);
	st01.push(2);
	st01.push(3);
	std::cout << "top() elem = " << st01.top() << std::endl;
	std::cout << "empty() = " << std::boolalpha << st01.empty() << std::endl;
	st01.pop();
	std::cout << "top() elem  after pop() = " << st01.top() << std::endl;
	st01.emplace(999);
	std::cout << "top() elem  after emplace(arg...) = " << st01.top() << std::endl;

	my::stack<int> st02;
	st02.push(222);
	std::cout << "st01 top =" << st01.top() << std::endl;
	std::cout << "st02 top =" << st02.top() << std::endl;
	st01.swap(st02);
	std::cout << "after swap st01 top =" << st01.top() << std::endl;
	std::cout << "after swap st02 top =" << st02.top() << std::endl;
	
	return 0;
}
