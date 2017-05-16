#include <iostream>
#include <vector>
#include <ctime>
#include "stack.h"

using std::cout;
using std::endl;
using std::vector;

void test_number_base_conversion_recursion (Stack<char> &s, vector<unsigned> v, unsigned base);
void conversion_recursion (Stack<char> &s, unsigned number, unsigned base);
void test_number_base_conversion_iteration (Stack<char> &s, vector<unsigned> v, unsigned base);
void conversion_iteration (Stack<char> &s, unsigned number, unsigned base);

int main (int argc, char *argv[])
{
	Stack<char> cSta;
	vector<unsigned> iVec;

	for (unsigned i = 0; i < 100; i++)
		iVec.push_back (i);

	cout << "test_number_base_conversion_recursion:" << endl;
	std::clock_t b1 = clock ();
	test_number_base_conversion_recursion (cSta, iVec, 2);
	std::clock_t e1 = clock ();
	cout << "Time elapse: " << e1 - b1 << endl;

	cout << "test_number_base_conversion_iteration: " << endl;
	std::clock_t b2 = clock ();
	test_number_base_conversion_iteration (cSta, iVec, 2);
	std::clock_t e2 = clock ();
	cout << "Time elapse: " << e2 - b2 << endl;


	return 0;
}

void test_number_base_conversion_recursion (Stack<char> &s, vector<unsigned> v, unsigned base)
{
	for (const unsigned e : v)
	{
		cout << e << " = ";
		conversion_recursion (s, e, base);
		cout << endl;
	}
}

void conversion_recursion (Stack<char> &s, unsigned number, unsigned base)
{
	static char digit[] = {'0','1','2','3','4','5','6','7','8','9',
			'A','B','C','D','F'};
	if (0 < number)
	{
		conversion_recursion (s, number / base, base);
		s.push (digit[number % base]);
	}

	while (!s.isEmpty ())
		cout << s.pop ();
}


void test_number_base_conversion_iteration (Stack<char> &s, vector<unsigned> v, unsigned base)
{
	for (const unsigned e : v)
	{
		cout << e << " = ";
		conversion_recursion (s, e, base);
		cout << endl;
	}
	
}
void conversion_iteration (Stack<char> &s, unsigned number, unsigned base)
{
	static char digit[] = {'0','1','2','3','4','5','6','7','8','9',
			'A','B','C','D','F'};
	while (0 < number)
	{
		s.push (digit[number % base]);
		number /= base;
	}	

	while (!s.isEmpty ())
		cout << s.pop ();
}
