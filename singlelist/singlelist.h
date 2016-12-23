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
		SingleList(const SingleList<T> &l,Position(T) p,int n);//部分复制
		~SingleList();//析构函数
		int Size() const 
		{//求规模
			return size_;
		}
		bool Empty()  const 
		{//判空
			return size_ == 0;
		}
		Position(T) Front() const 
		{
			return header_ -> succ_;
		}
		Position(T) Back() const ;//求尾位置
		T PopFront();//表首删除
		T PopBack();//表为删除
		void PushFront(const T &elem);//表首添加
		void PushBack(const T &elem);//表尾添加
		void Print();//打印到屏幕
		Position(T) Head() {return header_;}
private:
		void Init();//初始化头节点
		int ClearAllNodes();//清除所有节点（除头节点）
		void Remove(Position(T) p);//删除指定节点
		Position(T) NodeBefore(Position(T) p) const ;//求位置p之前的位置
private:
		Position(T) header_;
		int size_;
};

#include "singlelist_impl.h"

#endif
