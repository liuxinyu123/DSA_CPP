#include <iostream>

using std::cout;
using std::endl;

int floor (int a, int b);

int main (int argc, char *argv[])
{
	cout << floor (4, 3) << endl;
	cout << floor (5, 2) << endl;
	cout << floor (5, 7) << endl;

	return 0;
}

int floor (int a, int b)
{
	++a;
	int ret = 0;
	do
	{
		a -= b;
		++ret;
	} while (a > 0);

	return --ret;
}
