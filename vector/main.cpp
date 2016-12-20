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

	Vector<double> fVec1;
	Vector<double> fVec2(fArr,0,sz - 1);
	Vector<double> fVec3(fVec2);

	iVec1.Print();
	iVec2.Print();
	iVec3.Print();
	iVec2.Insert(iVec2.Size(),111);
	iVec2.Insert(iVec2.Size(),222);
	iVec2.Print();
	iVec3.Delete(iVec3.Size() - 1);
	iVec3.Print();	
	std::cout << iVec2.Find(111,0,iVec2.Size()) << std::endl;
	fVec1.Print();
	fVec2.Print();
	fVec3.Print();
	std::cout << iVec1.Size() << " " << iVec2.Size() << " " << iVec3.Size() << std::endl;
	std::cout << fVec1.Size() << " " << fVec2.Size() << " " << fVec3.Size() << std::endl;

	return 0;


}
