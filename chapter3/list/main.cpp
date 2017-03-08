#include <iostream>
#include <string>
#include "list.h"

using std::string;
using std::cout;
using std::endl;

void test_list ();

int main (int argc, char *argv[])
{
	test_list ();

	return 0;	
}

void test_list ()
{
	List<int> iList1;
	cout << iList1.size () << endl;

	for (int i = 10; i > 0; --i)
		iList1.insertAsFirst (i);

	for (int i = 0; i < iList1.size (); ++i)
		cout << iList1[i] << " ";
	cout << endl;

}
