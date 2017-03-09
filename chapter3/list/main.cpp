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
		iList1.insertAsLast (i);

	cout << iList1.size () << endl;
	cout << iList1.first () -> data << endl;
	cout << iList1.last () -> data << endl;
	for (int i = 0; i < iList1.size (); ++i)
		cout << iList1[i] << " ";
	cout << endl;

	if (!iList1.find (5))
		cout << "NULL" << endl;
	iList1.insertAfter (iList1.find (5), 55);
	for (int i = 0; i < iList1.size (); ++i)
		cout << iList1[i] << " ";
	cout << endl;

	iList1.insertBefore (iList1.find (3), 33);
	for (int i = 0; i < iList1.size (); ++i)
		cout << iList1[i] << " ";
	cout << endl;

}
