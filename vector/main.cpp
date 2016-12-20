#include <iostream>
#include "vector.h"

int main(int argc,char **argv)
{
	int iArr[] = {23,2324,212,43,12,53,123,533,3,-233};
	int len = sizeof(iArr) / sizeof(int);
	double fArr[] = {23.3,23.243,44.2,34.2,-23.1,323.23,324.12};
	int sz = sizeof(fArr) / sizeof(double);

	Vector<int> iVec1;
	Vector<int> iVec2(iArr,0,len);
	Vector<int> iVec3(iVec2);
	
	for(int i = 0; i < 11; ++i)
		iVec1.PushBack(i);
	std::cout << "iVec1 is : " << std::endl;
	iVec1.Print();
	std::cout << "iVec2 is : " << std::endl;
	iVec2.Print();
	std::cout << "iVec3 is : " << std::endl;
	iVec3.Print();

	Vector<double> fVec1;
	Vector<double> fVec2(fArr,0,sz - 1);
	Vector<double> fVec3(fVec2);
}
