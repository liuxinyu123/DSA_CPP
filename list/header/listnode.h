#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#define Postion(T) ListNode<T>*

template<typename T>
struct ListNode
{
	T data_;//数据域
	Postion(T) pred_;//前驱
	Postion(T) succ_;//后继

	ListNode() {}
	ListNode(const T &elem,Postion(T) p = nullptr,Postion(T) s = nullptr):data_(elem),
		pred_(p),succ_(s) {}//默认构造函数
	Postion(T) InsertAsPrev(const T &elem);//前面插入
	Postion(T) InsertAsSucc(const T &elem);//后面插入

};

#include "listnode_impl.h"

#endif
