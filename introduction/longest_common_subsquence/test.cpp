#include <iostream>

using std::cout;
using std::endl;

int main (void)
{
	char s1[] = {'h', 'e', 'l', 'l', 'o'};
	int sz = sizeof (s1) / sizeof (char);

	for (int i = 0; i < sz; ++i)
		cout << s1[i] << " ";
	cout <<endl;

	s1[sz - 1] = 0;
	for (int i = 0; i < sz; ++i)
		cout << s1[i] << " ";
	cout <<endl;

	return 0;
}
