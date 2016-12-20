#include <iostream>
#include "vector.h"

int main(int argc,char **argv)
{
	int iArr[] = {23,2324,212,43,12,53,123,533,3,-233};
	int len = sizeof(iArr) / sizeof(int);

	Vector<int> iVec1;
	Vector<int> iVec2(iArr,0,len);

	iVec1.Print();
	iVec2.Print();
	std::cout << iVec1.Size() << " " << iVec2.Size() << std::endl;

	return 0;


}
