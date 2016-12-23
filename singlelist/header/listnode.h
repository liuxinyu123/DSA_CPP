#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#define Position(T) ListNode<T>*

template<typename T>
class ListNode
{
public:
		T data_;//数据域
		Position(T) succ_;//指向后缀的指针

		ListNode() {}	
		ListNode(const T &elem,Position(T) s = nullptr):data_(elem),succ_(s) {}
		
		Position(T) InsertAsSucc(const T &elem)//作为后缀插入	
		{
			Position(T) p = new ListNode(elem,succ_);
			succ_ = p;
			return p;
		}
			
};

#endif
