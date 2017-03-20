#include <iostream>

#define max(a, b) ((a) > (b) ? (a) : (b))

using std::cout;
using std::endl;

int lcs (char *s1, int sz1, char *s2, int sz2);

int main (int argc, char *argv[])
{
	char s1[] = {'e', 'd', 'u', 'c', 'a', 't', 'i', 'o', 'n', 'a', 'l'};
	char s2[] = {'a', 'd', 'v', 'a', 'n', 't', 'a', 'g', 'e'};
	int sz1 = sizeof (s1) / sizeof (char);
	int sz2 = sizeof (s2) / sizeof (char);

	//cout << sz1 << endl;
	cout << lcs (s1, sz1, s2, sz2) << endl;

	return 0;
}

int lcs (char *s1, int sz1, char *s2, int sz2)
{
	if (sz1 == 0 || sz2 == 0)//任意一个为空序列
		return 0;

	if (s1[sz1 - 1] == s2[sz2 - 1])//末尾字母相等
	{
		return lcs (s1, sz1 - 1, s2, sz2 - 1) + 1;
	}
	else
	{
		int len1 = lcs (s1, sz1 - 1, s2, sz2);
		int len2 = lcs (s1, sz1, s2, sz2 - 1);

		return max (len1, len2);
	}
	
}


