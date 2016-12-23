#include <iostream>
#include "singlelist.h"

int main(int argc,char **argv)
{
	SingleList<int> list1;
	std::cout << "The size of list1 is: " << list1.Size() << std::endl;
	for(int i = 0; i < 11; ++i)
		list1.PushBack(i);
	std::cout << "The size of list1 is: " << list1.Size() << std::endl;
	for(int i = -1; i > -11; --i)
		list1.PushFront(i);
	std::cout << "The size of list1 is: " << list1.Size() << std::endl;

	list1.InsertAfter(list1.Find(8),88);
	list1.InsertBefore(list1.Find(4),44);
	std::cout << "The list1 is: " << std::endl; 
	list1.Print();
	std::cout << "The size of list1 is: " << list1.Size() << std::endl;
	//std::cout << "The front is : " << list1.Front() << std::endl;
	//std::cout << "The back is : " << list1.Back() << std::endl;

	return 0;	
}
