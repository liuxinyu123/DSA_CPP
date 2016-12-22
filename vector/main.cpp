#include <iostream>
#include "vector.h"

int main(int argc,char **argv)
{
	int iArr[] = {23,2324,212,43,12,53,123,533,3,-233,212,43,12,23,12};
	int len = sizeof(iArr) / sizeof(int);
//	double fArr[] = {23.3,23.243,44.2,34.2,-23.1,323.23,324.12};
//	int sz = sizeof(fArr) / sizeof(double);

	Vector<int> iVec1;//测试默认构造函数
	Vector<int> iVec2(iArr,0,len);//测试区间拷贝
	Vector<int> iVec3(iVec2);//测试vector到vector的拷贝
	
	for(int i = 0; i < 5; ++i)
		iVec1.PushBack(i);//测试pushback
	std::cout << "iVec1 is : " << std::endl;
	iVec1.Print();
	std::cout << "iVec2 is : " << std::endl;
	iVec2.Print();
	std::cout << "iVec3 is : " << std::endl;
	iVec3.Print();
	
	std::cout << "The capacity of iVec1 is : " << iVec1.Capacity() << std::endl;
	std::cout << "The capacity of iVec2 is : " << iVec2.Capacity() << std::endl;

	iVec2.PopBack();
	iVec2.PopBack();
	iVec2.PopBack();
	std::cout << "After 3 times PopBack,iVec2 is: " << std::endl;
    iVec2.Print();
	iVec1.Delete(2);
	std::cout << "After Delete Rank 2 ,iVec1 is: " << std::endl;
	iVec1.Print();	
	iVec2.Remove(3,iVec2.Size());
	std::cout << iVec3.Find(5,0,iVec3.Size()) << std::endl;
	std::cout << "After Remove rank 3 to end,iVec2 is:" << std::endl;
	std::cout << "The Capacity of iVec2 is : " << iVec2.Capacity() << std::endl;

	iVec3.Deduplicate();
	std::cout << "After Deduplicate,iVec3 is: " << std::endl;	
	iVec3.Print();
	std::cout << "The size of iVec3 is : " << iVec3.Size() << std::endl;
	iVec3.Replace(0,44);
	std::cout << "After Replace rank 0 to 44,iVec3 is : " << std::endl;
	iVec3.Print();
	
	//VectorIncrease(iVec3);
	////std::cout << "After Traverse,iVec3 is: " << std::endl;
	//iVec3.Print();
	std::cout << "The number of iVec3 inverse-pair is : " << iVec3.Disorder() << std::endl;
	int sz = iVec3.Size();
	for(int i = 0; i < sz; ++i)
	{
		iVec3.PushBack(iVec3.Get(i));
		iVec3.PushBack(iVec3.Get(i));
		iVec3.PushBack(iVec3.Get(i));
	}
	std::cout << "iVec3 is : " << std::endl;
	iVec3.Print();
	iVec3.Sort1();
	std::cout << "After sort,iVec3 is: " << std::endl;
	iVec3.Print();
	iVec3.Uniquify1();
	std::cout << "After Uniquify,iVec3 is: " << std::endl;
	iVec3.Print();
	
	std::cout << "In iVec3, " << iVec3[4] << " is in Rank " << iVec3.Search(iVec3[4] + 1,0,iVec3.Size())  << std::endl;
	return 0;
}
