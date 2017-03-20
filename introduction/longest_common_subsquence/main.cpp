#include <iostream>
#include <cstring>


#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

using std::cout;
using std::endl;

int lcs (char *s1, int sz1, char *s2, int sz2);//采用递归的方式求解
int lcs_dp (char *s1, int sz1, char *s2, int sz2);//采用迭代的方式求解

int main (int argc, char *argv[])
{
	char s1[] = {'e', 'd', 'u', 'c', 'a', 't', 'i', 'o', 'n', 'a', 'l'};
	char s2[] = {'a', 'd', 'v', 'a', 'n', 't', 'a', 'g', 'e'};
	int sz1 = sizeof (s1) / sizeof (char);
	int sz2 = sizeof (s2) / sizeof (char);

	//cout << sz1 << endl;
	cout << lcs (s1, sz1, s2, sz2) << endl;
	cout << lcs_dp (s1, sz1, s2, sz2) << endl;

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

int lcs_dp (char *s1, int sz1, char *s2, int sz2)
{
	int **m;//需要维护一个矩阵
	m = new int* [sz1];

	for (int i = 0; i < sz1; ++i)
		m[i] = new int[sz2];
	std::memset (m, 0, sz1 * sz2);
	int n = min (sz1, sz2);

	for (int j = 0; j < n; ++j)
	{
		if (s1[j] == s2[j])//对角线初始化
			m[j][j] = m[j - 1][j - 1] + 1;
		else
			m[j][j] = max (m[j - 1][j], m[j][j - 1]);

		for (int i = j + 1; i < sz1; ++i)//初始化一列
		{
			if (s1[i] == s2[j])
				m[i][j] = m[i - 1][j] + 1;
			else
				m[i][j] = m[i - 1][j];
		}
		for (int i = j + 1; i < sz2; ++i)//初始化一行
		{
			if (s1[j] == s2[i])
				m[j][i] = m[j][i - 1] + 1;
			else
				m[j][i] = m[j][i - 1];
		}

	
	}

	//还需要考虑sz1和sz2 多余出的部分

	int ret = m[n - 1][n - 1];
	delete [] m;

	return ret;

}
