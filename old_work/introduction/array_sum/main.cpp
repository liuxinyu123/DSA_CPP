#include <iostream>

using std::cout;
using std::endl;

int sum_of_array_A (int *arr, int sz);//迭代
int sum_of_array_B (int *arr, int sz);//减而治之
int sum_of_array_C (int *arr, int lo, int hi);//分而治之

int main (int argc, char *argv[])
{
	int iArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len = sizeof (iArr) / sizeof (int);

	cout << sum_of_array_A (iArr, len) << endl;
	cout << sum_of_array_B (iArr, len) << endl;
	cout << sum_of_array_C (iArr, 0, len - 1) << endl;

	return 0;
}

int sum_of_array_A (int *arr, int sz)
{
	int sum = 0;

	for (int i = 0; i < sz; ++i)
		sum += arr[i];

	return sum;
}

int sum_of_array_B (int *arr, int sz)
{
	if (sz >= 1)
		return sum_of_array_B (arr, sz - 1) + arr[sz - 1];
	return 0;
}

int sum_of_array_C (int *arr, int lo, int hi)
{
	if (lo == hi)
		return arr[lo];//递归基
	int mid = (lo + hi) / 2;

	return sum_of_array_C (arr, lo, mid) + sum_of_array_C (arr, mid + 1, hi);
}
