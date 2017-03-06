#include <iostream>
#include <string>
#include "vector.h"

using std::cout;
using std::endl;

void test_vector ();

int main (int argc, char *argv[])
{
	test_vector ();

	return 0;

}

void test_vector ()
{
	Vector<int> iVec (20, 4, 1);

	cout << iVec.size () << endl;
	for (int i = 0; i < iVec.size (); ++i)
		cout << iVec[i] << " ";
	cout << endl;
}
