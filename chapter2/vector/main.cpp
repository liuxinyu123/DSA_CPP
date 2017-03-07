#include <iostream>
#include <string>
#include "vector.h"

using std::cout;
using std::endl;
using std::string;

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

	Vector<int> iVec2 (iVec);
	cout << iVec2.size () << endl;
	for (int i = 0; i < iVec2.size (); ++i)
		cout << iVec2[i] << " ";
	cout << endl;

	Vector<int> iVec3;
	cout << iVec3.size () << endl;
	iVec3 = iVec2;
	for (int i = 0; i < iVec3.size (); ++i)
		cout << iVec3[i] << " ";
	cout << endl;

	cout << iVec3.get (2) << endl;
	iVec3.put (3, 23);
	for (int i = 0; i < iVec3.size (); ++i)
		cout << iVec3[i] << " ";
	cout << endl;

	string strArr[] = {"hello", "world", "what", "are", "you", "doing"};
	Vector<string> strVec (strArr, 0, sizeof (strArr) / sizeof (strArr[0]));
	for (int i = 0; i < strVec.size (); ++i)
		cout << strVec[i] << " ";
	cout << endl;
	cout << strVec.find ("wo", 0, strVec.size ()) << endl;

	strVec.unsort (0, strVec.size ());
	for (int i = 0; i < strVec.size (); ++i)
		cout << strVec[i] << " ";
	cout << endl;
		

	
	
}
