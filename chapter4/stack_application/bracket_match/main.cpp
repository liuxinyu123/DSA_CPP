#include <iostream>
#include <string>
#include <vector>
#include "stack.h"


using std::cout;
using std::endl;
using std::string;
using std::vector;

void test_recursion (vector<string> &strVec);
void test_iteration (vector<string> &strVec, Stack<char> &strSta);
bool bracket_parse_recursion (const string &s, int lo, int hi);
bool bracket_parse_iteration (const string &s, int lo, int hi, Stack<char> &strSta);

void trim (const string &s, int &lo, int &hi);//	确定两边都是括号，如果没有lo > hi
int divide (const string &s, int lo, int hi);

int main (int argc, char *argv[])
{
	vector<string> strVec;
	strVec.push_back ("(a+b)*c+(d+e)");
	strVec.push_back ("(a+b)*c+(d+e))");
	strVec.push_back ("(a+b)*c+(d+e)/(s+w)");
	strVec.push_back ("((a+b))*c+(()())d+e)");
	strVec.push_back ("sorry");

	test_recursion (strVec);

	cout << "=============================================" << endl;
	vector<string> strVec2;
	strVec2.push_back ("(a+b)/c+[a*(b+c)]/{s*[d*(d+d)]}");
	strVec2.push_back ("a+(s-d)/[d+e*(s+d))]");
	strVec2.push_back ("d+(sgs)/{sf*[sf+d*(a+b)]}");
	strVec2.push_back ("{df+d*[s*{(sg+dg)]}");

	Stack<char> strSta;

	test_iteration (strVec2, strSta);
	
	return 0;	
}

void test_recursion (vector<string> &strVec)
{
	for (const auto &e : strVec)
	{
		if (bracket_parse_recursion (e, 0, e.size () - 1))
			cout << "match ok" << endl;
		else
			cout << "not match" << endl;
	}
}

void test_iteration (vector<string> &strVec, Stack<char> &strSta)
{
	for (const auto &e : strVec)
		if (bracket_parse_iteration (e, 0, e.size () - 1, strSta))
			cout << "match ok" << endl;
		else
			cout << "not match" << endl;
}

bool bracket_parse_iteration (const string &s, int lo, int hi, Stack<char> &strSta)
{
	for (int i = lo; i <= hi; ++i)
	{
		switch (s[i])
		{
			case '(':
			case '[':
			case '{':
					strSta.push (s[i]);
					break;
			case ')':
					if (strSta.isEmpty () || ('(' != strSta.pop ()))
						return false;
					break;
			case ']':
					if (strSta.isEmpty () || ('[' != strSta.pop ()))
						return false;
					break;
			case '}':
					if (strSta.isEmpty () || ('{' != strSta.pop ()))
						return false;
					break;	
			default:
					break;
		}
	}

	if (strSta.isEmpty ())
		return true;
	else
		return false;
}

//lo 和 hi 都包含， 表达式为s[lo, hi]
void trim (const string &s, int &lo, int &hi)//	确定两边都是括号，如果没有lo > hi
{
	while ((lo <= hi) && (s[lo] != '(') && (s[lo] != ')'))
		++lo;
	while ((lo <= hi) && (s[hi] != '(') && (s[hi] != ')'))
		--hi;
}

int divide (const string &s, int lo, int hi)//	在两端都是括号的式子中，找出中间切分点
{
	int mid = lo;
	int crc = 1;//左右括号的差值
	while ((0 != crc) && (mid++ <= hi))
	{
		if (s[mid] == ')')
			--crc;
		if (s[mid] == '(')
			++crc;
	}

	return mid;
}

bool bracket_parse_recursion (const string &s, int lo, int hi)
{
	trim (s, lo, hi);
	if (lo > hi)//表示没有括号
		return true;

	if ((s[lo] == ')') || (s[hi] == '('))//有括号但是括号是反的
		return false;

	int mid = divide (s, lo, hi);

	if (mid > hi)//找不到括号不平衡的点
		return false;

	return bracket_parse_recursion (s, lo+1, mid - 1) && bracket_parse_recursion (s, mid + 1, hi);

}

