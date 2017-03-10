#include <iostream>
#include <vector>
#include "stack.h"

using std::cout;
using std::endl;
using std::vector;

void test_number_base_conversion_recursion (Stack<char> &s, vector<unsigned> v, unsigned base);
void conversion_recursion (Stack<char> &s, unsigned number, unsigned base);

int main (int argc, char *argv[])
{
	Stack<char> cSta;
	vector<unsigned> iVec;
	iVec.push_back (224);
	iVec.push_back (45);
	iVec.push_back (12);
	iVec.push_back (23);
	test_number_base_conversion_recursion (cSta, iVec, 2);

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


