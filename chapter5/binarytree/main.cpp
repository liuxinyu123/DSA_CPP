#include <iostream>
#include <string>
#include "bintree.h"

using std::cout;
using std::endl;
using std::string;

void test_bintree ();

int main (int argc, char *argv[])
{
	test_bintree ();

	return 0;

}

void test_bintree ()
{
	BinTree<int> iTree;

	iTree.insertAsRoot (4);
	iTree.insertAsRoot (5);
	iTree.insertAsRoot (6);
	
	cout << iTree.size () << endl;

}
