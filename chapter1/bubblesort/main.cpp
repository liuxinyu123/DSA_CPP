#include <iostream>

using std::cout;
using std::endl;

void bubble_sort (int A[], int n);
void swap (int &a, int &b);

int main (int argc, char *argv[])
{
	int Arr[] = {23, 3, 12, 345, 12, 44, 1, 44, 65};
	for (const int &e : Arr)
		cout << e << " ";
	cout << endl;

	int sz = sizeof (Arr) / sizeof (Arr[0]);
	bubble_sort (Arr, sz);
	for (const int &e : Arr)
		cout << e << " ";
	cout << endl;

	return 0;
}

void swap (int &a, int &b)
{
	int t = b;
	b = a;
	a = t;
}

void bubble_sort (int A[], int n)
{
	bool sorted = false;
	while(!sorted)
	{
		sorted = true;
		for (int i = 1; i < n; ++i)
		{
			if (A[i-1] > A[i])
			{
				swap (A[i - 1], A[i]);
				sorted = false;
			}
		}
		--n;
	}
}
