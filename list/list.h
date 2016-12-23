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

private:
		void Init();
private:
		
private:
		int size_;
		Position(T) header_;
		Position(T) trailer_;
};

#include "list_impl.h"

#endif
