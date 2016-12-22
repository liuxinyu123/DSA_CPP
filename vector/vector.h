#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "./header/increase.h"

typedef int Rank;//秩

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
		void Print() const;//打印输出
		int Size() const {return size_;}//求大小
		T& operator[](Rank r) const {return array_[r];}//重载[]操作符
		T Get(Rank r) const {return array_[r];}//访问元素
		Rank Insert(Rank r,const T &elem);//插入操作
		int Remove(Rank lo,Rank hi);//区间删除	
		T Delete(Rank r);//删除操作
		Rank Find(const T &elem,Rank lo,Rank hi) const;//元素查找
		void PushBack(const T &elem);//元素追加
		T PopBack();//元素尾部删除
		int Deduplicate();//去除重复的元素,返回重复个数
		int Capacity() const {return capacity_;}//获取容量
		void Replace(Rank r,const T &elem);//元素替换
		template<typename VST>
		void Traverse(VST &visit);
		static void VectorIncrease(Vector<T> &v);
		int Disorder() const;//返回逆序对个数
		void Sort();//排序
		void Sort(Rank lo,Rank hi);//排序的重载版本
		void Sort1(Rank lo,Rank hi);//归并排序调用程序
		void Sort1();//重载
		int Uniquify();//有序向量的去重,返回重复个数
		int Uniquify1();//去重高效算法
		Rank Search(const T &elem,Rank lo,Rank hi) const;//有序向量的查找
private:
		void CopyFrom(const T *arr,Rank lo,Rank hi);//拷贝
		void Expand();//扩容
		void Shrunk();//缩容
		void BubbleSort();//冒泡排序
		void BubbleSort(Rank lo,Rank hi);//冒泡排序的重载版本
		void BubbleSort1(Rank lo,Rank hi);
		bool Bubble(Rank lo,Rank hi);//如果剩下的元素已经排好序，则返回真
		Rank Bubble1(Rank lo,Rank hi);//跳过已经排好序的元素，返回最后交换元素的秩
		static void Swap(T &a,T &b) {T t = a;a = b; b = t;}//交换
		Rank BinSearch(const T &elem,Rank lo,Rank hi) const;//二分查找,失败返回-1，不平衡
		Rank BinSearch1(const T &elem,Rank lo,Rank hi) const;//二分查找的另一个版本，平衡
		Rank BinSearch2(const T &elem,Rank lo,Rank hi) const;//二分查找有一个版本，失败返回不大于elem的最大者
		void Merge(Rank lo,Rank mid,Rank hi);//合并	
		void MergeSort(Rank lo,Rank hi);//归并排序
private:
		T *array_;
		Rank size_;
		int capacity_;
};

#include "vector_impl.h"

#endif
