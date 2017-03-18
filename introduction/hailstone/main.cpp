#include <iostream>
#include <set>


using std::cout;
using std::endl;
using std::set;

set<int> hailStone (int n);


int main (int argc, char *argv[])
{
	set<int> iSet;
   
	for (int i = 1; i < 50; ++i)
	{
		iSet = hailStone (i);

		cout << i << " : " << endl;
		for (const int e : iSet)
			cout << e << " ";
		cout << endl;
	}

	return 0;
}

set<int> hailStone (int n)
{
	set<int> iS;

	iS.insert (1);

	while (n > 1)
	{
		iS.insert (n);
		if (n % 2)//奇数
			n = 3 * n + 1;
		else//偶数
			n /= 2;
	}

	return iS;
}
