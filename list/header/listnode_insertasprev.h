#ifndef _LISTNODE_INSERTASPREV_H_
#define _LISTNODE_INSERTASPREV_H_

template<typename T>
Position(T) ListNode<T>::InsertAsPrev(const T &elem)
{
	Position(T) p = new ListNode(elem,pred_,this);
	pred_ = p;
	pred_ -> succ_ = this;

	return p;	
}

#endif
