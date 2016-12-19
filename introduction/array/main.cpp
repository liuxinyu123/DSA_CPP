#include <iostream>
#include <vector>
#include "array.h"

int main(int argc,char **argv)
{
	std::vector<int> iVec;
	iVec.push_back(23);
	iVec.push_back(2);
	iVec.push_back(45);
	iVec.push_back(41);
	iVec.push_back(12);
	iVec.push_back(51);

	Array<int> iArr(iVec);
	iArr.Print();
	
	iArr.Inverse();
	iArr.Print();

	int sz = iArr.Size();
	iArr.Inverse(0,sz - 1);
	iArr.Print();

	std::cout << "The array's sum is: " << iArr.Sum(sz - 1) << std::endl;
	std::cout << "The array's sum is: " << iArr.Sum(0,sz - 1) << std::endl;
	return 0;
}
