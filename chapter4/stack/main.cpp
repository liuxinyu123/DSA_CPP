#include <iostream>
#include <string>
#include "stack.h"

using std::cout;
using std::endl;
using std::string;

void test_stack ();

int main (int argc, char *argv[])
{
	test_stack ();


	return 0;
}

void test_stack ()
{
	Stack<string> strStack1;
	strStack1.push ("hello");
	strStack1.push ("world");
	strStack1.push ("what");
	strStack1.push ("fuck");
	strStack1.push ("sorry");

	Stack<string> strStack2 (strStack1);
	//Stack<string> strStack3;
	//strStack3 = strStack2;
	

	cout << strStack1.top () << endl;
	while (!strStack1.isEmpty ())
		cout << strStack1.pop () << endl;

	while (!strStack2.isEmpty ())
		cout << strStack2.pop () << endl;

}
