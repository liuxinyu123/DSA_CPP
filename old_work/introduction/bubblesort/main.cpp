#include <iostream>
#include <vector>
#include "bubble.h"

int main(int argc,char **argv)
{
	std::vector<int> iVec;
	std::vector<int> iVec1;
	iVec.push_back(23);
	iVec.push_back(-3);
	iVec.push_back(244);
	iVec.push_back(54);
	iVec.push_back(-23);
	iVec.push_back(3);
	iVec.push_back(34);
	iVec.push_back(42);
	iVec.push_back(33);
	iVec.push_back(334);
	iVec.push_back(422);

	iVec1 = iVec;
	std::vector<int> iVec2(iVec);
	std::vector<int> iVec3(iVec);
	Bubble<int> bub(iVec);
	bub.Print();

	bub.BubbleSort();
	bub.Print();

	Bubble<int> bub1(iVec1);
	bub1.Print();
	bub1.BubbleSort1A();
	bub1.Print();

	Bubble<int> bub2(iVec2);
	bub2.Print();
	bub2.BubbleSort1B();
	bub2.Print();
	
	Bubble<int> bub3(iVec3);
	bub3.Print();
	bub3.BubbleSort2();
	bub3.Print();
	
	std::vector<double> fVec;
	fVec.push_back(43.23);
	fVec.push_back(-43.23);
	fVec.push_back(423.23);
	fVec.push_back(2.3);
	fVec.push_back(5.4);
	fVec.push_back(-32.3);
	fVec.push_back(0);
	fVec.push_back(2.34);
	fVec.push_back(534.4);

	Bubble<double> bub4(fVec);
	bub4.Print();
	bub4.BubbleSort2();
	bub4.Print();

	return 0;
}
