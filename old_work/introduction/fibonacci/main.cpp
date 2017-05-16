#include <iostream>

using std::cout;
using std::endl;

unsigned long fibonacci_A (int idx);//佛波那契数列中第idx个元素, 递归实现
unsigned long fibonacci_B (int idx);//需要存储数组
unsigned long fibonacci_C (int idx);//迭代 自底向顶求值

int main (int argc, char *argv[])
{
	cout << "memoization array" << endl;
	for (int i = 1; i < 50; ++i)
		cout << "fib (" << i << ")" << " = " << fibonacci_B (i)  << endl;
	cout << "+++++++++++++++++++++++++++++++++++" << endl;
	
	cout << "iterator " << endl;
	for (int i = 1; i < 50; ++i)
		cout << "fib (" << i << ")" << " = " << fibonacci_C (i)  << endl;
	cout << "+++++++++++++++++++++++++++++++++++" << endl;

	cout << "recursive " << endl;
	for (int i = 1; i < 50; ++i)
		cout << "fib (" << i << ")" << " = " << fibonacci_A (i)  << endl;
	cout << endl;

	
	return 0;
}

unsigned long fibonacci_A (int idx)
{
	if (idx > 2)
		return fibonacci_A (idx - 1) + fibonacci_A (idx - 2);
	return 1;//第一项和第二项都为1
}

unsigned long fibonacci_B (int idx)
{
	unsigned long *pArr = new unsigned long [idx];

	pArr[0] = 1;
	pArr[1] = 1;

	for (int i = 2; i < idx; ++i)
		pArr[i] = pArr[i - 1] + pArr[i - 2];

	unsigned long ret = pArr[idx - 1]; 
	delete [] pArr;

	return ret;
}

unsigned long fibonacci_C (int idx)//假设idx大于0
{
	unsigned long first = 1;
	unsigned long second = 1;
	for (int i = 2; i < idx; ++i)
	{
		unsigned long tmp = second;
		second += first;
		first = tmp;		
	}

	return second;
}
