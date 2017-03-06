#include <iostream>

using std::cout;
using std::endl;

int countOnes (int a);

int main (int argc, char *argv[])
{
	int iArr[] = {23, 43, 23333, 441};

	for (const int e : iArr)
		cout << e << " is consist of " << countOnes (e) << " 1 " << endl;

	return 0;
}

int countOnes (int a)
{
	int ret = 0;
	while (a)
	{
		if (a % 2)
			++ret;
		a /= 2;
	}

	return ret;
}
