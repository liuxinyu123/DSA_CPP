#ifndef _LIST_H_
#define _LIST_H_

#include "./header/listnode.h"

typedef int Rank;

template<typename T>
class List
{
public:
		List() {Init();}//默认构造函数
		List(const List &l);//整体拷贝
		List(const List &l,Rank r,int n);//从秩r开始的n个
		List(Position(T) p,int n);//从节点p开始的n个
		~List();//析构	
		
		Position(T) First() const //取首
		{
			if(Empty())
				return trailer_;
			return header_ -> succ_;
		}
		Position(T) Last() const//取末
		{
			if(Empty())
				return header_;
			return trailer_ -> pred_;
		}
		void Print() const ;//打印到屏幕
		T operator[](Rank r) const;//巡秩访问
		int Size() const {return size_;}//规模
		bool Empty() const  {return size_ == 0;}//判空
		int Disorder() const;//返回逆序数
		Position(T) Find(const T &elem) const;//查找
		Position(T) Find(Position(T) p,int n,const T &elem) const;//从p位置开始向前n个元素查找
		Position(T) InsertAsFirst(const T &elem);//作为首节点插入
		Position(T) InsertAsLast(const T &elem);//作为末节点插入
		Position(T) InsertAfter(Position(T) p,const T &elem);//节点p后插入
		Position(T) InsertBefore(Position(T) p,const T &elem);//节点p前插入
		T Remove(Position(T) p);//删除指定节点
private:
		void Init();//初始化
		int Clear();//清空节点
private:
		
private:
		int size_;
		Position(T) header_;
		Position(T) trailer_;
};

#include "list_impl.h"

#endif
