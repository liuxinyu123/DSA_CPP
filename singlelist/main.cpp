#include <iostream>
#include "singlelist.h"

int main(int argc,char **argv)
{
	SingleList<int> sList;

	//if(!sList.Head() -> succ_)
		//std::cout << "Hello" << std::endl;
	sList.PushBack(42);
	sList.PushBack(12);
	sList.PushBack(534);
	sList.PushBack(54);
	sList.PushFront(1);
	sList.PushFront(2);
	sList.PopFront();
	sList.PopBack();
	sList.Print();
	return 0;	
}
