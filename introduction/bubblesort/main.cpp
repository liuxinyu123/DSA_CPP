#include <iostream>
#include <vector>
#include "bubble.h"

int main(int argc,char **argv)
{
	std::vector<int> iVec;
	iVec.push_back(23);
	iVec.push_back(-3);
	iVec.push_back(244);
	iVec.push_back(54);
	iVec.push_back(-23);
	iVec.push_back(3);
	iVec.push_back(34);
	iVec.push_back(42);

	Bubble<int> bub(iVec);
	bub.Print();

	bub.BubbleSort();
	bub.Print();

	return 0;
}
