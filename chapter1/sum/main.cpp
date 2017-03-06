#include <iostream>

using std::cout;
using std::endl;

int sum (int A[], int n);

int main (int argc, char *argv[])
{
	int iArr[] = {2, 3, 4, 5, 6};
	int sz = sizeof (iArr) / sizeof (int);

	cout << sum (iArr, sz) << endl;

	return 0;
}

int sum (int A[], int n)
{
	int ret = 0;
	for (int i = 0; i < n; ++i)
		ret += A[i];

	return ret;
}
