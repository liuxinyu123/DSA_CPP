#include <iostream>

using std::cout;
using std::endl;

//区间为arr[lo,hi)
void print_array (int *arr, int sz);
void max2_in_array_A (int *arr, int lo, int hi, int &x1, int &x2);//先找出最大，再找出次大
void max2_in_array_B (int *arr, int lo, int hi, int &x1, int &x2);//一次扫描找出两个
void max2_in_array_C (int *arr, int lo, int hi, int &x1, int &x2);//分而治之

void swap (int &l, int &r)
{
	int tmp = l;
	l = r;
	r = tmp;
}

int main (int argc, char *argv[])
{
	int iArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int len = sizeof (iArr) / sizeof (int);

	int x1 = 0;
	int x2 = 0;
	
	max2_in_array_A (iArr, 0, len, x1, x2);
	cout << "First max is: " << iArr[x1] << " Second max is: " << iArr[x2] << endl;

	max2_in_array_B (iArr, 0, len, x1, x2);
	cout << "First max is: " << iArr[x1] << " Second max is: " << iArr[x2] << endl;

	max2_in_array_B (iArr, 0, len, x1, x2);
	cout << "First max is: " << iArr[x1] << " Second max is: " << iArr[x2] << endl;

	return 0;
}

void print_array (int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void max2_in_array_A (int *arr, int lo, int hi, int &x1, int &x2)
{
	x1 = lo;
	x2 = lo;
	for (int i = lo; i < hi; ++i)//先找最大
	{
		if (arr[i] > arr[x1])
			x1 = i;
	}
	
	for (int i = lo; i < x1; ++i)//除了最大者外，找次大者
	{
		if (arr[i] > arr[x2])
			x2 = i;		
	}

	for (int i = x1 + 1; i < hi; ++i)
	{
		if (arr[i] > arr[x2])
			x2 = i;		
	}
}

void max2_in_array_B (int *arr, int lo, int hi, int &x1, int &x2)
{
	x1 = lo;
	x2 = lo + 1;//初始化
	
	if (arr[x1] < arr[x2])
		swap (x1, x2);	

	for (int i = lo; i < hi; ++i)
	{
		if (arr[i] > arr[x2])
		{
			x2 = i;

			if (arr[x2] > arr[x1])
				swap (x1, x2);
		}
	}
}

void max2_in_array_C (int *arr, int lo, int hi, int &x1, int &x2)
{
	if (lo + 1 == hi)//只有一个元素
	{
		x1 = lo;
		x2 = lo;
		return;
	}	

	if (lo + 2 == hi)//只有两个元素
	{
		x1 = lo;
		x2 = lo + 1;

		if (arr[x1] < arr[x2])
			swap (x1, x2);
	}

	int mid = (lo + hi) / 2;

	int x1L = lo;
	int x2L = lo;
	max2_in_array_C (arr, lo, mid, x1L, x2L);

	int x1R = mid;
	int x2R = mid;
	max2_in_array_C (arr, mid, hi, x1R, x2R);

	if (arr[x1L] > arr[x2L])
	{
		x1 = x1L;
		
		if (arr[x1R] > arr[x2L])
			x2 = x1R;
		else
			x2 = x2L;
	}
	else
	{
		x1 = x2L;

		if (arr[x1L] > arr[x2R])
			x2 = x1L;
		else
			x2 = x2R;
	}

}
