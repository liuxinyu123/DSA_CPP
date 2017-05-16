#ifndef _LISTNODE_INSERTASSUCC_H_
#define _LISTNODE_INSERTASSUCC_H_

template<typename T>
Position(T) ListNode<T>::InsertAsSucc(const T &elem)
{
	Position(T) p = new ListNode(elem,this,succ_);
	succ_ -> pred_ = p;
	succ_ = p;

	return p;
}

#endif
