#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#define Position(T) ListNode<T>*

template<typename T>
class ListNode
{
public:
		T data_;//数据域
		Position(T) pred_;//前驱
		Position(T) succ_;//后继

		ListNode() {}
		Position(T) InsertAsPred(const T &elem);//前面插入
		Position(T) InsertAsSucc(const T &elem);//后面插入
private:
		ListNode(const T &elem,Position(T) p = nullptr,Position(T) s = nullptr):data_(elem),
			pred_(p),succ_(s) {}//默认构造函数

};

#include "listnode_impl.h"

#endif
