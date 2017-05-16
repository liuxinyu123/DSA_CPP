#ifndef _UNEXTREME_H_
#define _UNEXTREME_H_

#include <vector>

#define Max2(a,b) ( ((a) > (b))? (a):(b) )
#define Min2(a,b) ( ((a) < (b))? (a):(b) )


class Index
{
public:
		Index(int val1 = 0,int val2 = 1,int val3 = 2):idx1(val1),idx2(val2),idx3(val3) 
		{}//构造函数，默认取前三个

public:
		int idx1;
		int idx2;
		int idx3;
};

typedef Index *pIndex;

template <typename T>
class UnExtreme
{
public:
		UnExtreme(std::vector<T> &v):vec_(v) {}
		T UnExtremeElement();
private:
		pIndex RandProductThreeIndex();							
		T Max(T a,T b,T c);
		T Min(T a,T b,T c);
private:
		std::vector<T> vec_;
};

#include "unextreme_impl.h"

#endif
