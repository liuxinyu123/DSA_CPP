#include <iostream>

using std::cout;
using std::endl;

int fibonacci (int idx);//佛波那契数列中第idx个元素

int main (int argc, char *argv[])
{
	for (int i = 1; i < 50; ++i)
		cout << fibonacci (i) << " ";
	cout << endl;

	return 0;
}

int fibonacci (int idx)
{
	if (idx > 2)
		return fibonacci (idx - 1) + fibonacci (idx - 2);
	return 1;//第一项和第二项都为1
}
