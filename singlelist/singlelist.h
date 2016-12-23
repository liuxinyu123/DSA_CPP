#ifndef _SINGLELIST_H_
#define _SINGLELIST_H_

#include "./header/listnode.h"

typedef int Rank;

template<typename T>
class SingleList
{
public:
		SingleList();//默认构造函数
		SingleList(const SingleList<T> &l);//链表整体复制
		SingleList(Position(T) p,int n);//部分复制
		~SingleList();//析构函数
		int Size() const 
		{//求规模
			return size_;
		}
		bool Empty()  const 
		{//判空
			return size_ == 0;
		}
		Position(T) Begin() const 
		{
			return header_ -> succ_;
		}
		Position(T) End() const ;//求尾位置
		T Front() const//求首元素
	   	{
			if(!Empty()) 
				return Begin() -> data_;
	   	}
		T Back() const //求尾元素
		{
			if(!Empty())
				return End() -> data_;
		}
		T PopFront();//表首删除
		T PopBack();//表为删除
		void PushFront(const T &elem);//表首添加
		void PushBack(const T &elem);//表尾添加
		void Print();//打印到屏幕
		Position(T) Find(const T &elem) const;//查找elem所在的位置（第一次）， 失败返回null
		Position(T) InsertBefore(Position(T) p,const T &elem);//插入指定位置之前
		Position(T) InsertAfter(Position(T) p,const T &elem);//插入指定位置之后
		T operator[](Rank r) const;//循秩访问
		SingleList<T>& operator= (const SingleList &l);//赋值运算符

private:
		void Init();//初始化头节点
		int ClearAllNodes();//清除所有节点（除头节点）
		void Remove(Position(T) p);//删除指定节点
		Position(T) NodeBefore(Position(T) p) const ;//求位置p之前的位置
		void CopyNodes(Position(T) p,int n);//拷贝节点

private:
		Position(T) header_;
		int size_;
};

#include "singlelist_impl.h"

#endif
