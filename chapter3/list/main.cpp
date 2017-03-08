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

}
