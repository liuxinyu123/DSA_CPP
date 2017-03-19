#include <iostream>

using std::cout;
using std::endl;

void array_reverse_A (int *arr, int lo, int hi);//数组倒置，递归实现 arr[lo, hi]
void swap (int &l, int &r);
void array_reverse_B (int *arr, int lo, int hi);//迭代版本
void array_reverse_C (int *arr, int lo, int hi);//迭代精简版

int main (int argc, char *argv[])
{
	int iArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sz = sizeof (iArr) / sizeof (int);

	array_reverse_A (iArr, 0, sz - 1);

	for (int i = 0; i < sz; ++i)
		cout << iArr[i] << " ";
	cout << endl;

	array_reverse_B (iArr, 0, sz - 1);

	for (int i = 0; i < sz; ++i)
		cout << iArr[i] << " ";
	cout << endl;

	array_reverse_C (iArr, 0, sz - 1);

	for (int i = 0; i < sz; ++i)
		cout << iArr[i] << " ";
	cout << endl;
	return 0;
}

void array_reverse_A (int *arr, int lo, int hi)
{
	if (lo < hi)
	{
		swap (arr[lo], arr[hi]);
		array_reverse_A (arr, lo + 1, hi - 1);
	}
}

void swap (int &l, int &r)
{
	int tmp = l;
	l = r;
	r = tmp;
}

void array_reverse_B (int *arr, int lo, int hi)
{
	while (lo < hi)
	{
		swap (arr[lo], arr[hi]);
		++lo;
		--hi;
	}
}

void array_reverse_C (int *arr, int lo, int hi)
{
	while (lo < hi)
	{
		swap (arr[lo++], arr[hi--]);
	}
}
