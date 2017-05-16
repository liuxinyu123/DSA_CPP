#include <iostream>
#include "list.h"

int main(int argc,char **argv)
{
	//List<int> iList;
	ListNode<int> node1(32);
	node1.InsertAsPred(23);	
	//iList.InsertAsLast(23);
	//iList.InsertAsLast(233);
	//iList.InsertAsLast(44);
	//iList.Print();

	return 0;
}
