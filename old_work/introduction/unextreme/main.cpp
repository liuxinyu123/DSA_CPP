#include <iostream>
#include <vector>
#include "unextreme.h"

int main(int argc,char **argv)
{
	std::vector<int> iVec;
	for(int i = 0; i < 20; ++i)
		iVec.push_back(i);

	UnExtreme<int> uEx(iVec);
		
	std::cout << "The unextreme element is : " << uEx.UnExtremeElement() << std::endl;

	return 0;
}
