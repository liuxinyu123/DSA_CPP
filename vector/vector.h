#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef int Rank;

const int DEFAULT_CAPACITY = 10;//默认初始容量

template<typename T>
class Vector
{
public:
		Vector(int c = DEFAULT_CAPACITY):size_(0),capacity_(c) {array_ = new T[capacity_];}//默认构造函数
		Vector(const T *arr,Rank lo,Rank hi) {CopyFrom(arr,lo,hi);}
		Vector(const Vector<T> &vec,Rank lo,Rank hi) {CopyFrom(vec.array_,lo,hi);}//构造函数
		Vector(const Vector<T> &vec) {CopyFrom(vec.array_,0,vec.size_);}//构造函数重载
		~Vector() {delete [] array_;}//析构函数
		void Print();//打印输出
		int Size() {return size_;}//求大小
		

private:
		void CopyFrom(const T *arr,Rank lo,Rank hi);

private:
		T *array_;
		Rank size_;
		int capacity_;
};

#include "vector_impl.h"

#endif
